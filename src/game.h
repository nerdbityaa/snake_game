#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

enum directions {
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LEFT,
	DIR_UP,
};

typedef struct snake {
	Sint16 *body[2]; // array of snake's body coordinates
	enum directions *dirs; 
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