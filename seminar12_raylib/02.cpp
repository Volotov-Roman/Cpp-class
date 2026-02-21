#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Moving ball");
    SetTargetFPS(60);
    Vector2 center = {0, 300.0f};
    const float speed = 150.0f;
    while (!WindowShouldClose())
    {
        center.x += GetFrameTime()*speed;
        if (center.x > 850) center.x = -50;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(center, 50, GREEN);
        EndDrawing();
    }
    CloseWindow();
}