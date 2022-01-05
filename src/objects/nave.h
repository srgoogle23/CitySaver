
void desenhaNave();
void finalizaNave();

void desenhaNave()
{
    al_draw_bitmap_region(nave, 0, 0, 100, 100, 470, 225, 0);
}

void finalizaNave()
{
    al_destroy_bitmap(nave); 
}