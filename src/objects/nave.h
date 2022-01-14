
void iniciaNave();
void finalizaNave();
void teclasMovimentoNave(int tecla, int tipoEvento);
void calculaMovimentoNave();
void redesenhaNave();
void colisaoNave();
void animacaoExplosaoNave();
void desenhaAnimacaoNave();

void iniciaNave()
{
	nave_dx = inicio_dx_nave;
	nave_dy = (SCREEN_H / 2) - NAVE_W / 2;
    al_draw_bitmap_region(nave, 3 * NAVE_W, NAVE_H, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
}

void finalizaNave()
{
    al_destroy_bitmap(nave); 
}

void teclasMovimentoNave(int tecla, int tipoEvento)
{
    if(tipoEvento == 1)
    {
		//verifica qual tecla foi
		if(tecla == ALLEGRO_KEY_W) //se a tecla for o W
        {
			move_up = true;

			if(tecla == ALLEGRO_KEY_D)  //se a tecla for o W com o D
			{
				move_right = true;
			} 
			else if(tecla == ALLEGRO_KEY_A)  //se a tecla for o W com o A
			{
				move_left = true;
			}
        }
		else if(tecla == ALLEGRO_KEY_S) //se a tecla for o S
        {
            move_down = true;

			if(tecla == ALLEGRO_KEY_D)  //se a tecla for o S com o D
			{
				move_right = true;
			} 
			else if(tecla == ALLEGRO_KEY_A)  //se a tecla for o S com o A
			{
				move_left = true;
			}
        }
		else if(tecla == ALLEGRO_KEY_A) //se a tecla for o A
        {
            move_left = true;

			if(tecla == ALLEGRO_KEY_W)  //se a tecla for o A com o W
			{
				move_up = true;
			} 
			else if(tecla == ALLEGRO_KEY_S)  //se a tecla for o A com o S
			{
				move_down = true;
			}
        }
		else if(tecla == ALLEGRO_KEY_D) //se a tecla for o D
        {
            move_right = true;

			if(tecla == ALLEGRO_KEY_W)  //se a tecla for o A com o W
			{
				move_up = true;
			} 
			else if(tecla == ALLEGRO_KEY_S)  //se a tecla for o A com o S
			{
				move_down = true;
			}
        }
    }
    else if(tipoEvento == 2)
    {
        //verifica qual tecla foi
		if(tecla == ALLEGRO_KEY_W) //se a tecla for o W
        {
            move_up = false;
        }
		else if(tecla == ALLEGRO_KEY_S) //se a tecla for o S
        {
            move_down = false;
        }
		else if(tecla == ALLEGRO_KEY_A) //se a tecla for o A
        {
            move_left = false;
        }
		else if(tecla == ALLEGRO_KEY_D) //se a tecla for o D
        {
            move_right = false;
        }
    }
}

void calculaMovimentoNave()
{
	if(!nave_game_over)
	{
		if(move_up && (nave_dy - 4) >= limite_y_superior_nave && (nave_dy - 4) <= limite_y_inferior_nave)
		{
			nave_dy -= movimentacaoNave;

			// calculando movimentação diagonal
			if(move_right && (nave_dx + 4) >= limite_x_esquerda_nave && (nave_dx + 4) <= limite_x_direita_nave)
			{
				nave_dx += movimentacaoNave;
			}
			else if(move_left && (nave_dx - 4) >= limite_x_esquerda_nave && (nave_dx - 4) <= limite_x_direita_nave)
			{
				nave_dx -= movimentacaoNave;
			}
		}
		else if(move_down && (nave_dy + 4) >= limite_y_superior_nave && (nave_dy + 4) <= limite_y_inferior_nave)
		{
			nave_dy += movimentacaoNave;

			// calculando movimentação diagonal
			if(move_right && (nave_dx + 4) >= limite_x_esquerda_nave && (nave_dx + 4) <= limite_x_direita_nave)
			{
				nave_dx += movimentacaoNave;
			}
			else if(move_left && (nave_dx - 4) >= limite_x_esquerda_nave && (nave_dx - 4) <= limite_x_direita_nave)
			{
				nave_dx -= movimentacaoNave;
			}
		}
		else if(move_left && (nave_dx - 4) >= limite_x_esquerda_nave && (nave_dx - 4) <= limite_x_direita_nave)
		{
			nave_dx -= movimentacaoNave;

			// calculando movimentação diagonal
			if(move_down && (nave_dy + 4) >= limite_y_superior_nave && (nave_dy + 4) <= limite_y_inferior_nave)
			{
				nave_dy += movimentacaoNave;
			}
			else if(move_up && (nave_dy - 4) >= limite_y_superior_nave && (nave_dy - 4) <= limite_y_inferior_nave)
			{
				nave_dy -= movimentacaoNave;
			}
		}
		else if(move_right && (nave_dx + 4) >= limite_x_esquerda_nave && (nave_dx + 4) <= limite_x_direita_nave)
		{
			nave_dx += movimentacaoNave;

			// calculando movimentação diagonal
			if(move_down && (nave_dy + 4) >= limite_y_superior_nave && (nave_dy + 4) <= limite_y_inferior_nave)
			{
				nave_dy += movimentacaoNave;
			}
			else if(move_up && (nave_dy - 4) >= limite_y_superior_nave && (nave_dy - 4) <= limite_y_inferior_nave)
			{
				nave_dy -= movimentacaoNave;
			}
		}
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
		desenhaAnimacaoNave();
	}
	
}

void desenhaAnimacaoNave()
{
	// se a nave estiver se movimentando para frente, ela está acelerando
	if(move_right == true)
	{
		if(move_right == true && move_up == true)
		{
			al_draw_bitmap_region(nave, 5 * NAVE_W, 0, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
		}
		else if(move_right == true && move_down == true)
		{
			al_draw_bitmap_region(nave, 2 * NAVE_W, 0, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
		}
		else
		{
			al_draw_bitmap_region(nave, 0, 0, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
		}
	}
	else if(move_up == true) // se a nave estiver para a esquerda, ela está acelerando para a esquerda
	{
		if(move_left == true && move_up == true)
		{
			al_draw_bitmap_region(nave, 4 * NAVE_W, NAVE_H, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
		}
		else if(move_right == true && move_up == true)
		{
			al_draw_bitmap_region(nave, 5 * NAVE_W, 0, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
		}
		else
		{
			al_draw_bitmap_region(nave, 4 * NAVE_W, 0, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
		}
	}
	else if(move_down == true)  // se a nave estiver para a direita, ela está acelerando para a direita
	{
		if(move_left == true && move_down == true)
		{
			al_draw_bitmap_region(nave, 6 * NAVE_W, NAVE_H, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
		}
		else if(move_right == true && move_down == true)
		{
			al_draw_bitmap_region(nave, 2 * NAVE_W, 0, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
		}
		else
		{
			al_draw_bitmap_region(nave, NAVE_W, 0, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
		}
	}
	else if(move_left == true)
	{
		if(move_left == true && move_up == true)
		{
			al_draw_bitmap_region(nave, 4 * NAVE_W, NAVE_H, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
		}
		else if(move_left == true && move_down == true)
		{
			al_draw_bitmap_region(nave, 6 * NAVE_W, NAVE_H, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
		}
		else
		{
			al_draw_bitmap_region(nave, 3 * NAVE_W, NAVE_H, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
		}
	}
	else // se não, ela desliga o motor
	{
		al_draw_bitmap_region(nave, 3 * NAVE_W, NAVE_H, NAVE_W, NAVE_H, nave_dx, nave_dy, 0);
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
	if(animacaoColisao == 1)
	{
		nave_game_over = true;
		resetaPontuacao();
		al_play_sample(game_over, 1.5, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
	}
	else if(animacaoColisao < 20)
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
		nave_game_over = true;
	}

	animacaoColisao++;
}