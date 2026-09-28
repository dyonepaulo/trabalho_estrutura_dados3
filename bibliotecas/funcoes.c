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
    sprintf(texto_vida,"%d/100",jogador->vida_atual);
    DrawRectangleRec(retangulofundo, GRAY);
    DrawRectangleRec(retangulovisor, GREEN);
    DrawText(texto_vida,30,25,20,BLACK);
    
}

int gerar_cartas(carta carta, nos no, fila fila){
    
}