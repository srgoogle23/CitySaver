void eventoPressionarTecla();

void eventoPressionarTecla()
{
	if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		//imprime qual tecla foi
		printf("\ncodigo tecla: %d", ev.keyboard.keycode);

		switch(ev.keyboard.keycode) {
			//se a tecla for o W
			case ALLEGRO_KEY_W:
				move_up = true;
			break;

			//se a tecla for o S
			case ALLEGRO_KEY_S:
				move_down = true;
			break;

			//se a tecla for o A
			case ALLEGRO_KEY_A:
				move_left = true;
			break;

			//se a tecla for o D
			case ALLEGRO_KEY_D:
				move_right = true;
			break;
		}
	}
	else if(ev.type == ALLEGRO_EVENT_KEY_UP) 
	{
		//verifica qual tecla foi
		switch(ev.keyboard.keycode) {
			//se a tecla for o W
			case ALLEGRO_KEY_W:
				move_up = false;
			break;

			//se a tecla for o S
			case ALLEGRO_KEY_S:
				move_down = false;
			break;

			//se a tecla for o A
			case ALLEGRO_KEY_A:
				move_left = false;
			break;

			//se a tecla for o D
			case ALLEGRO_KEY_D:
				move_right = false;
			break;
		}
	}
}