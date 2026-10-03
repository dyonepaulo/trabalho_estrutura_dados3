#include <raylib.h>
#include <stdlib.h>
#include <time.h>
#include "bibliotecas/dados.h"
#include "bibliotecas/funcoes.h"
#include <stdio.h>
int main()
{
    InitWindow(1280, 718, "CARD GAMES");
    SetTargetFPS(60);

    Rectangle botao_menu = {520, 499, 240, 100};
    srand(time(NULL)); // define seed pro sorteador

    // alocação de memória para as estruturas de dados
    lixeira *lixeira = calloc(1, sizeof(lixeira));
    mao *mao_jogador1 = calloc(1, sizeof(mao));
    mao *mao_jogador2 = calloc(1, sizeof(mao));
    fila *fila_jogador1 = calloc(1, sizeof(fila));
    fila *fila_jogador2 = calloc(1, sizeof(fila));
    // nos *node = calloc(1, sizeof(nos));

    // mao_jogador1->carta_selecionada = node;
    // mao_jogador2->carta_selecionada = node;
    erro_alocacao(lixeira, mao_jogador1, mao_jogador2, fila_jogador1, fila_jogador2);

    // fila_jogador1->primeiro = NULL;
    // fila_jogador2->ultimo = NULL;
    // fila_jogador2->primeiro = NULL;
    // fila_jogador2->ultimo = NULL;
    // lixeira->topo = node;

    carregar_assets();
    gerar_cartas(fila_jogador1);
    gerar_cartas(fila_jogador2);
    mao_jogador1->carta_selecionada = fila_jogador1->primeiro;
    fila_jogador1->primeiro = fila_jogador1->primeiro->proximo;
    mao_jogador2->carta_selecionada = fila_jogador2->primeiro;
    fila_jogador2->primeiro = fila_jogador2->primeiro->proximo;

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(RAYWHITE);
        game_over();
        if (tela_menu == 0)
        {
            ClearBackground(BLACK);
            DrawRectangleRounded(botao_menu, 0.2f, 10, GRAY); // desenha o botao com cantos arredondados
            DrawText("JOGAR", 530, 520, 67, WHITE);
            DrawTextureEx(logo, (Vector2){420., 55}, 0, .35, RAYWHITE);

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
                if (mao_jogador1->carta_selecionada == NULL)
                {
                    carta_fila_pra_mão(mao_jogador1, lixeira, fila_jogador1);
                }
                proxima_carta(mao_jogador1, fila_jogador1); // em teste
                visor_mao(mao_jogador1, &jogador1, lixeira,fila_jogador1);
                visor_lixeiera(lixeira);
                sprite_inimigo(0);
                barra_de_status(&jogador1);
                mensagem_erro_lixeira();
                if (jogador1.energia == 0)
                {
                    jogador1.energia = 2;
                    turno = 1;
                }
            }
            else
            {
                if (turno == 1)
                {
                    if (mao_jogador2->carta_selecionada == NULL)
                    {
                        carta_fila_pra_mão(mao_jogador2, lixeira, fila_jogador2);
                    }
                    barra_de_status(&jogador2);
                    sprite_inimigo(1);
                    proxima_carta(mao_jogador1, fila_jogador2);
                    visor_mao(mao_jogador2, &jogador2, lixeira,fila_jogador2);
                    visor_lixeiera(lixeira);
                    sprite_inimigo(1);
                    mensagem_erro_lixeira();
                    ClearBackground(RAYWHITE);
                    if (jogador2.energia == 0)
                    {
                        jogador2.energia = 2;
                        turno = 0;
                    }
                }
            }
        }
        EndDrawing();
    }
    free(mao_jogador1);
    free(mao_jogador2);
    free(lixeira);
    CloseWindow();
}