void iniciaAsteroids();
void calculaAsteroids();
void redesenhaAsteroids();
void movimentacaoAsteroid(int indice, int tipo);
void reposicionaAsteroid(int indice);

struct Asteroid {
	int tipo;
	int x;
	int y;
	int largura;
	int altura;
	float velocidade;
};

struct Asteroid asteroid[quantidadeArteroids];

void iniciaAsteroids()
{
    calculaAsteroids();

    for (int i = 0; i < quantidadeArteroids; i++)
	{
		if(asteroid[i].tipo == 1)
		{
			al_draw_bitmap_region(arteroids, 0, 0, asteroid[i].largura, asteroid[i].altura, asteroid[i].x, asteroid[i].y, 0);
		}
		else if(asteroid[i].tipo == 2)
		{
			al_draw_bitmap_region(arteroids, tamanho_sprite_asteroid, 0, asteroid[i].largura, asteroid[i].altura, asteroid[i].x, asteroid[i].y, 0);
		}
		else if(asteroid[i].tipo == 3)
		{
			al_draw_bitmap_region(arteroids, 0, tamanho_sprite_asteroid, asteroid[i].largura, asteroid[i].altura, asteroid[i].x, asteroid[i].y, 0);
		}
		else if(asteroid[i].tipo == 4)
		{
			al_draw_bitmap_region(arteroids, tamanho_sprite_asteroid, tamanho_sprite_asteroid, asteroid[i].largura, asteroid[i].altura, asteroid[i].x, asteroid[i].y, 0);
		}
	}
}

void calculaAsteroids()
{
    for (int i = 0; i < quantidadeArteroids; i++)
	{
		tipo_asteroid = randInt(4);
		if (tipo_asteroid == 0)
		{
			asteroid[i].tipo = 1;
			asteroid[i].x = SCREEN_W;
			asteroid[i].y = randIntMinMax(limite_y_superior_asteroids, limite_y_inferior_asteroids);
			asteroid[i].largura = LARGURA_ASTEROID_1;
			asteroid[i].altura = ALTURA_ASTEROID_1;
			asteroid[i].velocidade = VELOCIDADE_ASTEROID_1;
		}
		else if (tipo_asteroid == 1)
		{
			asteroid[i].tipo = 2;
			asteroid[i].x = SCREEN_W;
			asteroid[i].y = randIntMinMax(limite_y_superior_asteroids, limite_y_inferior_asteroids);
			asteroid[i].largura = LARGURA_ASTEROID_2;
			asteroid[i].altura = ALTURA_ASTEROID_2;
			asteroid[i].velocidade = VELOCIDADE_ASTEROID_2;
		}
		else  if (tipo_asteroid == 2)
		{
			asteroid[i].tipo = 3;
			asteroid[i].x = SCREEN_W;
			asteroid[i].y = randIntMinMax(limite_y_superior_asteroids, limite_y_inferior_asteroids);
			asteroid[i].largura = LARGURA_ASTEROID_3;
			asteroid[i].altura = ALTURA_ASTEROID_3;
			asteroid[i].velocidade = VELOCIDADE_ASTEROID_3;
		}
		else
		{
			asteroid[i].tipo = 4;
			asteroid[i].x = SCREEN_W;
			asteroid[i].y = randIntMinMax(limite_y_superior_asteroids, limite_y_inferior_asteroids);
			asteroid[i].largura = LARGURA_ASTEROID_4;
			asteroid[i].altura = ALTURA_ASTEROID_4;
			asteroid[i].velocidade = VELOCIDADE_ASTEROID_4;
		}
	}
}

void redesenhaAsteroids()
{
    for (int i = 0; i < quantidadeArteroids; i++)
	{
		movimentacaoAsteroid(i, asteroid[i].tipo);

		if(asteroid[i].tipo == 1)
		{
			al_draw_bitmap_region(arteroids, 0, 0, asteroid[i].largura, asteroid[i].altura, asteroid[i].x, asteroid[i].y, 0);
		}
		else if(asteroid[i].tipo == 2)
		{
			al_draw_bitmap_region(arteroids, tamanho_sprite_asteroid, 0, asteroid[i].largura, asteroid[i].altura, asteroid[i].x, asteroid[i].y, 0);
		}
		else if(asteroid[i].tipo == 3)
		{
			al_draw_bitmap_region(arteroids, 0, tamanho_sprite_asteroid, asteroid[i].largura, asteroid[i].altura, asteroid[i].x, asteroid[i].y, 0);
		}
		else if(asteroid[i].tipo == 4)
		{
			al_draw_bitmap_region(arteroids, tamanho_sprite_asteroid, tamanho_sprite_asteroid, asteroid[i].largura, asteroid[i].altura, asteroid[i].x, asteroid[i].y, 0);
		}
	}
}

void movimentacaoAsteroid(int indice, int tipo)
{
	if (tipo == 1)
	{
		asteroid[indice].x -= asteroid[indice].velocidade;
	}
	else if (tipo == 2)
	{
		asteroid[indice].x -= asteroid[indice].velocidade;
	}
	else if (tipo == 3)
	{
		asteroid[indice].x -= asteroid[indice].velocidade;
	}
	else if (tipo == 4)
	{
		asteroid[indice].x -= asteroid[indice].velocidade;
	}

	reposicionaAsteroid(indice);
}

void reposicionaAsteroid(int indice)
{
	if(asteroid[indice].x < (-1 * tamanho_sprite_asteroid))
	{
		asteroid[indice].x = SCREEN_W;
		asteroid[indice].y = randIntMinMax(limite_y_superior_asteroids, limite_y_inferior_asteroids);
	}
}

void finalizaAsteroids()
{
    al_destroy_bitmap(arteroids); 
}