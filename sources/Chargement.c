#include "Chargement.h"
void Chargement (SDL_Surface *ecran, int *stage_dispo,int *difficulter)
{
    SDL_Surface *chargement=NULL;
    int i=0,continuer=0;
    SDL_Event event;
    while (continuer!=18)
    {
i++;
continuer++;
if ((continuer%3)==0)
{
i=1;
}
SDL_PollEvent(&event);

switch (i)
{
case 1 : chargement=SDL_LoadBMP("chargement_1.bmp");break;
case 2 : chargement=SDL_LoadBMP("chargement_2.bmp");break;
case 3 : chargement=SDL_LoadBMP("chargement_3.bmp");break;
}



        switch (event.type)
        {
        case SDL_QUIT :
            exit(1);
            break;
        case SDL_KEYDOWN :
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE :
                choix_stage(ecran,stage_dispo,difficulter);
                break;
            case SDLK_SPACE :
                choix_stage(ecran,stage_dispo,difficulter);
                break ;

            }
            break;
        }

    SDL_BlitSurface(chargement,NULL,ecran,NULL);
    SDL_Flip(ecran);
    SDL_FreeSurface(chargement);

    SDL_Delay(400);

}



}



