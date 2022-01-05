
void iniciaNave();
void finalizaNave();

void iniciaNave()
{
    nave_dy = (SCREEN_H / 2) - NAVE_W / 2;
    al_draw_bitmap_region(nave, 0, 0, 100, 100, nave_dx, nave_dy, 0);
}

void finalizaNave()
{
    al_destroy_bitmap(nave); 
}