void eventoPressionarTecla();
void imprimirTeclaPressionada(int tecla);
void teclaPause(int tecla, int tipoEvento);

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
			teclaPause(ev.keyboard.keycode, 1);
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
			teclaPause(ev.keyboard.keycode, 2);
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

void teclaPause(int tecla, int tipoEvento)
{
    if(tipoEvento == 1)
    {
        switch(tecla) {
            // se o usuario selecionou P pausa o jogo
			case ALLEGRO_KEY_P:
				if(pause == true)
				{
					pause = false;
				}
				else if(pause == false)
				{
					pause = true;
				}
                
			break;
		}
    }
}

void imprimirTeclaPressionada(int tecla)
{
	printf("\ncodigo tecla: %d", tecla);
}