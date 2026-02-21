#include "raylib.h"
#include <vector>

int main()
{
    InitWindow(800, 600, "Rotating circle");
    SetTargetFPS(60);
    std::vector<Color> colours {YELLOW, GOLD, ORANGE, PINK, RED, MAROON, GREEN, LIME, DARKGREEN, SKYBLUE, BLUE, DARKBLUE, PURPLE, VIOLET, DARKPURPLE, BEIGE, BROWN, DARKBROWN};
    Color current_colour = GREEN;
    Vector2 position = {400, 300};
    double v = 200.0;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircleV(position, 70, current_colour);

        double t = GetFrameTime();
        if (IsKeyDown(KEY_UP)) {position.y -= v*t;}
        if (IsKeyDown(KEY_DOWN)) {position.y += v*t;}
        if (IsKeyDown(KEY_RIGHT)) {position.x += v*t;}
        if (IsKeyDown(KEY_LEFT)) {position.x -= v*t;}
        if (IsKeyPressed(KEY_SPACE)) {current_colour = colours[GetRandomValue(0, colours.size()-1)];}
        EndDrawing();
    }
    CloseWindow();
}