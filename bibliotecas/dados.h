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

//id, energy, dmg, heal, shield, DB_ally, HB_ally, DB_enemy, HB_enemy, name, stats, description, 
carta machado_de_assis = {1, 1, 20, 0, 0, 0, 0, 0, 0, "machado de assis", "Da 20 de dano", "uma arma básica que causa uma quantia básica de dano"};

carta lágrimas = {2, 1, 0, 15, 0, 0, 0, 0, 0, "Lágrimas da santa", "cura 15 de pv", "Lágrimas de uma santa esquecida pelo tempo, possuem propriedades de cura."};

carta escudo = {3, 1, 0, 0, 10, 0, 0, 0, 0, "Placa de aço", "Da 10 de escudo", "Uma placa de aço de procedência desconhecida, encontrada jogada por aí. \"Do androids dream of eletrical sheep?\""};

carta marca_besta = {4, 1, 0, 0, 0, 15, 0, 10, 0, "Marca da besta", "aumenta o dano causado em 15 e recebido em 10", "Maldição que aumenta o dano inflingido ao custo de fragilizar o portador"};

carta espinafre = {5, 1, 0, 0, 0, 10, 0, 0, 0, "leite de boi", "aumenta o dano em 10", "deixa o caba mais forte"};

carta myke = {6, 2, 35, 0, 0, 0, 0, 0, 0, "mike tyson", "Causa 35 de dano", "evitherathe your enemith"};

carta beijo = {7, 1, 0, 0, 0, 0, 0, -10, 0, "Beijo de judas", "diminui o dano do seu inimigo em 10", "No future for betrayers."};

carta marca = {8, 1, 0, 0, 0, 0, 0, 0, -4, "marca da morte", "diminui a cura do inimigo em 4", "lets dance"};

// VARIAVEIS

Vector2 posicao = {0, 0};

vida_atual;

#endif