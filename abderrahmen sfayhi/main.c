#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <string.h>
#include "enigme.h"

int main() {
SDL_Surface *screen;
SDL_Event event;
enigme e;
enigmeData ed;

SDL_Init(SDL_INIT_VIDEO);
screen = SDL_SetVideoMode(1200,600,32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);

SDL_WM_SetCaption("enigme.exe",NULL);

e =initEnigme ();

ed= generateEnigme(e);

showEnigme(ed,screen,e);
//SDL_FreeSurface(screen);
SDL_Quit();


return 0;
}
