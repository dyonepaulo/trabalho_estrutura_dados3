#ifndef VARIAVEIS_H
#define VARIAVEIS_H

// ESTRUTURAS DE DADOS

typedef struct fila fila; // compilador precisa saber que existira uma struct chamada fila, para que eu consiga inicializar uma variavel do tipo fila dentro da propria estrutura fila

typedef struct
{
    int ID, energia, dano;
    char nome[20];
} carta;

struct fila
{
    carta carta;
    fila *proximo;
};

typedef struct
{
    int id_player, vida;
    carta mao;
} player;

// DEFINICAO DAS CARTAS



//

#endif