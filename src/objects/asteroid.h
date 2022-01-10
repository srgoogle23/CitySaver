void iniciaAsteroids();
void calculaAsteroids();
void redesenhaAsteroids();
void movimentacaoAsteroid(int indice, int tipo);
void reposicionaAsteroid(int indice);
bool verificaSeVaiColidirComAlgumAsteroid(int indice);

struct Asteroid {
	bool colisao;
	int tipo;
	double x;
	double y;
	int largura;
	int altura;
	double velocidade;
	bool status;
	int tentativas;
	int tempoTentativas;
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
		asteroid[i].colisao = false;
		asteroid[i].status = true;
		do{
			if(al_get_timer_count(timer) < asteroid[i].tempoTentativas)
			{
				break;
			}

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
		}while(verificaSeVaiColidirComAlgumAsteroid(i));
	}
}


bool verificaSeVaiColidirComAlgumAsteroid(int indice)
{
	bool colisaoEntreAsteroids = false;

	// se o asteroide está ativo
	if(asteroid[indice].status == true)
	{
		// verifica se o numero de tentativas ja saiu do limite
		if(asteroid[indice].tentativas >= 5)
		{
			asteroid[indice].status = false;
			asteroid[indice].tempoTentativas = al_get_timer_count(timer) + (FPS * 2);

			return false;
		}
	}
	else
	{
		// verifica se ja passou o tempo para tentar novamente
		if(al_get_timer_count(timer) > asteroid[indice].tempoTentativas)
		{
			asteroid[indice].status = true;
			asteroid[indice].tentativas = 0;
			asteroid[indice].tempoTentativas = 0;
		}
		else
		{
			// se não passou, retorna false para não tentar novamente nessa mesa execução de código
			return false;
		}
	}
	
	// verifica se os arteroids já não colidiram
	for (int i = 0; i < quantidadeArteroids; i++)
	{
		if (i != indice && asteroid[i].colisao == false && asteroid[indice].colisao == false && asteroid[indice].status == true && asteroid[i].status == true)
		{
			if (asteroid[i].x < asteroid[indice].x + asteroid[indice].largura && asteroid[i].x + asteroid[i].largura > asteroid[indice].x && asteroid[i].y < asteroid[indice].y + asteroid[indice].altura && asteroid[i].y + asteroid[i].altura > asteroid[indice].y)
			{
				colisaoEntreAsteroids = true;
			}
		}
	}

	// se não tiverem colido, calcula se irão colidir
	if(colisaoEntreAsteroids == false)
	{
		for (int i = 0; i < quantidadeArteroids; i++)
		{
			// se o asteroid analisado nao for o mesmo
			// e ambos estiverem com colisão false
			if (i != indice && asteroid[i].colisao == false && asteroid[indice].colisao == false && asteroid[indice].status == true && asteroid[i].status == true)
			{
				if(asteroid[i].y < asteroid[indice].y + asteroid[indice].altura && asteroid[i].y + asteroid[i].altura > asteroid[indice].y)
				{
					/*
						S(t) = So + v * t

						S(t) = asteroid[i].x + asteroid[i].velocidade * t
						S(t) = asteroid[indice].x + asteroid[indice].velocidade * t

						asteroid[i].x + asteroid[i].velocidade * t = asteroid[indice].x + asteroid[indice].velocidade * t
						asteroid[i].x - asteroid[indice].x = (asteroid[i].velocidade - asteroid[indice].velocidade) * t
						t = (asteroid[i].x - asteroid[indice].x) / (asteroid[i].velocidade - asteroid[indice].velocidade)

						como asteroid[indice].x nas chamadas dessa função sempre será SCREEN_W, considerado o zero da direita para a esquerda,:
						
						t = (asteroid[i].x) / (asteroid[i].velocidade - asteroid[indice].velocidade)
					*/
					double tempo_de_colisao = fabs(asteroid[i].x / (asteroid[i].velocidade - asteroid[indice].velocidade));
					tempo_de_colisao = tempo_de_colisao / FPS;
					double posicaoColisao = (asteroid[indice].velocidade * tempo_de_colisao) + asteroid[indice].x;
					
					if(posicaoColisao > 0)
					{
						colisaoEntreAsteroids = true;
					}
				}
			}
		}
	}
	
	asteroid[indice].tentativas++;

	return colisaoEntreAsteroids;
}

void redesenhaAsteroids()
{
    for (int i = 0; i < quantidadeArteroids; i++)
	{
		movimentacaoAsteroid(i, asteroid[i].tipo);

		if(asteroid[i].colisao == false &&  asteroid[i].status == true)
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
		else
		{
			asteroid[i].x = (-1 * randIntMinMax(2, 10) * tamanho_sprite_asteroid);
			asteroid[i].colisao = false;
			reposicionaAsteroid(i);
		}
	}	
}

void movimentacaoAsteroid(int indice, int tipo)
{
	if(asteroid[indice].status == true)
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
	}
	reposicionaAsteroid(indice);
}

void reposicionaAsteroid(int indice)
{
	if(asteroid[indice].x < (-1 * tamanho_sprite_asteroid))
	{
		do
		{
			if(al_get_timer_count(timer) < asteroid[indice].tempoTentativas)
			{
				break;
			}
			asteroid[indice].x = SCREEN_W;
			asteroid[indice].y = randIntMinMax(limite_y_superior_asteroids, limite_y_inferior_asteroids);
		} while (verificaSeVaiColidirComAlgumAsteroid(indice) == true);
	}
}

void finalizaAsteroids()
{
    al_destroy_bitmap(arteroids); 
}