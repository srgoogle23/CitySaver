void eventoPressionarTecla();
void imprimirTeclaPressionada(int tecla);

void eventoPressionarTecla()
{
	if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		
		if(DEBUG == true)
		{
			//imprime qual tecla foi
			imprimirTeclaPressionada(ev.keyboard.keycode);
		}
		
		if(!nave_game_over && !menu)
		{
			teclasMovimentoNave(ev.keyboard.keycode, 1);
			teclasTiro(ev.keyboard.keycode, 1);
		}
		else if(!nave_game_over && menu)
		{
			teclasMenu(ev.keyboard.keycode, 1);
		}
		else
		{
			teclasGameOver(ev.keyboard.keycode, 1);
		}
		
	}
	else if(ev.type == ALLEGRO_EVENT_KEY_UP) 
	{
		if(!nave_game_over && !menu)
		{
			teclasMovimentoNave(ev.keyboard.keycode, 2);
			teclasTiro(ev.keyboard.keycode, 2);
		}
		else if(!nave_game_over && menu)
		{
			teclasMenu(ev.keyboard.keycode, 2);
		}
		else
		{
			teclasGameOver(ev.keyboard.keycode, 2);
		}
	}
}

void imprimirTeclaPressionada(int tecla)
{
	printf("\ncodigo tecla: %d", tecla);
}