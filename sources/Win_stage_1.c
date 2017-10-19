#include "Win_stage_1.h"
#include "Stage_1.h"
#define TIME_BEETWEN_2_FRAMES 8

void Win1(SDL_Surface *ecran,SDL_Rect position_objet_pause, SDL_Rect camera_pause, int stage)
{

    SDL_Rect position_base ,pos_water, pos_cube , position_objet,camera ,pos_elevator,pos_elevator2,pos_p;
    int compteur=0,cpt_water =0, i=0,elv_y=0,cpt_t=0,elv2_y=0 ,dans_l_air=0 ,in_up_down=0 ,end_n=1 ,cpt_u_r=0,cpt_u_l=0 ,mvt_up_right=0 ;

    int cpt_n [5]= {0,0,0,0,0} ;
    SDL_Rect pos_cld_1 ,pos_cld_2,pos_cld_3,pos_cld_4,pos_cld_5;
    SDL_Surface *cld_1=NULL ,*squelette=NULL,*cube=NULL,*eft_water=NULL,*elevator=NULL,*cld_2=NULL,*pg=NULL , *cld_3=NULL ,*cld_4=NULL,*cld_5=NULL;
    SDL_Rect police ;
    police.x = 1250;
    police.y=615 ;
    int cpt_elv=0 ,cpt_water_mvt=0,i_water=0,up_and_down =0,up_down=0 ;
    squelette=SDL_LoadBMP("squelette.bmp") ;
    pos_elevator.x=100  ;
    pos_elevator.y=400 ;
    pos_elevator2.x=1200  ;
    pos_elevator2.y=250 ;
    Uint8 g=0,r=255;

    SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
    _Couleur_ loun;
//    sprintf(temps, "Temps : %d", compteur);
    SDL_Surface *test_map=NULL ,*water=NULL ,*sprite2=NULL ,*sprite3=NULL,*sprite4=NULL,*fond_base=NULL,*noir=NULL,*sprite=NULL;
    position_objet.x=500;
    position_objet.y=33;
    pos_p.x=830 ;
    pos_p.y= 540 ; SDL_FreeSurface(elevator) ;    elevator=SDL_LoadBMP("up_down.bmp") ;
    SDL_FreeSurface(sprite)   ;    sprite =SDL_LoadBMP("sprite.bmp");
    SDL_FreeSurface(sprite2)  ;    sprite2=SDL_LoadBMP("sprite_g.bmp");
    SDL_FreeSurface(sprite3)  ;    sprite3=SDL_LoadBMP("police_d.bmp") ;
    SDL_FreeSurface(sprite4)  ;    sprite4=SDL_LoadBMP("police_g.bmp") ;
    SDL_FreeSurface(water)    ;    water =SDL_LoadBMP("water.bmp") ;
    SDL_Rect position_sprite, position_sprite2 ,position_sprite3,position_sprite4;
    SDL_Event event,event2;
    int left=0,right=0,mvt_up_left=0,continuer=1,mvt_r=0,mvt_l=0,cpt=0,mvt_up=0,i_pause=1;
    int FPS=30;
    int speed=4;
    Uint32 start ;

    int time_frame=0,verif_frame=0,time_frame2=0,pos_sprite3 =0,verif_frame2=0,time_frame3=0,verif_frame3=0,time_frame4=0,verif_frame4=0;


    SDL_FreeSurface(test_map)  ;   test_map=SDL_LoadBMP("_map_test1.bmp");
    SDL_FreeSurface(fond_base) ;   fond_base=SDL_LoadBMP("map_stg1.bmp");
    SDL_FreeSurface(noir)      ;   noir=SDL_LoadBMP("noir.bmp");
    SDL_FreeSurface(cube)      ;   cube=SDL_LoadBMP("box.bmp") ;
    int pos_sprite=0,pos_sprite2=0,pos_sprite4=0;
    SDL_EnableKeyRepeat(10,10);

    position_sprite.w=142;
    position_sprite.h=170;
    position_sprite.x=0;
    position_sprite.y=0;
    position_sprite2.w=142;
    position_sprite2.h=140;
    position_sprite2.x=0;
    position_sprite2.y=0;
    position_sprite3.w=142;
    position_sprite3.h=170  ;
    position_sprite3.x=0;
    position_sprite3.y=0;
    position_sprite4.w=142;
    position_sprite4.h=140;
    position_sprite4.x=0;
    position_sprite4.y=0;
    camera.x=0;
    camera.y=0 ;
    camera.w=1366;
    camera.h=300;
    pos_water.x=0 ;
    pos_water.y=468 ;

    pos_cube.x= 540 ;
    pos_cube.y= 672 ;

    while (continuer)
    {

        if (verif_frame)
        {
            time_frame   =0 ;
            pos_sprite   ++ ;
            verif_frame  =0 ;
        }
        if (verif_frame2)
        {
            time_frame2  =0 ;
            pos_sprite2  ++ ;
            verif_frame2 =0 ;
        }
        if (verif_frame3)
        {
            time_frame3   =0 ;
            pos_sprite3   ++ ;
            verif_frame3  =0 ;
        }
        if (verif_frame4)
        {
            time_frame4   =0 ;
            pos_sprite4   ++ ;
            verif_frame4  =0 ;
        }

        start=SDL_GetTicks();
        SDL_PollEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT :
            exit(1);
            break;

        case SDL_KEYDOWN :
            switch (event.key.keysym.sym)
            {
            case SDLK_SPACE  :
                continuer=0              ;
                break ;
            }
            break ;
        }



        elv_y =  pos_elevator.y-noir->h ;
        elv2_y= pos_elevator2.y-noir->h ;
 affichage(ecran,fond_base,0,0,23,0,position_base,0) ;
        if (!up_and_down)
        {
            SDL_FreeSurface(pg);
            pg=SDL_LoadBMP("p_1.bmp") ;
            if ( position_objet.y>(elv2_y-40)&& position_objet.y <(elv2_y+40) && position_objet.x>1050 && position_objet.x< 1250)
            {
                in_up_down =1 ;
                dans_l_air=0;
            }
            else
            {
                in_up_down =0 ;
            }
            cpt_elv ++ ;
            if (cpt_elv==3)
            {
                if ( pos_elevator2.y == 250 )
                {
                    up_down =0  ;
                }
                if ( pos_elevator2.y == 400 )
                {
                    up_down =1  ;
                }
                if (!up_down)
                {
                    pos_elevator2.y+=1;
                }
                if ( up_down)
                {
                    pos_elevator2.y-=1;
                }
                if ( in_up_down)
                {
                    if (!mvt_up&& !mvt_up_left&& !mvt_up_right )
                    {
                        position_objet.y=4-noir->h+ pos_elevator2.y ;
                    }
                }
                cpt_elv =0 ;
            }
            affichage(ecran,elevator,pos_elevator2.x,pos_elevator2.y,240,0,position_sprite3,0) ;
        }
        if (up_and_down)
        {
            SDL_FreeSurface(pg);
            pg=SDL_LoadBMP("p_2.bmp") ;

            cpt_elv ++ ;
            if (cpt_elv==3)
            {
                if ( pos_elevator.y == 400 )
                {
                    up_down =0  ;
                }
                if ( pos_elevator.y == 525 )
                {
                    up_down =1  ;
                }

                if (!up_down)
                {
                    pos_elevator.y+=1;
                }
                if ( up_down)
                {
                    pos_elevator.y-=1;
                }
                cpt_elv =0 ;
            }
            affichage(ecran,elevator,pos_elevator.x,pos_elevator.y,240,0,position_sprite3,0) ;
        }

        affichage(ecran,pg,pos_p.x,pos_p.y,240,1,position_sprite3,0) ;


   if (!mvt_r) {affichage(ecran , sprite,position_objet.x,position_objet.y,0,0,position_sprite,1) ;}
   else if (mvt_r) { position_objet.x+=2; time_frame++ ;   affichage(ecran, sprite,position_objet.x,position_objet.y,0,0,position_sprite,1) ; }

 if (position_objet.x>1400) {continuer=0 ;}

if (!end_n)
    {

       if ( police.x >860 && right==0 ) {police.x-=3 ; time_frame4++;   affichage(ecran,sprite4,police.x,police.y,0,0,position_sprite4,1); }

      else if (police.x<1200  ) {
              police.x +=3 ; time_frame3 ++ ; right =1 ;   affichage(ecran,sprite3,police.x,police.y,0,0,position_sprite3,1) ; }
            else {right =0 ;mvt_r=1 ; }
    }

        affichage(ecran,cube,800,pos_cube.y,0,0,position_sprite3,0) ;

        if (end_n)
        {
             cpt_water_mvt++ ;
            pos_water.y++ ;
            if (cpt_water_mvt==4)
            {


                i_water ++ ;
                switch ( i_water )
                {
                case 1 :
                    SDL_FreeSurface(water ) ;
                    water=SDL_LoadBMP("water_1.bmp") ;
                    break ;
                case 2 :
                    SDL_FreeSurface(water ) ;
                    water=SDL_LoadBMP("water_2.bmp") ;
                    break ;
                case 3 :
                    SDL_FreeSurface(water ) ;
                    water=SDL_LoadBMP("water_3.bmp") ;
                    break ;
                case 4 :
                    SDL_FreeSurface(water ) ;
                    water=SDL_LoadBMP("water_4.bmp") ;
                    break ;
                case 5 :
                    SDL_FreeSurface(water ) ;
                    water=SDL_LoadBMP("water_5.bmp") ;
                    break ;
                case 6 :
                    SDL_FreeSurface(water ) ;
                    water=SDL_LoadBMP("water_6.bmp") ;
                    break ;
                case 7 :
                    SDL_FreeSurface(water ) ;
                    water=SDL_LoadBMP("water_7.bmp") ;
                    i_water =0    ;
                    break ;
                }
                cpt_water_mvt=0 ;
            }

            affichage(ecran,water,pos_water.x,pos_water.y,220,1,camera,1) ;
            if ( pos_water.y>=768 )
            {
                end_n =0 ;
            }
        }

            affichage(ecran,squelette,0,0,0,0,position_base,0) ;
        SDL_Flip(ecran) ;

        if (time_frame==3)
        {  position_sprite.x=pos_sprite*150;
            verif_frame=1;        }
        if (pos_sprite==27)
        {
            pos_sprite=1;
        }

        if (time_frame2==3)
        {
            position_sprite2.x=pos_sprite2*150;
            verif_frame2=1;
        }
        if (pos_sprite2==27)
        {
            pos_sprite2=1;
        }

        if (time_frame3==6)
        {
            position_sprite3.x=pos_sprite3*142;
            verif_frame3=1;
        }
        if (pos_sprite3==8)
        {
            pos_sprite3=1;
        }
        if (time_frame4==6)
        {
            position_sprite4.x=pos_sprite4*142;
            verif_frame4=1;
        }
        if (pos_sprite4==8)
        {
            pos_sprite4=1;
        }

        if(280/FPS > SDL_GetTicks()-start)
        {
            SDL_Delay(330/FPS-(SDL_GetTicks()-start));
        }


    }

}


