void desenhaTelaMenu();
void inciarMenu();
void defineVelocidadeImagensMenu(int i);
void finalizaMenu();
void calculaMenu();
void desenhaBackgroundMenuMovendo();

struct Background background_2[quantidadeBackground2];

void inciarMenu()
{
    // incia a quantidade exata de imagens de background
    for (int i = 0; i < quantidadeBackground2; i++)
    {
        background_2[i].background = load_bitmap_at_size(background_2_local[i], SCREEN_W, SCREEN_H);
        background_2[i].background_2 = load_bitmap_at_size(background_2_local[i], SCREEN_W, SCREEN_H);
        background_2[i].tipo = i + 1;
        background_2[i].x = 0;
        background_2[i].y = 0;
        background_2[i].dx = SCREEN_W;
        background_2[i].dy = 0;
        defineVelocidadeImagensMenu(i);
    }

    
}

void defineVelocidadeImagensMenu(int i)
{
    switch (background_2[i].tipo)
    {
        case 1:
            background_2[i].velocidade = -0.1;
            break;
        case 2:
            background_2[i].velocidade = -0.3;
            break;
        case 3:
            background_2[i].velocidade = -0.4;
            break;
        case 4:
            background_2[i].velocidade = -0.5;
            break;
        case 5:
            background_2[i].velocidade = -0.6;
            break;
    }
}

void calculaMenu()
{
    for (int i = 0; i < quantidadeBackground2; i++)
    {
        background_2[i].x += background_2[i].velocidade;
        background_2[i].dx += background_2[i].velocidade;

        if (background_2[i].x < -SCREEN_W)
        {
            background_2[i].x = 0;
        }

        if (background_2[i].dx < 0)
        {
            background_2[i].dx = SCREEN_W;
        }
    }
}

void redesenhaTelaMenu()
{
    calculaMenu();
    desenhaBackgroundMenuMovendo();

}

void desenhaBackgroundMenuMovendo()
{
    for (int i = 0; i < quantidadeBackground2; i++)
    {
        al_draw_bitmap(background_2[i].background, background_2[i].x, background_2[i].y, 0);
        al_draw_bitmap(background_2[i].background_2, background_2[i].dx, background_2[i].dy, 0);
    } 
}

void finalizaMenu()
{
    for (int i = 0; i < quantidadeBackground2; i++)
    {
        al_destroy_bitmap(background_2[i].background);
        al_destroy_bitmap(background_2[i].background_2);
    }
}