#include "raylib.h"

#define MGREEN (Color) {110, 220, 95, 255}
#define MGRAY (Color) {221, 221, 221, 255}
#define SCALE 30

struct Base
{
    Vector2 left;
    Vector2 right;
    Vector2 center;
    float radius;
};

class Toggle
{
private:
    int x;
    int y;
    bool IsOn;
    bool IsMoving;
    Base mBase;
    Vector2 mTriggerPos;
public:
    Toggle(int a, int b): x(a), y(b), IsOn(0), IsMoving(0), mBase{{a,b}, {a+2*SCALE,b}, {a+SCALE,b}, SCALE}, mTriggerPos{a,b} {}

    void onMousePressed(Vector2 mousePosition)
    {
        if (CheckCollisionPointCircle(mousePosition, mTriggerPos, 0.8*SCALE))
        {
            IsOn = !IsOn;
            IsMoving = true;
        }
    }

    void update()
    {
        double t = GetFrameTime();
        float v = 500;
        if (IsMoving)
        {
            if (IsOn)
            {
                if (mTriggerPos.x < mBase.right.x) {mTriggerPos.x += v*t;}
                else if (mTriggerPos.x >= mBase.right.x)
                {
                    mTriggerPos.x = mBase.right.x;
                    IsMoving = false;
                }
            }
            else if (!IsOn)
            {
                if (mTriggerPos.x > mBase.left.x) {mTriggerPos.x -= v*t;}
                else if (mTriggerPos.x <= mBase.left.x)
                {
                    mTriggerPos.x = mBase.left.x;
                    IsMoving = false;
                }
            }
        }
    }

    void handleEvents()
    {
        Vector2 mousePosition = GetMousePosition();
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            onMousePressed(mousePosition);
        }
    }

    void draw()
    {
        if (IsOn)
        {
            DrawCircleV(mBase.left, SCALE, MGREEN);
            DrawCircleV(mBase.right, SCALE, MGREEN);
            DrawRectangle(mBase.left.x, mBase.left.y-SCALE, 2*SCALE, 2*SCALE, MGREEN);
            DrawCircleV(mTriggerPos, 0.8*SCALE, WHITE);
        }
        else if (!IsOn)
        {
            DrawCircleV(mBase.left, SCALE, MGRAY);
            DrawCircleV(mBase.right, SCALE, MGRAY);
            DrawRectangle(mBase.left.x, mBase.left.y-SCALE, 2*SCALE, 2*SCALE, MGRAY);
            DrawCircleV(mTriggerPos, 0.8*SCALE, WHITE);
        }
    }
};

int main()
{
    InitWindow(800, 600, "Toggle");
    SetTargetFPS(60);

    Toggle a {50, 50};

    while (!WindowShouldClose())
    {
        a.handleEvents();
        a.update();
        BeginDrawing();
        ClearBackground(BLACK);
        a.draw();
        EndDrawing();
    }

    CloseWindow();
}