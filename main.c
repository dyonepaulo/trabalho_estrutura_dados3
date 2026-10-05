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
    pilha *lixeira = calloc(1, sizeof(pilha));
    mao *mao_jogador1 = calloc(1, sizeof(mao));
    mao *mao_jogador2 = calloc(1, sizeof(mao));
    fila *fila_jogador1 = calloc(1, sizeof(fila));
    fila *fila_jogador2 = calloc(1, sizeof(fila));

    if (lixeira == NULL || mao_jogador1 == NULL || mao_jogador2 == NULL || fila_jogador1 == NULL || fila_jogador2 == NULL)
    {
        printf("Falha na alocação de memória. ");
        exit(1);
    }

    jogador1.fila_player = fila_jogador1;
    jogador2.fila_player = fila_jogador2;

    fila_jogador1->primeiro = NULL;
    fila_jogador2->ultimo = NULL;
    fila_jogador2->primeiro = NULL;
    fila_jogador2->ultimo = NULL;

    lixeira->topo = NULL;

    mao_jogador1->carta_selecionada = NULL;
    mao_jogador2->carta_selecionada = NULL;

    carregar_assets();
    gerar_cartas(fila_jogador1);
    gerar_cartas(fila_jogador2);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (jogador2.vida_atual <= 0)
        {
            gameover_ativo = true;
            tela_menu = 3;
            id_loser_player = jogador2.id_player;
        }

        if (jogador1.vida_atual <= 0)
        {
            gameover_ativo = true;
            tela_menu = 3;
            id_loser_player == jogador1.id_player;
        }
        if (gameover_ativo)
        {
            game_over();
            if (!gameover_ativo)
            {
                break; //manda pra linha 139
            }
        }

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
                carta_fila_pra_mão(mao_jogador1, lixeira, fila_jogador1);
                visor_mao(mao_jogador1, &jogador1, lixeira, fila_jogador1);
                fix_player_stats(&jogador1);
                fix_player_stats(&jogador2);
                visor_lixeiera(lixeira);
                sprite_inimigo(jogador1.id_player);
                proxima_carta(mao_jogador1, fila_jogador1); // em teste
                barra_de_status(&jogador1);
                mensagem_erro_lixeira();

                if (jogador1.energia <= 0)
                {
                    jogador1.energia = 2;
                    turno = 1;
                }
            }
            else
            {
                if (turno == 1)
                {
                    carta_fila_pra_mão(mao_jogador2, lixeira, fila_jogador2);
                    visor_mao(mao_jogador2, &jogador2, lixeira, fila_jogador2);
                    fix_player_stats(&jogador1);
                    fix_player_stats(&jogador2);
                    visor_lixeiera(lixeira);
                    sprite_inimigo(jogador2.id_player);
                    proxima_carta(mao_jogador2, fila_jogador2); // em teste
                    barra_de_status(&jogador2);
                    consulta_pilha(lixeira);
                    mensagem_erro_lixeira();

                    if (jogador2.energia <= 0)
                    {
                        jogador2.energia = 2;
                        turno = 0;
                    }
                }
            }
        }
        EndDrawing();
    }
    esvaziar_filas(fila_jogador1);
    esvaziar_filas(fila_jogador2);
    esvaziar_pilha(lixeira);
    free(fila_jogador1);
    free(fila_jogador2);
    esvaziar_mao(mao_jogador1, mao_jogador2);
    free(mao_jogador1);
    free(mao_jogador2);
    free(lixeira);

    CloseWindow();
}