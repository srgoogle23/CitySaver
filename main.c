#include "src/autoload.h"

int main(int argc, char **argv)
{
	srand ( time(NULL) );
	iniciarAllegro();
    iniciaNave();
	iniciaAsteroids();

	asteroid[0].tipo = 1;
	asteroid[0].x = 475;
	asteroid[0].y = 260;

	asteroid[1].tipo = 2;
	asteroid[1].x = 475 + 128;
	asteroid[1].y = 260;

	asteroid[2].tipo = 3;
	asteroid[2].x = 475;
	asteroid[2].y = 260 + 128;

	asteroid[3].tipo = 4;
	asteroid[3].x = 475 + 128;
	asteroid[3].y = 260 + 128;

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
	}

    // execuções de finalizações
	finalizaBackground();
	finalizaNave();
	finalizaAsteroids();
	finalizaAllegro();
	
    return 0;
}