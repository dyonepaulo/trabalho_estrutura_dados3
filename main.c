#include <raylib.h>
#include <stdlib.h>
#include <time.h>
#include "bibliotecas/dados.h"
#include "bibliotecas/funcoes.h"
int main()
{

    player jogador;
    jogador.vida_atual = 67;
    jogador.escudo = 15;
    jogador.energia = 1;

    InitWindow(1280, 718, "CARD GAMES");
    SetTargetFPS(60);
    Texture2D background = LoadTexture("assets/retro-pixel-art-background-with-sun-arcade_1303033-5146.png");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        DrawTextureEx(background, posicao, 0, 0.7646f, RAYWHITE);
        DrawRectangle(0, 0, 1280, 720, Fade(BLACK, 0.3f));
        if (turno == 0)
        {
            barra_de_status(&jogador1);
            ClearBackground(RAYWHITE);
            turno = 1;
        }
        else
        {
            barra_de_status(&jogador2);
            ClearBackground(RAYWHITE);
            turno = 0;
        }
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}