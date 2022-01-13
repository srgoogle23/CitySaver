void eventosDeTemporizador();
void mostrarSegundosPassando();

void eventosDeTemporizador()
{
	if(ev.type == ALLEGRO_EVENT_TIMER)
	{
		// redesenha objetos na tela
		redesenhaTela();

		//atualiza a tela (quando houver algo para mostrar)
		al_flip_display();

		// adiciona um ponto a cada segundo
		if(al_get_timer_count(timer)%(int)FPS == 0 && !nave_game_over)
		{
			pontuacao++;			
		}
		
		if(DEBUG == true)
		{
			// mostra os segundos se passando ao longo do jogo
			mostrarSegundosPassando();
		}
		
	}
}

void mostrarSegundosPassando()
{
	if(al_get_timer_count(timer)%(int)FPS == 0)
		printf("\n%d segundos se passaram...", (int)(al_get_timer_count(timer)/FPS));
}