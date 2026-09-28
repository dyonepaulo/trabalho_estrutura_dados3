#include <raylib.h>
#include "bibliotecas/dados.h"
#include "bibliotecas/funcoes.h"
int main()
{

    player jogador;
    jogador.vida_atual = 67;

    InitWindow(1280, 718, "CARD GAMES");
    SetTargetFPS(60);
    Texture2D background = LoadTexture("assets/retro-pixel-art-background-with-sun-arcade_1303033-5146.png");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        DrawTextureEx(background, posicao, 0, 0.7646f, WHITE);
        barra_vida(&jogador);
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;

    
}