#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include <allegro5\allegro_image.h>
#include "general.h"
#include "package.h"
#define H 700
#define W 1920

class allegro_c
{
public:
	allegro_c();
	~allegro_c();
	bool load_music(const char * music_file);
	void draw(paquete pkt);
	void draw_cat();
	void draw_exp();
	void draw_exp2();
	void draw_mario();
	void draw_homero();
	void draw_sonic();
	void play_music();



private:
	ALLEGRO_DISPLAY * display = NULL;
	ALLEGRO_BITMAP * background = NULL;
	ALLEGRO_SAMPLE * music = NULL;
};


