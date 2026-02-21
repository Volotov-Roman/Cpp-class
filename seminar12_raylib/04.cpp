#include "raylib.h"
#include <cmath>

int main()
{
    InitWindow(800, 600, "Rotating circle");
    SetTargetFPS(60);
    float angle = 0;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircleV({(float)(400 + 200*cos(angle)), (float)(300 + 200.0*sin(angle))}, 50, GREEN);
        EndDrawing();
        angle += GetFrameTime()*2.0;
    }
    CloseWindow();
}