
void redesenhaExplosaoAsteroides();
void iniciarExplosoes();
void criaExplosao(double x, double y);
void limpaExplosao(int indice);

struct Explosao {
    bool status;
    double x;
	double y;
    double animacao;
};

struct Explosao explosao_struct[100];

void iniciarExplosoes()
{
    for (int i = 0; i < 100; i++)
    {
        explosao_struct[i].status = false;
        explosao_struct[i].x = 0.0;
        explosao_struct[i].y = 0.0;
        explosao_struct[i].animacao = 0.0;
    }
}

void criaExplosao(double x, double y)
{
    for (int i = 0; i < 100; i++)
    {
        if (explosao_struct[i].status == false)
        {
            explosao_struct[i].status = true;
            explosao_struct[i].x = x;
            explosao_struct[i].y = y;
            explosao_struct[i].animacao = 0.0;
            break;
        }
    }
}

void limpaExplosao(int indice)
{
    explosao_struct[indice].status = false;
    explosao_struct[indice].x = 0.0;
    explosao_struct[indice].y = 0.0;
    explosao_struct[indice].animacao = 0.0;
}

void redesenhaExplosaoAsteroides()
{
    for (int i = 0; i < 100; i++)
    {
        if (explosao_struct[i].status == true)
        {
            if(explosao_struct[i].animacao == 0)
            {
                // reproduz som de explosao
                al_play_sample(som_explosao, 1.0, 0.0, 1.8, ALLEGRO_PLAYMODE_ONCE, NULL);
            }
            else if(explosao_struct[i].animacao < 5)
            {
                al_draw_bitmap_region(explosao, explosao_tamanho[0][2], explosao_tamanho[0][3], explosao_tamanho[0][0], explosao_tamanho[0][1], explosao_struct[i].x, explosao_struct[i].y, 0);
            }
            else if(explosao_struct[i].animacao < 10)
            {
                al_draw_bitmap_region(explosao, explosao_tamanho[1][2], explosao_tamanho[1][3], explosao_tamanho[1][0], explosao_tamanho[1][1], explosao_struct[i].x, explosao_struct[i].y, 0);
            }
            else if(explosao_struct[i].animacao < 15)
            {
                al_draw_bitmap_region(explosao, explosao_tamanho[2][2], explosao_tamanho[2][3], explosao_tamanho[2][0], explosao_tamanho[2][1], explosao_struct[i].x, explosao_struct[i].y, 0);
            }
            else if(explosao_struct[i].animacao < 20)
            {
                al_draw_bitmap_region(explosao, explosao_tamanho[3][2], explosao_tamanho[3][3], explosao_tamanho[3][0], explosao_tamanho[3][1], explosao_struct[i].x, explosao_struct[i].y, 0);
            }
            else if(explosao_struct[i].animacao < 25)
            {
                al_draw_bitmap_region(explosao, explosao_tamanho[4][2], explosao_tamanho[4][3], explosao_tamanho[4][0], explosao_tamanho[4][1], explosao_struct[i].x, explosao_struct[i].y, 0);
            }
            else if(explosao_struct[i].animacao < 30)
            {
                al_draw_bitmap_region(explosao, explosao_tamanho[5][2], explosao_tamanho[5][3], explosao_tamanho[5][0], explosao_tamanho[5][1], explosao_struct[i].x, explosao_struct[i].y, 0);
            }
            else if(explosao_struct[i].animacao < 35)
            {
                al_draw_bitmap_region(explosao, explosao_tamanho[6][2], explosao_tamanho[6][3], explosao_tamanho[6][0], explosao_tamanho[6][1], explosao_struct[i].x, explosao_struct[i].y, 0);
            }
            else if(explosao_struct[i].animacao < 40)
            {
                al_draw_bitmap_region(explosao, explosao_tamanho[7][2], explosao_tamanho[7][3], explosao_tamanho[7][0], explosao_tamanho[7][1], explosao_struct[i].x, explosao_struct[i].y, 0);
                limpaExplosao(i);
            }
            explosao_struct[i].animacao++;
        }
    }
}