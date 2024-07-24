#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

struct game {
	Uint64 next_frame;
	SDL_Window* win;
	SDL_Renderer* ren;
	SDL_Event e;
	int quit;
};

struct settings {
	const char* win_title;
	int win_x;
	int win_y;
	int win_w;
	int win_h;
	Uint32 win_flags;
	Uint32 ren_flags;
};

// game logic 'n stuff

void handle_events(struct game*);
void update(struct game*);
void render(struct game*);

#endif