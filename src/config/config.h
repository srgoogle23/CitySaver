// constantes
const float FPS = 120;  
const int SCREEN_W = 960;
const int SCREEN_H = 540;
const int NAVE_W = 100;
const int NAVE_H = 100;
const bool DEBUG = false;

// imagens
const char *background_local[7] = {
	"src/images/bg/01/sky.png",
	"src/images/bg/01/cloud_lonely.png",
	"src/images/bg/01/clouds_bg.png",
	"src/images/bg/01/glacial_mountains.png",
	"src/images/bg/01/clouds_mg_3.png",
	"src/images/bg/01/clouds_mg_2.png",
	"src/images/bg/01/clouds_mg_1.png"
};

const char nave_local[] = "src/images/nave.png";
const char asteroids_local[] = "src/images/asteroids.png";
const char tiros_local[] = "src/images/shoots.png";
const char animacao_tiro_avancado_local[] = "src/images/animacaoTiroAvancado.png";
const char tiro_avancado_local[] = "src/images/shoots_big.png";
const char explosao_local[] = "src/images/explosao.png";

// fontes
const char fonte_local[] = "src/fonts/arial.TTF";
const int tamanho_fonte = 36;

// variaveis globais allegro
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_FONT *fonte = NULL;
ALLEGRO_EVENT ev;
ALLEGRO_BITMAP *nave;
ALLEGRO_BITMAP *arteroids;
ALLEGRO_BITMAP *tiros;
ALLEGRO_BITMAP *animacaoTiroAvancado;
ALLEGRO_BITMAP *tiro_avancado;
ALLEGRO_BITMAP *explosao;

// definição de jogo
int jogando = 1;

// definição de colisão
bool colisao = false;
int animacaoColisao = 1;

// coordenadas da nave
int nave_dx = -12;
int nave_dy = 0;
int movimentacaoNave = 4;

// movimentação por teclas
bool move_up = false;
bool move_down = false;
bool move_left = false;
bool move_right = false;

// limites da tela para a nave
const int limite_x_esquerda_nave = -12;
const int limite_y_inferior_nave  = 456;
const int limite_x_direita_nave  = 876;
const int limite_y_superior_nave  = -12;

// definições de asteroids
#define quantidadeArteroids 8
const int tamanho_sprite_asteroid = 128;
int tipo_asteroid;
int LARGURA_ASTEROID_1 = 128, ALTURA_ASTEROID_1 = 128;
int LARGURA_ASTEROID_2 = 128, ALTURA_ASTEROID_2 = 128;
int LARGURA_ASTEROID_3 = 128, ALTURA_ASTEROID_3 = 128;
int LARGURA_ASTEROID_4 = 128, ALTURA_ASTEROID_4 = 128;
float VELOCIDADE_ASTEROID_1 = 0.5, VELOCIDADE_ASTEROID_2 = 1, VELOCIDADE_ASTEROID_3 = 1.5, VELOCIDADE_ASTEROID_4 = 2;

// limites da tela para os asteroids
const int limite_x_esquerda_asteroids = 0;
const int limite_y_inferior_asteroids  = 418;
const int limite_x_direita_asteroids  = 830;
const int limite_y_superior_asteroids  = 0;

// definições de tiros
// [6] => tipos de tiros | [3] => tamanho width, height do sprite, offsex x
#define quantidadeTiros 100
const int tiros_tamanho[6][3] = {
	{40, 22, 70},
	{40, 22, 110},
	{40, 22, 150},
	{40, 22, 190},
	{35, 22, 37},
	{35, 22, 0}
};
const int animacao_tiros_avancados_tamanho[4][3] = {
	{20, 20, 0},
	{20, 20, 25},
	{20, 20, 50},
	{20, 20, 70}
};
const int tiros_avancados_tamanho[4][3] = {
	{108, 62, 2},
	{108, 62, 120},
	{108, 62, 230},
	{108, 62, 335}
};
bool tiroTecla = false, segurando_tecla = false;
double duracao_tiro, inicio_tiro;
const double duracao_tiro_avancado = 1.0;
int filaTiros = 0, filaAnimacaoTiroAvancado = 0;
const int velocidadeTiroSimples = 5;

// definições de explosao
const int explosao_tamanho[8][4] = {
	{256, 256, 0, 0},
	{300, 256, 256, 0},
	{300, 300, 556, 0},
	{325, 300, 856, 0},
	{256, 400, 0, 400},
	{300, 256, 256, 400},
	{256, 256, 556, 400},
	{256, 256, 856, 400}
};

// definições do background
#define quantidadeBackground 7

// declarando funções
int iniciarAllegro();
int finalizaAllegro();
ALLEGRO_BITMAP *load_bitmap_at_size(const char *filename, int w, int h);

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

    // incia a nave
    nave = al_load_bitmap(nave_local);

	// inicia os asteroids
	arteroids = al_load_bitmap(asteroids_local);

	// inicia os tiros
	tiros = al_load_bitmap(tiros_local);

	// inicia a animação dos tiros avançados
	animacaoTiroAvancado = al_load_bitmap(animacao_tiro_avancado_local);

	// inicia os tiros avançados
	tiro_avancado = al_load_bitmap(tiro_avancado_local);

	// incia as explosoes
	explosao = al_load_bitmap(explosao_local);

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

ALLEGRO_BITMAP *load_bitmap_at_size(const char *filename, int w, int h)
{
	ALLEGRO_BITMAP *resized_bmp, *loaded_bmp, *prev_target;

	// 1. create a temporary bitmap of size we want
	resized_bmp = al_create_bitmap(w, h);
	if (!resized_bmp) return NULL;

	// 2. load the bitmap at the original size
	loaded_bmp = al_load_bitmap(filename);
	if (!loaded_bmp)
	{
		al_destroy_bitmap(resized_bmp);
		return NULL;
	}

	// 3. set the target bitmap to the resized bmp
	prev_target = al_get_target_bitmap();
	al_set_target_bitmap(resized_bmp);

	// 4. copy the loaded bitmap to the resized bmp
	al_draw_scaled_bitmap(loaded_bmp,
		0, 0,                                // source origin
		al_get_bitmap_width(loaded_bmp),     // source width
		al_get_bitmap_height(loaded_bmp),    // source height
		0, 0,                                // target origin
		w, h,                                // target dimensions
		0                                    // flags
	);

	// 5. restore the previous target and clean up
	al_set_target_bitmap(prev_target);
	al_destroy_bitmap(loaded_bmp); 

	return resized_bmp;      
}