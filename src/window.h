#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include "game.h"

// util

int init_SDL(struct game*, struct settings*);
void close_SDL(struct game*);

#endif