#include "src/autoload.h"

int main(int argc, char **argv)
{
	srand ( time(NULL) );
	iniciarAllegro();
	iniciarBackground();
	iniciaBloco();
	iniciaNave();
	iniciarExplosoes();
	iniciaAsteroids();
	inciarTiros();

	// loop principal
	while(jogando)
	{
		while(!nave_game_over && jogando)
		{
			carregaEventos();
		}

		while(nave_game_over && jogando)
		{
			carregaEventos();
		}
	}

    // execuções de finalizações
	finalizaBackground();
	finalizaBloco();
	finalizaNave();
	finalizaAsteroids();
	finalizaTiro();
	finalizaExplosao();
	finalizaAllegro();
	
    return 0;
}