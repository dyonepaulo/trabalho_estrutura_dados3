#include "dados.h"

// DEFINICAO DAS CARTAS

// id, energy, dmg, heal, shield, DB_ally, HB_ally, DB_enemy, HB_enemy, name, stats, description
//  dano
carta machado_assis = {1, 1, 20, 0, 0, 0, 0, 0, 0, "machado de assis", "Da 20 de dano", "uma arma básica que causa uma quantia básica de dano"};

carta myke = {2, 2, 35, 0, 0, 0, 0, 0, 0, "mike tyson", "Causa 35 de dano", "\"evitherathe your enemith\""};
// cura
carta lágrimas = {3, 1, 0, 15, 0, 0, 0, 0, 0, "Lágrimas da santa", "cura 15 de pv", "Lágrimas de uma santa esquecida pelo tempo, possuem propriedades de cura."};

carta escudo = {4, 1, 0, 0, 10, 0, 0, 0, 0, "Placa de aço", "Da 10 de escudo", "Uma placa de aço de procedência desconhecida, encontrada jogada por aí. \"Do androids dream of eletrical sheep?\""};

carta aura = {5, 1, 0, 8, 5, 0, 0, 0, 0, "Escudo de aura", "cura 8 de vida e 5 de escudo", "Um escudo de aura com propriedades curativas"};
// buff
carta marca_besta = {6, 1, 0, 0, 0, 15, 0, 10, 0, "Marca da besta", "aumenta o dano causado em 15 e recebido em 10", "Maldição que aumenta o dano inflingido ao custo de fragilizar o portador"};

carta espinafre = {7, 1, 0, 0, 0, 10, 0, 0, 0, "leite de boi", "aumenta o dano em 10", "deixa o caba mais forte"};

carta benção = {8, 1, 0, 0, 0, 0, 3, 0, 0, "Benção da desgraça", "aumenta a eficiencia de cartas de cura em 3", "\"You feel blessed\""};
// debuff
carta beijo = {9, 1, 0, 0, 0, 0, 0, -10, 0, "Beijo de judas", "diminui o dano do seu inimigo em 10", "Um símbolo de traição e a venda de seus companheiros."};

carta marca_morte = {10, 1, 0, 0, 0, 0, 0, 0, -4, "marca da morte", "diminui a cura do inimigo em 4", "\"lets dance\""};

// VARIAVEIS

Vector2 posicao = {0, 0};

char texto_vida[3];

char texto_energia[3];

char texto_escudo[3];

int turno = 0;

player jogador1 = {1, 100, 20, 0, 0, 2};

player jogador2 = {1, 50, 20, 0, 0, 2};
