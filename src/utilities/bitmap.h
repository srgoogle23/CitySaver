ALLEGRO_BITMAP *load_bitmap_at_size(const char *filename, int w, int h);

ALLEGRO_BITMAP *load_bitmap_at_size(const char *filename, int w, int h)
{
	ALLEGRO_BITMAP *resized_bmp, *loaded_bmp, *prev_target;

	// 1. crie um bitmap temporário do tamanho que queremos
	resized_bmp = al_create_bitmap(w, h);
	if (!resized_bmp) return NULL;

	// 2. carregue o bitmap no tamanho original
	loaded_bmp = al_load_bitmap(filename);
	if (!loaded_bmp)
	{
		al_destroy_bitmap(resized_bmp);
		return NULL;
	}

	// 3. defina o bitmap de destino para o bmp redimensionado
	prev_target = al_get_target_bitmap();
	al_set_target_bitmap(resized_bmp);

	// 4. copie o bitmap carregado para o bmp redimensionado
	al_draw_scaled_bitmap(loaded_bmp,
		0, 0,                                // origem da fonte
		al_get_bitmap_width(loaded_bmp),     // largura da fonte
		al_get_bitmap_height(loaded_bmp),    // altura da fonte
		0, 0,                                // origem do alvo
		w, h,                                // dimensões de destino
		0                                    // flags
	);

	// 5. restaure o destino anterior e limpe
	al_set_target_bitmap(prev_target);
	al_destroy_bitmap(loaded_bmp); 

	return resized_bmp;      
}