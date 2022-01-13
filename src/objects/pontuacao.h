void redesenhaPontuacao();
void resetaPontuacao();

void redesenhaPontuacao()
{
    int numero_digitos_pontos = (pontuacao == 0) ? 1 : log10(pontuacao) + 1;
    int numero_digitos_recorde = (recorde == 0) ? 1 : log10(recorde) + 1;

    char p[numero_digitos_pontos];
    char r[numero_digitos_recorde];
    itoa(pontuacao, p, 10);
    itoa(recorde, r, 10);

    al_draw_text(fonte, al_map_rgb(0, 0, 0), 10, 10, 0, concat(concat(pontuacaoTexto, p), concat(recordeTexto, r)));
}

void resetaPontuacao()
{
    if(recorde < pontuacao)
    {
        recorde = pontuacao;
        bateu_recorde = true;
        if(!escreveInteiroArquivo(recorde_arquivo, recorde))
        {
            printf("Erro ao salvar pontuacao no arquivo de recorde\n");
        }  
    }
}