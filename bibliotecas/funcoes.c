#include <stdlib.h>
#include <time.h>
#include "funcoes.h"
#include "dados.h"
#include <raylib.h>
#include <stdio.h>

void barra_de_status(player *jogador)
{
    // barra de vida
    Rectangle retangulofundo = {20, 20, 300, 30};
    Rectangle retangulovisor = {20, 20, (jogador->vida_atual * 3), 30};
    sprintf(texto_vida, "%d/100", jogador->vida_atual);
    DrawRectangleRec(retangulofundo, GRAY);
    DrawRectangleRec(retangulovisor, GREEN);
    DrawText(texto_vida, 30, 25, 20, BLACK);

    // barra de escudo
    Rectangle retangulofundo_escudo = {20, 50, 100, 30};
    Rectangle retangulovisor_escudo = {20, 50, (jogador->escudo * 5), 30};
    sprintf(texto_escudo, "%d/20", jogador->escudo);
    DrawRectangleRec(retangulofundo_escudo, GRAY);
    DrawRectangleRec(retangulovisor_escudo, BLUE);
    DrawText(texto_escudo, 30, 55, 20, BLACK);

    // barra de energia
    Rectangle retangulofundo_energia = {20, 80, 60, 25};
    Rectangle retangulovisor_energia = {20, 80, (jogador->energia * 30), 25};
    sprintf(texto_energia, "%d/2", jogador->energia);
    DrawRectangleRec(retangulofundo_energia, GRAY);
    DrawRectangleRec(retangulovisor_energia, PURPLE);
    DrawText(texto_energia, 30, 85, 20, BLACK);
    return;
}

void inserirNode(fila *fila)
{
    nos *node = calloc(1, sizeof(nos));

    if (node == NULL)
    {
        printf("Falha na alocação de memória. ");
        exit(1);
    }

    if (fila->primeiro == NULL)
    {
        fila->primeiro = node;
        fila->ultimo = node;
    }
    else
    {
        fila->ultimo->proximo = node;
        fila->ultimo = node;
    }

    fila->ultimo->proximo = NULL;
}

void gerar_cartas(fila *fila)
{
    for (int i = 0; i < 5; i++)
        inserirNode(fila);

    nos *current = fila->primeiro;
    int limite[] = {3, 1, 2, 2, 2, 1, 1, 2, 1, 1}; // limite de quantas vezes cada carta pode aparecer, por ordem de ID
    int contador[10] = {0};                        // conta quantas vezes cada carta já apareceu

    while (current)
    { // condição de saída do loop: somente quando current == NULL
        do
        {
            current->id = rand() % 10 + 1; // atribui um numero aleatorio q representa o id da carta sorteada a posição do vetor
        } while (contador[current->id - 1] >= limite[current->id - 1]); // verifica quantas vezes o ID foi gerado
        contador[current->id - 1]++; // conta quantas vezes o ID apareceu
        fila->tamanho++;

        switch (current->id)
        {
        case 1:
            current->carta = machado_assis;
            break;

        case 2:
            current->carta = mike;
            break;

        case 3:
            current->carta = lágrimas;
            break;

        case 4:
            current->carta = escudo;
            break;

        case 5:
            current->carta = aura;
            break;

        case 6:
            current->carta = marca_besta;
            break;

        case 7:
            current->carta = espinafre;
            break;

        case 8:
            current->carta = benção;
            break;

        case 9:
            current->carta = beijo;
            break;

        case 10:
            current->carta = marca_morte;
            break;
        }
        current = current->proximo;
    }

    for (int i = 0; i < 9; i++)
    {
        contador[i] = 0;
    }
}

// OPERAÇÕES DAS CARTAS

int Fmachado_assis(carta card, player *jogador1, player *jogador2)
{
    player *jogador_afetado, *jogador_caster;

    if (turno == 0)
    { // levando em consideração que o turno = 0 pertence ao jogador 1
        jogador_afetado = jogador2;
        jogador_caster = jogador1;
    }
    else
    {
        jogador_afetado = jogador1;
        jogador_caster = jogador2;
    }

    if (jogador_afetado->escudo > 0)
        jogador_afetado->escudo -= card.dano + jogador_caster->dmg_buff;
    else
        jogador_afetado->vida_atual -= card.dano + jogador_caster->dmg_buff;

    return 0;
}

int Fmike(carta card, player *jogador1, player *jogador2)
{
    player *jogador_afetado, *jogador_caster;

    if (turno == 0)
    {
        jogador_afetado = jogador2;
        jogador_caster = jogador1;
    }
    else
    {
        jogador_afetado = jogador1;
        jogador_caster = jogador2;
    }

    if (jogador_afetado->escudo > 0)
        jogador_afetado->escudo -= card.dano + jogador_caster->dmg_buff;
    else
        jogador_afetado->vida_atual -= card.dano + jogador_caster->dmg_buff;

    return 0;
}

int Flágrimas(carta card, player *jogador1, player *jogador2)
{
    player *jogador_afetado;

    if (turno == 0)
        jogador_afetado = jogador1;
    else
        jogador_afetado = jogador2;

    jogador_afetado->vida_atual += card.cura + jogador_afetado->heal_buff;

    return 0;
}

int Fescudo(carta card, player *jogador1, player *jogador2)
{
    player *jogador_afetado;

    if (turno == 0)
        jogador_afetado = jogador1;
    else
        jogador_afetado = jogador2;

    jogador_afetado->escudo += card.escudo;

    return 0;
}

int Faura(carta card, player *jogador1, player *jogador2)
{
    player *jogador_afetado;

    if (turno == 0)
    {
        jogador_afetado = jogador1;
    }
    else
    {
        jogador_afetado = jogador2;
    }

    jogador_afetado->vida_atual += card.cura + jogador_afetado->heal_buff;
    jogador_afetado->escudo += card.escudo;

    return 0;
}

int Fmarca_besta(carta card, player *jogador1, player *jogador2)
{
    player *jogador_afetado;

    if (turno == 0)
    {
        jogador_afetado = jogador1;
        jogador_afetado->dmg_buff += card.dmg_buff_ally;

        jogador_afetado = jogador2;
        jogador_afetado->dmg_buff += card.dmg_buff_enemy;
    }
    else
    {
        jogador_afetado = jogador2;
        jogador_afetado->dmg_buff += card.dmg_buff_ally;

        jogador_afetado = jogador1;
        jogador_afetado->dmg_buff += card.dmg_buff_enemy;
    }

    return 0;
}

int Fespinafre(carta card, player *jogador1, player *jogador2)
{
    player *jogador_afetado;

    if (turno == 0)
        jogador_afetado = jogador1;
    else
        jogador_afetado = jogador2;

    jogador_afetado->dmg_buff += card.dmg_buff_ally;

    return 0;
}

int Fbenção(carta card, player *jogador1, player *jogador2)
{
    player *jogador_afetado;

    if (turno == 0)
    {
        jogador_afetado = jogador1;
    }
    else
    {
        jogador_afetado = jogador2;
    }

    jogador_afetado->heal_buff += card.heal_buff_ally;

    return 0;
}

int Fbeijo(carta card, player *jogador1, player *jogador2)
{
    player *jogador_afetado;

    if (turno == 0)
        jogador_afetado = jogador2;
    else
        jogador_afetado = jogador1;

    jogador_afetado->dmg_buff -= card.dmg_buff_enemy;

    return 0;
}

int Fmarca_morte(carta card, player *jogador1, player *jogador2)
{
    player *jogador_afetado;

    if (turno == 0)
        jogador_afetado = jogador2;
    else
        jogador_afetado = jogador1;

    jogador_afetado->heal_buff -= card.heal_buff_enemy;

    return 0;
}

// OPERAÇÕES DO JOGADOR

int jogar_carta(fila *fila, mao *hand, player *jogador)
{
    if (hand->carta_selecionada == NULL)
        return 1;

    if (jogador->energia - 1 < 0)
        return 2;

    jogador->energia--;

    int retorno_função = hand->carta_selecionada->carta.card_operation((hand->carta_selecionada->carta), &jogador1, &jogador2);
    free(hand->carta_selecionada);
    hand->carta_selecionada = NULL;

    if (fila->primeiro == NULL)
        return 3;

    if (fila->ultimo == fila->primeiro)
        fila->ultimo = NULL;

    hand->carta_selecionada = fila->primeiro;
    fila->primeiro = fila->primeiro->proximo;
    hand->carta_selecionada->proximo = NULL;

    fila->tamanho--;
    return 0;
}

int descartar_carta(fila *fila, pilha *lixeira, mao *hand, player *jogador)
{
    if (hand->carta_selecionada == NULL)
    {
        return 1;
    }

    if (lixeira->topo == NULL)
    {
        lixeira->topo = hand->carta_selecionada;
        lixeira->topo->proximo = NULL;
    }
    else
    {
        hand->carta_selecionada->proximo = lixeira->topo;
        lixeira->topo = hand->carta_selecionada;
    }

    // avançando a fila...
    if (fila->primeiro == NULL)
    {
        hand->carta_selecionada = NULL;
        return 2;
    }

    if (fila->ultimo == fila->primeiro)
        fila->ultimo = NULL;

    hand->carta_selecionada = fila->primeiro;
    fila->primeiro = fila->primeiro->proximo;
    hand->carta_selecionada->proximo = NULL;

    fila->tamanho--;
    return 0;
}

int colher_carta(fila *fila, pilha *lixeira, player *jogador)
{
    if (jogador->energia - 1 < 0)
        return 1;

    if (lixeira->topo == NULL)
        return 2;

    nos *temp = lixeira->topo;
    lixeira->topo = lixeira->topo->proximo;
    temp->proximo = NULL;

    if (fila->primeiro == NULL)
    {
        fila->primeiro = temp;
        fila->ultimo = temp;
        fila->ultimo->proximo = NULL;
    }
    else
    {
        fila->ultimo->proximo = temp;
        fila->ultimo = temp;
        fila->ultimo->proximo;
    }

    jogador->energia--;
    fila->tamanho++;
    return 0;
}

int guardar_carta(fila *fila, mao *hand, player *jogador)
{
    if (jogador->energia - 1 < 0)
        return 1;

    if (hand->carta_selecionada == NULL)
        return 2;

    if (fila->primeiro == NULL)
        return 3;
    
    fila->ultimo->proximo = hand->carta_selecionada;
    fila->ultimo = hand->carta_selecionada;
    fila->ultimo->proximo = NULL;

    hand->carta_selecionada = fila->primeiro;
    fila->primeiro = fila->primeiro->proximo;
    hand->carta_selecionada->proximo = NULL;

    jogador->energia--;
    return 0;
}

void carregar_assets(void)
{
    // carrega todas as imagens do jogo e atribui a imagem a sua respectiva carta
    machado_assis.imagem_carta = LoadTexture("assets/machadoDeAssis.png");
    aura.imagem_carta = LoadTexture("assets/aura.png");
    mike.imagem_carta = LoadTexture("assets/MikeTyson.png");
    lágrimas.imagem_carta = LoadTexture("assets/lagrimaDaSanta.png");
    escudo.imagem_carta = LoadTexture("assets/escudo.png");
    marca_besta.imagem_carta = LoadTexture("assets/marcaDaBesta.png");
    marca_morte.imagem_carta = LoadTexture("assets/marcaDaMorte.png");
    espinafre.imagem_carta = LoadTexture("assets/espinafre.png");
    beijo.imagem_carta = LoadTexture("assets/beijo-removebg-preview.png");
    benção.imagem_carta = LoadTexture("assets/bencao.png");
    icon_mao = LoadTexture("assets/mao.png");
    fonte = LoadFont("assets/fonte/PressStart2P-Regular.ttf");
    sprite_jogador1 = LoadTexture("assets/TungTungSahurCeslestialProMax.png");
    sprite_jogador2 = LoadTexture("assets/ZePilintra.png");
    background = LoadTexture("assets/retro-pixel-art-background-with-sun-arcade_1303033-5146.png");
    logo = LoadTexture("assets/exugames.png");
    jogador1WIN = LoadTexture("assets/tungWIN.png");
    jogador2WIN = LoadTexture("assets/zeWIN.png");
    return;
}

void visor_lixeiera(pilha *lixeira) // ta imcompleto
{
    if (lixeira->topo == NULL)
    {
        DrawRectangle(10, 400, 220, 310, GRAY);
        DrawTextEx(fonte, "LIXEIRA\nVAZIA", (Vector2){40, 550}, 20, 1, BLACK);
        return;
    }
    else
    {
        DrawRectangle(10, 370, 200, 300, GRAY);

        DrawTextureEx(
            lixeira->topo->carta.imagem_carta,
            (Vector2){-35, 378},
            0,
            0.6f,
            RAYWHITE);

        DrawTextEx(fonte,
                   "ULTIMA CARTA\n DA LIXEIRA",
                   (Vector2){25, 374},
                   13,
                   1,
                   BLACK);
    }
    return;
}

void visor_mao(mao *mao, player *jogador, pilha *lixeira, fila *fila)
{
    // mostra as opcaos que o jogador pode escolher fazer com a carta
    opcoes_menu(mao, NULL, lixeira, jogador);
    if (mao->carta_selecionada != NULL)
    {
        // desenha a carta selecionada na mão do jogador
        DrawTextureEx(icon_mao, (Vector2){900, 240}, 0, 1, RAYWHITE);
        DrawTextureEx(mao->carta_selecionada->carta.imagem_carta, (Vector2){950, 345}, 5, .6, RAYWHITE);

        // descreve os stats da carta selecionadvisor_maoa na mão do jogador
        DrawRectangle(300, 650, 710, 48, Fade(BLACK, 0.6f));
        DrawTextEx(fonte, mao->carta_selecionada->carta.stats, (Vector2){310, 678}, 15, 0.5, (Color){255, 255, 255, 200});
        DrawTextEx(fonte, "Efeito da carta Atual:", (Vector2){310, 655}, 15, 0.5, RED);
    }
    else
    {
        DrawTextureEx(icon_mao, (Vector2){900, 240}, 0, 1, RAYWHITE);
    }

    DrawRectangle(15, 185, 430, 135, Fade(BLACK, 0.6f));
    DrawTextEx(fonte, "1. Usar carta\n"
                      "2. Colocar na lixeira\n"
                      "3. Guardar no final da fila\n"
                      "4. Colher carta da lixeira\n"
                      "5. Aceitar a derrota\n"
                      "6. Passar a vez",
               (Vector2){30, 200}, 15, 0, (Color){255, 255, 255, 200});
    return;
}

void sprite_inimigo(int id_jogador)
{
    if (id_jogador == jogador2.id_player)
    {
        DrawTextureEx(sprite_jogador1, (Vector2){500, 220}, 0, .3, RAYWHITE);
        Rectangle retangulofundo_inimigo = {515, 180, 200, 20};
        Rectangle retangulovisor_inimigo = {515, 180, jogador1.vida_atual * 2, 20};
        Rectangle retangulofundo_inimigo_escudo = {515, 205, 200, 20};
        Rectangle retangulovisor_inimigo_escudo = {515, 205, jogador1.escudo * 10, 20};
        DrawRectangleRec(retangulofundo_inimigo, BLACK);
        DrawRectangleRec(retangulovisor_inimigo, RED);
        DrawRectangleRec(retangulofundo_inimigo_escudo, BLACK);
        DrawRectangleRec(retangulovisor_inimigo_escudo, SKYBLUE);
        return;
    }
    else
    {
        DrawTextureEx(sprite_jogador2, (Vector2){500, 220}, 0, .25, RAYWHITE);
        Rectangle retangulofundo_inimigo = {515, 180, 200, 20};
        Rectangle retangulovisor_inimigo = {515, 180, jogador2.vida_atual * 2, 20};
        Rectangle retangulofundo_inimigo_escudo = {515, 205, 200, 20};
        Rectangle retangulovisor_inimigo_escudo = {515, 205, jogador2.escudo * 10, 20};
        DrawRectangleRec(retangulofundo_inimigo, BLACK);
        DrawRectangleRec(retangulovisor_inimigo, RED);
        DrawRectangleRec(retangulofundo_inimigo_escudo, BLACK);
        DrawRectangleRec(retangulovisor_inimigo_escudo, SKYBLUE);
        return;
    }
}

void proxima_carta(mao *mao, fila *fila)
{ // imcompletro
    int fix_index = 20;

    if (fila->primeiro == NULL)
    {
        Rectangle fundo_fila_vazia = {1140, 60, 150, 190};
        DrawRectangleRounded(fundo_fila_vazia, 0.2f, 10, ColorAlpha(DARKGRAY, 0.7f));
        DrawTextEx(fonte, "Nenhuma \ncarta \nrestante!", (Vector2){1148, 130}, 15, 0, MAROON);
    }
    else
    {
        DrawRectangle(1140, 40, 150, 45, ColorAlpha(DARKGRAY, 0.7f));
        DrawTextEx(fonte, "Proxima\n carta", (Vector2){1150, 48}, 15, 0, MAROON);

        for (int i = 0; i < fila->tamanho; i++, fix_index += 10)
            DrawTextureEx(fila->primeiro->carta.imagem_carta, (Vector2){1100 - fix_index, 70}, 0, .5, RAYWHITE);
    }
}

void carta_fila_pra_mão(mao *mao, pilha *lixeira, fila *fila)
{
    if (mao->carta_selecionada == NULL)
    {
        if (fila->primeiro != NULL)
        {
            if (fila->ultimo == fila->primeiro)
                fila->ultimo = NULL;

            mao->carta_selecionada = fila->primeiro;
            fila->primeiro = fila->primeiro->proximo;
            mao->carta_selecionada->proximo = NULL;
            fila->tamanho--;
        }
        else
        {
            if (lixeira->topo == NULL)
            {
                gerar_cartas(fila);
            }
        }
    }
}

void teste(void)
{

    DrawRectangle(0, 0, 1280, 720, Fade(RED, 0.2f));
}

void opcoes_menu(mao *mao_jogador, fila *fila, pilha *lixeira, player *jogador)
{
    int error_type;

    if (IsKeyPressed(KEY_ONE))
    {
        // efeito_ativo = 1;
        error_type = jogar_carta(jogador->fila_player, mao_jogador, jogador);
    }
    else if (IsKeyPressed(KEY_TWO))
    {
        descartar_carta(jogador->fila_player, lixeira, mao_jogador, jogador);
    }
    else if (IsKeyPressed(KEY_THREE))
    {
        error_type = guardar_carta(jogador->fila_player, mao_jogador, jogador);
        if(error_type == 3)
        {
            efeito_ativo = 1;
            return;
        }
    }
    else if (IsKeyPressed(KEY_FOUR))
    {
        colher_carta(jogador->fila_player, lixeira, jogador);
        if (lixeira->topo == NULL)
        {
            efeito_ativo = 1;
            return;
        }
    }
    else if (IsKeyPressed(KEY_FIVE))
    {
        gameover_ativo = 1;
        tela_menu = 3;
        id_loser_player = jogador->id_player;
    }
    else if (IsKeyPressed(KEY_SIX))
    {
        if (jogador->id_player == 1)
        {
            turno = 1;
            jogador->energia = 2;
        }
        else
        {
            turno = 0;
            jogador->energia = 2;
        }
    }
}

void mensagem_erro_lixeira(void)
{
    if (efeito_ativo)
    {
        tempo_efeito += GetFrameTime();
        teste();

        if (tempo_efeito >= .5f)
        {
            efeito_ativo = 0;
            tempo_efeito = 0;
        }
    }
}

void esvaziar_filas(fila *fila)
{
    if (fila->primeiro == NULL)
        return;

    nos *atual = fila->primeiro;
    nos *prox = atual;

    while (atual != NULL)
    {
        prox = atual->proximo;
        free(atual);
        atual = prox;
    }

    fila->primeiro = NULL;
    fila->ultimo = NULL;

    return;
}

void esvaziar_pilha(pilha *lixeira)
{
    if (lixeira->topo == NULL)
        return;

    nos *atual = lixeira->topo;
    nos *prox = atual;

    while (atual != NULL)
    {
        prox = atual->proximo;
        free(atual);
        atual = prox;
    }

    lixeira->topo = NULL;
    return;
}
void game_over(void)
{
    if (gameover_ativo)
    {
        tempo_gameover += GetFrameTime();
        transparencia -= GetFrameTime();

        if (id_loser_player == jogador2.id_player)
        {
            DrawTextureEx(jogador1WIN, (Vector2){0, 0}, 0, 0.7656, RAYWHITE);
            DrawText("Obrigado por jogar <3", 40, 40, 30, WHITE);
        }
        else
        {
            DrawTextureEx(jogador2WIN, (Vector2){0, 0}, 0, 0.7656, RAYWHITE);
            DrawText("Obrigado por jogar <3", 40, 40, 30, WHITE);
        }
        DrawRectangle(0, 0, 1280, 718, Fade(BLACK, transparencia));
        if (tempo_gameover >= 3.0f)
        {
            tempo_gameover = 0;

            gameover_ativo = 0;
        }
    }
}

void erro_alocacao(pilha *lixeira, mao *mao_jogador1, mao *mao_jogador2, fila *fila_jogador1, fila *fila_jogador2)
{
    if (lixeira == NULL || mao_jogador1 == NULL || mao_jogador2 == NULL || fila_jogador1 == NULL || fila_jogador2 == NULL)
    {
        printf("Falha na alocação de memória. ");
        exit(1);
    }
}

void fix_player_stats(player *jogador)
{
    if (jogador->escudo > ESCUDO_MAX)
        jogador->escudo = ESCUDO_MAX;

    if (jogador->vida_atual > VIDA_MAX)
        jogador->vida_atual = VIDA_MAX;

    if (jogador->escudo < 0)
        jogador->escudo = 0;

    if (jogador->heal_buff < 0)
        jogador->heal_buff = 0;

    if (jogador->dmg_buff < 0)
        jogador->dmg_buff = 0;
}

void esvaziar_mao(mao *hand1, mao *hand2){
    if (hand1->carta_selecionada != NULL) {
        free(hand1->carta_selecionada);
    }
    if (hand2->carta_selecionada != NULL) {
        free(hand2->carta_selecionada);
    }
}
