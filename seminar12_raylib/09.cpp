#include "raylib.h"
#include <vector>

int main()
{
    InitWindow(800, 600, "Rotating circle");
    SetTargetFPS(60);
    std::vector<Color> colours {YELLOW, GOLD, ORANGE, PINK, RED, MAROON, GREEN, LIME, DARKGREEN, SKYBLUE, BLUE, DARKBLUE, PURPLE, VIOLET, DARKPURPLE, BEIGE, BROWN, DARKBROWN};
    Color current_colour = WHITE;
    std::vector<Vector2> positions {};
    double v = 200.0;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            positions.push_back(GetMousePosition());
        }

        for (auto position = positions.begin(); position != positions.end(); ++position)
        {
            DrawCircleV(*position, 70, current_colour);
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            current_colour = colours[GetRandomValue(0, colours.size()-1)];
        }

        EndDrawing();
    }
    CloseWindow();
}