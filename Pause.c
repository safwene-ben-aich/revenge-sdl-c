#include "Pause.h"
#include "Stage_1.h"

int Pause(SDL_Surface *ecran, SDL_Rect camera, SDL_Rect position_objet){
SDL_Rect camera_pause, position_objet_pause;
SDL_Surface *pause=NULL;
int quit =0,i=1 ;
SDL_Event event;
do
{
   switch(i){
case 1 : pause=SDL_LoadBMP("pause_1.bmp");break;
case 2 : pause=SDL_LoadBMP("pause_2.bmp");break;
case 3 : pause=SDL_LoadBMP("pause_3.bmp");break;
case 4 : pause=SDL_LoadBMP("pause_4.bmp");break;
            }
SDL_BlitSurface(pause,NULL,ecran,NULL);
SDL_Flip(ecran);
SDL_WaitEvent(&event);
switch (event.type)
{
    case SDL_KEYUP :
   switch (event.key.keysym.sym){

case SDLK_UP :
i--;
if (i<1){ i=4; }
break;

case SDLK_DOWN :
i++;
if (i>4){ i=1; }
break;
   }
   break ;
case SDL_KEYDOWN :
    switch (event.key.keysym.sym){
case SDLK_SPACE :quit =1 ; break ;
case SDLK_RETURN : if ( i== 1 ) quit =1 ;break ;
                                 }
    break ;}}
while(quit!=1) ;
SDL_FreeSurface(pause);
return 0 ;
}
