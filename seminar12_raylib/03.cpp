#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Rotating square");
    SetTargetFPS(60);
    float rotation = 0;
    while (!WindowShouldClose())
    {
        rotation += 2.0f;
        BeginDrawing();
        ClearBackground(DARKGRAY);
        DrawRectanglePro({450, 250, 100, 100}, {0, 100}, rotation, LIME);
        EndDrawing();
    }
    CloseWindow();
}