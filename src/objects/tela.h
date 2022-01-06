void redesenhaTela();
void redesenhaBackground();

void redesenhaTela()
{
    // limpa a tela com a cor preta
    al_clear_to_color(al_map_rgb(0, 0, 0));

    // redesenha objetos
    redesenhaBackground();
    redesenhaNave();
    redesenhaAsteroids();
    redesenhaTiro();
}

void redesenhaBackground()
{
    al_draw_bitmap(background, 0, 0, 0);
    al_draw_bitmap(background_2, 0, 0, 0);
    al_draw_bitmap(background_3, 0, 0, 0);
    al_draw_bitmap(background_4, 0, 0, 0);
    al_draw_bitmap(background_5, 0, 0, 0);
    al_draw_bitmap(background_6, 0, 0, 0);
    al_draw_bitmap(background_7, 0, 0, 0);
}