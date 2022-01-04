// Arquivo separado com todos os includes necessários para a execução do programa
#include "includes.h"
const int largura_game = 800;
const int altura_game = 600;
const int sair_game = 1;

struct Game
{
    ALLEGRO_BITMAP* fundo;
    ALLEGRO_DISPLAY *janela;
    ALLEGRO_FONT *fonte;
    ALLEGRO_EVENT_QUEUE *filaEventos;
    ALLEGRO_TIMER *timer;
    int largura;
    int altura;
    int sair;
};

int main()
{
    // iniciando váriavel do game
    struct Game game;
    
    // atribuindo valores aos atributos da struct game
    game.largura    = largura_game;
    game.altura     = altura_game;
    game.sair       = sair_game;

    printf("%d\n", game.largura);
    printf("%d\n", game.altura);
    printf("%d\n", game.sair);

}