#include <raylib.h>
#ifndef VARIAVEIS_H
#define VARIAVEIS_H

// ESTRUTURAS DE DADOS
typedef struct nos nos; // compilador precisa saber que existira uma struct chamada fila, para que eu consiga inicializar uma variavel do tipo fila dentro da propria estrutura fila

typedef struct carta carta;
typedef struct player player;
typedef struct mao mao;

struct carta
{
    int ID, energia, dano, cura, escudo, dmg_buff_ally, heal_buff_ally, dmg_buff_enemy, heal_buff_enemy, turns_cont;
    int (*card_operation)(carta carta, player *jogador1, player *jogador2); // ponteiro para uma função que retorna um int e utiliza ponteiros para struct carta e player como parâmetros;
    char nome[30], stats[50], descricao[150];
    Texture2D imagem_carta;
};

struct nos
{
    int id;
    carta carta;
    nos *proximo;
    int status;
};

typedef struct
{
    nos *primeiro;
    nos *ultimo;
} fila;

typedef struct
{
    nos *topo;
} lixeira;

struct mao
{
    nos *carta_selecionada;
};

struct player
{
    int id_player, vida_atual, escudo, dmg_buff, heal_buff, energia;
    fila fila_player;
};

// DEFINICAO DAS CARTAS

// id, energy, dmg, heal, shield, DB_ally, HB_ally, DB_enemy, HB_enemy, card_operation, turns_count, name, stats, description

// dano
extern carta machado_assis;

extern carta mike;

// cura
extern carta lágrimas;

extern carta escudo;

extern carta aura;

// buff
extern carta marca_besta;

extern carta espinafre;

extern carta benção;

// debuff
extern carta beijo;

extern carta marca_morte;

// VARIAVEIS

extern Vector2 posicao;

extern char texto_vida[16];

extern char texto_energia[16];

extern char texto_escudo[16];

extern _Bool turno;

extern player jogador1;

extern player jogador2;

extern Font fonte;

extern Texture2D icon_mao;

extern Texture2D sprite_jogador1;

extern Texture2D sprite_jogador2;

extern Texture2D background;

extern Texture2D logo;

extern int efeito_ativo;

extern float tempo_efeito;



#endif