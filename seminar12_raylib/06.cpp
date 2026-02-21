#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Colour change");
    SetTargetFPS(60);
    struct Color gray {190, 190, 190, 255};
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(gray);
        int x = GetMouseX();
        int y = GetMouseY();
        if (x > 300 && x < 500 && y > 250 && y < 350) {DrawRectangle(300, 250, 200, 100, GREEN);}
        else DrawRectangle(300, 250, 200, 100, RED);
        EndDrawing();
    }
    CloseWindow();
}