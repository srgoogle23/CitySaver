void iniciaBloco();
void finalizaBloco();

struct Bloco {
    ALLEGRO_BITMAP *bloco;
    double x;
    double y;
    double largura;
    double altura;
    double velocidade;
    bool status;
    int maxTentativas;
    int tentativas;
	int tempoTentativas;
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
    bloco.status = true;
    bloco.maxTentativas = 10;
    bloco.tentativas = 0;
    bloco.tempoTentativas = 0;
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

void finalizaBloco()
{
    al_destroy_bitmap(bloco.bloco);
}