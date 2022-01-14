// includes do allegro
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

// includes nativos
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

// includes de utilidades
#include "utilities/rand.h"
#include "utilities/bitmap.h"
#include "utilities/graus.h"
#include "utilities/string.h"
#include "utilities/arquivo.h"

// includes de configurações
#include "config/config.h"

// includes de objetos
#include "objects/background.h"
#include "objects/pontuacao.h"
#include "objects/bloco.h"
#include "objects/extended/explosaoAsteroides.h"
#include "objects/asteroid.h"
#include "objects/extended/calculosBloco.h"
#include "objects/extended/gameOverReinicia.h"
#include "objects/tiro.h"
#include "objects/nave.h"
#include "objects/jogo.h"
#include "objects/gameover.h"
#include "objects/tela.h"

// includes de eventos
#include "events/mouse.h"
#include "events/tela.h"
#include "events/teclas.h"
#include "events/temporizador.h"
#include "events/extended/carregaEventos.h"