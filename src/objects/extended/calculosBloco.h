void redesenhaBloco();
void calculaMovimentoBloco();
void reiniciaBloco();
bool calculaColisaoBlocoAsteroid();
void verificaSeOBlocoEstaNaTela();

void reiniciaBloco()
{
    bloco.largura = randDoubleMinMax(blocoLarguraMin, blocoLarguraMax);
    bloco.altura = randDoubleMinMax(blocoAlturaMin, blocoAlturaMax);
    bloco.velocidade = randDoubleMinMax(1, 3);
    bloco.x = SCREEN_W;
    bloco.y = randDoubleMinMax(0, SCREEN_H - bloco.altura);
    bloco.bloco = al_create_bitmap(bloco.largura, bloco.altura);

    al_set_target_bitmap(bloco.bloco);
    al_clear_to_color(al_map_rgb(rand()%256, rand()%256, rand()%256));
    al_set_target_bitmap(al_get_backbuffer(display));
}

void calculaMovimentoBloco()
{
    // movimenta o bloco
	if(!pause)
	{
		if(bloco.status)
		{
			bloco.x -= bloco.velocidade;
		}
	}
    

    // verifica se o bloco ja saiu da tela
    verificaSeOBlocoEstaNaTela();
}

void verificaSeOBlocoEstaNaTela()
{
    if ((-1 * bloco.largura) > bloco.x)
    {
        do
        {
            if(al_get_timer_count(timer) <  bloco.tempoTentativas)
			{
				break;
			}
            reiniciaBloco();
        }
        while(calculaColisaoBlocoAsteroid() == true);
    }
    else if(SCREEN_W <= bloco.x)
    {
        do
        {
            if(al_get_timer_count(timer) <  bloco.tempoTentativas)
			{
				break;
			}
            reiniciaBloco();
        }
        while(calculaColisaoBlocoAsteroid() == true);
    }
}

void redesenhaBloco()
{
    calculaMovimentoBloco();

    if(bloco.status)
    {
        al_draw_bitmap(bloco.bloco, bloco.x, bloco.y, 0);
    }
}

bool calculaColisaoBlocoAsteroid()
{
    bool colisaoBloco = false;

	// se o bloco está ativo
	if(bloco.status == true)
	{
		// verifica se o numero de tentativas ja saiu do limite
		if(bloco.tentativas >= bloco.maxTentativas)
		{
			bloco.status = false;
			bloco.tempoTentativas = al_get_timer_count(timer) + (FPS * 2);

			return false;
		}
	}
	else
	{
		// verifica se ja passou o tempo para tentar novamente
		if(al_get_timer_count(timer) > bloco.tempoTentativas)
		{
			bloco.status = true;
			bloco.tentativas = 0;
			bloco.tempoTentativas = 0;
		}
		else
		{
			// se não passou, retorna false para não tentar novamente nessa mesa execução de código
			return false;
		}
	}

    // verifica se o bloco já não colidiu com nenhum asteroide
	for (int i = 0; i < quantidadeArteroids; i++)
	{
		if (asteroid[i].colisao == false && asteroid[i].status == true)
        {
            if (asteroid[i].x < bloco.x + bloco.largura && asteroid[i].x + asteroid[i].largura > bloco.x && asteroid[i].y < bloco.y + bloco.altura && asteroid[i].y + asteroid[i].altura > bloco.y)
            {
                colisaoBloco = true;
            }
        }
	}

	//verifica não tiverem colidido, se irá colidir com um bloco
	if(colisaoBloco == false)
	{
		for (int i = 0; i < quantidadeArteroids; i++)
		{
			if(asteroid[i].colisao == false && asteroid[i].status == true)
			{
				if(asteroid[i].y < bloco.y + bloco.altura && asteroid[i].y + asteroid[i].altura > bloco.y)
				{
					double tempo_de_colisao = (bloco.x - asteroid[i].x ) / ( bloco.velocidade - asteroid[i].velocidade );
					double posicaoColisao = asteroid[i].x - (asteroid[i].velocidade * tempo_de_colisao);

					// se a colisão estiver na tela ou perto dela
					if(posicaoColisao >= -SCREEN_W && posicaoColisao <= SCREEN_W)
					{
						colisaoBloco = true;
					}
				}
			}
		}
	}
	
	bloco.tentativas += 1;

    return colisaoBloco;
}