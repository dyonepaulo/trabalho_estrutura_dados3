#include <raylib.h>
#include <stdlib.h>
#include <time.h>
#include "bibliotecas/dados.h"
#include "bibliotecas/funcoes.h"
#include <stdio.h>

int main()
{
    Rectangle botao_menu = {520, 499, 240, 100};
    int tela_menu = 0;

    InitWindow(1280, 718, "CARD GAMES");
    SetTargetFPS(60);
    Texture2D background = LoadTexture("assets/retro-pixel-art-background-with-sun-arcade_1303033-5146.png");
    Texture2D logo = LoadTexture("assets/exugames.png");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        if (tela_menu == 0)
        {

            DrawRectangleRounded(botao_menu, 0.2f, 10, GRAY); // desenha o botao com cantos arredondados
            DrawText("JOGAR", 530, 520, 67, WHITE);
            DrawTextureEx(logo, (Vector2){435.2, 70}, 0, .4, RAYWHITE);

            if (CheckCollisionPointRec(GetMousePosition(), botao_menu) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) // verifica se o mouse esta em cima do botao na janela e se apertou
            {
                tela_menu = 1;
            }
        }
        else if (tela_menu == 1)
        {
            DrawTextureEx(background, posicao, 0, 0.7646f, RAYWHITE);
            DrawRectangle(0, 0, 1280, 720, Fade(BLACK, 0.2f)); // coloca um fitro preto na imagem para destacar as barras de status
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
        }
        ClearBackground(BLACK);
        EndDrawing();
    }
    CloseWindow();
}