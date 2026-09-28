#ifndef VARIAVEIS_H
#define VARIAVEIS_H

// ESTRUTURAS DE DADOS

typedef struct nos nos; // compilador precisa saber que existira uma struct chamada fila, para que eu consiga inicializar uma variavel do tipo fila dentro da propria estrutura fila

typedef struct
{
    int ID, energia, dano, cura, escudo, dmg_buff_ally, heal_buff_ally, dmg_buff_enemy, heal_buff_enemy;
    char nome[30], stats[50], descricao[150];
} carta;

struct nos
{
    carta carta;
    nos *proximo;
};

typedef struct
{
    nos *primerio;
    nos *ultimo;
} fila;

typedef struct {
    nos *topo;
} lixeira;

typedef struct
{
    int id_player, vida_atual, escudo, dmg_buff, heal_buff;
    carta mao;
} player;

// DEFINICAO DAS CARTAS

//id, energy, dmg, heal, shield, DB_ally, HB_ally, DB_enemy, HB_enemy, name, stats, description
// dano
extern carta machado_assis;

extern carta myke;
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

Vector2 posicao = {0, 0};

vida_atual;

#endif