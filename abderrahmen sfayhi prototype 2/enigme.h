#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <time.h>


typedef struct 
{	
	int tab[3][3];
}grille;
grille initGrille();
void affGrille(grille a,SDL_Surface *screen);
void joueurPrincipale(SDL_Surface *screen,grille *a);
void blit(SDL_Surface *screen,SDL_Rect pos,int a);
int coupPossible(grille *a, int c);
int alea();
void ia(SDL_Surface *screen,grille *a);
#endif
