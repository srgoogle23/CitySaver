void redesenhaTela();
void redesenhaNave();
void redesenhaBackground();

void redesenhaTela()
{
    // limpa a tela com a cor preta
    al_clear_to_color(al_map_rgb(0, 0, 0));

    // redesenha objetos
    redesenhaBackground();
    redesenhaNave();
}

void redesenhaNave()
{
    calculaMovimentoNave();
    al_draw_bitmap_region(nave, 0, 0, 100, 100, nave_dx, nave_dy, 0);
}

void redesenhaBackground()
{
    al_draw_bitmap(background, 0, 0, 0);
}