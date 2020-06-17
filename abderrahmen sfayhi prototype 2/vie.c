#include"vie.h"


void Init_Vie(Vie *v)
{
	v->vie=5;
	v->survie=true;
        v->score=100;
}

void Calcul_Vie(Vie *v)
{
	v->vie--;
        v->score-=20;
	if(v->vie==0)
	{
		v->survie=false;
	}
}

void Display_Vie(Vie *v,SDL_Surface*ecran,SDL_Rect position)
{//configuration de vie
SDL_Surface *vie0;
SDL_Surface *vie1;
SDL_Surface *vie2;
SDL_Surface *vie3;
SDL_Surface *vie4;
SDL_Surface *vie5;
SDL_Surface *coa;

vie0  =  IMG_Load( "vie/vie0.png" );
vie1  =  IMG_Load( "vie/vie1.jpg" );
vie2  =  IMG_Load( "vie/vie2.jpg" );
vie3  =  IMG_Load( "vie/vie3.jpg" );
vie4  =  IMG_Load( "vie/vie4.jpg" );
vie5  =  IMG_Load( "vie/vie5.jpg" );
coa   =  IMG_Load( "coa.png" );

SDL_Rect position_vie0;
SDL_Rect position_vie1;
SDL_Rect position_vie2;
SDL_Rect position_vie3;
SDL_Rect position_vie4;
SDL_Rect position_vie5;
SDL_Rect position_coa;

position_vie0.x = 1000 ;position_vie0.y  = 87 ;
position_vie1.x = 1000  ;position_vie1.y  = 0 ;
position_vie2.x = 1000  ;position_vie2.y  = 0 ;
position_vie3.x = 1000  ;position_vie3.y  = 0 ;
position_vie4.x = 1000  ;position_vie4.y  = 0 ;
position_vie5.x = 1000  ;position_vie5.y  = 0 ;
position_coa.x =  1200   ;position_coa.y  = 0 ;

//configuration de score en ttf
TTF_Init();
int tempsdebut=0;
SDL_Color couleurNoire = {0, 0, 0};
TTF_Font *police_score = NULL;
police_score = TTF_OpenFont("arial.ttf", 40);
SDL_Rect position_score;
position_score.x=250 ;position_score.y=0 ;


SDL_Surface *score;
char scor[20];
sprintf(scor, "score : %d", v->score);
score= TTF_RenderText_Blended(police_score, scor, couleurNoire);
SDL_BlitSurface(score, NULL, ecran, &position_score);
SDL_BlitSurface(coa,NULL,ecran,&position_coa);

    
    switch (v->vie)
    {
    case 5:
        SDL_BlitSurface(vie5,NULL,ecran,&position_vie5); break;

    case 4:
        SDL_BlitSurface(vie4,NULL,ecran,&position_vie4);break;

    case 3:
        SDL_BlitSurface(vie3,NULL,ecran,&position_vie3);break;

    case 2:
        SDL_BlitSurface(vie2,NULL,ecran,&position_vie2);break;

    case 1:
        SDL_BlitSurface(vie1,NULL,ecran,&position_vie1);break;

    
    }
}

void Free_vie(Vie *v)
{
	for(int i=1;i<4;i++)
	{
		SDL_FreeSurface(v->Barre[i]);
	}
}
