#include "dados.h"
#ifndef FUNCOES_H
#define FUNCOES_H

void barra_de_status(player *jogador);

int Fmachado_assis(carta card, player *jogador1, player *jogador2);

int Fmike(carta card, player *jogador1, player *jogador2);

int Flágrimas(carta card, player *jogador1, player *jogador2);

int Fescudo(carta card, player *jogador1, player *jogador2);

int Faura(carta card, player *jogador1, player *jogador2);

int Fmarca_besta(carta card, player *jogador1, player *jogador2);

int Fespinafre(carta card, player *jogador1, player *jogador2);

int Fbenção(carta card, player *jogador1, player *jogador2);

int Fbeijo(carta card, player *jogador1, player *jogador2);

int Fmarca_morte(carta card, player *jogador1, player *jogador2);

void carregar_assets(void);

void visor_lixeiera(nos **lixeira);

void visor_mao(mao *mao_jogador);

void sprite_inimigo(int id_jogador);



void carregar_assets(void);

void visor_lixeiera(nos **lixeira);

void visor_mao(mao *mao_jogador);

void sprite_inimigo(int id_jogador);




#endif