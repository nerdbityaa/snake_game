#include "game.h"

Uint16 get_snake_size(snake* s)
{
	int snake_size = 0;
	while (s->body[snake_size][0] != -1)
		++snake_size;
	return snake_size;
}

void handle_events(struct game* g)
{
	if (g->e.type == SDL_QUIT) g->quit = 1;
	if (g->e.type == SDL_KEYDOWN) {
		switch (g->e.key.keysym.sym) {
		case SDLK_RIGHT:
			if (g->p->dirs[0] != DIR_LEFT)
				g->p->dirs[0] = DIR_RIGHT;
			break;
		case SDLK_DOWN:
			if (g->p->dirs[0] != DIR_UP)
				g->p->dirs[0] = DIR_DOWN;
			break;
		case SDLK_LEFT:
			if (g->p->dirs[0] != DIR_RIGHT)
				g->p->dirs[0] = DIR_LEFT;
			break;
		case SDLK_UP:
			if (g->p->dirs[0] != DIR_DOWN)
				g->p->dirs[0] = DIR_UP;
			break;
		default:
			break;
		}
	}
}

void update(struct game* g)
{
	(void) g;
}

void render(struct game* g)
{
	SDL_Rect current_tile;
	current_tile.w = 40;
	current_tile.h = 40;
	for (int i = 0; i < g->m->h; ++i) {
		for (int j = 0; j < g->m->w; ++j) {
			current_tile.x = j * current_tile.w;
			current_tile.y = i * current_tile.h;
			switch (g->m->m[i][j]) {
			case '#':
				SDL_SetRenderDrawColor(g->ren, 0xff, 0xaa, 0x11, 0xff);			
				break;
			case '.':
				SDL_SetRenderDrawColor(g->ren, 0x00, 0x00, 0x00, 0xff);
				break;
			}
			SDL_RenderFillRect(g->ren, &current_tile);
		}
	}
	for (int i = 0; i < get_snake_size(g->p); ++i) {
		current_tile.x = g->p->body[i][0] * current_tile.w;
		current_tile.y = g->p->body[i][1] * current_tile.h;
		SDL_SetRenderDrawColor(g->ren, 0x11, 0x11, 0xee, 0xff);
		SDL_RenderFillRect(g->ren, &current_tile);
	}
	SDL_RenderPresent(g->ren);
}