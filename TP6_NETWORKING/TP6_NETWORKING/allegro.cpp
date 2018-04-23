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

							if (display = al_create_display(W, H))//Despues fijate comoq ueda piola
							{

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


void allegro_c::play_music()
{
	al_play_sample(music, 1.0, 1.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
}

void allegro_c::draw(paquete pkt)
{
	switch (pkt.animation)///usa la animacion de usr. acordate que es bloqueante tenes un metodo para el display pero creo que s einicia antes le display
	{
	case 'A':
		draw_cat();
		break;
	case 'B':
		draw_exp();
		break;
	case 'C':
		draw_exp2();
		break;
	case 'D':
		draw_homero();
		break;
	case 'E':
		draw_mario();
		break;
	case 'F':
		draw_sonic();
		break;

	};
}
void allegro_c::draw_cat()
{
	load_music("cat_music.wav");
	play_music();

	string files[12];
	for (int i = 0; i < 12; i++)
		files[i] = "Cat_Running-F" + to_string(i + 1) + ".png";
	ALLEGRO_BITMAP * bitmaps[12];
	for (int i = 0; i < 12; i++)
		bitmaps[i] = al_load_bitmap(files[i].c_str());
	background = al_load_bitmap("backgroundCat.png");//ACORDATE DE PONER UNA IMAGEN
	int x = -al_get_bitmap_width(bitmaps[0]);
	while (x  < (W - 50))
	{
		for (int i = 0; i < 12; i++)
		{
			al_draw_bitmap(background, 0, 0, 0);
			al_draw_bitmap(bitmaps[i], x, H / 3.0, 0);
			al_flip_display();
			x += 2;
			al_rest(0.1);

		}
	}
}
void allegro_c::draw_exp()
{
	load_music("explosion_music.wav");
	play_music();
	string files[8];
	for (int i = 0; i < 8; i++)
		files[i] = "Explosion 1-F" + to_string(i + 1) + ".png";
	ALLEGRO_BITMAP * bitmaps[8];
	for (int i = 0; i < 8; i++)
		bitmaps[i] = al_load_bitmap(files[i].c_str());
	int x = -al_get_bitmap_width(bitmaps[0]);

	for (int i = 0; i < 8; i++)
	{

		al_draw_scaled_bitmap(bitmaps[i], 0, 0, al_get_bitmap_width(bitmaps[i]), al_get_bitmap_height(bitmaps[i]), 0, 0, W, H, 0);
		al_flip_display();
		al_rest(0.12);

	}
}
void allegro_c::draw_exp2()
{
	load_music("explosion2_music.wav");
	play_music();

	string files[48];
	for (int i = 0; i < 48; i++)
		files[i] = "Explosion 2-F" + to_string(i + 1) + ".png";
	ALLEGRO_BITMAP * bitmaps[48];
	for (int i = 0; i < 48; i++)
		bitmaps[i] = al_load_bitmap(files[i].c_str());
	int x = -al_get_bitmap_width(bitmaps[0]);

	for (int i = 0; i < 48; i++)
	{

		al_draw_scaled_bitmap(bitmaps[i], 0, 0, al_get_bitmap_width(bitmaps[i]), al_get_bitmap_height(bitmaps[i]), 0, 0, W, H, 0);
		al_flip_display();
		al_rest(0.1);

	}
}
void allegro_c::draw_homero()
{
	load_music("homero_music.wav");
	play_music();

	string files[10];
	for (int i = 0; i < 10; i++)
		files[i] = "homerdance-F" + to_string(i + 1) + ".png";
	ALLEGRO_BITMAP * bitmaps[10];
	for (int i = 0; i < 10; i++)
		bitmaps[i] = al_load_bitmap(files[i].c_str());
	background = al_load_bitmap("backgroundHomero.png");//ACORDATE DE PONER UNA IMAGEN
	int x = -al_get_bitmap_width(bitmaps[0]);
	while (x  < (W - 50))
	{
		for (int i = 0; i < 10; i++)
		{
			al_draw_bitmap(background, 0, 0, 0);
			al_draw_bitmap(bitmaps[i], x, H / 2, 0);
			al_flip_display();
			x += 100;
			al_rest(0.1);

		}
	}
}
void allegro_c::draw_mario()
{
	load_music("mario_music.wav");
	play_music();

	string files[12];
	for (int i = 0; i < 12; i++)
		files[i] = "Super Mario Running-F" + to_string(i + 1) + ".png";
	ALLEGRO_BITMAP * bitmaps[12];
	for (int i = 0; i < 12; i++)
		bitmaps[i] = al_load_bitmap(files[i].c_str());
	background = al_load_bitmap("backgroundMario.png");//ACORDATE DE PONER UNA IMAGEN
	int x = -al_get_bitmap_width(bitmaps[0]);
	while (x  < (W - 50))
	{
		for (int i = 0; i < 12; i++)
		{
			al_draw_bitmap(background, 0, 0, 0);
			al_draw_bitmap(bitmaps[i], x, 0, 0);
			al_flip_display();
			x += 2;
			al_rest(0.04);

		}
	}
}
void allegro_c::draw_sonic()
{
	load_music("sonic_music.wav");
	play_music();
	string files[10];
	for (int i = 0; i < 10; i++)
		files[i] = "Sonic Running-F" + to_string(i + 1) + ".png";
	ALLEGRO_BITMAP * bitmaps[10];
	for (int i = 0; i < 10; i++)
		bitmaps[i] = al_load_bitmap(files[i].c_str());
	background = al_load_bitmap("backgroundSonic.png");//ACORDATE DE PONER UNA IMAGEN
	int x = -al_get_bitmap_width(bitmaps[0]);
	while (x  < (W - 50))
	{
		for (int i = 0; i < 4; i++)
		{
			al_draw_bitmap(background, 0, 0, 0);
			al_draw_bitmap(bitmaps[i], x, 0, ALLEGRO_FLIP_HORIZONTAL);
			al_flip_display();
			al_rest(0.06);
		}
		x += 70;
		for (int i = 4; i < 10; i++)
		{
			al_draw_bitmap(background, 0, 0, 0);
			al_draw_bitmap(bitmaps[i], x, 0, ALLEGRO_FLIP_HORIZONTAL);
			al_flip_display();
			al_rest(0.06);
		}
		x += 70;
	}
}