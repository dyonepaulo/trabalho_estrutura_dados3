#include <stdlib.h>
#include <time.h>
#include "funcoes.h"
#include "dados.h"
#include <raylib.h>
#include <stdio.h>

void barra_de_status(player *jogador)
{
    // barra de vida
    Rectangle retangulofundo = {20, 20, 300, 30};
    Rectangle retangulovisor = {20, 20, (jogador->vida_atual * 3), 30};
    sprintf(texto_vida, "%d/100", jogador->vida_atual);
    DrawRectangleRec(retangulofundo, GRAY);
    DrawRectangleRec(retangulovisor, GREEN);
    DrawText(texto_vida, 30, 25, 20, BLACK);

    // barra de escudo
    Rectangle retangulofundo_escudo = {20, 50, 100, 30};
    Rectangle retangulovisor_escudo = {20, 50, (jogador->escudo * 5), 30};
    sprintf(texto_escudo, "%d/20", jogador->escudo);
    DrawRectangleRec(retangulofundo_escudo, GRAY);
    DrawRectangleRec(retangulovisor_escudo, SKYBLUE);
    DrawText(texto_escudo, 30, 55, 20, BLACK);

    // barra de energia
    Rectangle retangulofundo_energia = {20, 80, 60, 25};
    Rectangle retangulovisor_energia = {20, 80, (jogador->energia * 30), 25};
    sprintf(texto_energia, "%d/2", jogador->energia);
    DrawRectangleRec(retangulofundo_energia, GRAY);
    DrawRectangleRec(retangulovisor_energia, PURPLE);
    DrawText(texto_energia, 30, 85, 20, BLACK);
    return;
}

int gerar_cartas(carta carta, nos no, fila fila)
{
    int limite[] = {2, 1, 2, 2, 2, 1, 1, 2, 1, 1}; // limite de quantas vezes cada carta pode aparecer, por ordem de ID

    int contador[10] = {0}; // conta quantas vezes cada carta já apareceu
    int fila_cartas_p1[10]; // fila de cartas do player 1
    int fila_cartas_p2[10]; // fila de cartas do player 2

    srand(time(NULL)); // define seed pro sorteador
    for (int i = 0; i < 10; i++)
    {
        do
        {

            fila_cartas_p1[i] = rand() % 10 + 1; // atribui um numero aleatorio q representa o id da carta sorteada a posição do vetor
        } while (contador[fila_cartas_p1[i]] >= limite[fila_cartas_p1[i]]); // verifica quantas vezes o ID foi gerado
        contador[fila_cartas_p1[i]]++; // conta quantas vezes o ID apareceu
    }

    srand(time(NULL)); // define seed pro sorteador
    for (int i = 0; i < 10; i++)
    {
        do
        {

            fila_cartas_p2[i] = rand() % 10 + 1; // atribui um numero aleatorio q representa o id da carta sorteada a posição do vetor
        } while (contador[fila_cartas_p2[i]] >= limite[fila_cartas_p2[i]]);
        contador[fila_cartas_p1[i]]++; // conta quantas vezes o ID apareceu
    }
}
