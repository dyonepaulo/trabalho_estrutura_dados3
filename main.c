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
    char opcao;
    nos *lixeira = calloc(1, sizeof(nos));

    srand(time(NULL)); // define seed pro sorteador
    InitWindow(1280, 718, "CARD GAMES");
    SetTargetFPS(60);
    carregar_assets();

    // teste
    nos *node_teste = calloc(1, sizeof(nos));
    nos *node_teste2 = calloc(1, sizeof(nos));

    mao *mao_jogador1 = calloc(1, sizeof(mao));
    mao_jogador1->carta_selecionada = node_teste;
    mao_jogador1->carta_selecionada->carta = aura;
    mao_jogador1->carta_selecionada->status = 1;
    mao *mao_jogador2 = calloc(1, sizeof(mao));
    mao_jogador2->carta_selecionada = node_teste2;
    mao_jogador2->carta_selecionada->status = 1;
    mao_jogador2->carta_selecionada->carta = aura;
    lixeira->carta = marca_besta;
    lixeira->status = 0;
    // fimTeste

    fila *fila_jogador1 = calloc(1, sizeof(fila));
    fila *fila_jogador2 = calloc(1, sizeof(fila));
    if(fila_jogador1 == NULL || fila_jogador2 == NULL){
        printf("Falha na alocação de memória. ");
        exit(1);
    }

    gerar_cartas(fila_jogador1);
    gerar_cartas(fila_jogador2);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        if (tela_menu == 0)
        {
            // ClearBackground(BLACK);
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
                visor_lixeiera(&lixeira);
                visor_mao(mao_jogador1);
                sprite_inimigo(0);
                proxima_carta(mao_jogador1, fila_jogador1); //em teste
                barra_de_status(&jogador1);
                mensagem_erro_lixeira();
                if (jogador1.energia == 0)
                {
                    turno = 1;
                }
            }
            else
            {
                if (turno == 1)
                {
                    barra_de_status(&jogador2);
                    sprite_inimigo(1);
                    visor_lixeiera(&lixeira);
                    visor_mao(mao_jogador2);
                    sprite_inimigo(1);
                    // proxima_carta(mao_jogador2); //falta concertar parametro
                    switch (opcao)
                    {
                    case '1':
                        break;
                    case '2':
                        break;
                    case '3':
                        break;
                    case '4':
                        break;
                    case '5':
                        break;
                    }
                    ClearBackground(RAYWHITE);
                    if (jogador2.energia == 0)
                    {
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