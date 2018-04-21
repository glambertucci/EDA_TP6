#include "allegro.h"



allegro_c::allegro_c()
{
	if (al_init())
	{
		if (al_install_audio())
		{
			if (al_init_acodec_addon())
			{
				if ((al_reserve_samples(1)))
				{
					if (al_init_image_addon())
					{
						if ((ev_queue = al_create_event_queue()))
						{
							if ((timer = al_create_timer(1.0 / FPS)))
							{
								if (display = al_create_display(W, H))//Despues fijate comoq ueda piola
								{
								ALLEGRO_BITMAP * icon = al_load_bitmap("icon.png");
								al_set_display_icon(display, icon); //Optional
								al_load_bitmap("background.png");//ACORDATE DE PONER UNA IMAGEN
								al_flip_display();
								al_register_event_source(this->ev_queue, al_get_timer_event_source(this->timer));
								al_start_timer(this->timer);
								}
							}
						}
					}
				}
			}
		}
	}
}


allegro_c::~allegro_c()
{
	al_destroy_display(display);
	al_stop_samples();
	al_destroy_sample(music);
	al_destroy_timer(timer);
	al_destroy_event_queue(ev_queue);
	al_shutdown_image_addon();
	al_uninstall_audio();
}

bool allegro_c::load_music(const char * music_file) //Devuelve 1 si todo salio bien
{
	bool result;
	if ((music = al_load_sample(music_file)))
		result = true;
	else
		result = false;
	return result;

}

void allegro_c::updateDisplay()
{
	al_flip_display();
}

ALLEGRO_EVENT_QUEUE * allegro_c::getEventQueue()
{
	return ev_queue;
}

void allegro_c::play_music()
{
	al_play_sample(music, 1.0, 1.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
}

void allegro_c::draw(userData& usr)
{
	//usa la animacion de usr. acordate que es bloqueante tenes un metodo para el display pero creo que s einicia antes le display

}