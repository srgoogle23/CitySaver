
void redesenhaBackground();
void finalizaBackground();
void iniciarBackground();
void calculaBackground();
void defineVelocidadeBaseadoNoTipo();

struct Background {
    ALLEGRO_BITMAP* background;
	int tipo;
	int x;
	int y;
	float velocidade;
};

struct Background background[quantidadeBackground];
int qtd_img_background = sizeof(background_local)/sizeof(background_local[0]); // quantidades de imagens de background

void iniciarBackground()
{
    // incia a quantidade exata de imagens de background
    for (int i = 0; i < qtd_img_background; i++)
    {
        background[i].background = load_bitmap_at_size(background_local[i], SCREEN_W, SCREEN_H);
        background[i].tipo = i + 1;
        background[i].x = 0;
        background[i].y = 0;
        background[i].velocidade = 0;
    }
    /*
    // duplica a quantidade de imagens para ajudar na animação
    for (int i = 0; i < quantidadeBackground; i++)
    {
        background[i + (qtd_img_background - 1)].background = load_bitmap_at_size(background_local[i], SCREEN_W, SCREEN_H);
        background[i + (qtd_img_background - 1)].tipo = i + 1;
        background[i + (qtd_img_background - 1)].x = 1000;
        background[i + (qtd_img_background - 1)].y = 1000;
        background[i + (qtd_img_background - 1)].velocidade = 1;
    }
    qtd_img_background *= 2;
    */
    defineVelocidadeBaseadoNoTipo();
}

void defineVelocidadeBaseadoNoTipo()
{
    for (int i = 0; i < qtd_img_background; i++)
    {
        switch (background[i].tipo)
        {
            case 1:
                background[i].velocidade = 0;
                break;
            case 2:
                background[i].velocidade = -2.5;
                break;
            case 3:
                background[i].velocidade = -1;
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
    for (int i = 0; i < qtd_img_background; i++)
    {
        background[i].x += background[i].velocidade;
        background[i].y = 0;
    }
}

void redesenhaBackground()
{
    calculaBackground();

    for (int i = 0; i < qtd_img_background; i++)
    {
        al_draw_bitmap(background[i].background, background[i].x, background[i].y, 0);
    }
}

void finalizaBackground()
{
    for (int i = 0; i < qtd_img_background; i++)
    {
        al_destroy_bitmap(background[i].background);
    }
}