#include "raylib.h"
#include <vector>

#define BLUEMAIN (Color) {175, 221, 233, 255}
#define BLUEAUX (Color) {215, 238, 244, 255}

class DropList
{
private:
    Vector2 top_left;
    int length;
    int width;
    std::vector<const char*> data;
    int current_index;
    bool IsInSelectionMode;
public:
    DropList(Vector2 a, int l, int w, std::vector<const char*> d): top_left(a), length(l), width(w), data(d), current_index(0), IsInSelectionMode(0) {}

    void onMousePressed(Vector2 mousePosition)
    {
        if (CheckCollisionPointRec(mousePosition, {top_left.x, top_left.y, length, width}))
        {
            IsInSelectionMode = !IsInSelectionMode;
        }
        if (IsInSelectionMode)
        {
            for(int i=0; i < data.size(); i++)
            {
                if (CheckCollisionPointRec(mousePosition, {top_left.x, top_left.y+(i+1)*width, length, width}))
                {
                    current_index = i;
                    IsInSelectionMode = 0;
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
        if (!IsInSelectionMode)
        {
            DrawRectangle(top_left.x, top_left.y, length, width, BLUEMAIN);
            DrawRectangleLines(top_left.x, top_left.y, length, width, BLACK);
            DrawPoly({top_left.x+0.9*length, top_left.y+0.5*width}, 3, 0.25*width, 90, BLACK);
            DrawText(data[current_index], top_left.x+5, top_left.y+5, 20, BLACK);
        }
        else
        {
            DrawRectangle(top_left.x, top_left.y, length, width, BLUEMAIN);
            DrawRectangleLines(top_left.x, top_left.y, length, width, BLACK);
            DrawPoly({top_left.x+0.9*length, top_left.y+0.5*width}, 3, 0.25*width, 30, BLACK);
            DrawText(data[current_index], top_left.x+5, top_left.y+5, 20, BLACK);

            for (int i = 0; i < data.size(); i++)
            {
                DrawRectangle(top_left.x, top_left.y+(i+1)*width, length, width, BLUEAUX);
                DrawRectangleLines(top_left.x, top_left.y+(i+1)*width, length, width, BLACK);
                DrawText(data[i], top_left.x+5, top_left.y+(i+1)*width+5, 20, BLACK);
            }
        }
    }
};

int main()
{
    InitWindow(800, 600, "Droplist");
    SetTargetFPS(60);

    DropList a {{50, 50}, 200, 30, std::vector<const char*> {"1", "2", "232", "a", "AA"}};

    while (!WindowShouldClose())
    {
        a.handleEvents();
        BeginDrawing();
        ClearBackground(BLACK);
        a.draw();
        EndDrawing();
    }

    CloseWindow();
}