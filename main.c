#include "src/autoload.h"

int main(int argc, char **argv)
{
	iniciarAllegro();

    iniciaNave();

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
	finalizaAllegro();
    finalizaNave();
	
    return 0;
}