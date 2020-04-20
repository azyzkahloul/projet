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
int resultat=-1;
enigme e;
enigmeData ed;

int i;
SDL_Init(SDL_INIT_EVERYTHING);
TTF_Init();
screen = SDL_SetVideoMode(1200,600,32,SDL_HWSURFACE);



e =initEnigme ();

ed= generateEnigme(e);

showEnigme(ed,screen,e);

resultat = resolutionEnigme(ed,event);
if(resultat == 0){
printf("you won");
}
else if(resultat == 1){
printf("you lost");
}
else{
printf("bug resulat different de 1 et 0");
}
return 0;
}