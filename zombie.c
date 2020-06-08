#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "zombie.h"

void initzombie(zombie* z)
{
z->zombie[0]=IMG_Load("zombie1.png");
z->zombie[1]=IMG_Load("zombie2.png");
z->zombie[2]=IMG_Load("zombie3.png");
z->zombie[3]=IMG_Load("zombie4.png");
z->zombie[4]=IMG_Load("zombie5.png");
z->zombie[5]=IMG_Load("zombie6.png");
z->zombie[6]=IMG_Load("zombie7.png");
z->zombie[7]=IMG_Load("zombie8.png");
z->zombie[8]=IMG_Load("zombie9.png");
z->zombie[9]=IMG_Load("zombie10.png");
z->zombiepos.x=200;
z->zombiepos.y=370;
z->i=0;
z->mov=10;							
}
void movezombie(zombie* z,SDL_Surface* screen)
{
	
z->zombiepos.x=z->zombiepos.x+z->mov;	
SDL_BlitSurface(z->zombie[z->i],NULL,screen,&z->zombiepos);
z->i++;
if(z->i>9)
{
z->i=0;	
}
if(z->zombiepos.x>=330)
{
z->zombiepos.x=330;
z->mov=-10;	
}
if(z->zombiepos.x<200)
{
z->zombiepos.x=200;
z->mov=10;
}
}
	
