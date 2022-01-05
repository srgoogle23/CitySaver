#include "src/autoload.h"

void atualizatela(int c);

int main(int argc, char **argv)
{
	iniciarAllegro();

    iniciaNave();

    int c = 0;
    // loop principal
	while(jogando)
	{
		//espera por um evento e o armazena na variavel de evento ev
		al_wait_for_event(event_queue, &ev);

		// se o tipo de evento for um evento do temporizador, ou seja, se o tempo passou de t para t+1
		eventosDeTemporizador();

		//se o tipo de evento for o fechamento da tela (clique no x da janela)
		eventoFechamentoDeTela();

		//se o tipo de evento for um clique de mouse
		eventoCliqueDoMouse();

		//se o tipo de evento for um pressionar de uma tecla
		eventoPressionarTecla();

        atualizatela(c);

        c += 1;
    }

    // execuções de finalizações
	finalizaAllegro();
    finalizaNave();
	
    return 0;
}

void atualizatela( int c)
{
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_bitmap(background, 0, 0, 0);
        al_draw_bitmap_region(nave, 0, 0, 100, 100, nave_dx+c, nave_dy, 0);
        al_flip_display();
}