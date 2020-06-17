#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "enigme.h"
#include "vie.h"
#include "SDL/SDL_mixer.h"
#include <time.h>
int verifGrilleFull(grille g, SDL_Surface *screen);

int verifVertical(grille g,SDL_Surface *screen);
int verifHorizontal(grille g,SDL_Surface *screen);
int verifOblique(grille g,SDL_Surface *screen);
int finVie(v vie);
int random_number(int min_num, int max_num);
int full(grille g, SDL_Surface *screen);










#endif