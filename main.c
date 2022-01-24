#include "src/autoload.h"

int main(int argc, char **argv)
{
	srand ( time(NULL) );
	iniciarAllegro();
	iniciarBackground();
	inciarMenu();
	iniciaBloco();
	iniciaNave();
	iniciarExplosoes();
	iniciaAsteroids();
	inciarTiros();

	// loop principal
	while(jogando)
	{

		while(menu && !nave_game_over && jogando)
		{
			carregaEventosMenu();
		}

		while(!menu && !nave_game_over && jogando)
		{
			carregaEventos();
		}

		while(!menu && nave_game_over && jogando)
		{
			carregaEventos();
		}
	}

    // execuções de finalizações
	finalizaBackground();
	finalizaMenu();
	finalizaBloco();
	finalizaNave();
	finalizaAsteroids();
	finalizaTiro();
	finalizaExplosao();
	finalizaAllegro();
	
    return 0;
}