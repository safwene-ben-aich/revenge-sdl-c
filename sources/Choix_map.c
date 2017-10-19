#include "Choix_map.h"
#include "Stage_1.h"
#include "Stage_2.h"
#include "Stage_3.h"
#include "Stage_4.h"
#include "Chargement.h"
//#include "Stage_5.h"
void choix_stage(SDL_Surface *ecran,int *stage_dispo, int *difficulter)
{

    int continuer=1,i=1;
    SDL_Event event;
    SDL_Surface *choix_stage=NULL;
    SDL_Rect camera, position_objet;

    SDL_EnableKeyRepeat(10,100);
     while (continuer)
    {

        switch (i)
        {
        case 1 :

            choix_stage=SDL_LoadBMP("choix_stages_1_open.bmp");

            break;
        case 2 :
            if (*(stage_dispo)<2)
            {
                choix_stage=SDL_LoadBMP("choix_stages_2_closed.bmp");
            }
            else if (*(stage_dispo)>=2)
            {
                 choix_stage=SDL_LoadBMP("choix_stages_2_open.bmp");
            }
            break;

        case 3 :
             if (*(stage_dispo)<3)
            {
                choix_stage=SDL_LoadBMP("choix_stages_3_closed.bmp");
            }
            else if (*(stage_dispo)>=3)
            {
                choix_stage=SDL_LoadBMP("choix_stages_3_open.bmp");
            }

            break;
        case 4 :

             if (*(stage_dispo)<4)
            {

                choix_stage=SDL_LoadBMP("choix_stages_4_closed.bmp");
            }
            else if (*(stage_dispo)>=4)
            {
                choix_stage=SDL_LoadBMP("choix_stages_4_open.bmp");
            }
            break;
        case 5 :

              if (*(stage_dispo)<5)
            {

                choix_stage=SDL_LoadBMP("choix_stages_5_closed.bmp");
            }
            else if (*(stage_dispo)>=5)
            {
                choix_stage=SDL_LoadBMP("choix_stages_5_open.bmp");
            }
            break;
        }
   SDL_Flip(ecran) ;
       SDL_WaitEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT :
            continuer =0;
            break;
        case SDL_KEYDOWN :

            switch (event.key.keysym.sym)
            {

            case SDLK_ESCAPE :
                menu_principale(ecran,stage_dispo,difficulter);
                break;

            case SDLK_BACKSPACE :
                menu_principale(ecran,stage_dispo,difficulter);
                break;

            case SDLK_LEFT :
                i--;
                if (i<1)
                {
                    i=5;
                }
                break;
            case SDLK_RIGHT :
                i++;
                if (i>5)
                {
                    i=1;
                }
                break;
            case SDLK_RETURN :
                switch (i)
                {
                case 1 :
                {
                    Chargement(ecran,stage_dispo,difficulter) ;
                    main_stage_1(ecran,1,stage_dispo,difficulter);
                    Win1(ecran,position_objet,camera,1);
                    Chargement(ecran,stage_dispo,difficulter) ;

                }
                    break;
                case 2 :
                    if (*(stage_dispo)>=2)
                    {
                    Chargement(ecran,stage_dispo,difficulter) ;
                    main_stage_2(ecran,2,stage_dispo,difficulter);
                    Chargement(ecran,stage_dispo,difficulter) ;

                   } break;

                case 3 :
                    if (*(stage_dispo)>=3)
                    {
                       Chargement(ecran,stage_dispo,difficulter) ;

                         main_stage_3(ecran, 3,stage_dispo,difficulter);
                         Chargement(ecran,stage_dispo,difficulter) ;
                                  }
                    break;
                case 4 :
                    if (*(stage_dispo)>=4)
                 {
                    Chargement(ecran,stage_dispo,difficulter) ;
                    main_stage_4(ecran,4,stage_dispo,difficulter);
                    Chargement(ecran,stage_dispo,difficulter) ;
                }
                    break;
                case 5 :
                    if (*(stage_dispo)>=5)
                    {
                        Chargement(ecran,stage_dispo,difficulter) ;
                        main_stage_5(ecran,5,stage_dispo,difficulter);
                        Chargement(ecran,stage_dispo,difficulter) ;
                    } break;
                }

                break;



            }
            break;
        }


        SDL_BlitSurface(choix_stage,NULL,ecran,NULL);
        SDL_Flip(ecran);
        SDL_FreeSurface(choix_stage);

    }

}
