#include "Stage_1.h"
#define TIME_BEETWEN_2_FRAMES 8

void main_stage_1(SDL_Surface *ecran, int stage, int *stage_dispo,int *difficulter)
{


    Mix_AllocateChannels(10);
    Mix_Music *musique_run, *musique_water,*musique_jump;
    musique_run= Mix_LoadWAV("run.wav");
    Mix_VolumeChunk(musique_run,MIX_MAX_VOLUME/4);
        musique_water =Mix_LoadWAV("water_sound.wav");
    Mix_VolumeChunk(musique_water,(MIX_MAX_VOLUME)*2);
    musique_jump =Mix_LoadWAV("jump.wav");
    Mix_VolumeChunk(musique_jump,(MIX_MAX_VOLUME));

    SDL_Rect  position_base ,pos_water, pos_eft_water ,pos_cube , position_objet,camera ,pos_elevator,pos_elevator2,pos_p;
    int compteur=0,cpt_s_w=0,cpt_sound=300,cpt_water =0,kel_3bed =0,cpt_fin=0 ,surf=0 ,i=0,elv_y=0,cpt_t=0,elv2_y=0 ,dans_l_air=0 ,in_up_down=0 ,end_n=0 ,cpt_u_r=0,cpt_u_l=0 ,mvt_up_right=0 ;

    int cpt_n [5]= {0,0,0,0,0},a=0 ;
    SDL_Rect pos_cld_1 ,pos_cld_2,position_texte,pos_cld_3,pos_cld_4,pos_cld_5;
    SDL_Surface *texte=NULL,*gameover=NULL,*uwin=NULL , *cld_1=NULL ,*squelette=NULL,*cube=NULL,*eft_water=NULL,*elevator=NULL,*cld_2=NULL,*pg=NULL , *cld_3=NULL ,*cld_4=NULL,*cld_5=NULL;
    int X[20]= {945,920,890,880,850,790,750,722,665,605,544,515,455,403,353,310,255,186,180,150} ;
    int Y[20]= {60,40,50,60,75,95,90,80,45,80,86,70,50,40,45,50,88,40,145,109} ;
    position_texte.x=1280 ;
    position_texte.y=35 ;
    int cpt_elv=0 ,jouer=0,cpt_jeu=0,cpt_aide=0,cpt_water_mvt=0,i_water=0,up_and_down =0,up_down=0 ;
    squelette=SDL_LoadBMP("squelette.bmp") ;
    pos_elevator.x=100  ;
    pos_elevator.y=400 ;
    pos_elevator2.x=1200  ;
    pos_elevator2.y=250 ;

    SDL_Surface *me_perso_g_g =NULL , *me_perso_g_d=NULL ,*me_perso_d_d=NULL , *me_perso_d_g=NULL ,*me_perso_t=NULL ;
    me_perso_d_d=SDL_LoadBMP("me-perso+d.bmp") ;
    me_perso_d_g=SDL_LoadBMP("me-perso-d.bmp") ;
    me_perso_g_d=SDL_LoadBMP("me-perso-g.bmp") ;
    me_perso_g_g=SDL_LoadBMP("me-perso+g.bmp") ;
    me_perso_t  =SDL_LoadBMP("me-perso-t.bmp") ;
    uwin=SDL_LoadBMP("youwin.bmp");
    gameover=SDL_LoadBMP("gameover.bmp");
int precedent_water_x,precedent_water_y;
char text_aide [1000] ="" ;

    Uint8 g=0,r=255;
    SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
    _Couleur_ loun;
    SDL_Surface *test_map=NULL ,*water=NULL ,*sprite2=NULL ,*sprite3=NULL,*sprite4=NULL,*fond_base=NULL,*noir=NULL,*sprite=NULL;
    position_objet.x=100;
    position_objet.y=610;
    pos_p.x=830 ;
    pos_p.y= 540 ;
    elevator=SDL_LoadBMP("up_down.bmp") ;
    sprite =SDL_LoadBMP("sprite_d.bmp");
    sprite2=SDL_LoadBMP("sprite_g.bmp");
    sprite3=SDL_LoadBMP("tanguiza_r.bmp") ;
    sprite4=SDL_LoadBMP("tanguiza_l.bmp") ;
    water =SDL_LoadBMP("water.bmp") ;
    SDL_Rect position_sprite , position_sprite2 ,position_sprite3,position_sprite4;
    SDL_Event event,event2;
    int left=0,right=1,mvt_up_left=0,continuer=1,mvt_r=0,mvt_l=0,cpt=0,mvt_up=0,i_pause=1,you_lose=0;
    int FPS=30;
    int speed=4;
    Uint32 start ;

    int time_frame=0,timer_cpt=0 , time_min=1,time_sec=30, verif_frame=0,time_frame2=0,pos_sprite3 =0,verif_frame2=0,time_frame3=0,verif_frame3=0,time_frame4=0,verif_frame4=0;

   char time[5]="01:30";

    TTF_Font *police = NULL;
    TTF_Init();
    police = TTF_OpenFont("aaa.ttf", 25);

    test_map=SDL_LoadBMP("_map_test1.bmp");
    fond_base=SDL_LoadBMP("map_stg1.bmp");
    noir=SDL_LoadBMP("noir.bmp");
    cube=SDL_LoadBMP("box.bmp") ;
    int pos_sprite=0,pos_sprite2=0,pos_sprite4=0;
    SDL_EnableKeyRepeat(10,10);

    position_sprite.w=150;
    position_sprite.h=105;
    position_sprite.x=150;
    position_sprite.y=0;
    position_sprite2.w=150;
    position_sprite2.h=105;
    position_sprite2.x=150;
    position_sprite2.y=0;
    position_sprite3.w=150;
    position_sprite3.h=105;
    position_sprite3.x=150;
    position_sprite3.y=0;
    position_sprite4.w=150;
    position_sprite4.h=105;
    position_sprite4.x=150;
    position_sprite4.y=0;
    camera.x=210;
    camera.y=0 ;
    camera.w=30;
    camera.h=20;
    pos_water.x=210 ;
    pos_water.y=720 ;

    pos_cube.x= 540 ;
    pos_cube.y= 672 ;
    Musique(1);
int ordre_blit_water=0;
if (*(difficulter)==3) {jouer=1 ; }
    while (continuer)
    {
start=SDL_GetTicks();
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


        SDL_PollEvent(&event);
 if (jouer==0)
 {if (*(difficulter)==1)
  {   position_texte.x=400;
   position_texte.y=300;
   cpt_jeu++ ;
  if (cpt_jeu==700)
  {
   cpt_aide++ ;
   cpt_jeu=0;
  }
  switch (cpt_aide)
  {case 0 :
  sprintf(text_aide,"you should open the water tap using the key 'c ' ");
  break ;
  case 1 :
      position_texte.x-=30;
  sprintf(text_aide,"when the water rich the switcher it will be desactivated");
  break ;
  case 2 :
      position_texte.x+=20;
  sprintf(text_aide,"the ellevater will appear on the right side");
    break ;
  case 3 :
      position_texte.x+=130;
  sprintf(text_aide,"good luck !");

    break ;
  case 4 :
    jouer=1 ;
    position_texte.x=1280;
    position_texte.y=35;
    break ;
  }
        SDL_BlitSurface(fond_base,NULL,ecran,NULL) ;
      texte = TTF_RenderText_Shaded(police, text_aide ,couleurBlanche, couleurNoire);
       SDL_BlitSurface(texte,NULL,ecran,&position_texte);

   SDL_Flip(ecran) ;
  }
  else if (*(difficulter)==2)
  {
   position_texte.x=400;
   position_texte.y=300;
   cpt_jeu++ ;
  if (cpt_jeu==500)
  {
   cpt_aide++ ;
   cpt_jeu=0;
  }
  switch (cpt_aide)
  {case 0 :
  sprintf(text_aide,"in high temperature the ice cube melt");
  break ;
  case 1 :
      position_texte.x-=30;
  sprintf(text_aide,"you should find a solution to block the gas ");
  break ;
  case 2 :
      position_texte.x+=150;
  sprintf(text_aide,"good luck !! ");
    break ;
  case 3 :
    jouer=1 ;
    position_texte.x=1280;
    position_texte.y=35;
    break ;
  }
        SDL_BlitSurface(fond_base,NULL,ecran,NULL) ;
      texte = TTF_RenderText_Shaded(police, text_aide ,couleurBlanche, couleurNoire);
       SDL_BlitSurface(texte,NULL,ecran,&position_texte);

   SDL_Flip(ecran) ;
  }
    }
 else if (jouer ==1)
        {
            switch (event.type)
        {
        case SDL_QUIT :
            exit(1);
            break;

        case SDL_KEYDOWN :
            switch (event.key.keysym.sym)
            {
            case SDLK_SPACE  :
                position_objet.y=400               ;
                break ;
            case SDLK_ESCAPE :
                Pause(ecran,NULL,position_objet,1) ;
                break ;
            case SDLK_UP :
                if (!dans_l_air)
                {    Mix_PlayChannel(3,musique_jump,1);
                    mvt_up=1 ;
                    dans_l_air =1 ;
                }
                break ;

            case SDLK_RIGHT :
                time_frame++;
                if(!Verif_collision_objet(position_objet,test_map,noir))
                {       cpt_sound++;
                       if (cpt_sound>=300)    { Mix_PlayChannel(2,musique_run,1);cpt_sound=0; }
                    mvt_r =1 ;

                    position_objet.x+=3;
                }
                break;
                SDL_PollEvent(&event2);
                switch (event2.type)
                {
                case   SDL_KEYDOWN :
                    switch (event2.key.keysym.sym)
                    {
                    case SDLK_UP :
                        if (!dans_l_air)
                        {
                            mvt_up_right =1 ;
                            dans_l_air  = 1 ;
                            position_objet.x-=4;
                        }
                        break ;
                    }
                    break ;
                case   SDL_KEYUP :
                    switch (event2.key.keysym.sym)
                    {
                    case SDLK_UP :
                        if ((!dans_l_air)&& (!cpt_u_r) )
                        {
                            mvt_up_right= 0;
                            dans_l_air  = 0 ;
                            position_objet.x-=2;
                        }
                        break ;
                    }
                    break ;

                }

                break ;
            case SDLK_c :
                if ( ( position_objet.x < 200) && ( position_objet.x > 50) && ( position_objet.y < 650) && ( position_objet.y > 500)  )
                {
                    end_n++;
                    end_n = end_n%2 ;
                }
                if ( ( position_objet.x < 830) && ( position_objet.x > 770) && ( position_objet.y < 550) && ( position_objet.y > 450)  )
                {
                    up_and_down++;
                    up_and_down =up_and_down%2 ;
                }
                break ;

            case SDLK_LEFT :

if(position_objet.x>20)
            {
                 cpt_sound++;
                       if (cpt_sound>=300)    { Mix_PlayChannel(2,musique_run,1);cpt_sound=0; }

                mvt_l=1 ;
                position_objet.x-=3;
            }
            time_frame2++;

            SDL_PollEvent(&event2);

            switch (event2.type)
            {
            case   SDL_KEYDOWN :
                switch (event2.key.keysym.sym)
                {
                case SDLK_UP :
                    if (!dans_l_air)
                    {
                        mvt_up_left = 1 ;
                        dans_l_air  = 1 ;
                        position_objet.x+=2;
                    }
                    break ;
                }
                break ;
            case   SDL_KEYUP :
                switch (event2.key.keysym.sym)
                {
                case SDLK_UP :
                    if  ( (!dans_l_air)&& (!cpt_u_l) )
                    {
                        mvt_up_left = 0;
                        dans_l_air  = 0 ;
                        position_objet.x+=2;
                    }
                    break ;
                }
                break ;
            }

            break ;
            }
            break ;

        case SDL_KEYUP :
            switch (event.key.keysym.sym)
            {

            case SDLK_RIGHT :
                Mix_HaltChannel(2);
                mvt_r  =0 ;
                cpt_sound=300;
                right=1;
                left =0 ;
                break ;
            case SDLK_LEFT  :
                Mix_HaltChannel(2);
                cpt_sound=300;
                mvt_l  =0 ;
                left =1;
                right=0 ;
                break ;
            }
            break ;
        }

        if (mvt_up)
        {
            cpt++ ;
            dans_l_air=1 ;
            if (cpt < 30)
            {
                position_objet.y-=noir->h ;
                surf = up_to_Surface(position_objet,test_map,noir, 5) ;
                if (surf==0)
                    position_objet.y-=3 ;
                else if (surf>0)
                {
                    cpt=30 ;
                }
                position_objet.y+=noir->h ;
            }

            if ( cpt>= 30 )
            {
                surf = down_to_Surface(position_objet,test_map,noir, 15) ;
                if (surf!=0)
                {
                    dans_l_air=1 ;
                }
                cpt=0 ;
                mvt_up=0 ;
            }
        }


        if ( mvt_up_right)
        {
            left =0 ;
            right =1 ;
            cpt_u_r ++ ;
            dans_l_air=1 ;
            if (cpt_u_r<30 )
            {
                position_objet.x+=3 ;
                position_objet.y-=noir->h ;
                surf = up_to_Surface(position_objet,test_map,noir, 5) ;
                if (surf==0)
                    position_objet.y-=3 ;
                else if (surf>0)
                {
                    cpt=30 ;
                }
                position_objet.y+=noir->h ;
                if (Verif_collision_objet(position_objet,test_map,noir))
                {
                    surf = up_to_Surface(position_objet,test_map,noir, 50) ;
                    if (surf<30)
                    {
                        position_objet.y-=surf ;
                    }
                    position_objet.x-=3 ;
                }
            }

            if (cpt_u_r>=30)
            {
                surf = down_to_Surface(position_objet,test_map,noir, 15) ;
                if (surf>=15)
                {
                    position_objet.y+=15 ;
                    dans_l_air=1 ;
                    if ( !Verif_collision_objet(position_objet,test_map,noir))
                    {
                        position_objet.x+=3 ;
                    }
                }

                if (surf<15)
                {
                    position_objet.y+=surf ;
                    dans_l_air=0;
                    cpt_u_r=0;
                    mvt_up_right=0 ;
                }
            }

        }


        if (mvt_up_left)

        {
            left =1 ;
            right =0 ;
            cpt_u_l++ ;
            dans_l_air=1 ;
            if (cpt_u_l<30)
            {
                position_objet.x -=noir->w +13 ;
                position_objet.y-=noir->h ;
                surf = up_to_Surface(position_objet,test_map,noir, 5) ;

                if (surf==0)
                {
                    position_objet.y-=3 ;
                }
                else if (surf> 0)
                {
                    cpt=30 ;
                }
                position_objet.y+=noir->h ;
                if (Verif_collision_objet(position_objet,test_map,noir))
                {
                    surf = up_to_Surface(position_objet,test_map,noir, 50) ;
                    if (surf>30)
                        position_objet.x+=3 ;
                }
                position_objet.x += noir->w+10 ;
            }

            if (cpt_u_l>=30)
            {
                if ( !Verif_collision_objet(position_objet,test_map,noir))
                {
                    position_objet.x-=3 ;
                }
                surf = down_to_Surface(position_objet,test_map,noir, 15) ;
                if (surf>=15)
                {
                    position_objet.y+=15   ;
                    dans_l_air=1 ;
                }
                else if (surf< 15)
                {
                    position_objet.y+=surf ;
                    dans_l_air=0 ;
                    cpt_u_l=0 ;
                    mvt_up_left=0 ;
                }
            }
        }
        surf = down_to_Surface(position_objet,test_map,noir, 20 ) ;
        if ((surf> 10) && !mvt_up && !mvt_up_right && ! mvt_up_left && !in_up_down )
        {
            position_objet.y+=7   ;
            dans_l_air=1;
        }
        else if ((surf<=10 ) && !mvt_up && !mvt_up_right && ! mvt_up_left && !in_up_down )
        {
            position_objet.y+=surf ;
            dans_l_air=0 ;
        }

        surf =up_to_Surface(position_objet,test_map,noir, 20  ) ;
        if ((surf< 5 ) && surf !=0 )
        {
            position_objet.y -=surf ;
            dans_l_air=0 ;
        }
        else if (surf>=5)
        {
            position_objet.y -=5 ;
        }
        surf =0 ;

        SDL_BlitSurface(fond_base,NULL,ecran,NULL);

        timer_cpt++;
        if (timer_cpt==70)
        {
            time_sec-- ;
            if ( (time_sec==0 ) && (time_min>0) )
            {
                time_sec=60 ;
                time_min=0;
            }
            else if ( (time_sec==0)&& (time_min==0) )
            {
                you_lose=1 ;
            }
        timer_cpt=0;
        }


         sprintf(time,"0%d:%d%d",time_min,time_sec/10,time_sec%10);
        texte = TTF_RenderText_Shaded(police, time,couleurBlanche, couleurNoire);
        SDL_BlitSurface(texte,NULL,ecran,&position_texte);

        if (!end_n)
        {
            cpt_n[0] ++ ;
            cloud_creation(&pos_cld_1,cld_1,ecran,&cpt_n[0],X,Y,150,&i,1) ;
            cpt_n[1] ++ ;
            cloud_creation(&pos_cld_2,cld_2,ecran,&cpt_n[1],X,Y,90 ,&i,2) ;
            cpt_n[2] ++ ;
            cloud_creation(&pos_cld_3,cld_3,ecran,&cpt_n[2],X,Y,80 ,&i,1) ;
            cpt_n[3] ++ ;
            cloud_creation(&pos_cld_4,cld_4,ecran,&cpt_n[3],X,Y,80 ,&i,1) ;
            cpt_n[4] ++ ;
            cloud_creation(&pos_cld_5,cld_5,ecran,&cpt_n[4],X,Y,80 ,&i,1) ;
        }
        elv_y =  pos_elevator.y-noir->h ;
        elv2_y= pos_elevator2.y-noir->h ;

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
            if ( position_objet.y>(elv_y-40)&& position_objet.y <(elv_y+40) && position_objet.x>20 && position_objet.x< 145)
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
                if ( in_up_down)
                {
                    if (!mvt_up&& !mvt_up_left&& !mvt_up_right )
                    {
                        position_objet.y=4-noir->h+ pos_elevator.y ;
                    }
                }
                cpt_elv =0 ;
            }
            affichage(ecran,elevator,pos_elevator.x,pos_elevator.y,240,0,position_sprite3,0) ;
        }

        affichage(ecran,pg,pos_p.x,pos_p.y,240,1,position_sprite3,0) ;


        /**** D�placement du cube***/
        if (pos_cube.x <1200)
        {
            if ( position_objet.y> 600 && position_objet.y<700 && position_objet.x> pos_cube.x-80 && position_objet.x<pos_cube.x-50   )
            {
                pos_cube.x = position_objet.x +80 ;
            }
        }

        else if ( pos_cube.x>=1200 && cpt_fin ==0 )
        {
            cpt_fin =1;
            test_map=SDL_LoadBMP("_map_test2.bmp");
        }
        SDL_FreeSurface(cube);
        cube=SDL_LoadBMP("box.bmp");
        affichage(ecran,cube,pos_cube.x,pos_cube.y,0,0,position_sprite3,0) ;





        if (mvt_r&& !dans_l_air)
        {
            affichage(ecran,sprite,position_objet.x,position_objet.y,0,0,position_sprite,1) ;
        }
        else if (mvt_l&& !dans_l_air)
        {
            affichage(ecran,sprite2,position_objet.x,position_objet.y,0,0,position_sprite2,1) ;
        }
        else if ((!mvt_l) && !dans_l_air)
        {
            if (right)
            {
                position_sprite.x=0;
                SDL_FreeSurface(sprite);
                sprite =SDL_LoadBMP("sprite_d.bmp");
                affichage(ecran,sprite,position_objet.x,position_objet.y,0,0,position_sprite,1) ;
            }
            else if (left)
            {
                position_sprite2.x=0;
                SDL_FreeSurface(sprite2);
                sprite2=SDL_LoadBMP("sprite_g.bmp");
                affichage(ecran,sprite2,position_objet.x,position_objet.y,0,0,position_sprite2,1) ;
            }
        }

        if (dans_l_air)
        {
            if (right||mvt_r)
            {
                cpt_t++ ;
                if (cpt_t==2)
                {
                    time_frame3++;
                    cpt_t=0 ;
                }
                SDL_FreeSurface(sprite3);
                 sprite3=SDL_LoadBMP("tanguiza_r.bmp") ;
                affichage(ecran,sprite3,position_objet.x,position_objet.y,0,0,position_sprite3,1) ;
            }
            else if (left||mvt_l)
            {
                cpt_t++ ;
                if (cpt_t==2)
                {
                    time_frame4++;
                    cpt_t=0 ;
                }
                 SDL_FreeSurface(sprite4);
    sprite4=SDL_LoadBMP("tanguiza_l.bmp") ;
                affichage(ecran,sprite4,position_objet.x,position_objet.y,22,0,position_sprite4,1) ;
            }
        }
        else if ( !dans_l_air)
        {
            pos_sprite3=1 ;
            cpt_t=0 ;
        }

        if (end_n)
        {    if (cpt_s_w==0){Mix_PlayChannel(4,musique_water,1);cpt_s_w=1;}
            cpt_water_mvt++ ;
            if (cpt_water_mvt==9)
            {
                SDL_FreeSurface(water);
                i_water ++ ;
                switch ( i_water )
                {


                case 1 :

                    water=SDL_LoadBMP("water_1.bmp") ;
                    break ;
                case 2 :
                    water=SDL_LoadBMP("water_2.bmp") ;
                    break ;
                case 3 :
                    water=SDL_LoadBMP("water_3.bmp") ;
                    break ;
                case 4 :
                    water=SDL_LoadBMP("water_4.bmp") ;
                    break ;
                case 5 :
                    water=SDL_LoadBMP("water_5.bmp") ;
                    break ;
                case 6 :
                    water=SDL_LoadBMP("water_6.bmp") ;
                    break ;
                case 7 :
                    water=SDL_LoadBMP("water_7.bmp") ;
                    i_water =0    ;
                    break ;
                }
                cpt_water_mvt=0 ;
            }

            if ((1366-camera.w)>210)
            {
                camera.w+=1 ;
                if ( pos_cube.x<= (camera.w + pos_water.x) )
                {
                    if (pos_cube.x<1200 )
                    {
                        pos_cube.x  = camera.w + pos_water.x    ;
                    }

                    if ( camera.h<50 )
                    {
                        cpt_water++;
                        if (cpt_water==3)
                        {
                            cpt_water=0;

                            camera.h ++ ;
                            camera.w--;
                            pos_water.y-- ;

                        }
                    }
                }
            }

            else if ((1366-camera.w <= 210 ) && (1366-camera.w !=0 ))
            {
                camera.x--;
                camera.w++;
                pos_water.x--;
            }

            if (camera.w==1366 && pos_water.y!=0 )
            {
                cpt_water ++ ;
                if (cpt_water==2)
                {
                    pos_water.y--;
                    camera.h++;
                    cpt_water=0 ;
                }
            }
            if (pos_water.y<530)
            {
                up_and_down=0;
            }

            if ((pos_water.y <( position_objet.y+ 100  ) ) && (pos_water.y >( position_objet.y+ 10  ) ) && ( position_objet.x<(camera.w+pos_water.x) -100 ) && ( position_objet.x-100 >pos_water.x ))
            {
                if (mvt_r|| mvt_up_right)
                {
                    affichage(ecran,me_perso_d_d,position_objet.x+85,pos_water.y-30,130,1,position_base,0) ;
                    affichage(ecran,me_perso_d_g,position_objet.x+10,pos_water.y-30,130,1,position_base,0) ;
                }
                else if (mvt_l|| mvt_up_left )
                {
                    affichage(ecran,me_perso_g_g,position_objet.x+85,pos_water.y-30,130,1,position_base,0) ;
                    affichage(ecran,me_perso_g_d,position_objet.x+10,pos_water.y-30,130,1,position_base,0) ;
                }
            }

            else if ((pos_water.y < (position_objet.y-10  ) )  && ( position_objet.x<(camera.w+pos_water.x) -100 ) && ( position_objet.x-100 >pos_water.x ))
            {
        affichage(ecran,me_perso_t,position_objet.x+25,pos_water.y-30,130,1,position_base,0) ;
        you_lose=1;


            }





        }




        if (time_frame==3)
        {
            position_sprite.x=pos_sprite*150;
            verif_frame=1;
        }
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

        if (time_frame3==3)
        {
            position_sprite3.x=pos_sprite3*150;
            verif_frame3=1;
        }
        if (pos_sprite3==9)
        {
            pos_sprite3=1;
        }
        if (time_frame4==3)
        {
            position_sprite4.x=pos_sprite4*150;
            verif_frame4=1;
        }
        if (pos_sprite4==9)
        {
            pos_sprite4=1;
        }


  if(280/FPS > SDL_GetTicks()-start)
        {
            SDL_Delay(280/FPS-(SDL_GetTicks()-start));
        }



affichage(ecran,water,pos_water.x,pos_water.y,220,1,camera,3);

        SDL_Flip(ecran);

 if (you_lose==1){
//SDL_Delay(1000);
   Mix_HaltChannel(4);
   Mix_HaltChannel(2);
   Mix_HaltChannel(3);
   Mix_HaltChannel(1);
    SDL_BlitSurface(gameover,NULL,ecran,NULL);
    SDL_Flip(ecran);
    SDL_Delay(8000);
    choix_stage(ecran,stage_dispo,difficulter) ;
}
else if (!you_lose && position_objet.y<200 && position_objet.x<100){

    Mix_HaltChannel(4);
   Mix_HaltChannel(2);
   Mix_HaltChannel(3);
    if (*(stage_dispo)<2) {*stage_dispo=2;}
    SDL_BlitSurface(uwin,NULL,ecran,NULL);
    SDL_Flip(ecran);
    SDL_Delay(3000);
}

}

}



}


int down_to_Surface (SDL_Rect position_objet, SDL_Surface *test_map, SDL_Surface *noir,int max_pix )
{
    int i=0 ,test=0 ;
    _Couleur_ loun;

    for (i=0; i<max_pix; i++ )
    {
        SDL_LockSurface(test_map);
        loun=SDL_LireCouleur(test_map,(position_objet.x+(noir->w)-20),(position_objet.y+(noir->h)+i-5));
        SDL_UnlockSurface(test_map);
        if (loun.r!=0 && loun.g!=0 && loun.b!=0)
        {
            test ++ ;
        }
    }

    return test ;
}


int up_to_Surface (SDL_Rect position_objet,  SDL_Surface *test_map, SDL_Surface *noir,int max_pix )
{
    int i=0 ,test=0 ;
    _Couleur_ loun;

    for (i=0; i<max_pix; i++ )
    {
        SDL_LockSurface(test_map);
        loun=SDL_LireCouleur(test_map,(position_objet.x+(noir->w)+10),(position_objet.y+(noir->h)-i));
        SDL_UnlockSurface(test_map);
        if (loun.r!=0 && loun.g!=0 && loun.b!=0)
        {
            test ++ ;
        }
    }
    test = max_pix-test  ;
    return test ;
}


int Verif_collision_objet(SDL_Rect position_objet,SDL_Surface *test_map,SDL_Surface *noir)
{
    int i=0 , test =0 ;
    _Couleur_ loun;
    for (i=0; i<30; i++)
    {
        SDL_LockSurface(test_map);
        loun=SDL_LireCouleur(test_map,(position_objet.x+noir->w+5),position_objet.y+(noir->h)-i-10);
        SDL_UnlockSurface(test_map);
        if (loun.r!=0 && loun.g!=0 && loun.b!=0)
        {
            test ++ ;
        }
    }
    if ( test==30)
        return 0;

}

Uint32 SDL_LireCouleurAux(SDL_Surface* surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;

    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp)
    {
    case 1:
        return *p;
    case 2:
        return *(Uint16 *)p;
    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
    case 4:
        return *(Uint32 *)p;
    default:
        return 0;
    }
}

void cloud_creation ( SDL_Rect *position_cloud ,SDL_Surface *cloud ,SDL_Surface *ecran , int *cpt , int X[20] , int Y[20] , int verif , int *position ,int ajout )
{
    int i = 0 ;
    i = *position ;
    SDL_FreeSurface(cloud);
    if ( i <5 )
    {
        cloud=SDL_LoadBMP("n_1.bmp");
    }
    else if ( i<8)
    {
        cloud=SDL_LoadBMP("n_2.bmp");
    }
    else if (i<13)
    {
        cloud=SDL_LoadBMP("n_3.bmp");
    }
    else if (i<17 )
    {
        cloud=SDL_LoadBMP("n_4.bmp");
    }
    else
    {
        cloud=SDL_LoadBMP("n_5.bmp");
    }

    if (*cpt ==verif )
    {
        *position =  *position + ajout ;
        position_cloud->x =X[i] ;
        position_cloud->y =Y[i] ;
        *cpt=0 ;
    }
    if (*position>=20)
    {
        *position=0;
    }

    affichage(ecran,cloud,position_cloud->x,position_cloud->y,128,1,*position_cloud,0) ;
SDL_FreeSurface(cloud);
}

_Couleur_ SDL_LireCouleur(SDL_Surface * surface, int x, int y)
{
    _Couleur_ couleur;
    SDL_GetRGB(SDL_LireCouleurAux(surface, x, y), surface->format,
               (Uint8*)   &couleur.r, (Uint8*) &couleur.g, (Uint8*) &couleur.b);
    return couleur;
}

void affichage ( SDL_Surface *ecran,SDL_Surface *effect, int x , int y,int transparance,int i ,SDL_Rect camera ,int j )
{
    SDL_Rect pos_effect ;
    pos_effect.y =y ;
    pos_effect.x = x ;

    if (i==1)
    {
    SDL_SetAlpha(effect, SDL_SRCALPHA, transparance);
    }

    if (j==1){
    SDL_SetColorKey(effect,SDL_SRCCOLORKEY, SDL_MapRGB(effect->format,255, 255,255));
    SDL_BlitSurface(effect,&camera,ecran,&pos_effect);
    }
else if (j==3)
{
    SDL_BlitSurface(effect,&camera,ecran,&pos_effect);
}
    else if (j==0)
    {

SDL_SetColorKey(effect,SDL_SRCCOLORKEY, SDL_MapRGB(effect->format,255, 255,255));
SDL_BlitSurface(effect,NULL,ecran,&pos_effect);
    }

}



