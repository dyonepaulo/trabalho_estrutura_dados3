#include <raylib.h>
#include <stdlib.h>
#include <time.h>
#include "bibliotecas/dados.h"
int main()
{
    InitWindow(1280, 718, "CARD GAMES");
    SetTargetFPS(60);
    Texture2D background = LoadTexture("assets/retro-pixel-art-background-with-sun-arcade_1303033-5146.png");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        DrawTextureEx(background, posicao, 0, 0.7646f, WHITE);
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
    
}