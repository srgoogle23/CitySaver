void eventoCliqueDoMouse();
void imprimirPosicaoCliqueMouse(int x, int y);

void eventoCliqueDoMouse()
{
	if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
		if(DEBUG == true)
		{
			//imprime qual tecla foi
			imprimirPosicaoCliqueMouse(ev.mouse.x, ev.mouse.y);
		}
	}
}

void imprimirPosicaoCliqueMouse(int x, int y)
{
	printf("\nmouse clicado em: %d, %d", x, y);
}