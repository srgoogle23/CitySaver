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
void animacaoTiroIniciando();

struct Tiro {
    bool ativado;
    bool colisao;
    int timerExplosao;
    int categoriaTiro;
    int timerTiro;
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
        struct_tiro[i].categoriaTiro = 0;
        struct_tiro[i].timerTiro = 0;
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

        // se o tiro for um tiro simples
        if(duracao_tiro < duracao_tiro_avancado)
        {
            struct_tiro[filaTiros-1].timerExplosao = 0;
            struct_tiro[filaTiros-1].ativado = true;
            struct_tiro[filaTiros-1].colisao = false;
            struct_tiro[filaTiros-1].categoriaTiro = 0;
            struct_tiro[filaTiros-1].timerTiro = 0;
            struct_tiro[filaTiros-1].tipo = 0;
            struct_tiro[filaTiros-1].x = nave_dx + 50;
            struct_tiro[filaTiros-1].y = nave_dy + 40;
            struct_tiro[filaTiros-1].x_inicial = struct_tiro[filaTiros-1].x;
            struct_tiro[filaTiros-1].y_inicial = struct_tiro[filaTiros-1].y;
            struct_tiro[filaTiros-1].largura = tiros_tamanho[struct_tiro[filaTiros - 1].tipo][0];
            struct_tiro[filaTiros-1].altura = tiros_tamanho[struct_tiro[filaTiros-1].tipo][1];
            struct_tiro[filaTiros-1].offset_x = tiros_tamanho[struct_tiro[filaTiros-1].tipo][2];

            al_draw_bitmap_region(tiros, struct_tiro[filaTiros-1].offset_x, 0, struct_tiro[filaTiros-1].largura, struct_tiro[filaTiros-1].altura, struct_tiro[filaTiros-1].x, struct_tiro[filaTiros-1].y, 0);
            
            tiroTecla = false; // como o tiro é simples, desativa a tecla de tiro para permitir apenas um tiro por aperto de tecla
        }
        else
        {
            duracao_tiro = 0;
            tiroTecla = false;
            
            struct_tiro[filaTiros-1].timerExplosao = 0;
            struct_tiro[filaTiros-1].ativado = true;
            struct_tiro[filaTiros-1].colisao = false;
            struct_tiro[filaTiros-1].categoriaTiro = 1;
            struct_tiro[filaTiros-1].timerTiro = 0;
            struct_tiro[filaTiros-1].tipo = 0;
            struct_tiro[filaTiros-1].x = nave_dx + 50;
            struct_tiro[filaTiros-1].y = nave_dy + 20;
            struct_tiro[filaTiros-1].x_inicial = struct_tiro[filaTiros-1].x;
            struct_tiro[filaTiros-1].y_inicial = struct_tiro[filaTiros-1].y;
            struct_tiro[filaTiros-1].largura = tiros_avancados_tamanho[struct_tiro[filaTiros - 1].tipo][0];
            struct_tiro[filaTiros-1].altura = tiros_avancados_tamanho[struct_tiro[filaTiros-1].tipo][1];
            struct_tiro[filaTiros-1].offset_x = tiros_avancados_tamanho[struct_tiro[filaTiros-1].tipo][2];

            al_draw_bitmap_region(tiro_avancado, struct_tiro[filaTiros-1].offset_x, 0, struct_tiro[filaTiros-1].largura, struct_tiro[filaTiros-1].altura, struct_tiro[filaTiros-1].x, struct_tiro[filaTiros-1].y, 0);
        }
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

            if(struct_tiro[i].categoriaTiro == 0)
            {
                struct_tiro[i].largura = tiros_tamanho[struct_tiro[i].tipo][0];
                struct_tiro[i].altura = tiros_tamanho[struct_tiro[i].tipo][1];
                struct_tiro[i].offset_x = tiros_tamanho[struct_tiro[i].tipo][2];
            }
            else if(struct_tiro[i].categoriaTiro == 1)
            {
                struct_tiro[i].largura = tiros_avancados_tamanho[struct_tiro[i].tipo][0];
                struct_tiro[i].altura = tiros_avancados_tamanho[struct_tiro[i].tipo][1];
                struct_tiro[i].offset_x = tiros_avancados_tamanho[struct_tiro[i].tipo][2];
            }

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
        struct_tiro[i].categoriaTiro = 0;
        struct_tiro[i].timerTiro = 0;
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
    if(struct_tiro[i].categoriaTiro == 0)
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
    else if(struct_tiro[i].categoriaTiro == 1)
    {
        if(struct_tiro[i].timerTiro < 10)
        {
            struct_tiro[i].tipo = 0;
        }
        else if(struct_tiro[i].timerTiro < 20)
        {
            struct_tiro[i].tipo = 1;
        }
        else if(struct_tiro[i].timerTiro < 30)
        {
            struct_tiro[i].tipo = 2;
        }
        else if(struct_tiro[i].timerTiro < 40)
        {
            struct_tiro[i].tipo = 3;
        }
        else
        {
            struct_tiro[i].timerTiro = 0;
        }
        struct_tiro[i].timerTiro++;
    }
}

void redesenhaTiro()
{
    animacaoTiroIniciando();
    
    if (tiroTecla)
    {
        disparaTiro();
    }

    calculaMovimentoTiro();

    for (int i = 0; i < quantidadeTiros; i++)
    {
        if (struct_tiro[i].ativado == true && struct_tiro[i].colisao == false)
        { 
            if(struct_tiro[i].categoriaTiro == 0)
            {
                al_draw_bitmap_region(tiros, struct_tiro[i].offset_x, 0, struct_tiro[i].largura, struct_tiro[i].altura, struct_tiro[i].x, struct_tiro[i].y, 0);
            }
            else if(struct_tiro[i].categoriaTiro == 1)
            {
                al_draw_bitmap_region(tiro_avancado, struct_tiro[i].offset_x, 0, struct_tiro[i].largura, struct_tiro[i].altura, struct_tiro[i].x, struct_tiro[i].y, 0);
            }
        }
        else if(struct_tiro[i].colisao == true)
        {
            animacaoExplosao(i);
        }
    }
}

void animacaoTiroIniciando()
{
    if (segurando_tecla)
    {
        if(controleCrescimento)
        {
            al_destroy_bitmap(animacaoTiroAvancado);

            int w = animacao_tiros_avancados_tamanho_bmp[0] * controleCrescimentoAnimacaoTiroAvancado;
            int h = animacao_tiros_avancados_tamanho_bmp[1] * controleCrescimentoAnimacaoTiroAvancado;

            animacaoTiroAvancado = load_bitmap_at_size(animacao_tiro_avancado_local, w, h);
            controleCrescimento = false;
        }

        double x_animacao = nave_dx + 80, y_animacao = nave_dy + controlePosicaoCrescimento;
 
        if (filaAnimacaoTiroAvancado < 10)
        {
            int offset_x = animacao_tiros_avancados_tamanho[0][2] * controleCrescimentoAnimacaoTiroAvancado;
            int largura  = animacao_tiros_avancados_tamanho[0][0] * controleCrescimentoAnimacaoTiroAvancado;
            int altura  = animacao_tiros_avancados_tamanho[0][1] * controleCrescimentoAnimacaoTiroAvancado;
            al_draw_bitmap_region(animacaoTiroAvancado, offset_x, 0, largura, altura, x_animacao, y_animacao, 0);
        }
        else if(filaAnimacaoTiroAvancado < 20)
        {
            int offset_x = animacao_tiros_avancados_tamanho[1][2] * controleCrescimentoAnimacaoTiroAvancado;
            int largura = animacao_tiros_avancados_tamanho[1][0] * controleCrescimentoAnimacaoTiroAvancado;
            int altura = animacao_tiros_avancados_tamanho[1][1] * controleCrescimentoAnimacaoTiroAvancado;
            al_draw_bitmap_region(animacaoTiroAvancado, offset_x, 0, largura, altura, x_animacao, y_animacao, 0);
        }
        else if(filaAnimacaoTiroAvancado < 30)
        {
            int offset_x = animacao_tiros_avancados_tamanho[2][2] * controleCrescimentoAnimacaoTiroAvancado;
            int largura = animacao_tiros_avancados_tamanho[2][0] * controleCrescimentoAnimacaoTiroAvancado;
            int altura = animacao_tiros_avancados_tamanho[2][1] * controleCrescimentoAnimacaoTiroAvancado;
            al_draw_bitmap_region(animacaoTiroAvancado, offset_x, 0, largura, altura, x_animacao, y_animacao, 0);
        }
        else if(filaAnimacaoTiroAvancado < 40)
        {
            int offset_x = animacao_tiros_avancados_tamanho[3][2] * controleCrescimentoAnimacaoTiroAvancado;
            int largura = animacao_tiros_avancados_tamanho[3][0] * controleCrescimentoAnimacaoTiroAvancado;
            int altura = animacao_tiros_avancados_tamanho[3][1] * controleCrescimentoAnimacaoTiroAvancado;
            al_draw_bitmap_region(animacaoTiroAvancado, offset_x, 0, largura, altura, x_animacao, y_animacao, 0);
        }
        else
        {
            controleCrescimento = true;
            filaAnimacaoTiroAvancado = 0;

            if(controleCrescimentoAnimacaoTiroAvancado <= 2)
            {
                controleCrescimentoAnimacaoTiroAvancado += 0.5;
                controlePosicaoCrescimento -= 5;
            }
        }
        filaAnimacaoTiroAvancado++;
    }
    else
    {
        controlePosicaoCrescimento = 40;
        controleCrescimentoAnimacaoTiroAvancado = 1;
        filaAnimacaoTiroAvancado = 0;
        controleCrescimento = true;
    }
}

void animacaoExplosao(int i)
{
    if(struct_tiro[i].timerExplosao < 5)
    {
       al_draw_bitmap_region(explosao, explosao_tamanho[0][2], explosao_tamanho[0][3], explosao_tamanho[0][0], explosao_tamanho[0][1], struct_tiro[i].x, struct_tiro[i].y, 0);
    }
    else if(struct_tiro[i].timerExplosao < 10)
    {
        al_draw_bitmap_region(explosao, explosao_tamanho[1][2], explosao_tamanho[1][3], explosao_tamanho[1][0], explosao_tamanho[1][1], struct_tiro[i].x, struct_tiro[i].y, 0);
    }
    else if(struct_tiro[i].timerExplosao < 15)
    {
        al_draw_bitmap_region(explosao, explosao_tamanho[2][2], explosao_tamanho[2][3], explosao_tamanho[2][0], explosao_tamanho[2][1], struct_tiro[i].x, struct_tiro[i].y, 0);
    }
    else if(struct_tiro[i].timerExplosao < 20)
    {
        al_draw_bitmap_region(explosao, explosao_tamanho[3][2], explosao_tamanho[3][3], explosao_tamanho[3][0], explosao_tamanho[3][1], struct_tiro[i].x, struct_tiro[i].y, 0);
    }
    else if(struct_tiro[i].timerExplosao < 25)
    {
        al_draw_bitmap_region(explosao, explosao_tamanho[4][2], explosao_tamanho[4][3], explosao_tamanho[4][0], explosao_tamanho[4][1], struct_tiro[i].x, struct_tiro[i].y, 0);
    }
    else if(struct_tiro[i].timerExplosao < 30)
    {
        al_draw_bitmap_region(explosao, explosao_tamanho[5][2], explosao_tamanho[5][3], explosao_tamanho[5][0], explosao_tamanho[5][1], struct_tiro[i].x, struct_tiro[i].y, 0);
    }
    else if(struct_tiro[i].timerExplosao < 35)
    {
        al_draw_bitmap_region(explosao, explosao_tamanho[6][2], explosao_tamanho[6][3], explosao_tamanho[6][0], explosao_tamanho[6][1], struct_tiro[i].x, struct_tiro[i].y, 0);
    }
    else if(struct_tiro[i].timerExplosao < 40)
    {
        al_draw_bitmap_region(explosao, explosao_tamanho[7][2], explosao_tamanho[7][3], explosao_tamanho[7][0], explosao_tamanho[7][1], struct_tiro[i].x, struct_tiro[i].y, 0);
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
    struct_tiro[i].categoriaTiro = 0;
    struct_tiro[i].timerTiro = 0;
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
                inicio_tiro = al_get_time ();
                segurando_tecla = true;
			break;

		}
    }
    else if(tipoEvento == 2)
    {
        //verifica qual tecla foi
		switch(tecla) {
			//se a tecla for o W
			case ALLEGRO_KEY_SPACE:
                duracao_tiro = al_get_time() - inicio_tiro;
				tiroTecla = true;
                segurando_tecla = false;
            break;
		}
    }
}

void finalizaTiro()
{
    al_destroy_bitmap(tiros);
    al_destroy_bitmap(animacaoTiroAvancado);
    al_destroy_bitmap(tiro_avancado);
}

void finalizaExplosao()
{
    al_destroy_bitmap(explosao);
}