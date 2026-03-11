#include "raylib.h"
#include <iostream>
#include <algorithm>

class Slider
{
protected:
    Rectangle mTrackRect{};
    Rectangle mThumbRect{};

    bool mIsPressed{false};

public:
    Slider(Vector2 centerPosition, Vector2 trackSize, Vector2 thumbSize)
    {
        mTrackRect.width = trackSize.x;
        mTrackRect.height = trackSize.y;
        mTrackRect.x = centerPosition.x - trackSize.x / 2.0f;
        mTrackRect.y = centerPosition.y - trackSize.y / 2.0f;

        mThumbRect.width = thumbSize.x;
        mThumbRect.height = thumbSize.y;
        mThumbRect.x = centerPosition.x - thumbSize.x / 2.0f;
        mThumbRect.y = centerPosition.y - thumbSize.y / 2.0f;
    }

    void draw()
    {
        DrawRectangleRec(mTrackRect, {200, 200, 220, 255});
        DrawRectangleRec(mThumbRect, {150, 150, 240, 255});
    }

    void setRestrictedThumbPosition(Vector2 position)
    {
        float min = mTrackRect.x;
        float max = mTrackRect.x + mTrackRect.width;
        float clampedX = std::clamp(position.x, min, max);
        mThumbRect.x = clampedX - mThumbRect.width / 2.0f;
    }

    bool handleEvent()
    {
        Vector2 mousePosition = GetMousePosition();
        bool result = false;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (CheckCollisionPointRec(mousePosition, mThumbRect) ||
                CheckCollisionPointRec(mousePosition, mTrackRect))
            {
                mIsPressed = true;
                setRestrictedThumbPosition(mousePosition);
                result = true;
            }
        }

        if (mIsPressed && (GetMouseDelta().x != 0 || GetMouseDelta().y != 0))
        {
            setRestrictedThumbPosition(mousePosition);
        }

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            mIsPressed = false;
        }

        return result;
    }

    bool isPressed() const
    {
        return mIsPressed;
    }

    float getValue() const
    {
        float start = mTrackRect.x;
        float finish = mTrackRect.x + mTrackRect.width;
        float position = mThumbRect.x + mThumbRect.width / 2.0f;
        return 100.0f * (position - start) / (finish - start);
    }
};



int main()
{
    InitWindow(800, 600, "RGB Sliders");
    SetTargetFPS(60);
    Color circle_color {WHITE};

    Slider r_slider({200, 200}, {300, 20}, {15, 60});
    Slider g_slider({200, 300}, {300, 20}, {15, 60});
    Slider b_slider({200, 400}, {300, 20}, {15, 60});

    while (!WindowShouldClose())
    {
        r_slider.handleEvent();
        g_slider.handleEvent();
        b_slider.handleEvent();

        if (r_slider.isPressed() && (GetMouseDelta().x != 0 || GetMouseDelta().y != 0))
        {
            circle_color.r = r_slider.getValue()*2.55;
        }

        if (g_slider.isPressed() && (GetMouseDelta().x != 0 || GetMouseDelta().y != 0))
        {
            circle_color.g = g_slider.getValue()*2.55;
        }

        if (b_slider.isPressed() && (GetMouseDelta().x != 0 || GetMouseDelta().y != 0))
        {
            circle_color.b = b_slider.getValue()*2.55;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        r_slider.draw();
        g_slider.draw();
        b_slider.draw();
        DrawCircleV({600, 300}, 100, circle_color);
        EndDrawing();
    }

    CloseWindow();
}