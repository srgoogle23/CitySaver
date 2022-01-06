void disparaTiro();
void finalizaTiro();
void teclasTiro(int tecla, int tipoEvento);
void calculaMovimentoTiro();
void redesenhaTiro();

struct Tiro {
    bool ativado;
    int tipo;
	int x;
	int y;
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
        struct_tiro[filaTiros-1].largura = tiros_tamanho[struct_tiro[filaTiros - 1].tipo][0];
        struct_tiro[filaTiros-1].altura = tiros_tamanho[struct_tiro[filaTiros-1].tipo][1];
        struct_tiro[filaTiros-1].offset_x = tiros_tamanho[struct_tiro[filaTiros-1].tipo][2];

        al_draw_bitmap_region(tiros, struct_tiro[filaTiros-1].offset_x, 0, struct_tiro[filaTiros-1].largura, struct_tiro[filaTiros-1].altura, struct_tiro[filaTiros-1].x, struct_tiro[filaTiros-1].y, 0);
    }
    printf("filaTiros: %d\n", filaTiros);
}

void calculaMovimentoTiro()
{
    for (int i = 0; i < quantidadeTiros; i++)
    {
        if (struct_tiro[i].ativado == true)
        {
            struct_tiro[i].x += struct_tiro[i].velocidade;
        }
    }
}

void redesenhaTiro()
{
    if(tiroTecla)
    {
        tiroTecla = false;
        disparaTiro();
    }

    for (int i = 0; i < quantidadeTiros; i++)
    {
        if (struct_tiro[i].ativado == true)
        {
            struct_tiro[i].x += struct_tiro[i].velocidade;
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