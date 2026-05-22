#include "raylib.h"
#include <vector>
#include <iostream>
#include <optional>

#include "button.hpp"
#include "slider.hpp"
#include "draggable.hpp"

class Widget
{
public:
    virtual std::optional<bool> update() = 0;
    virtual void draw() const = 0;
    virtual ~Widget() = default;
};

class ButtonWidget : public Widget 
{
    Button mButton;
public:
    ButtonWidget(Rectangle rect, const std::string& textData): mButton(rect, textData) {}
    void draw() const override {mButton.draw();}
    std::optional<bool> update() override 
    {
        bool flag = mButton.update();
        if (flag) std::cout << "Button clicked\n";
        return flag;
    }
};

class DraggableWidget : public Widget
{
    Draggable mDraggable;
public:
    DraggableWidget(Vector2 position, Vector2 size, Color color): mDraggable(position, size, color) {}
    void draw() const override {mDraggable.draw();}
    std::optional<bool> update() override 
    {
        mDraggable.update();
        return {};
    }
};

class SliderWidget : public Widget
{
    Slider mSlider;
public:
    SliderWidget(Vector2 centerPosition, Vector2 trackSize, Vector2 thumbSize): mSlider(centerPosition, trackSize, thumbSize) {}
    void draw() const override {mSlider.draw();}
    std::optional<bool> update() override {return mSlider.update();}
};

int main()
{
    InitWindow(800, 800, "Widgets");
    SetTargetFPS(60);

    std::vector<ButtonWidget> buttons;
    buttons.emplace_back(Rectangle{350, 300, 200, 80}, "Cat");
    buttons.emplace_back(Rectangle{200, 450, 100, 80}, "Dog");
    buttons.emplace_back(Rectangle{600, 600, 150, 70}, "Mouse");

    std::vector<SliderWidget> sliders;
    sliders.emplace_back(Vector2{500, 500}, Vector2{200, 10}, Vector2{20, 40});
    sliders.emplace_back(Vector2{300, 100}, Vector2{250, 20}, Vector2{30, 60});

    std::vector<DraggableWidget> draggables;
    draggables.emplace_back(Vector2{550, 100}, Vector2{200, 120}, Color{20, 120, 50, 255});
    draggables.emplace_back(Vector2{50, 550}, Vector2{200, 200}, Color{170, 20, 50, 255});
    draggables.emplace_back(Vector2{50, 200}, Vector2{100, 100}, Color{100, 20, 150, 255});

    std::vector<Widget*> widgets;
    for (auto& b : buttons)
        widgets.push_back(&b);
    for (auto& s : sliders)
        widgets.push_back(&s);
    for (auto& d : draggables)
        widgets.push_back(&d);

    while (!WindowShouldClose())
    {
        for (auto w : widgets)
            w->update();

        BeginDrawing();
        ClearBackground(BLACK);

        for (auto w : widgets)
            w->draw();

        EndDrawing();
    }

    CloseWindow();
}
