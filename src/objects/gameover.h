void escurecerTela();
void desenhaGameOver();

void desenhaGameOver()
{
    if(nave_game_over)
    {
        // enquanto a animação da nave sendo destruida estiver passando, escurece a tela
        if(animacaoColisao < 140)
        {
            escurecerTela();
        }
        else
        {
            al_draw_filled_rectangle(0, 0, SCREEN_W, SCREEN_H, al_map_rgba(1, 1, 1, 200));
        }

    }
}

void escurecerTela()
{
    al_draw_filled_rectangle(0, 0, SCREEN_W, SCREEN_H, al_map_rgba(1, 1, 1, animacaoColisao * 1.4286));
}