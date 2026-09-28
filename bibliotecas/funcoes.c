#include <stdlib.h>
#include <time.h>
#include "funcoes.h"
#include "dados.h"
#include <raylib.h>

void barra_vida(player *jogador)
{
    Rectangle retangulofundo = {20, 20, 100, 30};
    Rectangle retangulovisor = {20, 20, jogador->vida_atual, 30};

    DrawRectangleRec(retangulofundo, GRAY);
    DrawRectangleRec(retangulovisor, GREEN);
    
}

int gerar_cartas(carta carta, nos no, fila fila){
    
}