void eventoPressionarTecla();

void eventoPressionarTecla()
{
	if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		//imprime qual tecla foi
		printf("\ncodigo tecla: %d", ev.keyboard.keycode);
		
		teclasMovimentoNave(ev.keyboard.keycode, 1);
	}
	else if(ev.type == ALLEGRO_EVENT_KEY_UP) 
	{
		teclasMovimentoNave(ev.keyboard.keycode, 2);
	}
}