// constantes
const float FPS = 120;  
const int SCREEN_W = 960;
const int SCREEN_H = 540;
const int NAVE_W = 100;
const int NAVE_H = 100;

// fontes
const char fonte_local[] = "src/fonts/arial.TTF";
const int tamanho_fonte = 36;

// background
const char background_local[] = "src/images/background.jpg";

// sprites da nave
const char nave_local[] = "src/images/nave.png";

// variaveis globais allegro
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_FONT *fonte = NULL;
ALLEGRO_EVENT ev;
ALLEGRO_BITMAP* background;
ALLEGRO_BITMAP *nave;

// definição de jogo
int jogando = 1;

// coordenadas da nave
int nave_dx = -12;
int nave_dy = 0;
int movimentacaoNave = 4;

// movimentação por teclas
bool move_up = false;
bool move_down = false;
bool move_left = false;
bool move_right = false;

// limites da tela
int limite_x_esquerda = -12;
int limite_y_inferior = 456;
int limite_x_direita = 876;
int limite_y_superior = -12;

int iniciarAllegro();
int finalizaAllegro();
void iniciarBackground();

int iniciarAllegro()
{
	//inicializa o Allegro
	if(!al_init()) {
		fprintf(stderr, "falha ao inicializar o allegro!\n");
		return -1;
	}
	
    //inicializa o módulo de primitivas do Allegro
    if(!al_init_primitives_addon()){
		fprintf(stderr, "falha ao inicializar as primitivas do Allegro!\n");
        return -1;
    }	
	
	//inicializa o modulo que permite carregar imagens no jogo
	if(!al_init_image_addon()){
		fprintf(stderr, "falha ao inicializar o modulo de imagens!\n");
		return -1;
	}
   
	//cria um temporizador que incrementa uma unidade a cada 1.0/FPS segundos
    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
		fprintf(stderr, "falha ao criar o timer!\n");
		return -1;
	}
 
	//cria uma tela com dimensoes de SCREEN_W, SCREEN_H pixels
	display = al_create_display(SCREEN_W, SCREEN_H);
	if(!display) {
		fprintf(stderr, "falha ao criar a tela!\n");
		al_destroy_timer(timer);
		return -1;
	}

	//instala o teclado
	if(!al_install_keyboard()) {
		fprintf(stderr, "falha ao instalar o teclado!\n");
		return -1;
	}
	
	//instala o mouse
	if(!al_install_mouse()) {
		fprintf(stderr, "falha ao instalar o mouse!\n");
		return -1;
	}

	//inicializa o modulo allegro que carrega as fontes
	al_init_font_addon();

	//inicializa o modulo allegro que entende arquivos tff de fontes
	if(!al_init_ttf_addon()) {
		fprintf(stderr, "falha ao iniciarlizar o modulo de fontes!\n");
		return -1;
	}
	
	//carrega o arquivo de fonte e define o tamanho que sera usado
    fonte = al_load_font(fonte_local, tamanho_fonte, 0);   
	if(fonte == NULL) {
		fprintf(stderr, "arquivo de fonte nao pode ser encontrado!\n");
	}

 	//cria a fila de eventos
	event_queue = al_create_event_queue();
	if(!event_queue) {
		fprintf(stderr, "falha ao criar a fila de eventos!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

    //registra na fila os eventos de tela (ex: clicar no X na janela)
	al_register_event_source(event_queue, al_get_display_event_source(display));
	//registra na fila os eventos de tempo: quando o tempo altera de t para t+1
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	//registra na fila os eventos de teclado (ex: pressionar uma tecla)
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	//registra na fila os eventos de mouse (ex: clicar em um botao do mouse)
	al_register_event_source(event_queue, al_get_mouse_event_source());

    // Dá nome a janela
    al_set_window_title(display, "R-Type | Leonardo Oliveira");

    //carrega a imagem de fundo
    iniciarBackground();

    // incia a nave
    nave = al_load_bitmap(nave_local);

    // atualiza a tela
    al_flip_display();

    //inicia o temporizador
	al_start_timer(timer);
}

int finalizaAllegro()
{
    //procedimentos de fim de jogo (fecha a tela, limpa a memoria, etc)
    al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
}

void iniciarBackground()
{
    // define o background
    background = al_load_bitmap(background_local);
    al_draw_bitmap(background, 0, 0, 0);
}