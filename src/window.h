#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include "game.h"

#define TICK_INTERVAL 30

// util

Uint64 time_left(struct game*);

int init_SDL(struct game*, struct settings*);
void close_SDL(struct game*);

#endif