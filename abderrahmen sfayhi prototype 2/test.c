#include <stdio.h>
#include <stdlib.h>
#include "enigme.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <time.h>
#include "fin.h"
#include "enigme.h"

int main() {
SDL_Surface *screen;
SDL_Init(SDL_INIT_VIDEO);
screen = SDL_SetVideoMode(638,597,32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
SDL_WM_SetCaption("ia2.exe",NULL);
//int x = rand();
//int tab[3][3];//= {(1,2,3) , (4, 5 ,6),(7,8,9)};
/*tab[0][0]=0;
tab[0][1]=0;
tab[0][2]=0;
tab[1][0]=0;
tab[1][1]=0;
tab[1][2]=0;
tab[2][0]=0;
tab[2][1]=0;
tab[2][2]=0; */
grille a;
a=initGrille();
a.tab[0][0]=0;
a.tab[0][1]=0;
a.tab[0][2]=0;
a.tab[1][0]=0;
a.tab[1][1]=0;
a.tab[1][2]=0;
a.tab[2][0]=0;
a.tab[2][1]=0;
a.tab[2][2]=0;
int x=0;
int y=0;
int z=0;
int nb=0;
int draw=0;
//affGrille(a,screen);
int verifHorizontal(grille g,SDL_Surface *screen);
int verifGrilleFull(grille a,SDL_Surface *screen);
int verifVertical(grille g,SDL_Surface *screen);
int verifOblique(grille g,SDL_Surface *screen);
void affMatrice(grille g);
int full(grille g, SDL_Surface *screen);
/*int rand(){
//srand(time(0)); //probleme long returns long int
int num;
    num =  rand() % 10	;
return num;
}*/
affGrille(a,screen);
SDL_Flip(screen);

do{

affMatrice(a);
joueurPrincipale(screen,&a);
draw=full(a,screen);
	x =verifHorizontal(a,screen);
	y = verifVertical(a,screen);
	z = verifOblique(a,screen);

SDL_Flip(screen);
if(x==1 || y == 1 || z == 1 || draw == 9){
	nb = x+y+z+draw;
	SDL_Delay(2000);
	break;
}

SDL_Delay(900);

/*if(verifGrilleFull(a,screen) == 1){
printf("2\n");
	break;*/	


//printf("%d",verifOblique(a,screen));
//verifVertical(a,screen);
//verifOblique(a,screen);
//printf("-----------------");
ia(screen,&a);
SDL_Flip(screen);
draw=full(a,screen);
	x =verifHorizontal(a,screen);
	y = verifVertical(a,screen);
	z = verifOblique(a,screen);

SDL_Flip(screen);
if(x==1 || y == 1 || z == 1 || draw == 9){
	nb = x+y+z+draw;
	SDL_Delay(2000);
	break;
}
//printf("%d",verifOblique(a,screen));
//verifVertical(a,screen);
//verifOblique(a,screen);

affMatrice(a);

//x = verifVertical(a,screen);
//} while(x!= 1);

//x=verifGrilleFull(a,screen);
}while(nb != 1 );
SDL_Quit();


return 0;
}
/* grille g;
g = initGrille();
affGrille();
joueurPrincipale();
coupPossible();
ia(); */