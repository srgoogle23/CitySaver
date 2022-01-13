void escurecerTela();
void desenhaGameOver();
void desenhaTelaEscurecida();
void desenhaTextosGameOver();
void denhaMenuGameOver();
void animacaoPalavraMenu();
void animacaoPalavraReiniciar();
void desenhaPalavraMenu();
void desenhaPalavraReiniciar();

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
            // mantém a tela escurecida
            desenhaTelaEscurecida();

            // desenha o game over
            desenhaTextosGameOver();  

            // desenha menu de opções no game over
            denhaMenuGameOver();
        }
    }
}

void denhaMenuGameOver()
{
    if(menu_game_over[0])
    {
        animacaoPalavraMenu();
        desenhaPalavraReiniciar();
    }
    else if(menu_game_over[1])
    {
        animacaoPalavraReiniciar();
        desenhaPalavraMenu();
    }
}

void teclasGameOver(int tecla, int tipoEvento)
{
    if(tipoEvento == 1)
    {
        switch(tecla) {
			//se a tecla for o W ou a seta para cima, ou S ou para baixo, troca para a opção
			case ALLEGRO_KEY_W:
                if(menu_game_over[0] == true)
                {
                    menu_game_over[0] = false;
                    menu_game_over[1] = true;
                }
                else
                {
                    menu_game_over[0] = true;
                    menu_game_over[1] = false;
                }
			break;
            case ALLEGRO_KEY_UP:
                if(menu_game_over[0] == true)
                {
                    menu_game_over[0] = false;
                    menu_game_over[1] = true;
                }
                else
                {
                    menu_game_over[0] = true;
                    menu_game_over[1] = false;
                }
			break;
            case ALLEGRO_KEY_S:
                if(menu_game_over[0] == true)
                {
                    menu_game_over[0] = false;
                    menu_game_over[1] = true;
                }
                else
                {
                    menu_game_over[0] = true;
                    menu_game_over[1] = false;
                }
			break;
            case ALLEGRO_KEY_DOWN:
                if(menu_game_over[0] == true)
                {
                    menu_game_over[0] = false;
                    menu_game_over[1] = true;
                }
                else
                {
                    menu_game_over[0] = true;
                    menu_game_over[1] = false;
                }
			break;
		}
    }
}

void desenhaPalavraMenu()
{
    al_draw_text(fonte3_24, al_map_rgba(255, 255, 255, 1), SCREEN_W / 2, 6 * SCREEN_H / 8, ALLEGRO_ALIGN_CENTRE, menu_texto);
}

void desenhaPalavraReiniciar()
{
    al_draw_text(fonte3_24, al_map_rgba(255, 255, 255, 1), SCREEN_W / 2, 6.5 * SCREEN_H / 8, ALLEGRO_ALIGN_CENTRE, reiniciar_texto);
}

void animacaoPalavraReiniciar()
{
    double tpm = 0.00;

    if(reiniciar_texto_animacao <= 1)
    {
        tpm = reiniciar_texto_animacao;
        al_draw_text(fonte3_24, al_map_rgba(255 * tpm, 255 * tpm, 255 * tpm, tpm), SCREEN_W / 2, 6.5 * SCREEN_H / 8, ALLEGRO_ALIGN_CENTRE, reiniciar_texto);
        reiniciar_texto_animacao += 0.02;
    }
    else if(reiniciar_texto_animacao <= 2)
    {
        tpm = 1 - (reiniciar_texto_animacao - 1);
        al_draw_text(fonte3_26, al_map_rgba(255 * tpm, 255 * tpm, 255 * tpm, tpm), SCREEN_W / 2, 6.5 * SCREEN_H / 8, ALLEGRO_ALIGN_CENTRE, reiniciar_texto);
        reiniciar_texto_animacao += 0.02;
    }
    else
    {
        reiniciar_texto_animacao = 0;
    }
}

void animacaoPalavraMenu()
{
    double tpm = 0.00;

    if(menu_texto_animacao <= 1)
    {
        tpm = menu_texto_animacao;
        al_draw_text(fonte3_24, al_map_rgba(255 * tpm, 255 * tpm, 255 * tpm, tpm), SCREEN_W / 2, 6 * SCREEN_H / 8, ALLEGRO_ALIGN_CENTRE, menu_texto);
        menu_texto_animacao += 0.02;
    }
    else if(menu_texto_animacao <= 2)
    {
        tpm = 1 - (menu_texto_animacao - 1);
        al_draw_text(fonte3_26, al_map_rgba(255 * tpm, 255 * tpm, 255 * tpm, tpm), SCREEN_W / 2, 6 * SCREEN_H / 8, ALLEGRO_ALIGN_CENTRE, menu_texto);
        menu_texto_animacao += 0.02;
    }
    else
    {
        menu_texto_animacao = 0;
    }
}

void desenhaTextosGameOver()
{
    int numero_digitos_pontos = (pontuacao == 0) ? 1 : log10(pontuacao) + 1;
    int numero_digitos_recorde = (recorde == 0) ? 1 : log10(recorde) + 1;

    char p[numero_digitos_pontos];
    char r[numero_digitos_recorde];
    itoa(pontuacao, p, 10);
    itoa(recorde, r, 10);

    al_draw_text(fonte2_64, al_map_rgba(255, 255, 255, 1), SCREEN_W / 2, 1 * SCREEN_H / 8, ALLEGRO_ALIGN_CENTRE, game_over_texto);
        
    // se o jogador bateu o recorde
    if(bateu_recorde)
    {
        // parabeniza o jogador pelo recorde
        al_draw_text(fonte2_24, al_map_rgba(255, 255, 255, 1), SCREEN_W / 2, 2.5 * SCREEN_H / 8, ALLEGRO_ALIGN_CENTRE, bateu_recorde_game_over_texto);
    }

    // desenha a pontuação
    al_draw_text(fonte2_24, al_map_rgba(255, 255, 255, 1), SCREEN_W / 2, 3.5 * SCREEN_H / 8, ALLEGRO_ALIGN_CENTRE, concat(pontuacao_game_over_texto, p));
    
    // desenha o recorde
    al_draw_text(fonte2_24, al_map_rgba(255, 255, 255, 1), SCREEN_W / 2, 4 * SCREEN_H / 8, ALLEGRO_ALIGN_CENTRE, concat(recorde_game_over_texto, r));
}

void desenhaTelaEscurecida()
{
     al_draw_filled_rectangle(0, 0, SCREEN_W, SCREEN_H, al_map_rgba(1, 1, 1, 200));
}

void escurecerTela()
{
    al_draw_filled_rectangle(0, 0, SCREEN_W, SCREEN_H, al_map_rgba(1, 1, 1, animacaoColisao * 1.4286));
}