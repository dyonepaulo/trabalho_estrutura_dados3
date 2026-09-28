#include <raylib.h>
#include "bibliotecas/dados.h"
int main()
{
    InitWindow(1280, 720, "CARD GAMES");
    SetTargetFPS(60);
    Texture2D background = LoadTexture("assets/retro-pixel-art-background-with-sun-arcade_1303033-5146.png");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        DrawTextureEx(background, posicao, 0, 3.6f, WHITE);
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
    
}