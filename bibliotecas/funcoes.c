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

void inserirNode(fila *fila){
    nos* node = calloc(1, sizeof(nos));

    if(node == NULL){
        printf("Falha na alocação de memória. ");
        exit(1);
    }

    if (fila->primeiro == NULL)
    {
        fila->primeiro = node;
        fila->ultimo = node;
    } else {
        fila->ultimo->proximo = node;
        fila->ultimo = node;
        node->proximo = NULL;
    }
}

void gerar_cartas_p1(fila *fila){
    for(int i = 0; i < 10; i++)
        inserirNode(fila); 

    nos *current = fila->primeiro;
    int limite[] = {2, 1, 2, 2, 2, 1, 1, 2, 1, 1}; // limite de quantas vezes cada carta pode aparecer, por ordem de ID
    int contador[10] = {0}; // conta quantas vezes cada carta já apareceu

    srand(time(NULL)); // define seed pro sorteador

    while(current){ // condição de saída do loop: somente quando current == NULL
        do
        {
            current->id = rand() % 10 + 1; // atribui um numero aleatorio q representa o id da carta sorteada a posição do vetor
        } while (contador[current->id - 1] >= limite[current->id - 1]); // verifica quantas vezes o ID foi gerado
        contador[current->id - 1]++; // conta quantas vezes o ID apareceu

        current = current->proximo;
    }
}

void gerar_cartas_p2(fila *fila){
    for(int i = 0; i < 10; i++)
        inserirNode(fila); 

    nos *current = fila->primeiro;
    int limite[] = {2, 1, 2, 2, 2, 1, 1, 2, 1, 1}; // limite de quantas vezes cada carta pode aparecer, por ordem de ID
    int contador[10] = {0}; // conta quantas vezes cada carta já apareceu

    srand(time(NULL)); // define seed pro sorteador

    while(current){ // condição de saída do loop: somente quando current == NULL
        do
        {
            current->id = rand() % 10 + 1; // atribui um numero aleatorio q representa o id da carta sorteada a posição do vetor
        } while (contador[current->id - 1] >= limite[current->id - 1]); // verifica quantas vezes o ID foi gerado
        contador[current->id - 1]++; // conta quantas vezes o ID apareceu

        current = current->proximo;
    }
}

// OPERAÇÕES DAS CARTAS

int Fmachado_assis(carta *ptr, player *jogador1, player *jogador2)
{   
    if (turno == 0) // levando em consideração que o turno = 0 pertence ao jogador 1
        jogador2->vida_atual -= ptr->dano + jogador1->dmg_buff;
    else
        jogador1->vida_atual -= ptr->dano + jogador2->dmg_buff;
     

    ptr->turns_cont--;
    return 0;
}

int Fmike(carta *ptr, player *jogador1, player *jogador2)
{
    if(turno == 0)
        jogador2->vida_atual -= ptr->dano + jogador1->dmg_buff;
    else
        jogador1->vida_atual -= ptr->dano + jogador2->dmg_buff;

    
    ptr->turns_cont--;

    return 0;
}

int Flágrimas(carta *ptr, player *jogador1, player *jogador2){
    player *jogador_afetado;

    if(turno == 0)
        jogador_afetado = jogador1;
    else
        jogador_afetado = jogador2;
    

    jogador_afetado->vida_atual += ptr->cura + jogador_afetado->heal_buff;
    ptr->turns_cont--;

    return 0;
}

int Fescudo(carta *ptr, player *jogador1, player *jogador2){
    player *jogador_afetado;

    if(turno == 0){
        jogador_afetado = jogador1;
    } else { 
        jogador_afetado = jogador2;
    }

    jogador_afetado->escudo += ptr->escudo;
    ptr->turns_cont--;

    return 0;
}

int Faura(carta *ptr, player *jogador1, player *jogador2){
    player *jogador_afetado;

    if(turno == 0){
        jogador_afetado = jogador1;
    } else { 
        jogador_afetado = jogador2;
    }

    jogador_afetado->vida_atual += ptr->cura + jogador_afetado->heal_buff;
    jogador_afetado->escudo += ptr->escudo;
    ptr->turns_cont--;

    return 0;
}

int Fmarca_besta(carta *ptr, player *jogador1, player *jogador2){
    player *jogador_afetado;

    if(turno == 0){
        jogador_afetado = jogador1;
        jogador_afetado->dmg_buff += ptr->dmg_buff_ally;

        jogador_afetado = jogador2;
        jogador_afetado->dmg_buff += ptr->dmg_buff_enemy;
    } else { 
        jogador_afetado = jogador2;
        jogador_afetado->dmg_buff += ptr->dmg_buff_ally;

        jogador_afetado = jogador1;
        jogador_afetado->dmg_buff += ptr->dmg_buff_enemy; 
    }

    ptr->turns_cont--;
    return 0;
}

int Fespinafre(carta *ptr, player *jogador1, player *jogador2){
    player *jogador_afetado;

    if(turno == 0)
        jogador_afetado = jogador1;
    else  
        jogador_afetado = jogador2;
    

    jogador_afetado->dmg_buff += ptr->dmg_buff_ally;
    ptr->turns_cont--;

    return 0;
}

int Fbenção(carta *ptr, player *jogador1, player *jogador2){
    player *jogador_afetado;

    if(turno == 0){
        jogador_afetado = jogador1;
    } else { 
        jogador_afetado = jogador2;
    }

    jogador_afetado->heal_buff += ptr->heal_buff_ally;
    ptr->turns_cont--;

    return 0;
}

int Fbeijo(carta *ptr, player *jogador1, player *jogador2){
    player *jogador_afetado;

    if(turno == 0){
        jogador_afetado = jogador2;
    } else { 
        jogador_afetado = jogador1;
    }

    jogador_afetado->dmg_buff -= ptr->dmg_buff_enemy;
    ptr->turns_cont--;

    return 0;
}


int Fmarca_morte(carta *ptr, player *jogador1, player *jogador2){
    player *jogador_afetado;

    if(turno == 0){
        jogador_afetado = jogador2;
    } else { 
        jogador_afetado = jogador1;
    }

    jogador_afetado->heal_buff -= ptr->heal_buff_enemy;
    ptr->turns_cont--;

    return 0;
}
