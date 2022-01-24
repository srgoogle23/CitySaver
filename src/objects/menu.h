void desenhaTelaMenu();
void inciarMenu();
void defineVelocidadeImagensMenu(int i);
void finalizaMenu();
void calculaMenu();
void desenhaBackgroundMenuMovendo();
void desenhaNomeDoJogo();
void escureceParcialmenteTelaMenu();
void desenhaMenuOpcoes();
void animacaoIniciarJogo();
void teclasMenu(int tecla, int tipoEvento);

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
    escureceParcialmenteTelaMenu();
    desenhaNomeDoJogo();
    desenhaMenuOpcoes();
}

void desenhaMenuOpcoes()
{
    if(menu_opcoes[0])
    {
        animacaoIniciarJogo();

        if(menu_selecionado)
        {
            menu_selecionado = false;
            reiniciarJogo();
        }
    }
}

void animacaoIniciarJogo()
{
    double tpm = 0.00;

    if(menu_inciar_jogo_animacao <= 1)
    {
        tpm = menu_inciar_jogo_animacao;
        al_draw_text(fonte3_24, al_map_rgba(255 * tpm, 255 * tpm, 255 * tpm, tpm), SCREEN_W / 2, 4 * SCREEN_H / 8, ALLEGRO_ALIGN_CENTRE, inciar_jogo_texto);
        menu_inciar_jogo_animacao += 0.02;
    }
    else if(menu_inciar_jogo_animacao <= 2)
    {
        tpm = 1 - (menu_inciar_jogo_animacao - 1);
        al_draw_text(fonte3_26, al_map_rgba(255 * tpm, 255 * tpm, 255 * tpm, tpm), SCREEN_W / 2, 4 * SCREEN_H / 8, ALLEGRO_ALIGN_CENTRE, inciar_jogo_texto);
        menu_inciar_jogo_animacao += 0.02;
    }
    else
    {
        menu_inciar_jogo_animacao = 0;
    }
}

void escureceParcialmenteTelaMenu()
{
    al_draw_filled_rectangle(0, 0, SCREEN_W, SCREEN_H, al_map_rgba(1, 1, 1, 100));
}

void desenhaNomeDoJogo()
{
    double posicao_x = SCREEN_W / 2;
    double posicao_y = 1 * SCREEN_H / 8;
    al_draw_text(fonte4_71, al_map_rgb(1, 1, 1), posicao_x, posicao_y, ALLEGRO_ALIGN_CENTRE, nome_do_jogo);
    posicao_x -= 1;
    posicao_y -= 2;
    al_draw_text(fonte4_72, al_map_rgba(255, 255, 255, 1), posicao_x, posicao_y, ALLEGRO_ALIGN_CENTRE, nome_do_jogo);
}

void desenhaBackgroundMenuMovendo()
{
    for (int i = 0; i < quantidadeBackground2; i++)
    {
        al_draw_bitmap(background_2[i].background, background_2[i].x, background_2[i].y, 0);
        al_draw_bitmap(background_2[i].background_2, background_2[i].dx, background_2[i].dy, 0);
    } 
}

void teclasMenu(int tecla, int tipoEvento)
{
    if(tipoEvento == 1)
    {
        switch(tecla) {
            // se o usuario selecionou uma opção
            case ALLEGRO_KEY_SPACE:
                menu_selecionado = true;
            break;
            //se a tecla for o W ou a seta para cima, ou S ou para baixo, troca para a opção
			case ALLEGRO_KEY_W:
                menu_opcoes[0] = true;
			break;
            case ALLEGRO_KEY_UP:
                 menu_opcoes[0] = true;
			break;
            case ALLEGRO_KEY_S:
                 menu_opcoes[0] = true;
			break;
            case ALLEGRO_KEY_DOWN:
                 menu_opcoes[0] = true;
			break;
		}
    }
    else if(tipoEvento == 2)
    {
        switch(tecla) {
            // se o usuario selecionou uma opção
            case ALLEGRO_KEY_SPACE:
                menu_selecionado = false;
            break;
        }
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