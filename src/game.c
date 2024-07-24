#include "game.h"

void handle_events(struct game* g)
{
	if (g->e.type == SDL_QUIT) g->quit = 1;
	if (g->e.type == SDL_KEYDOWN) {
		switch (g->e.key.keysym.sym) {
		case SDLK_RIGHT:
			if (g->p->dir != DIR_LEFT)
				g->p->dir = DIR_RIGHT;
			break;
		case SDLK_DOWN:
			if (g->p->dir != DIR_UP)
				g->p->dir = DIR_DOWN;
			break;
		case SDLK_LEFT:
			if (g->p->dir != DIR_RIGHT)
				g->p->dir = DIR_LEFT;
			break;
		case SDLK_UP:
			if (g->p->dir != DIR_DOWN)
				g->p->dir = DIR_UP;
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
	SDL_RenderPresent(g->ren);
}