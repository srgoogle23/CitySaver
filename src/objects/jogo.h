void reiniciarJogo();

void reiniciarJogo()
{
    // reinicia o jogo
    estaNoTimePosReinicial = true;
    gameOverReinicia = al_get_time();

    // desativa toda a movimentação da nave
    move_up = false;
    move_down = false;
    move_left = false;
    move_right = false;

    // retira a nave do modo de colisao
    colisao = false;
    animacaoColisao = 0;

    // reinicia os asteroides
    for (int i = 0; i < quantidadeArteroids; i++)
	{
        asteroid[i].colisao = true;
        asteroid[i].status = false;
    }

    // reinicia o bloco
    bloco.x = (-2 * bloco.largura);

    // reinicia posicao nave
    nave_dx = inicio_dx_nave;
    nave_dy = (SCREEN_H / 2) - NAVE_W / 2;

    // reiniciar todos os tiros
    limpaTiros();

    // desativa o calculo de tiro
    tiroTecla = false;

    // reinicia pontuacao
    pontuacao = 0;

    // reinicia o game over
    nave_game_over = false;
    menu = false;
}