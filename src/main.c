#include "window.h"

int main()
{
	struct game* g;
	// init block
	g = &(struct game) {
		.m = &(map) {
			.w = 20,
			.h = 20,
			.m = calloc(20 * 20, sizeof(char)),
		},
		.win = NULL,
		.ren = NULL,
		.quit = -1,
	};
	for (int i = 0; i < g->m->h; ++i)
		g->m->m[i] = malloc(g->m->w * sizeof(char));
	strcpy(g->m->m[0], "####################");
	for (int i = 1; i < g->m->h - 1; ++i)
		strcpy(g->m->m[i], "#..................#");
	strcpy(g->m->m[19], "####################");

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
	g->p = &(snake) {
		.body = &(struct snake_body) {
			.values = calloc((g->m->h-2)*(g->m->w-2), sizeof(Sint16)),
			.dirs = calloc((g->m->h-2)*(g->m->w-2), sizeof(enum directions)),
		},
		.head = &(struct snake_head) {
			.dir = DIR_RIGHT,
			.x = 5,
			.y = 5
		},
		.size = 1,
	};
	// init block

	// game loop
	g->next_frame = SDL_GetTicks64() + TICK_INTERVAL;
	while (g->quit < 0) {
		while (SDL_PollEvent(&g->e)) {
			handle_events(g);
		}
		update(g);
		render(g);
		SDL_Delay(time_left(g));
		g->next_frame += TICK_INTERVAL;
	}
	// game loop

	// quit block
	close_SDL(g);
	for (int i = 0; i < g->m->h; ++i)
		free((void*) g->m->m[i]);
	free(g->m->m);
	// quit block
}