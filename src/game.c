#include "game.h"

void handle_events(struct game* g)
{
	if (g->e.type == SDL_QUIT) g->quit = 1;
	if (g->e.type == SDL_KEYDOWN) {
		switch (g->e.key.keysym.sym) {
		default:
			break;
		}
	}
}

void update(struct game* g)
{

}

void render(struct game* g)
{

}