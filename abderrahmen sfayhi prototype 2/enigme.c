#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "enigme.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <time.h>
void blit(SDL_Surface *screen,SDL_Rect pos,int a)
{
 SDL_Surface *x;
 SDL_Surface *o;
 x = IMG_Load("x.png");
 o = IMG_Load("o.png");
 if (a==1){
 	SDL_BlitSurface(x,NULL,screen,&pos);
 	SDL_Flip(screen);
 }
 else if (a==2){
 	SDL_BlitSurface(o,NULL,screen,&pos);
 	SDL_Flip(screen);
 }

 else
 {
 	printf("erreur\n");
 }
}

grille initGrille()
{
grille g;
g.tab[0][0]=0;
g.tab[0][1]=0;
g.tab[0][2]=0;
g.tab[1][0]=0;
g.tab[1][1]=0;
g.tab[1][2]=0;
g.tab[2][0]=0;
g.tab[2][1]=0;
g.tab[2][2]=0;

return g;
}
void affGrille(grille a,SDL_Surface *screen)
{
	SDL_Rect pos;
	SDL_Surface *bg;
	pos.x=0;
	pos.y=0;
	bg = IMG_Load("bg.png");
	SDL_BlitSurface(bg,NULL,screen,&pos);
	SDL_Flip(screen);
 }
void joueurPrincipale(SDL_Surface *screen,grille *a)
 {
 	SDL_Event event;
 	int continuer = 1;
 	SDL_Rect pos1_1;
 	SDL_Rect pos1_2;
 	SDL_Rect pos1_3;

 	SDL_Rect pos2_1;
 	SDL_Rect pos2_2;
 	SDL_Rect pos2_3;

 	SDL_Rect pos3_1;
 	SDL_Rect pos3_2;
 	SDL_Rect pos3_3;

 	pos1_1.x=50;
 	pos1_1.y=40;

 	pos1_2.x=220;
 	pos1_2.y=40;

 	pos1_3.x=430;
 	pos1_3.y=40;


 	pos2_1.x=50;
 	pos2_1.y=190;

 	pos2_2.x=220;
 	pos2_2.y=190;

 	pos2_3.x=430;
 	pos2_3.y=190;

 	pos3_1.x=50;
 	pos3_1.y=400;

 	pos3_2.x=220;
 	pos3_2.y=400;

 	pos3_3.x=430;
 	pos3_3.y=400;
 	
 
 	while(continuer)
 	{
 		SDL_WaitEvent(&event);
 		switch(event.type)
		{
			case SDL_QUIT:
			continuer = 0;
			break;

	case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
		{
		case SDLK_KP9:

	if(coupPossible(a,9)==1){	
		blit(screen,pos1_3,1);
		a->tab[0][2]=1;
		SDL_Flip(screen);
		continuer = 0;
		}
		break;

		case SDLK_KP8: 
		if(coupPossible(a,8)==1){
		blit(screen,pos1_2,1);
		a->tab[0][1]=1;
		SDL_Flip(screen);	

		continuer = 0;
		}
		break;

		case SDLK_KP7:
		if(coupPossible(a,7)==1){
		blit(screen,pos1_1,1);
		a->tab[0][0]=1;
		SDL_Flip(screen);
		continuer = 0;
	    }
		break;

		case SDLK_KP6:
		if(coupPossible(a,6)==1){
		blit(screen,pos2_3,1);
		a->tab[1][2]=1;
		SDL_Flip(screen);
		continuer = 0;
			}
		break;

		case SDLK_KP5:
		if(coupPossible(a,5)==1){
			blit(screen,pos2_2,1);
			a->tab[1][1]=1;
			SDL_Flip(screen);
			continuer = 0;
		}
		break;

		case SDLK_KP4:
		if(coupPossible(a,4)==1){
			blit(screen,pos2_1,1);
			a->tab[1][0]=1;
			SDL_Flip(screen);
			continuer = 0;
		}
		break;
			case SDLK_KP3: 
			if(coupPossible(a,3)==1){
			blit(screen,pos3_3,1);
			a->tab[2][2]=1;
			SDL_Flip(screen);
			continuer = 0;
		}
		break;
		case SDLK_KP2:
			if(coupPossible(a,2)==1){
			blit(screen,pos3_2,1);
			a->tab[2][1]=1;
			SDL_Flip(screen);
			continuer = 0;
		}
		break;
		case SDLK_KP1:
		if(coupPossible(a,1)==1){
			blit(screen,pos3_1,1);
			a->tab[2][0]=1;
			SDL_Flip(screen);
			continuer = 0;
		}
		break;
		}
	}
	}

 }
int coupPossible(grille *a, int c)
{
	SDL_Surface *wrong;
	//wrong = IMG_Load("wrong.png");
	int x;
	 int i,j;

	if(c==9){
		if(	a->tab[0][2]==0){

			return 1; //vrai tu peux ajouter
		}
		else
		return 0; //tu peu pas ajouter
	}
	else if(c==8){
			if(	a->tab[0][1]==0){
			return 1; //vrai tu peux ajouter
		}
		else
		return 0;
		
				}
	else if(c==7)
	{
			if(	a->tab[0][0]==0){
			return 1; //vrai tu peux ajouter
		}
		else
		//{
		return 0;
		//}	
	}
	else if(c==6)
	{
			if(	a->tab[1][2]==0){
			return 1; //vrai tu peux ajouter
		}
		else
		//{
		return 0;
		//}
	}
	else if(c==5)
	{
			if(	a->tab[1][1]==0){
			return 1; //vrai tu peux ajouter
		}
		else
		//{
		return 0;
		//}
	}
		else if(c==4)
	{
			if(	a->tab[1][0]==0){
			return 1; //vrai tu peux ajouter
		}
		else
		//{
		return 0;
		//}
	}

		else if(c==3)
	{
			if(	a->tab[2][2]==0){
			return 1; //vrai tu peux ajouter
		}
		else
		//{
		return 0;
		//}
	}
		else if(c==2)
	{
			if(	a->tab[2][1]==0){
			return 1; //vrai tu peux ajouter
		}
		else
		//{
		return 0;
		//}
	}

		else if(c==1)
	{
			if(	a->tab[2][0]==0){
			return 1; //vrai tu peux ajouter
		}
		else
		//{
		return 0;
		//}
	}

	return -1;
}

int alea(){
	int num;
srand(time(0));
num = rand() % 9;
num++;
return num;
}


void ia(SDL_Surface *screen,grille *a)
{


 	SDL_Rect pos1_1;
 	SDL_Rect pos1_2;
 	SDL_Rect pos1_3;

 	SDL_Rect pos2_1;
 	SDL_Rect pos2_2;
 	SDL_Rect pos2_3;

 	SDL_Rect pos3_1;
 	SDL_Rect pos3_2;
 	SDL_Rect pos3_3;

 	pos1_1.x=50;
 	pos1_1.y=40;

 	pos1_2.x=220;
 	pos1_2.y=40;

 	pos1_3.x=430;
 	pos1_3.y=40;


 	pos2_1.x=50;
 	pos2_1.y=190;

 	pos2_2.x=220;
 	pos2_2.y=190;

 	pos2_3.x=430;
 	pos2_3.y=190;

 	pos3_1.x=50;
 	pos3_1.y=400;

 	pos3_2.x=220;
 	pos3_2.y=400;

 	pos3_3.x=430;
 	pos3_3.y=400;
 SDL_Surface *o;
 o = IMG_Load("o.png");
  int random;
  int continuer = 1;
do{
random = alea();
}while(coupPossible(a,random)!=1);
  
    	switch(random)
		{
		case 9:
		blit(screen,pos1_3,2);
		a->tab[0][2]=2;
		SDL_Flip(screen);

		break;

		case 8: 

		blit(screen,pos1_2,2);
		a->tab[0][1]=2;
		SDL_Flip(screen);	
		break;

		case 7:	
		blit(screen,pos1_1,2);
		a->tab[0][0]=2;
		SDL_Flip(screen);
		break;

		case 6: 
		blit(screen,pos2_3,2);
		a->tab[1][2]=2;
		SDL_Flip(screen);
		break;

		case 5: 
			blit(screen,pos2_2,2);
			a->tab[1][1]=2;
			SDL_Flip(screen);
		break;

		case 4: 
			blit(screen,pos2_1,2);
			a->tab[1][0]=2;
			SDL_Flip(screen);
		break;

			case 3: 
			if(coupPossible(a,3)==1){
			blit(screen,pos3_3,2);
			a->tab[2][2]=2;
			SDL_Flip(screen);
		}
		break;
		case 2: 
		
			blit(screen,pos3_2,2);
			a->tab[2][1]=2;
			SDL_Flip(screen);

		break;

		case 1: 
			blit(screen,pos3_1,2);
			a->tab[2][0]=2;
			SDL_Flip(screen);
		break;
	}
    }


 

