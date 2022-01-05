void eventoPressionarTecla();

void eventoPressionarTecla()
{
	if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		//imprime qual tecla foi
		printf("\ncodigo tecla: %d", ev.keyboard.keycode);
	}
}