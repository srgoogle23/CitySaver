void redesenhaPontuacao();

void redesenhaPontuacao()
{
    char pontos[10];
    itoa(pontuacao, pontos, 10);
    al_draw_text(fonte, al_map_rgb(0, 0, 0), 10, 10, 0, concat(pontuacaoTexto, pontos));
}