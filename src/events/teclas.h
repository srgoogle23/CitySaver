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
		
		teclasMovimentoNave(ev.keyboard.keycode, 1);
	}
	else if(ev.type == ALLEGRO_EVENT_KEY_UP) 
	{
		teclasMovimentoNave(ev.keyboard.keycode, 2);
	}
}

void imprimirTeclaPressionada(int tecla)
{
	printf("\ncodigo tecla: %d", tecla);
}