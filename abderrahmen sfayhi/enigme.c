#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "enigme.h"
#include <time.h>
enigme initEnigme (){
  enigme e;
  e.f = fopen("lesenigmes.txt", "r");
 return e;
}
void showEnigme (enigmeData ed, SDL_Surface *screen, enigme e){
int v;
SDL_Event event;
char txt_win[15]="You  passed  !";
char txt_lose[14]="You  lost  !";
SDL_Surface *win_lose;
SDL_Rect pos_win_lose_txt;
posenigme pe;
SDL_Surface *questsurf;
SDL_Surface *c1surf;
SDL_Surface *c2surf;
SDL_Surface *c3surf;
TTF_Font * police;
SDL_Color red = {34,40,49};
SDL_Color black  = {0,0,0};
if (TTF_Init() < 0) {
  printf("error\n");
}else{
police = TTF_OpenFont("Midnight_Drive_Two.ttf", 24);
if (police == NULL) {
  printf("error dans open font enigma\n");
}else{
  questsurf = TTF_RenderText_Solid(police, ed.quest, black);
  c1surf = TTF_RenderText_Solid(police, ed.c1, red);
  c2surf = TTF_RenderText_Solid(police, ed.c2, red);
  c3surf = TTF_RenderText_Solid(police, ed.c3, red);
  pe.back.x = 0;
  pe.back.y = 0;
  pe.back.h = questsurf->h;
  pe.back.w = questsurf->w;
  pe.quest.x = 240;
  pe.quest.y = 180;
  pe.c1.x= 400;
  pe.c1.y= 250;
  pe.c2.x= 550;
  pe.c2.y= 250;
  pe.c3.x= 700;
  pe.c3.y= 250;
pos_win_lose_txt.x = 550;
pos_win_lose_txt.y = 400;
e.back=IMG_Load("letter.jpg");
  SDL_BlitSurface(e.back, NULL, screen, &pe.back);
  SDL_Flip(screen);
  SDL_BlitSurface(questsurf, NULL, screen, &pe.quest);
  SDL_Flip(screen);
  SDL_BlitSurface(c1surf, NULL, screen, &pe.c1);
  SDL_Flip(screen);
  SDL_BlitSurface(c2surf, NULL, screen, &pe.c2);
  SDL_Flip(screen);
  SDL_BlitSurface(c3surf, NULL, screen, &pe.c3);
  SDL_Flip(screen);
v=resolutionEnigme(ed,event);
if(v == 1)
{
  win_lose = TTF_RenderText_Solid(police,txt_win, black);
  SDL_BlitSurface(win_lose, NULL, screen, &pos_win_lose_txt);
  SDL_Flip(screen);
  SDL_Delay(1000);
}
else if (v == -1)
{
  win_lose = TTF_RenderText_Solid(police,txt_lose, black);
  SDL_BlitSurface(win_lose, NULL, screen, &pos_win_lose_txt);
  SDL_Flip(screen);
  SDL_Delay(1000);
}
else{
printf("erreur");
}
TTF_CloseFont(police);
TTF_Quit();
SDL_FreeSurface(screen);
SDL_FreeSurface(win_lose);
SDL_FreeSurface(questsurf);
SDL_FreeSurface(c1surf);
SDL_FreeSurface(c2surf);
SDL_FreeSurface(c3surf);
SDL_Quit();

}
}
}
int randomize(){
int pos;
 srand(time(NULL));
pos=rand()%(9-0+1)+0;
return pos;
}
enigmeData generateEnigme(enigme e){
  enigmeData ed [10];
  enigmeData edata;
  int i;
  int pos = randomize();
  for (i = 0; i < 10; i++) {
    fgets(ed[i].quest, 400, e.f);
    fscanf(e.f,"1)%s 2)%s 3)%s -%s\n",ed[i].c1, ed[i].c2, ed[i].c3, ed[i].x);
  }
  strcpy(edata.quest,ed[pos].quest);
  strcpy (edata.c1 ,ed[pos].c1);
      strcpy(edata.c2 ,ed[pos].c2);
        strcpy(edata.c3 ,ed[pos].c3);
          strcpy(edata.x ,ed[pos].x);
  return edata;
}
int resolutionEnigme(enigmeData ed, SDL_Event event){
int x=1;

	while(x) {
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
					x = 0;
			}
            if(event.key.keysym.sym == SDLK_a){
 		
             if (strcmp (ed.c1, ed.x) == 0) {
		x=0;
               return 1;
			
             }
	else if(strcmp (ed.c2, ed.x) != 0){
x=0;
return -1;
	}
            }else{
              if(event.key.keysym.sym == SDLK_b){
                if (strcmp (ed.c2, ed.x) == 0) {
		x=0;
                  return 1;
                }
	else if(strcmp (ed.c2, ed.x) != 0){
x=0;
return -1;
	}
             }else{
               if(event.key.keysym.sym == SDLK_c){
                 if (strcmp (ed.c3, ed.x) == 0) {
			x=0;
                   return 1;
                 }
	else if(strcmp (ed.c2, ed.x) != 0){
		x=0;
return -1;
	}
               }
             }
            }
}
}

return 0;
}
