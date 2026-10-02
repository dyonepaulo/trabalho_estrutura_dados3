#include "dados.h"
#include "funcoes.h"
// DEFINICAO DAS CARTAS

// id, energy, dmg, heal, shield, DB_ally, HB_ally, DB_enemy, HB_enemy, turns_count, card_operation, name, stats, description

carta machado_assis = {1, 1, 20, 0, 0, 0, 0, 0, 0, 1, .card_operation = Fmachado_assis, "machado de assis", "Da 20 de dano", "uma arma básica que causa uma quantia básica de dano"};

carta mike = {2, 2, 35, 0, 0, 0, 0, 0, 0, 1, .card_operation = Fmike, "mike tyson", "Causa 35 de dano", "\"evitherathe your enemith\""};
// cura
carta lágrimas = {3, 1, 0, 15, 0, 0, 0, 0, 0, 1, .card_operation = Flágrimas, "Lágrimas da santa", "cura 15 de pv", "Lágrimas de uma santa esquecida pelo tempo, possuem propriedades de cura."};

carta escudo = {4, 1, 0, 0, 10, 0, 0, 0, 0, 1, .card_operation = Fescudo, "Placa de aço", "Da 10 de escudo", "Uma placa de aço de procedência desconhecida, encontrada jogada por aí. \"Do androids dream of eletrical sheep?\""};

carta aura = {5, 1, 0, 8, 5, 0, 0, 0, 0, 1, .card_operation = Faura, "Escudo de aura", "cura 8 de vida e 5 de escudo", "Um escudo de aura com propriedades curativas"};
// buff
carta marca_besta = {6, 1, 0, 0, 0, 15, 0, 10, 0, 1, .card_operation = Fmarca_besta, "Marca da besta", "aumenta o dano causado em 15 e recebido em 10", "Maldição que aumenta o dano inflingido ao custo de fragilizar o portador"};

carta espinafre = {7, 1, 0, 0, 0, 10, 0, 0, 0, 1, .card_operation = Fespinafre, "leite de boi", "aumenta o dano em 10", "deixa o caba mais forte"};

carta benção = {8, 1, 0, 0, 0, 0, 3, 0, 0, 1, .card_operation = Fbenção, "Benção", "aumenta a eficiencia de cartas de cura em 3", "\"You feel blessed\""};
// debuff
carta beijo = {9, 1, 0, 0, 0, 0, 0, 10, 0, 1, .card_operation = Fbeijo, "Beijo de judas", "diminui o dano do seu inimigo em 10", "Um símbolo de traição e a venda de seus companheiros."};

carta marca_morte = {10, 1, 0, 0, 0, 0, 0, 0, 4, 1, .card_operation = Fmarca_morte, "marca da morte", "diminui a cura do inimigo em 4", "\"lets dance\""};

// VARIAVEIS

Vector2 posicao = {0, 0};

char texto_vida[16];

char texto_energia[16];

char texto_escudo[16];

_Bool turno = 0;

player jogador1 = {1, 67, 13, 0, 0, 2};

player jogador2 = {2, 14, 13, 0, 0, 2};

Texture2D icon_mao;

Font fonte;

Texture2D sprite_jogador1;

Texture2D sprite_jogador2;

Texture2D background;

Texture2D logo;


