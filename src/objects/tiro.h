void disparaTiro();
void finalizaTiro();
void teclasTiro(int tecla, int tipoEvento);
void calculaMovimentoTiro();
void redesenhaTiro();
void mudaAnimacaoTiro(int i);
void verificaSeOTiroEstaNaTela(int i);
int verificaSeTodosOsTirosEstaoDesativados();
void limpaTiros();
void colisaoTiros(int j);
void animacaoExplosao(int i);
void finalizaExplosao();
void limpaTiro(int i);

struct Tiro {
    bool ativado;
    bool colisao;
    int timerExplosao;
    int tipo;
	int x;
	int y;
    int x_inicial;
	int y_inicial;
	int largura;
	int altura;
    int offset_x;
    float velocidade;
};

struct Tiro struct_tiro[quantidadeTiros];

void inciarTiros()
{
    for (int i = 0; i < quantidadeTiros; i++)
    {
        struct_tiro[i].timerExplosao = 0;
        struct_tiro[i].ativado = false;
        struct_tiro[i].colisao = false;
        struct_tiro[i].tipo = 0;
        struct_tiro[i].x = 0;
        struct_tiro[i].y = 0;
        struct_tiro[i].x_inicial = 0;
        struct_tiro[i].y_inicial = 0;
        struct_tiro[i].largura = 0;
        struct_tiro[i].altura = 0;
        struct_tiro[i].offset_x = 0;
        struct_tiro[i].velocidade = velocidadeTiroSimples;
    }
}

void disparaTiro()
{
    if(filaTiros < quantidadeTiros)
    {
        filaTiros++;

        struct_tiro[filaTiros-1].timerExplosao = 0;
        struct_tiro[filaTiros-1].ativado = true;
        struct_tiro[filaTiros-1].colisao = false;
        struct_tiro[filaTiros-1].tipo = 0;
        struct_tiro[filaTiros-1].x = nave_dx + 50;
        struct_tiro[filaTiros-1].y = nave_dy + 40;
        struct_tiro[filaTiros-1].x_inicial = struct_tiro[filaTiros-1].x;
        struct_tiro[filaTiros-1].y_inicial = struct_tiro[filaTiros-1].y;
        struct_tiro[filaTiros-1].largura = tiros_tamanho[struct_tiro[filaTiros - 1].tipo][0];
        struct_tiro[filaTiros-1].altura = tiros_tamanho[struct_tiro[filaTiros-1].tipo][1];
        struct_tiro[filaTiros-1].offset_x = tiros_tamanho[struct_tiro[filaTiros-1].tipo][2];

        al_draw_bitmap_region(tiros, struct_tiro[filaTiros-1].offset_x, 0, struct_tiro[filaTiros-1].largura, struct_tiro[filaTiros-1].altura, struct_tiro[filaTiros-1].x, struct_tiro[filaTiros-1].y, 0);
    }
    else
    {
        if(verificaSeTodosOsTirosEstaoDesativados())
        {
            limpaTiros();
        }
    }
}

void calculaMovimentoTiro()
{
    for (int i = 0; i < quantidadeTiros; i++)
    {
        verificaSeOTiroEstaNaTela(i);
        colisaoTiros(i);
        if (struct_tiro[i].ativado == true && struct_tiro[i].colisao == false)
        {
            mudaAnimacaoTiro(i);
            struct_tiro[i].x += struct_tiro[i].velocidade;
            struct_tiro[i].largura = tiros_tamanho[struct_tiro[i].tipo][0];
            struct_tiro[i].altura = tiros_tamanho[struct_tiro[i].tipo][1];
            struct_tiro[i].offset_x = tiros_tamanho[struct_tiro[i].tipo][2];
        }
    }
}

void colisaoTiros(int j)
{
    if (struct_tiro[j].ativado == true)
    {
        //verifica se o tiro colidiu com algum asteroide
        for(int i = 0; i < quantidadeArteroids; i++)
        {
            if(asteroid[i].x + tamanho_sprite_asteroid >= struct_tiro[j].x && asteroid[i].x <= struct_tiro[j].x + struct_tiro[j].largura)
            {
                if(asteroid[i].y + tamanho_sprite_asteroid >= struct_tiro[j].y  && asteroid[i].y <= struct_tiro[j].y + struct_tiro[j].altura)
                {
                    //se o tiro com o asteroide, atualiza o valor da colisão
                    struct_tiro[j].colisao = true;
                    asteroid[i].colisao = true;
                }
            }
        }
    }
}

void limpaTiros()
{
    for (int i = 0; i < quantidadeTiros; i++)
    {
        struct_tiro[i].timerExplosao = 0;
        struct_tiro[i].ativado = false;
        struct_tiro[i].colisao = false;
        struct_tiro[i].tipo = 0;
        struct_tiro[i].x = 0;
        struct_tiro[i].y = 0;
        struct_tiro[i].x_inicial = 0;
        struct_tiro[i].y_inicial = 0;
        struct_tiro[i].largura = 0;
        struct_tiro[i].altura = 0;
        struct_tiro[i].offset_x = 0;
        struct_tiro[i].velocidade = velocidadeTiroSimples;
    }
    filaTiros = 0;
}

int verificaSeTodosOsTirosEstaoDesativados()
{
    for (int i = 0; i < quantidadeTiros; i++)
    {
        if (struct_tiro[i].ativado == true)
        {
            return 0;
        }
    }
    return 1;
}

void verificaSeOTiroEstaNaTela(int i)
{
    if(struct_tiro[i].x > SCREEN_W)
    {
        struct_tiro[i].ativado = false;
    }
}

void mudaAnimacaoTiro(int i)
{
    if((struct_tiro[i].x - struct_tiro[i].x_inicial) < 50)
    {
        struct_tiro[i].tipo = 0;
    }
    else if((struct_tiro[i].x - struct_tiro[i].x_inicial) < 100)
    {
        struct_tiro[i].tipo = 1;
    }
    else if((struct_tiro[i].x - struct_tiro[i].x_inicial) < 150)
    {
        struct_tiro[i].tipo = 2;
    }
    else if((struct_tiro[i].x - struct_tiro[i].x_inicial) < 200)
    {
        struct_tiro[i].tipo = 3;
    }
    else if((struct_tiro[i].x - struct_tiro[i].x_inicial) < 250)
    {
        struct_tiro[i].tipo = 4;
    }
    else if((struct_tiro[i].x - struct_tiro[i].x_inicial) < 300)
    {
        struct_tiro[i].tipo = 5;
    }
}

void redesenhaTiro()
{
    if (tiroTecla)
    {
        tiroTecla = false;
        disparaTiro();
    }

    calculaMovimentoTiro();

    for (int i = 0; i < quantidadeTiros; i++)
    {
        if (struct_tiro[i].ativado == true && struct_tiro[i].colisao == false)
        { 
            al_draw_bitmap_region(tiros, struct_tiro[i].offset_x, 0, struct_tiro[i].largura, struct_tiro[i].altura, struct_tiro[i].x, struct_tiro[i].y, 0);
        }
        else if(struct_tiro[i].colisao == true)
        {
            animacaoExplosao(i);
        }
    }
}

void animacaoExplosao(int i)
{
    printf("x:%d, y:%d\n", struct_tiro[i].x, struct_tiro[i].y);
    if(struct_tiro[i].timerExplosao < 10)
    {
        al_draw_bitmap_region(explosao, explosao_tamanho[0][2], explosao_tamanho[0][3], explosao_tamanho[0][0], explosao_tamanho[0][1], struct_tiro[i].x, struct_tiro[i].y, 0);
    }
    else if(struct_tiro[i].timerExplosao < 20)
    {
        al_draw_bitmap_region(explosao, explosao_tamanho[1][2], explosao_tamanho[1][3], explosao_tamanho[1][0], explosao_tamanho[1][1], struct_tiro[i].x, struct_tiro[i].y, 0);
    }
    else if(struct_tiro[i].timerExplosao < 30)
    {
        al_draw_bitmap_region(explosao, explosao_tamanho[2][2], explosao_tamanho[1][3], explosao_tamanho[1][0], explosao_tamanho[2][1], struct_tiro[i].x, struct_tiro[i].y, 0);
    }
    else if(struct_tiro[i].timerExplosao < 40)
    {
        al_draw_bitmap_region(explosao, explosao_tamanho[3][2], explosao_tamanho[1][3], explosao_tamanho[1][0], explosao_tamanho[3][1], struct_tiro[i].x, struct_tiro[i].y, 0);
    }
    else if(struct_tiro[i].timerExplosao < 50)
    {
        al_draw_bitmap_region(explosao, explosao_tamanho[4][2], explosao_tamanho[1][3], explosao_tamanho[1][0], explosao_tamanho[4][1], struct_tiro[i].x, struct_tiro[i].y, 0);
    }
    else if(struct_tiro[i].timerExplosao < 60)
    {
        al_draw_bitmap_region(explosao, explosao_tamanho[5][2], explosao_tamanho[1][3], explosao_tamanho[1][0], explosao_tamanho[5][1], struct_tiro[i].x, struct_tiro[i].y, 0);
    }
    else if(struct_tiro[i].timerExplosao < 70)
    {
        al_draw_bitmap_region(explosao, explosao_tamanho[6][2], explosao_tamanho[1][3], explosao_tamanho[1][0], explosao_tamanho[6][1], struct_tiro[i].x, struct_tiro[i].y, 0);
    }
    else if(struct_tiro[i].timerExplosao < 80)
    {
        al_draw_bitmap_region(explosao, explosao_tamanho[7][2], explosao_tamanho[1][3], explosao_tamanho[1][0], explosao_tamanho[7][1], struct_tiro[i].x, struct_tiro[i].y, 0);
        limpaTiro(i);
    }
    struct_tiro[i].timerExplosao++;
}

void limpaTiro(int i)
{
    struct_tiro[i].timerExplosao = 0;
    struct_tiro[i].ativado = false;
    struct_tiro[i].colisao = false;
    struct_tiro[i].tipo = 0;
    struct_tiro[i].x = 0;
    struct_tiro[i].y = 0;
    struct_tiro[i].x_inicial = 0;
    struct_tiro[i].y_inicial = 0;
    struct_tiro[i].largura = 0;
    struct_tiro[i].altura = 0;
    struct_tiro[i].offset_x = 0;
    struct_tiro[i].velocidade = velocidadeTiroSimples;
}

void teclasTiro(int tecla, int tipoEvento)
{
    if(tipoEvento == 1)
    {
        switch(tecla) {
			//se a tecla for o W
			case ALLEGRO_KEY_SPACE:
				tiroTecla = true;
			break;

		}
    }
    /*
    else if(tipoEvento == 2)
    {
        //verifica qual tecla foi
		switch(tecla) {
			//se a tecla for o W
			case ALLEGRO_KEY_SPACE:
				tiroTecla = false;
			break;
		}
    }
    */
}

void finalizaTiro()
{
    al_destroy_bitmap(tiros);
}

void finalizaExplosao()
{
    al_destroy_bitmap(explosao);
}