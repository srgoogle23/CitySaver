void disparaTiro();
void finalizaTiro();
void teclasTiro(int tecla, int tipoEvento);
void calculaMovimentoTiro();
void redesenhaTiro();
void mudaAnimacaoTiro(int i);
void verificaSeOTiroEstaNaTela(int i);
int verificaSeTodosOsTirosEstaoDesativados();
void limpaTiros();

struct Tiro {
    bool ativado;
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
        struct_tiro[i].ativado = false;
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

        struct_tiro[filaTiros-1].ativado = true;
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

    printf("filaTiros: %d\n", filaTiros);
}

void calculaMovimentoTiro()
{
    for (int i = 0; i < quantidadeTiros; i++)
    {
        verificaSeOTiroEstaNaTela(i);
        if (struct_tiro[i].ativado == true)
        {
            mudaAnimacaoTiro(i);
            struct_tiro[i].x += struct_tiro[i].velocidade;
            struct_tiro[i].largura = tiros_tamanho[struct_tiro[i].tipo][0];
            struct_tiro[i].altura = tiros_tamanho[struct_tiro[i].tipo][1];
            struct_tiro[i].offset_x = tiros_tamanho[struct_tiro[i].tipo][2];
        }
    }
}

void limpaTiros()
{
    for (int i = 0; i < quantidadeTiros; i++)
    {
        struct_tiro[i].ativado = false;
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
    if(tiroTecla)
    {
        tiroTecla = false;
        disparaTiro();
    }

    calculaMovimentoTiro();

    for (int i = 0; i < quantidadeTiros; i++)
    {
        if (struct_tiro[i].ativado == true)
        {
            al_draw_bitmap_region(tiros, struct_tiro[i].offset_x, 0, struct_tiro[i].largura, struct_tiro[i].altura, struct_tiro[i].x, struct_tiro[i].y, 0);
        }
    }
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