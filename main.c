#include "src/autoload.h"
 
void mostrarSegundosPassando()
{
	if(al_get_timer_count(timer)%(int)FPS == 0)
		printf("\n%d segundos se passaram...", (int)(al_get_timer_count(timer)/FPS));
}

void eventosDeTemporizador()
{
	if(ev.type == ALLEGRO_EVENT_TIMER)
	{
		//atualiza a tela (quando houver algo para mostrar)
		al_flip_display();

		// mostra os segundos se passando ao longo do jogo
		mostrarSegundosPassando();
	}
}

void eventoFechamentoDeTela()
{
	if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
		jogando = 0;
	}
}

void eventoCliqueDoMouse()
{
	if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
		printf("\nmouse clicado em: %d, %d", ev.mouse.x, ev.mouse.y);
	}
}

void eventoPressionarTecla()
{
	if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		//imprime qual tecla foi
		printf("\ncodigo tecla: %d", ev.keyboard.keycode);
	}
}

int main(int argc, char **argv)
{
	iniciarAllegro();

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

	} //fim do while
	finalizaAllegro();

	return 0;
}