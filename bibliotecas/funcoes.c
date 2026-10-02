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
    DrawRectangleRec(retangulovisor_escudo, SKYBLUE);
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

void inserirNode(fila *fila){
    nos* node = calloc(1, sizeof(nos));

    if(node == NULL){
        printf("Falha na alocação de memória. ");
        exit(1);
    }

    if (fila->primeiro == NULL)
    {
        fila->primeiro = node;
        fila->ultimo = node;
    } else {
        fila->ultimo->proximo = node;
        fila->ultimo = node;
        node->proximo = NULL;
    }
}

void gerar_cartas(fila *fila)
{
    for (int i = 0; i < 10; i++)
        inserirNode(fila);

    nos *current = fila->primeiro;
    int limite[] = {2, 1, 2, 2, 2, 1, 1, 2, 1, 1}; // limite de quantas vezes cada carta pode aparecer, por ordem de ID
    int contador[10] = {0}; // conta quantas vezes cada carta já apareceu

    srand(time(NULL)); // define seed pro sorteador

    while(current){ // condição de saída do loop: somente quando current == NULL
        do
        {
            current->id = rand() % 10 + 1; // atribui um numero aleatorio q representa o id da carta sorteada a posição do vetor
        } while (contador[current->id - 1] >= limite[current->id - 1]); // verifica quantas vezes o ID foi gerado
        contador[current->id - 1]++; // conta quantas vezes o ID apareceu

        current = current->proximo;
    }
}

// OPERAÇÕES DAS CARTAS

int Fmachado_assis(carta card, player *jogador1, player *jogador2)
{   
    if (turno == 0) // levando em consideração que o turno = 0 pertence ao jogador 1
        jogador2->vida_atual -= card.dano + jogador1->dmg_buff;
    else
        jogador1->vida_atual -= card.dano + jogador2->dmg_buff;
     

    card.turns_cont--;
    return 0;
}

int Fmike(carta card, player *jogador1, player *jogador2)
{
    if(turno == 0)
        jogador2->vida_atual -= card.dano + jogador1->dmg_buff;
    else
        jogador1->vida_atual -= card.dano + jogador2->dmg_buff;

    
    card.turns_cont--;
    return 0;
}

int Flágrimas(carta card, player *jogador1, player *jogador2)
{
    player *jogador_afetado;

    if(turno == 0)
        jogador_afetado = jogador1;
    else
        jogador_afetado = jogador2;
    

    jogador_afetado->vida_atual += card.cura + jogador_afetado->heal_buff;

    card.turns_cont--;
    return 0;
}

int Fescudo(carta card, player *jogador1, player *jogador2)
{
    player *jogador_afetado;

    if(turno == 0)
        jogador_afetado = jogador1;
    else
        jogador_afetado = jogador2;
    

    jogador_afetado->escudo += card.escudo;
    card.turns_cont--;

    return 0;
}

int Faura(carta card, player *jogador1, player *jogador2)
{
    player *jogador_afetado;

    if(turno == 0){
        jogador_afetado = jogador1;
    } else { 
        jogador_afetado = jogador2;
    }

    jogador_afetado->vida_atual += card.cura + jogador_afetado->heal_buff;
    jogador_afetado->escudo += card.escudo;
    card.turns_cont--;

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

    card.turns_cont--;
    return 0;
}

int Fespinafre(carta card, player *jogador1, player *jogador2)
{
    player *jogador_afetado;

    if(turno == 0)
        jogador_afetado = jogador1;
    else  
        jogador_afetado = jogador2;
    

    jogador_afetado->dmg_buff += card.dmg_buff_ally;
    card.turns_cont--;

    return 0;
}

int Fbenção(carta card, player *jogador1, player *jogador2)
{
    player *jogador_afetado;

    if(turno == 0){
        jogador_afetado = jogador1;
    } else { 
        jogador_afetado = jogador2;
    }

    jogador_afetado->heal_buff += card.heal_buff_ally;
    card.turns_cont--;

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
    card.turns_cont--;

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
    card.turns_cont--;

    return 0;
}

// OPERAÇÕES DO JOGADOR

int jogar_carta(fila *fila, mao *hand, player *jogador){
    if (hand == NULL)
    {
        // aviso centralizado dizendo que a hand não tem cartas
        return 1;
    }

    int retorno_função = hand->carta_selecionada->carta.card_operation((hand->carta_selecionada->carta), &jogador1, &jogador2);
    free(hand->carta_selecionada);

    if (fila->primeiro == NULL)
    {
        /*pequeno aviso de que a fila foi esvaziada*/
    } 
    return 0; 
    
    // avançando a fila...
    nos *temp = fila->primeiro;
    fila->primeiro = fila->primeiro->proximo;
    hand->carta_selecionada = temp;

    jogador->energia--;
    return 0;
}

int descartar_carta(fila *fila, lixeira *pilha, mao *hand, player *jogador){
    if (pilha->topo == NULL) {                                            // checa se a pilha é pilha vazia
        pilha->topo = hand->carta_selecionada;
        pilha->topo->proximo = NULL; 
    } else {
        hand->carta_selecionada->proximo = pilha->topo; // o novo node vindo da mão aponta para o topo da pilha
        pilha->topo = hand->carta_selecionada; // o novo node se torna o topo da pilha
    }
    
    // avançando a fila...
    nos *temp = fila->primeiro;
    fila->primeiro = fila->primeiro->proximo;
    hand->carta_selecionada = temp;

    jogador->energia--;
    return 0;
}

int colher_carta(fila *fila, lixeira *pilha, mao *hand, player *jogador){
    if (pilha->topo == NULL)
    {
        /* aviso dizendo que não tem pilha disponível */
        return 0;
    }

    fila->ultimo->proximo = pilha->topo; // o último node da fila aponta para o topo da pilha
    fila->ultimo = fila->ultimo->proximo; // o final da fila é atualizado
    pilha->topo = pilha->topo->proximo; // topo da pilha é atualizado

    jogador->energia--;
    return 0;
}

int guardar_carta(fila *fila, mao *hand, player *jogador){
    fila->ultimo->proximo = hand->carta_selecionada; // a carta é passada da mão para o final da fila
    fila->ultimo = hand->carta_selecionada;

    jogador->energia -= 2;
    return 0;
}


void carregar_assets(void)
{
    // coloca todos os sprites das cartas na struct de cada uma
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
    return;
}
void visor_lixeiera(nos **lixeira) // ta imcompleto
{
    char texto[20];
    if ((*lixeira)->status == 0)
    {
        DrawRectangle(10, 400, 220, 310, GRAY);
        DrawTextEx(fonte, "LIXEIRA VAZIA", (Vector2){40, 550}, 20, 1, BLACK);
        return;
    }
    else
    {
        DrawRectangle(10, 370, 200, 300, GRAY);

        DrawTextureEx(
            (*lixeira)->carta.imagem_carta,
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
void visor_mao(mao *mao)
{
    if (mao->carta_selecionada->status == 0)
    {
        DrawTextureEx(icon_mao, (Vector2){900, 240}, 0, 1, RAYWHITE);
        return;
    }
    else
    {
        DrawTextureEx(icon_mao, (Vector2){900, 240}, 0, 1, RAYWHITE);
        DrawTextureEx(mao->carta_selecionada->carta.imagem_carta, (Vector2){950, 345}, 5, .6, RAYWHITE);
        DrawRectangle(300, 650, 710, 48, Fade(BLACK, 0.6f));
        DrawTextEx(fonte, mao->carta_selecionada->carta.stats, (Vector2){310, 678}, 15, 0.5, WHITE);
        DrawTextEx(fonte, "Efeito da carta Atual:", (Vector2){310, 655}, 15, 0.5, RED);
        return;
    }
}
void sprite_inimigo(int id_jogador)
{
    if (id_jogador == 0)
    {
        DrawTextureEx(sprite_jogador1, (Vector2){500, 220}, 0, .3, RAYWHITE);
        Rectangle retangulofundo_inimigo = {515, 200, 200, 20};
        Rectangle retangulovisor_inimigo = {515, 200, jogador1.vida_atual*2, 20};
        DrawRectangleRec(retangulofundo_inimigo, BLACK);
        DrawRectangleRec(retangulovisor_inimigo, RED);
        return;
    }
    else
    {
        DrawTextureEx(sprite_jogador2, (Vector2){500, 220}, 0, .25, RAYWHITE);
        Rectangle retangulofundo_inimigo = {515, 200, 200, 20};
        Rectangle retangulovisor_inimigo = {515, 200, jogador2.vida_atual*2, 20};
        DrawRectangleRec(retangulofundo_inimigo, BLACK);
        DrawRectangleRec(retangulovisor_inimigo, RED);
        return;
    }
}
