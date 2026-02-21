#include "raylib.h"
#include <string>

int main()
{
    InitWindow(800, 600, "Mouse coords");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        int x = GetMouseX();
        int y = GetMouseY();
        std::string str = "x: " + std::to_string(x) + "\n" + "y: " + std::to_string(y);
        DrawText(str.c_str(), 10, 10, 50, BLACK);
        EndDrawing();
    }
    CloseWindow();
}