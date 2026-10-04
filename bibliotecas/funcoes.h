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

void sprite_inimigo(int id_jogador);

void visor_lixeiera(pilha *lixeira);

void visor_mao(mao *mao_jogador, player *jogador, pilha *lixeira, fila *fila);

int guardar_carta(fila *fila, mao *hand, player *jogador);

void proxima_carta(mao *mao, fila *fila);

void opcoes_menu(mao *mao_jogador, fila *fila, pilha *lixeira, player *jogador);

void teste(void);

void mensagem_erro_lixeira(void);

void gerar_cartas(fila *fila);

void inserirNode(fila *fila);

int jogar_carta(fila *fila, mao *hand, player *jogador);

int descartar_carta(fila *fila, pilha *lixeira, mao *hand, player *jogador);

int colher_carta(fila *fila, pilha *lixeira, player *jogador);

void carta_fila_pra_mão(mao *mao, pilha *lixeira, fila *fila);

void game_over(void);

void recarregar_jogo(void);

void esvaziar_pilha(pilha *pilha);

void esvaziar_filas(fila *fila);

#endif