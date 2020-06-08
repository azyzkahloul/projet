#ifndef ZOMBIE_H_INCLUDED
#define ZOMBIE_H_INCLUDED
typedef struct
{
SDL_Surface * zombie[11];
SDL_Rect zombiepos;
int i;
int mov;
}zombie;

void initzombie(zombie* z);
void movezombie(zombie* z,SDL_Surface* screen);




#endif 