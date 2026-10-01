#include "dados.h"
#ifndef FUNCOES_H
#define FUNCOES_H

void barra_de_status(player *jogador);

int Fmachado_assis(carta *ptr, player *jogador1, player *jogador2);

int Fmike(carta *ptr, player *jogador1, player *jogador2);

int Flágrimas(carta *ptr, player *jogador1, player *jogador2);

int Fescudo(carta *ptr, player *jogador1, player *jogador2);

int Faura(carta *ptr, player *jogador1, player *jogador2);

int Fmarca_besta(carta *ptr, player *jogador1, player *jogador2);

int Fespinafre(carta *ptr, player *jogador1, player *jogador2);

int Fbenção(carta *ptr, player *jogador1, player *jogador2);

int Fbeijo(carta *ptr, player *jogador1, player *jogador2);

int Fmarca_morte(carta *ptr, player *jogador1, player *jogador2);

void carregar_assets(void);

void visor_lixeiera(nos **lixeira);

int visor_mao(mao *mao_jogador);




#endif