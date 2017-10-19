#include "Choix_map.h"
#include "Stage_1.h"
#include "stage_2.h"

void choix_stage(SDL_Surface *ecran){
int continuer=1,i=1;
SDL_Event event;
SDL_Surface *choix_stage=NULL;
SDL_Rect camera, position_objet;
do
{SDL_WaitEvent(&event);
switch (event.type){
case SDL_QUIT : continuer =0;break;
case SDL_KEYUP :
    {switch (event.key.keysym.sym){
case SDLK_LEFT :
i--;
if (i<1){ i=5; }
break;
case SDLK_RIGHT :
i++;
if (i>5){ i=1; }
break;
}
break;}
case SDL_KEYDOWN :
    {
     switch (event.key.keysym.sym){

 case SDLK_ESCAPE : continuer=0;break;
 case SDLK_BACKSPACE : continuer=0 ;break;
  case SDLK_RETURN :
switch (i){
case 1 : main_stage_1(ecran,camera,position_objet,0);
 break;
case 2 : main_stage_2(ecran,camera,position_objet,0); break;
          }
    }}
break ;
}

switch (i){
case 1 : choix_stage=SDL_LoadBMP("choix_stages_1.bmp");break;
case 2 : choix_stage=SDL_LoadBMP("choix_stages_2.bmp");break;
case 3 : choix_stage=SDL_LoadBMP("choix_stages_3.bmp");break;
case 4 : choix_stage=SDL_LoadBMP("choix_stages_4.bmp");break;
case 5 : choix_stage=SDL_LoadBMP("choix_stages_5.bmp");break;
          }
SDL_BlitSurface(choix_stage,NULL,ecran,NULL);
SDL_Flip(ecran);
}
while (continuer) ;

SDL_FreeSurface(choix_stage);
}
