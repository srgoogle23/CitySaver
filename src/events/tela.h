void eventoFechamentoDeTela();

void eventoFechamentoDeTela()
{
	if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
		jogando = 0;
	}
}