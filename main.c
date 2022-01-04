// Arquivo separado com todos os includes necessários para a execução do programa
#include "includes.h"
const int largura_game = 800;
const int altura_game = 600;
const int sair_game = 1;
int velocidade_do_asteroide = 5;
bool menu = true;
ALLEGRO_MUTEX *mutex;
ALLEGRO_SAMPLE *som_de_explosao;

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

void inciarGame(struct Game *game){
    // iniciando funções básicas do Allegro
    al_init();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_keyboard();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(2);

    // iniciando timer
    game->timer = al_create_timer(1.0/60);
    // inciando janela do jogo com as dimensões informadas
    game->janela = al_create_display(game->largura, game->altura);
    // iniciando fila de eventos do Allegro
    game->filaEventos = al_create_event_queue();
    // inicializando fonte utilizada no jogo
    game->fonte = al_load_font("src/fonts/ARCADE_I.TTF", 20, 0);

    // declarando e registrando eventos
    // eventos de teclado
    al_register_event_source(game->filaEventos, al_get_keyboard_event_source());
    // eventos da janela
    al_register_event_source(game->filaEventos, al_get_display_event_source(game->janela));
    // eventos do timer
    al_register_event_source(game->filaEventos, al_get_timer_event_source(game->timer));

    // definindo titulo da janela do jogo
    al_set_window_title(game->janela, "R-Type | Leonardo Oliveira");

    // iniciando fundo do jogo
    game->fundo = al_load_bitmap("src/images/fundo.jpg");
    al_draw_bitmap(game->fundo, 0, 0, 0);
    al_flip_display();
    al_start_timer(game->timer);
}

int main()
{
    // iniciando váriavel do game
    struct Game game;
    
    // atribuindo valores aos atributos da struct game
    game.largura    = largura_game;
    game.altura     = altura_game;
    game.sair       = sair_game;

    // iniciando o jogo e suas respectivas váriavieis e rotinas
    inciarGame(&game);

    // inica o mutex do allegro
    mutex = al_create_mutex();

    // carrega o som de explosão
    som_de_explosao = al_load_sample("src/sounds/explosao.wav");

    // inicia um array com foto da nave parada e acelerando
    ALLEGRO_BITMAP *naves[2];
    // carrega as imagens da nave
    naves[0] = al_load_bitmap("src/images/nave.png");
    naves[1] = al_load_bitmap("src/images/nave2.png");
}