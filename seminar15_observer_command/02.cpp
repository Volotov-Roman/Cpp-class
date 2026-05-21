#include "raylib.h"
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>

class Observer
{
public:
    virtual void update(float value, std::string type) = 0;
    virtual ~Observer() = default;
};

class Drawable
{
public:
    virtual void draw() const = 0;
    virtual ~Drawable() = default;
};

class Slider : public Drawable
{
private:
    Rectangle mTrack;
    Rectangle mThumb;
    Color mTrackColor {200, 200, 220, 255};
    Color mThumbColor {150, 150, 240, 255};
    bool mIsPressed {false};
    std::set<Observer*> mObservers;
    std::string mType;

public:
    Slider(Vector2 center, Vector2 trackSize, Vector2 thumbSize, std::string type) : mType(type)
    {
        mTrack = {center.x - trackSize.x / 2, center.y - trackSize.y / 2, trackSize.x, trackSize.y};
        mThumb = {center.x - thumbSize.x / 2, center.y - thumbSize.y / 2, thumbSize.x, thumbSize.y};
    }

    void draw() const override
    {
        DrawRectangleRec(mTrack, mTrackColor);
        DrawRectangleRec(mThumb, mThumbColor);
    }

    void updateInput()
    {
        Vector2 mouse = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (CheckCollisionPointRec(mouse, mThumb) || CheckCollisionPointRec(mouse, mTrack))
            {
                mIsPressed = true;
                mThumb.x = mouse.x - mThumb.width / 2;
                notifyObservers();
            }
        }

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            mIsPressed = false;
        }

        if (mIsPressed)
        {
            float min = mTrack.x;
            float max = mTrack.x + mTrack.width;
            float clampedX = std::clamp(mouse.x, min, max);
            mThumb.x = clampedX - mThumb.width / 2;
            notifyObservers();
        }
    }

    float getValue() const
    {
        float part = (mThumb.x + mThumb.width / 2) - mTrack.x;
        return (part / mTrack.width) * 100.0f;
    }

    void addObserver(Observer* p)
    {
        mObservers.insert(p);
    }

    void notifyObservers()
    {
        for (auto p : mObservers)
        {
            p->update(getValue(), mType);
        }
    }
};


class Square : public Observer, public Drawable
{
private:
    Vector2 mPosition;
    float mSize;
    float mRotation {0.0f};
    Color mColor;
    Color mCurrentColor;

public:
    Square(Vector2 position, float size, Color c)
        : mPosition(position), mSize(size), mColor(c), mCurrentColor(c)
    {
    }

    void draw() const override
    {
        DrawRectanglePro({mPosition.x, mPosition.y, mSize, mSize}, {mSize / 2, mSize / 2}, mRotation, mCurrentColor);
    }

    void update(float value, std::string type) override
    {
        if (type == "Rotation")
        {
            mRotation = 3 * value;
        }
        else if (type == "Color")
        {
            mCurrentColor.r = (unsigned char) (mColor.r*(100.0f-value)/100.0f + value*140.0f/100.0f);
            mCurrentColor.g = (unsigned char) (mColor.g*(100.0f-value)/100.0f);
            mCurrentColor.b = (unsigned char) (mColor.b*(100.0f-value)/100.0f + value*255.0f/100.0f);
        }
    }
};

int main()
{
    InitWindow(800, 800, "Multiple Observers (raylib)");
    SetTargetFPS(60);

    Slider rslider({400, 500}, {500, 20}, {25, 90}, std::string{"Rotation"});
    Slider cslider({400, 600}, {500, 20}, {25, 90}, std::string{"Color"});

    std::vector<Observer*> observers
    {
        new Square({100, 300}, 100, RED),
        new Square({400, 300}, 100, BLUE),
        new Square({700, 300}, 100, GREEN),
    };

    for (auto p : observers)
    {
        rslider.addObserver(p);
        cslider.addObserver(p);
    }

    while (!WindowShouldClose())
    {
        rslider.updateInput();
        cslider.updateInput();

        BeginDrawing();
        ClearBackground(BLACK);

        rslider.draw();
        cslider.draw();

        for (auto p : observers)
        {
            dynamic_cast<Drawable*>(p)->draw();
        }

        EndDrawing();
    }

    for (auto p : observers)
    {
        delete p;
    }

    CloseWindow();
    return 0;
}