#include "window.h"

Uint64 time_left(struct game* g)
{
	Uint64 now;

	now = SDL_GetTicks64();
	if (g->next_frame <= now)
		return 0;
	else
		return g->next_frame - now;
}

int init_SDL(struct game* g, struct settings* sett)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("!!\tsdl init failed. e: %s\n", SDL_GetError());
		return -1;
	}
	else {
		g->win = SDL_CreateWindow(sett->win_title, sett->win_x, sett->win_y,
								  sett->win_w, sett->win_h, sett->win_flags);
		if (g->win == NULL) {
			printf("!!\twindow creation failed. e: %s\n", SDL_GetError());
			return -1;
		}
		else {
			g->ren = SDL_CreateRenderer(g->win, -1, sett->ren_flags);
			SDL_SetRenderDrawColor(g->ren, 0, 0, 0, 0);
			SDL_RenderClear(g->ren);
			SDL_RenderPresent(g->ren);
			return 1;
		}
	}	
}

void close_SDL(struct game* g)
{
	SDL_DestroyRenderer(g->ren);
	g->ren = NULL;

	SDL_DestroyWindow(g->win);
	g->win = NULL;
}