
void iniciaNave();
void finalizaNave();
void teclasMovimentoNave(int tecla, int tipoEvento);
void calculaMovimentoNave();

void iniciaNave()
{
    nave_dy = (SCREEN_H / 2) - NAVE_W / 2;
    al_draw_bitmap_region(nave, 0, 0, 100, 100, nave_dx, nave_dy, 0);
}

void finalizaNave()
{
    al_destroy_bitmap(nave); 
}

void teclasMovimentoNave(int tecla, int tipoEvento)
{
    if(tipoEvento == 1)
    {
        switch(tecla) {
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
    else if(tipoEvento == 2)
    {
        //verifica qual tecla foi
		switch(tecla) {
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

void calculaMovimentoNave()
{
	if(move_up && (nave_dy - 4) >= limite_y_superior && (nave_dy - 4) <= limite_y_inferior)
	{
		nave_dy -= movimentacaoNave;
	}
	else if(move_down && (nave_dy + 4) >= limite_y_superior && (nave_dy + 4) <= limite_y_inferior)
	{
		nave_dy += movimentacaoNave;
	}
	else if(move_left && (nave_dx - 4) >= limite_x_esquerda && (nave_dx - 4) <= limite_x_direita)
	{
		nave_dx -= movimentacaoNave;
	}
	else if(move_right && (nave_dx + 4) >= limite_x_esquerda && (nave_dx + 4) <= limite_x_direita)
	{
		nave_dx += movimentacaoNave;
	}
}