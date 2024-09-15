#include "game.h"

void handle_events(struct game* g)
{
	if (g->e.type == SDL_QUIT) g->quit = 1;
	if (g->e.type == SDL_KEYDOWN) {
		char next_tile = 0;
		switch (g->e.key.keysym.sym) {
		case SDLK_RIGHT:
			next_tile = g->m->m[g->p->head->x + 1][g->p->head->y];
			if (next_tile != '#') {
				g->p->head->x++;
			}
			if (g->p->head->dir != DIR_LEFT)
				g->p->head->dir = DIR_RIGHT;
			break;
		case SDLK_DOWN:
			next_tile = g->m->m[g->p->head->x][g->p->head->y + 1];
			if (next_tile != '#') {
				g->p->head->y++;
			}
			if (g->p->head->dir != DIR_UP)
				g->p->head->dir = DIR_DOWN;
			break;
		case SDLK_LEFT:
			next_tile = g->m->m[g->p->head->x - 1][g->p->head->y];
			if (next_tile != '#') {
				g->p->head->x--;
			}
			if (g->p->head->dir != DIR_RIGHT)
				g->p->head->dir = DIR_LEFT;
			break;
		case SDLK_UP:
			next_tile = g->m->m[g->p->head->x][g->p->head->y - 1];
			if (next_tile != '#') {
				g->p->head->y--;
			}
			if (g->p->head->dir != DIR_DOWN)
				g->p->head->dir = DIR_UP;
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
	current_tile.x = g->p->head->x * current_tile.w;
	current_tile.y = g->p->head->y * current_tile.h;
	SDL_SetRenderDrawColor(g->ren, 0x11, 0xee, 0x11, 0xff);
	SDL_RenderFillRect(g->ren, &current_tile);
/*	for (int i = 0; i < g->p->size; ++i) {
		current_tile.x = g->p->body[i][0] * current_tile.w;
		current_tile.y = g->p->body[i][1] * current_tile.h;
		SDL_SetRenderDrawColor(g->ren, 0x11, 0xdd, 0x11, 0xff);
		SDL_RenderFillRect(g->ren, &current_tile);
	} */
	SDL_RenderPresent(g->ren);
}