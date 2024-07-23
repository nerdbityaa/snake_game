#include "window.h"

int main()
{
	struct game* g = &(struct game) {
		.win = NULL,
		.ren = NULL,
		.quit = -1,
	};	
	{
	struct settings* sett = &(struct settings) {
		.win_title = "it werks!",
		.win_x = 0,
		.win_y = 0,
		.win_w = 800,
		.win_h = 800,
		.win_flags = SDL_WINDOW_SHOWN,
		.ren_flags = SDL_RENDERER_ACCELERATED,
	};
	
	if (init_SDL(g, sett) < 0) {
		printf("!!\t[main]init error.\n");
		return 1;
	}
	}

	while (g->quit < 0) {
		SDL_UpdateWindowSurface(g->win);
		while (SDL_PollEvent(&g->e)) {
			handle_events(g);
		}
		update(g);
		render(g);
	}
	close_SDL(g);
}