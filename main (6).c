#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
int menu();

int main()
{
int done=1;
SDL_Init(SDL_INIT_VIDEO);
//TTF_Init();
if(SDL_Init(SDL_INIT_VIDEO))
{
fprintf(stderr,"Erreur : %s\n",SDL_GetError());
}
SDL_Surface* ecran=NULL;
ecran=SDL_SetVideoMode(500,400,32,SDL_HWSURFACE);
if (!ecran)
{printf("unable to set video mode : %s\n",SDL_GetError());
return -1;
}

//creation couleurs
SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255)); //  pour remplir toute la fenetre
SDL_Flip(ecran); //essentiel pour appliquer les changements


//creation background
SDL_Surface *background=NULL;
background = SDL_LoadBMP("Screenshotmenu1.bmp");
if (background == NULL) {
printf("unable to load image %s\n",SDL_GetError());
return 1;}
SDL_Rect background_pos;
background_pos.x=0;
background_pos.y=0;
SDL_BlitSurface(background,NULL,ecran,&background_pos);
SDL_Flip(ecran);


//si on importe des icons jouer/options/exit
/*
SDL_Surface* jouer=NULL;
jouer=IMG_Load("jouer.jpg");
if(jouer==NULL)
{
fprintf(stderr,"erreur %s\n",SDL_GetError());
return 1;
}

SDL_Rect jouer_pos;
jouer_pos.x=200;
jouer_pos.y=100;
jouer_pos.h=15;
jouer_pos.w=15;
SDL_BlitSurface(jouer,NULL,ecran,&jouer_pos);
SDL_Flip(ecran);



SDL_Surface* parametre;
parametre=IMG_Load("parametres.png");
SDL_Rect parametre_pos;
parametre_pos.x=200;
parametre_pos.y=300;
parametre_pos.h=100;
parametre_pos.w=100;
SDL_BlitSurface(parametre,&parametre_pos,ecran,NULL);
SDL_Flip(ecran);


SDL_Surface* quitter;
quitter=IMG_Load("quitter.bmp")       ;
SDL_Rect quitter_pos;
quitter_pos.x=200;
quitter_pos.y=300;
quitter_pos.h=10;
quitter_pos.w=10;
SDL_FillRect(jouer,NULL,SDL_MapRGB(quitter->format,0,0,120));
SDL_BlitSurface(quitter,NULL,ecran,&quitter_pos);
SDL_Flip(ecran);
*/


while(done)
{
SDL_Event event;
SDL_WaitEvent(&event);
switch(event.type)
{
case SDL_QUIT:
done=0;
break;
case SDL_MOUSEBUTTONUP:
if(((event.button.x>100)&&(event.button.x<200))&&((event.button.y>150)&&(event.button.y<200)))
{

if(menu()==1)
{
done=0;
}


}
break;
}
}
//SDL_FreeSurface(quitter);
//SDL_FreeSurface(texte);
SDL_FreeSurface(ecran);
//SDL_FreeSurface(jouer);
//SDL_FreeSurface(parametre);

SDL_Quit();
}

/*
*********************************************************************
*/

int menu()
{

char pause;
int done=1,p=1;

SDL_Init(SDL_INIT_VIDEO);
if (SDL_Init(SDL_INIT_VIDEO)!=0)
{printf("unable to initialize SDL : %s\n",SDL_GetError());
return 1;
}
TTF_Init();

//fenetre principale
SDL_Surface *fenetre;
fenetre=SDL_SetVideoMode (700,500,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if (!fenetre)
{printf("unable to set video mode : %s\n",SDL_GetError());
return -1;
}
SDL_WM_SetCaption("THE DETECTIVE GAME",NULL);  //titre de la fenetre
//creation couleurs
SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,255,255,255)); //  pour remplir toute la fenetre
SDL_Flip(fenetre); //essentiel pour appliquer les changements




//creation background
SDL_Surface *background=NULL;
background = SDL_LoadBMP("background.bmp");
if (background == NULL) {
printf("unable to load image %s\n",SDL_GetError());
return 1;}
SDL_Rect background_pos;
background_pos.x=150;
background_pos.y=0;
SDL_BlitSurface(background,NULL,fenetre,&background_pos);
SDL_Flip(fenetre);








//creation personnage principal
SDL_Surface *pp=NULL;
pp=IMG_Load("detective.png");
if (pp == NULL) {
printf("unable to load image %s\n",SDL_GetError());
return 1;}
SDL_Rect pp_pos;
pp_pos.x=0;
pp_pos.y=200;
SDL_BlitSurface(pp,NULL,fenetre,&pp_pos);
SDL_Flip(fenetre);



//set camera
SDL_Rect camera_pos;
camera_pos.w=700;
camera_pos.h=500;


const int speed_sides =30; // sans if 2 avec if 30
const int speed_up_down=15; //sans if 1 avec if 15


//boucle pseudo infini
SDL_Event event;
int now=0,before=0,interval=50;
while (done)
{
now=SDL_GetTicks();
if (SDL_PollEvent(&event)){
//WaitEvent ==> le prog ne fait rien si on n'appuie pas sur une touche (comme solitaire) ** PollEvent ==> le programme marche meme si on appuie pas (comme pacman)
switch(event.type)
{
case SDL_QUIT : done = 0; break;// quitte si on appuie sur (x) au menu de la fenetre

case SDL_KEYDOWN : //SDL_KEYDOWN ==> si une touche est pressée ** SDL_KEYUP ==> si une touche est lachée


//mvt droite : avancer
if(event.key.keysym.sym == SDLK_RIGHT) {
if (pp_pos.x>=300 && camera_pos.x<=850) camera_pos.x+=speed_sides;
else pp_pos.x+=speed_sides;
if (pp_pos.x+camera_pos.x>=obstacle_pos.x && camera_pos.x<=850)
obstacle_pos.x-=speed_sides;
//collision avec obstacle
if( (pp_pos.y + pp->h < obstacle_pos.y + obstacle->h) && (pp_pos.y + pp->h > obstacle_pos.y+40) && (pp_pos.x + pp->w > obstacle_pos.x+40) && (pp_pos.x < obstacle_pos.x+obstacle->w - 20) )
{
life_remaining--;
pp_pos.x-=5*speed_sides;
}
}


//mvt gauche : reculer
if(event.key.keysym.sym == SDLK_LEFT)  {
if (pp_pos.x<=300 && camera_pos.x>0) camera_pos.x-=speed_sides;
else pp_pos.x-=speed_sides;
if (pp_pos.x+camera_pos.x>=obstacle_pos.x && camera_pos.x<=850 && pp_pos.x<=300)
obstacle_pos.x+=speed_sides;
//collision avec obstacle
if( (pp_pos.y + pp->h < obstacle_pos.y + obstacle->h) && (pp_pos.y + pp->h > obstacle_pos.y+40) && (pp_pos.x + pp->w > obstacle_pos.x+40) && (pp_pos.x < obstacle_pos.x+obstacle->w - 40) )
{
life_remaining--;
pp_pos.x+=3*speed_sides;
}
}

//mvt haut
if(event.key.keysym.sym == SDLK_UP){
if (pp_pos.y > 100) // n'entre pas dans les arbres
pp_pos.y-=speed_up_down;
//collision avec obstacle
if( (pp_pos.y + pp->h < obstacle_pos.y + obstacle->h) && (pp_pos.y + pp->h > obstacle_pos.y+20) && (pp_pos.x + pp->w > obstacle_pos.x+40) && (pp_pos.x < obstacle_pos.x+obstacle->w - 40) )
{
life_remaining--;
pp_pos.y+=2*speed_sides;
}
}


//mvt bas
if(event.key.keysym.sym == SDLK_DOWN){
if (pp_pos.y < 250) //ne depasse pas l'ecran
pp_pos.y+=speed_up_down;
//collision avec obstacle
if( (pp_pos.y + pp->h < obstacle_pos.y + obstacle->h) && (pp_pos.y + pp->h > obstacle_pos.y+30) && (pp_pos.x + pp->w > obstacle_pos.x+40) && (pp_pos.x < obstacle_pos.x+obstacle->w - 40) )
{
life_remaining--;
pp_pos.y-=2*speed_sides;
}
}


//create delay
if(now-before<interval)
SDL_Delay(interval-now+before);

break;
}
}

//refresh
SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,255,255,255));
SDL_BlitSurface (background,&camera_pos,fenetre,NULL);
if(obstacle_pos.x >= 0 && obstacle_pos.x <= 700) SDL_BlitSurface(obstacle,NULL,fenetre,&obstacle_pos);
SDL_BlitSurface(pp,NULL,fenetre,&pp_pos);
before=now;
SDL_Flip(fenetre);
}





SDL_FreeSurface(background);
SDL_FreeSurface (fenetre);
TTF_Quit();
SDL_Quit();
return p ;
}
