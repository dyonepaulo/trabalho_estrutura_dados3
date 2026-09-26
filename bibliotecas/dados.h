#ifndef VARIAVEIS_H
#define VARIAVEIS_H

// ESTRUTURAS DE DADOS

typedef struct nos nos; // compilador precisa saber que existira uma struct chamada fila, para que eu consiga inicializar uma variavel do tipo fila dentro da propria estrutura fila

typedef struct
{
    int ID, energia, dano;
    char nome[20], descricao[100];
} carta;

struct nos
{
    carta *fim;
};

struct fila
{
    carta carta;
    nos no;
};

typedef struct
{
    int id_player, vida;
    carta mao;
} player;

// DEFINICAO DAS CARTAS

// VARIAVEIS

Vector2 posicao = {0, 0};



#endif