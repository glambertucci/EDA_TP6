#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include <allegro5\allegro_image.h>
#include "general.h"
class allegro_c
{
public:
	allegro_c();
	~allegro_c();
	ALLEGRO_EVENT_QUEUE * getEventQueue();
	bool load_music(const char * music_file);
	void draw(userData& usr);
	void play_music();
	void updateDisplay();
	void createDisplay();
	void destroyDisplay();

private:
	ALLEGRO_DISPLAY * display = NULL;
	ALLEGRO_EVENT_QUEUE * ev_queue = NULL;
	ALLEGRO_SAMPLE * music = NULL;
	ALLEGRO_TIMER * timer = NULL;
};

#define FPS 50.0
#define H 1080
#define W 1920