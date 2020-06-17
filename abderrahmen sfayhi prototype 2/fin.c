#include <stdio.h>
#include <stdlib.h>
#include "enigme.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <time.h>
#include "vie.h"
#include "fin.h"


// animation missing crossing the wining ligne
void affMatrice(grille g) {
 int i,j;
 printf("\n");
 for(i=0;i<3;i++){
 for(j=0;j<3;j++){
 	printf("%d |",g.tab[i][j] );
 	  }
 	  printf("\n");
 	}
 }

int verifVertical(grille g,SDL_Surface *screen){
 	SDL_Surface *win;
 	SDL_Surface *lose;
 	SDL_Rect pos;

 	pos.x=0;
 	pos.y=0;


 	int i;
		win = IMG_Load("win.png");
		lose = IMG_Load("lose.png");

 //oblique bug
 		

		//draw = IMG_Load("draw.png")
	int x=0;
	

if(g.tab[0][0]==1 && g.tab[0][0] == g.tab[1][0] && g.tab[1][0] == g.tab[2][0]){
	SDL_BlitSurface(win,NULL,screen,&pos);
	SDL_Flip(screen);
	SDL_Delay(1000);
	//SDL_BlitSurface(cross,NULL,screen,&posC1_2); //need condition to change .y value dependin on i value
	//SDL_Flip(screen);
	x++;
}

else if(g.tab[0][0]==2 && g.tab[0][0] == g.tab[1][0] && g.tab[1][0] == g.tab[2][0]){
	SDL_BlitSurface(lose,NULL,screen,&pos);
	SDL_Flip(screen);
	SDL_Delay(1000);
	//SDL_BlitSurface(cross,NULL,screen,&posC1_2); //need condition to change .y value dependin on i value
        	//SDL_Flip(screen);
	x++;
}
else if(g.tab[0][1]==1 && g.tab[0][1] == g.tab[1][1] && g.tab[1][1] == g.tab[2][1]){
	SDL_BlitSurface(win,NULL,screen,&pos);
	SDL_Flip(screen);
	SDL_Delay(1000);
	//SDL_BlitSurface(cross,NULL,screen,&posC1_2); //need condition to change .y value dependin on i value
	//SDL_Flip(screen);
	x++;
}
else if(g.tab[0][1]==2 && g.tab[0][1] == g.tab[1][1] && g.tab[1][1] == g.tab[2][1]){
	SDL_BlitSurface(lose,NULL,screen,&pos);
	SDL_Flip(screen);
	SDL_Delay(1000);
	//SDL_BlitSurface(cross,NULL,screen,&posC1_2); //need condition to change .y value dependin on i value
	//SDL_Flip(screen);
	x++;
}
else if(g.tab[0][2]==1 && g.tab[0][2] == g.tab[1][2] && g.tab[1][2] == g.tab[2][2]){
	SDL_BlitSurface(win,NULL,screen,&pos);
	SDL_Flip(screen);
	SDL_Delay(1000);
	//SDL_BlitSurface(cross,NULL,screen,&posC1_2); //need condition to change .y value dependin on i value
	//SDL_Flip(screen);
	x++;
}
else if(g.tab[0][2]==2 && g.tab[0][2] == g.tab[1][2] && g.tab[1][2] == g.tab[2][2]){
	SDL_BlitSurface(lose,NULL,screen,&pos);
	SDL_Flip(screen);
	SDL_Delay(1000);
	//SDL_BlitSurface(cross,NULL,screen,&posC1_2); //need condition to change .y value dependin on i value
	//SDL_Flip(screen);
	x++;
}





return x;

}

int verifHorizontal(grille g,SDL_Surface *screen){
	SDL_Surface *win;
 	SDL_Surface *lose;
 	SDL_Rect pos;
 	pos.x=0;
 	pos.y=0;
 	int j;
		win = IMG_Load("win.png");
		lose = IMG_Load("lose.png");

	//	cross = IMG_Load("crossH.png"); need img

	//	draw = IMG_Load("draw.png")
	int x=0;
	if(g.tab[0][0]==1 && g.tab[0][0] == g.tab[0][1] && g.tab[0][1] == g.tab[0][2]){


	SDL_BlitSurface(win,NULL,screen,&pos);
	x++;
	SDL_Delay(1000);
		}

	
 	else if(g.tab[0][0]==2 && g.tab[0][0] == g.tab[0][1] && g.tab[0][1] == g.tab[0][2]){

	SDL_BlitSurface(lose,NULL,screen,&pos);
	x++;
	SDL_Delay(1000);
}
	else if(g.tab[1][0]==1 && g.tab[1][0] == g.tab[1][1] && g.tab[1][1] == g.tab[1][2]){

	SDL_BlitSurface(win,NULL,screen,&pos);
	x++;
	SDL_Delay(1000);
}
else if(g.tab[1][0]==2 && g.tab[1][0] == g.tab[1][1] && g.tab[1][1] == g.tab[1][2]){

	SDL_BlitSurface(lose,NULL,screen,&pos);
	x++;
	SDL_Delay(1000);
}
else if(g.tab[2][0]==1 && g.tab[2][0] == g.tab[2][1] && g.tab[2][1] == g.tab[2][2]){

	SDL_BlitSurface(win,NULL,screen,&pos);
	x++;
	SDL_Delay(1000);
}
else if(g.tab[2][0]==2 && g.tab[2][0] == g.tab[2][1] && g.tab[2][1] == g.tab[2][2]){

	SDL_BlitSurface(lose,NULL,screen,&pos);
	x++;
	SDL_Delay(1000);
}

return x;
	
}


int verifOblique(grille g,SDL_Surface *screen){
	SDL_Surface *win;
 	SDL_Surface *lose;
 	SDL_Rect pos;

 	pos.x=0;
 	pos.y=0;

 	int i;
 	int x=0;
		win = IMG_Load("win.png");
		lose = IMG_Load("lose.png");
		//cross = IMG_Load("crossO.png") need img;
	int j=1;
if(g.tab[1][1]==1){
	if((g.tab[0][0]==1 && g.tab[2][2]==1) || (g.tab[0][2]==1 && g.tab[2][0]==1)){
		SDL_BlitSurface(win,NULL,screen,&pos);
		x++;
		SDL_Delay(1000);
	}
}
	 if(g.tab[1][1]==2){
	if((g.tab[0][0]==2 && g.tab[2][2]==2) || (g.tab[0][2]==2 && g.tab[2][0]==2)){
		SDL_BlitSurface(lose,NULL,screen,&pos);
		x++;
		SDL_Delay(1000);
}
}
 	return x;
	//)
}
int full(grille g, SDL_Surface *screen)
{
	SDL_Surface *draw;
	draw= IMG_Load("draw.png");
	SDL_Rect pos;
	pos.x =0;
	pos.y=0;
	int i,j,nb;
	int x,y,z;
	nb =0;
	for(i=0;i<3;i++){ //verif si la grille est full
	for(j=0;j<3;j++){
		if (g.tab[i][j]==1 || g.tab[i][j]==2){
				nb++;
		}
	}
}
	x =verifHorizontal(g,screen);
	y = verifVertical(g,screen);
	z = verifOblique(g,screen);
if( ((nb==9) && (x == 0)) && ((nb == 9) && (y == 0)) && ( (nb==9) && (z ==0) )){
	SDL_BlitSurface(draw,NULL,screen,&pos);
	return nb;
}
else
return 0;
}
/* int verifGrilleFull(grille g, SDL_Surface *screen)
{
	SDL_Surface *draw;
	SDL_Rect posD;
	posD.x=0;
	posD.y=0;
	draw = IMG_Load("draw.png");
	int i,j;
	int nb=0;
	int a,b,c=0;
	a=verifOblique(g,screen); 
	b=verifHorizontal(g,screen);
	c=verifVertical(g,screen);
	int x=0;
	if(a == 1 || b == 1 || c == 1){
		x++;
		//en cas l'un des joueurs a gagner
	}


	else if(full(g,screen)== 9)	{ //??
		SDL_BlitSurface(draw,NULL,screen,&posD);
		x++;

			}
	return x;
}		 */
int finVie(Vie v,SDL_Surface *screen){
	SDL_Surface *lose;
	SDL_Rect posL;
	lose = IMG_Load("lose.png");
	posL.x=600;
	posL.y=300;
if(v.vie==0){
SDL_BlitSurface(lose,NULL,screen,&posL);
SDL_Flip(screen);
return 1; //joueur mort
}
/*else{
return -1;//joueur vivant
}*/

return -1;
} 