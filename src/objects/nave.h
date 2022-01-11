
void iniciaNave();
void finalizaNave();
void teclasMovimentoNave(int tecla, int tipoEvento);
void calculaMovimentoNave();
void redesenhaNave();
void colisaoNave();
void animacaoExplosaoNave();

void iniciaNave()
{
    nave_dy = (SCREEN_H / 2) - NAVE_W / 2;
    al_draw_bitmap_region(nave, 0, 0, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
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
	if(move_up && (nave_dy - 4) >= limite_y_superior_nave && (nave_dy - 4) <= limite_y_inferior_nave)
	{
		nave_dy -= movimentacaoNave;
	}
	else if(move_down && (nave_dy + 4) >= limite_y_superior_nave && (nave_dy + 4) <= limite_y_inferior_nave)
	{
		nave_dy += movimentacaoNave;
	}
	else if(move_left && (nave_dx - 4) >= limite_x_esquerda_nave && (nave_dx - 4) <= limite_x_direita_nave)
	{
		nave_dx -= movimentacaoNave;
	}
	else if(move_right && (nave_dx + 4) >= limite_x_esquerda_nave && (nave_dx + 4) <= limite_x_direita_nave)
	{
		nave_dx += movimentacaoNave;
	}
}

void redesenhaNave()
{
    calculaMovimentoNave();
	colisaoNave();
	
	if(colisao)
	{
		animacaoExplosaoNave();
	}
	else
	{
		al_draw_bitmap_region(nave, 0, 0, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
	}
	
}

void colisaoNave()
{
	//verifica se a nave colidiu com algum asteroide
	for(int i = 0; i < quantidadeArteroids; i++)
	{
		if(asteroid[i].x + tamanho_sprite_asteroid >= nave_dx && asteroid[i].x <= nave_dx + NAVE_W)
		{
			if(asteroid[i].y + tamanho_sprite_asteroid >= nave_dy && asteroid[i].y <= nave_dy + NAVE_H)
			{
				//se a nave colidiu com o asteroide, atualiza o valor da colisão
				colisao = true;
			}
		}
	}

	//verifica se a nave colidiu com algum bloco
	if(nave_dx < bloco.x + bloco.largura && nave_dx + NAVE_W > bloco.x && nave_dy < bloco.y + bloco.altura && nave_dy + NAVE_H > bloco.y)
	{
		//se a nave colidiu com uma nave, atualiza o valor da colisão
		colisao = true;
	}
}

void animacaoExplosaoNave()
{
	if(animacaoColisao < 20)
	{
		al_draw_bitmap_region(nave, 0, NAVE_H * 3, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
	}
	else if(animacaoColisao < 40)
	{
		al_draw_bitmap_region(nave, NAVE_W, NAVE_H * 3, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
	}
	else if(animacaoColisao < 60)
	{
		al_draw_bitmap_region(nave, NAVE_W * 2, NAVE_H * 3, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
	}
	else if(animacaoColisao < 80)
	{
		al_draw_bitmap_region(nave, NAVE_W * 3, NAVE_H * 3, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
	}
	else if(animacaoColisao < 100)
	{
		al_draw_bitmap_region(nave, NAVE_W * 4, NAVE_H * 3, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
	}
	else if(animacaoColisao < 120)
	{
		al_draw_bitmap_region(nave, NAVE_W * 5, NAVE_H * 3, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
	}
	else if(animacaoColisao < 140)
	{
		al_draw_bitmap_region(nave, NAVE_W * 6, NAVE_H * 3, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
	}
	else
	{
		colisao = false;
		animacaoColisao = 0;
	}

	animacaoColisao++;
}