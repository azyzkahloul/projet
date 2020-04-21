#include<SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <SDL/SDL_mixer.h>

void init_vie_score(vie_score* vs)
{
*vs.vie=5;
*vs.score=100;

//configuration de score en ttf
TTF_Init();
SDL_Color couleurNoire = {0, 0, 0};
TTF_Font *police_score = NULL;
police_score = TTF_OpenFont("angelina.ttf", 65);

char SCORE100[10] = "SCORE:100";
char SCORE80[10] = "SCORE:80";
char SCORE60[10] = "SCORE:60";
char SCORE40[10] = "SCORE:40";
char SCORE20[10] = "SCORE:20";
char SCORE0[10] = "SCORE:00";

SDL_Surface *texte_score100 = NULL;
SDL_Surface *texte_score80 = NULL ;
SDL_Surface *texte_score60 = NULL ;
SDL_Surface *texte_score40 = NULL ;
SDL_Surface *texte_score20 = NULL ;
SDL_Surface *texte_score0 = NULL ;

texte_score100 = TTF_RenderText_Blended(police_score,SCORE100,couleurNoire);
texte_score80 = TTF_RenderText_Blended(police_score,SCORE80,couleurNoire);
texte_score60 = TTF_RenderText_Blended(police_score,SCORE60,couleurNoire);
texte_score40 = TTF_RenderText_Blended(police_score,SCORE40,couleurNoire);
texte_score20 = TTF_RenderText_Blended(police_score,SCORE20,couleurNoire);
texte_score0 = TTF_RenderText_Blended(police_score,SCORE0,couleurNoire);

SDL_Rect position_score;
position_score.x=0 ;position_score.y=0 ;

//configuration de vie
SDL_Surface *vie0;
SDL_Surface *vie1;
SDL_Surface *vie2;
SDL_Surface *vie3;
SDL_Surface *vie4;
SDL_Surface *vie5;

vie0  =  IMG_Load( "vie0.jpg" );
vie1  =  IMG_Load( "vie1.jpg" );
vie2  =  IMG_Load( "vie2.jpg" );
vie3  =  IMG_Load( "vie3.jpg" );
vie4  =  IMG_Load( "vie4.jpg" );
vie5  =  IMG_Load( "vie5.jpg" );

SDL_Rect position_vie0;
SDL_Rect position_vie1;
SDL_Rect position_vie2;
SDL_Rect position_vie3;
SDL_Rect position_vie4;
SDL_Rect position_vie5;

position_vie0.x=40 ;position_vie0.y=0 ;
position_vie1.x=40 ;position_vie1.y=0 ;
position_vie2.x=40 ;position_vie2.y=0 ;
position_vie3.x=40 ;position_vie3.y=0 ;
position_vie4.x=40 ;position_vie4.y=0 ;
position_vie5.x=40 ;position_vie5.y=0 ;
}


void Gestion_vie_score(int collision_pp_bb,vie_score* vs,SDL_Surface *screen)
{
    if (collision_pp_bb==1)
    {
        *vs.vie--;
        *vs.score=vs.score-20;
    }
    switch (*vs.vie)
    {
    case 5:
        SDL_BlitSurface(vie5,NULL,ecran,&position_vie5);
        SDL_BlitSurface(texte_score100, NULL, ecran, &position_score);break;
    case 4:
        SDL_BlitSurface(vie4,NULL,ecran,&position_vie4);
         SDL_BlitSurface(texte_score80, NULL, ecran, &position_score);break;
    case 3:
         SDL_BlitSurface(vie3,NULL,ecran,&position_vie3);
        SDL_BlitSurface(texte_score60, NULL, ecran, &position_score);break;
    case 2:
        SDL_BlitSurface(vie2,NULL,ecran,&position_vie2);
        SDL_BlitSurface(texte_score40, NULL, ecran, &position_score);break;
    case 1:
        SDL_BlitSurface(vie1,NULL,ecran,&position_vie1);
        SDL_BlitSurface(texte_score20, NULL, ecran, &position_score);break;
    case 0:
        SDL_BlitSurface(vie0,NULL,ecran,&position_vie0);
        SDL_BlitSurface(texte_score0, NULL, ecran, &position_score);break;
    }
}
