void iniciaBloco();
void finalizaBloco();
void redesenhaBloco();
void calculaMovimentoBloco();
void reiniciaBloco();

struct Bloco {
    ALLEGRO_BITMAP *bloco;
    double x;
    double y;
    double largura;
    double altura;
    double velocidade;
};

struct Bloco bloco;

void iniciaBloco()
{
    // incia definições dos blocos
    blocoAlturaMin = SCREEN_H / 5; // blocos devem ocupar pelo menos um quinto da altura da tela
    blocoAlturaMax = (SCREEN_H / 5 ) * 4; // blocos devem ocupar no máximo quatro quintos da altura da tela
    blocoLarguraMin = SCREEN_W; // blocos devem ocupar pelo menos uma largura da tela
    blocoLarguraMax = SCREEN_W * 2; // blocos devem ocupar no máximo duas larguras da tela

    // inicia bloco
    bloco.largura = randDoubleMinMax(blocoLarguraMin, blocoLarguraMax);
    bloco.altura = randDoubleMinMax(blocoAlturaMin, blocoAlturaMax);
    bloco.velocidade = randDoubleMinMax(1, 3);
    bloco.x = SCREEN_W;
    bloco.y = randDoubleMinMax(0, SCREEN_H - bloco.altura);
    bloco.bloco = al_create_bitmap(bloco.largura, bloco.altura);

    al_set_target_bitmap(bloco.bloco);
    al_clear_to_color(al_map_rgb(rand()%256, rand()%256, rand()%256));
    al_set_target_bitmap(al_get_backbuffer(display));
}

void reiniciaBloco()
{
    bloco.largura = randDoubleMinMax(blocoLarguraMin, blocoLarguraMax);
    bloco.altura = randDoubleMinMax(blocoAlturaMin, blocoAlturaMax);
    bloco.velocidade = randDoubleMinMax(1, 3);
    bloco.x = SCREEN_W;
    bloco.y = randDoubleMinMax(0, SCREEN_H - bloco.altura);
    bloco.bloco = al_create_bitmap(bloco.largura, bloco.altura);

    al_set_target_bitmap(bloco.bloco);
    al_clear_to_color(al_map_rgb(rand()%256, rand()%256, rand()%256));
    al_set_target_bitmap(al_get_backbuffer(display));
}

void calculaMovimentoBloco()
{
    // movimenta o bloco
    bloco.x -= bloco.velocidade;

    // verifica se o bloco ja saiu da tela
    if ((-1 * bloco.largura) > bloco.x)
    {
        reiniciaBloco();
    }    
}

void redesenhaBloco()
{
    calculaMovimentoBloco();

    al_draw_bitmap(bloco.bloco, bloco.x, bloco.y, 0);
}

void finalizaBloco()
{
    al_destroy_bitmap(bloco.bloco);
}