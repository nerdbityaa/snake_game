#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "util.h"

enum directions {
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LEFT,
	DIR_UP,
};

struct snake_head {
	Sint16 x;
	Sint16 y;
	enum directions dir; 
};

struct snake_body {
	Sint16* values;
	enum directions* dirs;
};

typedef struct snake {
	struct snake_head* head;
	struct snake_body* body;
	Sint16 size;
} snake;

typedef struct food {
	Uint16 x;
	Uint16 y;
} food;

typedef struct map {
	int w;
	int h;
	char** m;
} map;

struct game {
	snake* p;
	map* m;
	food* f;

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

Uint16 get_snake_size(snake*);

void handle_events(struct game*);
void update(struct game*);
void render(struct game*);

#endif