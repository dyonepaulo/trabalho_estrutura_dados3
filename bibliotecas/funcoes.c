#include <stdlib.h>
#include <time.h>
#include "funcoes.h"
#include "dados.h"
#include <raylib.h>
#include <stdio.h>

void barra_vida(player *jogador)
{
    Rectangle retangulofundo = {20, 20, 100, 30};
    Rectangle retangulovisor = {20, 20, jogador->vida_atual, 30};
    sprintf(texto_vida,"%d",jogador->vida_atual);
    DrawRectangleRec(retangulofundo, GRAY);
    DrawRectangleRec(retangulovisor, GREEN);
    
}

int gerar_cartas(carta carta, nos no, fila fila){
    int limite[] = {2, 1, 2, 2, 2, 1, 1, 2, 1, 1}; //limite de quantas vezes cada carta pode aparecer, por ordem de ID
    
    int contador[10] = {0}; //conta quantas vezes cada carta já apareceu
    int fila_cartas_p1[10]; //fila de cartas do player 1
    int fila_cartas_p2[10]; //fila de cartas do player 2

    srand(time(NULL)); //define seed pro sorteador
    for(int i=0;i<10;i++){
        do{
    
            fila_cartas_p1[i] = rand () % 10+1; //atribui um numero aleatorio q representa o id da carta sorteada a posição do vetor 
        }
        while (contador[fila_cartas_p1[i]] >= limite[fila_cartas_p1[i]]); //verifica quantas vezes o ID foi gerado
        contador[fila_cartas_p1[i]]++; //conta quantas vezes o ID apareceu
    }

    srand(time(NULL)); //define seed pro sorteador
    for(int i=0;i<10;i++){
        do{
    
            fila_cartas_p2[i] = rand () % 10+1; //atribui um numero aleatorio q representa o id da carta sorteada a posição do vetor 
        }
        while (contador[fila_cartas_p2[i]] >= limite[fila_cartas_p2[i]]);
        contador[fila_cartas_p1[i]]++; //conta quantas vezes o ID apareceu
    }
}