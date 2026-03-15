#include "raylib.h"
#include <math.h>
#include <stdio.h>

void DrawTree(float x, float y, float angle, float length, float currentSway)
{
    if (length < 5)
        return; 


    float y2 = y + sin(angle * DEG2RAD) * length;
    float x2 = x + cos(angle * DEG2RAD) * length;

    DrawLineEx((Vector2){x, y}, (Vector2){x2, y2}, length / 10, BLACK);


    DrawTree(x2, y2, angle - currentSway, length * 0.7, currentSway);
    DrawTree(x2, y2, angle + currentSway, length * 0.7, currentSway);
}

int main()
{
    InitWindow(800, 600, "Fractal Tree");
    SetTargetFPS(60);

    float timer = 0.0f;

    while (!WindowShouldClose())
    {

        timer += GetFrameTime();
        printf("Timer: %.2f seconds\n", timer);

        float dynamicAngle = 30.0f + sinf(timer * 1.0f) * 10.0f;
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTree(400, 550, -90, 100, dynamicAngle);
        
        DrawText("Fractal Tree", 10, 10, 20, DARKGRAY);


        EndDrawing();
    }
    CloseWindow();
    return 0;
}