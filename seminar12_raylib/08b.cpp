#include "raylib.h"
#include <cmath>

int main()
{
    InitWindow(800, 600, "Rotating circle");
    SetTargetFPS(60);
    Vector2 position = {400, 300};
    Vector2 v = {0.0, 0.0};
    double w = 100.0;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground((Color){190, 190, 190, 255});
        DrawCircleV(position, 70, BLUE);

        double t = GetFrameTime();
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            Vector2 direction = GetMousePosition();
            Vector2 delta = {direction.x - position.x, direction.y - position.y};
            float dist = std::sqrt(delta.x * delta.x + delta.y * delta.y);
            v.x += w*t*delta.x/dist;
            v.y += w*t*delta.y/dist;
        }
        position.x += v.x*t;
        position.y += v.y*t;

        EndDrawing();
    }
    CloseWindow();
}