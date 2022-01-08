
void redesenhaBackground();
void finalizaBackground();
void iniciarBackground();
void calculaBackground();
void defineVelocidadeBaseadoNoTipo();

struct Background {
    ALLEGRO_BITMAP* background;
    ALLEGRO_BITMAP* background_2;
	int tipo;
    float x;
	float y;
    float dx;
	float dy;
	float velocidade;
};

struct Background background[quantidadeBackground];

void iniciarBackground()
{
    // incia a quantidade exata de imagens de background
    for (int i = 0; i < quantidadeBackground; i++)
    {
        background[i].background = load_bitmap_at_size(background_local[i], SCREEN_W, SCREEN_H);
        background[i].background_2 = load_bitmap_at_size(background_local[i], SCREEN_W, SCREEN_H);
        background[i].tipo = i + 1;
        background[i].x = 0;
        background[i].y = 0;
        background[i].dx = SCREEN_W;
        background[i].dy = 0;
        background[i].velocidade = 0;
    }
    
    defineVelocidadeBaseadoNoTipo();
}

void defineVelocidadeBaseadoNoTipo()
{
    for (int i = 0; i < quantidadeBackground; i++)
    {
        switch (background[i].tipo)
        {
            case 1:
                background[i].velocidade = 0;
                break;
            case 2:
                background[i].velocidade = -1;
                break;
            case 3:
                background[i].velocidade = -2.5;
                break;
            case 4:
                background[i].velocidade = -3;
                break;
            case 5:
                background[i].velocidade = -4;
                break;
            case 6:
                background[i].velocidade = -4.5;
                break;
            case 7:
                background[i].velocidade = -5;
                break;
        }
    }
}

void calculaBackground()
{
    for (int i = 0; i < quantidadeBackground; i++)
    {
        background[i].x += background[i].velocidade;
        background[i].dx += background[i].velocidade;

        if (background[i].x < -SCREEN_W)
        {
            background[i].x = 0;
        }

        if (background[i].dx < 0)
        {
            background[i].dx = SCREEN_W;
        }
    }
}

void redesenhaBackground()
{
    calculaBackground();

    for (int i = 0; i < quantidadeBackground; i++)
    {
        al_draw_bitmap(background[i].background, background[i].x, background[i].y, 0);
        al_draw_bitmap(background[i].background_2, background[i].dx, background[i].dy, 0);
    }
}

void finalizaBackground()
{
    for (int i = 0; i < quantidadeBackground; i++)
    {
        al_destroy_bitmap(background[i].background);
        al_destroy_bitmap(background[i].background_2);
    }
}