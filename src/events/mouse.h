void eventoCliqueDoMouse();

void eventoCliqueDoMouse()
{
	if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
		printf("\nmouse clicado em: %d, %d", ev.mouse.x, ev.mouse.y);
	}
}