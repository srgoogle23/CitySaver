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
            int numero_digitos_pontos = (pontuacao == 0) ? 1 : log10(pontuacao) + 1;
            int numero_digitos_recorde = (recorde == 0) ? 1 : log10(recorde) + 1;

            char p[numero_digitos_pontos];
            char r[numero_digitos_recorde];
            itoa(pontuacao, p, 10);
            itoa(recorde, r, 10);

            // mantém a tela escurecida
            al_draw_filled_rectangle(0, 0, SCREEN_W, SCREEN_H, al_map_rgba(1, 1, 1, 200));

            // desenha o game over
            al_draw_text(fonte2_64, al_map_rgba(255, 255, 255, 1), SCREEN_W / 2, 2 * SCREEN_H / 8, ALLEGRO_ALIGN_CENTRE, game_over_texto);
        
            // se o jogador bateu o recorde
            if(bateu_recorde)
            {
                // parabeniza o jogador pelo recorde
                al_draw_text(fonte2_24, al_map_rgba(255, 255, 255, 1), SCREEN_W / 2, 3.5 * SCREEN_H / 8, ALLEGRO_ALIGN_CENTRE, bateu_recorde_game_over_texto);
            }

            // desenha a pontuação
            al_draw_text(fonte2_24, al_map_rgba(255, 255, 255, 1), SCREEN_W / 2, 4.5 * SCREEN_H / 8, ALLEGRO_ALIGN_CENTRE, concat(pontuacao_game_over_texto, p));
            
            // desenha o recorde
            al_draw_text(fonte2_24, al_map_rgba(255, 255, 255, 1), SCREEN_W / 2, 5 * SCREEN_H / 8, ALLEGRO_ALIGN_CENTRE, concat(recorde_game_over_texto, r));
            
            
        }

    }
}

void escurecerTela()
{
    al_draw_filled_rectangle(0, 0, SCREEN_W, SCREEN_H, al_map_rgba(1, 1, 1, animacaoColisao * 1.4286));
}