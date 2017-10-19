#include "Stage_4.h"
#define TIME_BEETWEN_2_FRAMES 8

void main_stage_4(SDL_Surface *ecran, int stage, int *stage_dispo , int *difficulter )
{

      Mix_AllocateChannels(10);
    Mix_Music *musique_run, *musique_water,*musique_jump;
    musique_run= Mix_LoadWAV("run.wav");
    Mix_VolumeChunk(musique_run,MIX_MAX_VOLUME/2);
    musique_jump =Mix_LoadWAV("jump.wav");
    Mix_VolumeChunk(musique_jump,(MIX_MAX_VOLUME));



    SDL_Rect position_base ,position_texte, pos_hchich2, position_objet,pos_cowboy2,camera ;
    int compteur=0,cpt_bermil=0,rool_back=0,x=0,n=0,cow_boy=0, cpt_hchich=0 , a_kar=0,dog_cpt=0,tue1=0,tue2=0,cow_cpt=0,dead =0 ,cpt_doggi=0,cpt_lou7a=1,y_pres=0,y_suiv=0 ,j =0,cpt_u_ll=0,y=0, i=0, elv_y=0,mvt_l_stop=1,key_c=0,mvt_r_stop=0  ,cpt_t=0,elv2_y=0 ,dans_l_air=0 ,in_up_down=0 ,end_n=1 ,cpt_u_r=0,cpt_u_l=0 ,mvt_up_right=0 ;
    char temps [20]="";
    int X[5] = {895,950,1005,1060,1115} , Y[5]= {544,570,590,610,650} ;
    int surf=0,cpt_sound=300,cpt_n [5]= {0,0,0,0,0} ;
    SDL_Rect pos_cld_1,pos_bermil ,pos_dog ,pos_elvator , pos_kartouch ;
    pos_elvator.x=X[0] ;
    pos_elvator.y=Y[0] ;
    pos_bermil.x=1200;
    pos_bermil.y=290;
    char text_aide [1000] ="" ;

int jouer=0;
int   cpt_cow_mvt2=0 ,cow_cpt2=0 ,cpt_cow_mvt=0;
    SDL_Surface *cld_1=NULL ,*img_won=NULL,*img_lose=NULL, *bermil=NULL,*kartouch=NULL ,*test_m=NULL,*texte=NULL,*squelette=NULL,*cube=NULL,*elevator=NULL,*cld_2=NULL,*pg=NULL , *cld_3=NULL ,*cld_4=NULL,*cld_5=NULL;
//   SDL_Rect police ;
    // police.x = 1250;
    //police.y=615 ;
    img_won=SDL_LoadBMP("won.bmp") ;
    img_lose=SDL_LoadBMP("lose.bmp") ;

    int cpt_elv=0 ,won=0,lose=0, forsage_jump =0, cpt_water_mvt=0,i_water=0,up_and_down =0,up_down=0 ;
    // squelette=SDL_LoadBMP("squelette.bmp") ;
    Uint8 g=0,r=255;
    pos_dog.x=10 ;
    pos_dog.y=65 ;
    SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
    _Couleur_ loun;


    TTF_Font *police = NULL;
    TTF_Init();
    police = TTF_OpenFont("aaa.ttf", 25);


    SDL_Surface *test_map=NULL ,*hchich2=NULL,*sprite5=NULL,*sprite2=NULL,*sprite6=NULL,*sprite7=NULL ,*sprite3=NULL,*sprite4=NULL,*fond_base=NULL,*noir2=NULL,*noir=NULL,*sprite=NULL;
    position_objet.x=1200;
    position_objet.y=500;
    pos_hchich2.x=500;
    pos_hchich2.y=100;

    hchich2=SDL_LoadBMP("hchich.bmp") ;

    sprite =SDL_LoadBMP("sprite_matar_d.bmp");
    sprite2=SDL_LoadBMP("sprite_matar_g.bmp");
    sprite3=SDL_LoadBMP("hchich.bmp") ;
    sprite4=SDL_LoadBMP("dog_2.bmp") ;
    sprite5=SDL_LoadBMP("cowboy_3_2.bmp") ;
    elevator =SDL_LoadBMP("case_2.bmp") ;
    noir2=SDL_LoadBMP("noir2.bmp") ;
    bermil=SDL_LoadBMP("bermil.bmp") ;
    SDL_Rect position_sprite,pos_hchich, position_sprite2 ,position_sprite3,position_sprite4,position_sprite5,position_sprite6,position_sprite7;
    SDL_Event event,event2;
    int left=0,right=0,mvt_up_left=0,continuer=1,mvt_r=0,mvt_l=0,cpt=0,mvt_up=0,i_pause=1;
    int FPS=30;
    int speed=4;
    Uint32 start ;
    pos_hchich.x=10 ;
    pos_hchich.y=650 ;
    int time_frame=0,verif_frame=0,cpt_jeu=0,cpt_aide=0,dead_dog=0,time_frame6=0,verif_frame6=0,time_frame7=0,verif_frame7=0,time_frame2=0,pos_sprite3 =0,verif_frame2=0,time_frame3=0,verif_frame3=0,time_frame4=0,verif_frame4=0,time_frame5=0,verif_frame5=0;

    test_map=SDL_LoadBMP("map_test_stg4.bmp");
    test_m=SDL_LoadBMP("map_test_stg4.bmp");
    fond_base=SDL_LoadBMP("cowboy.bmp");
    noir=SDL_LoadBMP("noir4.bmp");
      pos_cowboy2.x =800;
    pos_cowboy2.y=290 ;
    //SDL_FreeSurface(chien)      ;   chien=SDL_LoadBMP("box.bmp") ;
    int pos_sprite=0, pos_sprite2=0,pos_sprite4=0,pos_sprite5=0,pos_sprite6=0,pos_sprite7=0;
    SDL_EnableKeyRepeat(10,10);
    SDL_Rect position_text,pos_cowboy1  ;
    pos_cowboy1.x =40;
    pos_cowboy1.y=450 ;
    position_text.x =400 ;
    position_text.y =400 ;
    position_sprite.w=75 ;
    position_sprite.h=53 ;
    position_sprite.x=0   ;
    position_sprite.y=0   ;
    position_sprite2.w=75 ;
    position_sprite2.h=53;
    position_sprite2.x=0  ;
    position_sprite2.y=0  ;
    position_sprite3.w=75;
    position_sprite3.h=60;
    position_sprite3.x=0  ;
    position_sprite3.y=0  ;
    position_sprite4.w=96;
    position_sprite4.h=96;
    position_sprite4.x=0  ;
    position_sprite4.y=0  ;
    position_sprite5.w=150 ;
    position_sprite5.h=105 ;
    position_sprite5.x=0   ;
    position_sprite5.y=0   ;
    position_sprite6.w=150 ;
    position_sprite6.h=105 ;
    position_sprite6.x=0   ;
    position_sprite6.y=0   ;
    position_sprite7.w=150 ;
    position_sprite7.h=105 ;
    position_sprite7.x=0   ;
    position_sprite7.y=0   ;

    kartouch=SDL_LoadBMP("cartoucha.bmp") ;
    camera.x=0;
    camera.y=0 ;
    camera.w=1366;
    camera.h=300;
Musique(4);
   if  (*(difficulter)==3) { jouer=1 ; }

    while (continuer)
    {

if (!lose && !won ){

 if (jouer ==1 )
        {if (verif_frame)
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

        if (verif_frame5)
        {
            time_frame5   =0 ;
            pos_sprite5   ++ ;
            verif_frame5  =0 ;
        }

        if (verif_frame6)
        {
            time_frame6   =0 ;
            pos_sprite6   ++ ;
            verif_frame6  =0 ;
        }

        if (verif_frame7)
        {
            time_frame7   =0 ;
            pos_sprite7   ++ ;
            verif_frame7  =0 ;
        }}

        start=SDL_GetTicks();
        SDL_PollEvent(&event);
if (jouer==0)
{

if (*(difficulter)==1)
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
  sprintf(text_aide,"go to the shop ");
  break ;
  case 1 :
      position_texte.x-=30;
  sprintf(text_aide,"press 'c ' to dress like a cow boy ");
  break ;
  case 2 :
      position_texte.x+=20;
  sprintf(text_aide,"know avoid the cowboys and press 'c' to kill the dog to rich your grand father ");
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
  sprintf(text_aide,"wearing a suit will not help you in the cowboy town ");
  break ;
  case 1 :
      position_texte.x-=40;
  sprintf(text_aide," dog will not kill you but he block your way find a solution ");
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
else if (jouer==1 )
            {switch (event.type)
        {
        case SDL_QUIT :
            exit(1);
            break;

        case SDL_KEYDOWN :
            switch (event.key.keysym.sym)
            {
     case SDLK_ESCAPE :
                Pause(ecran,NULL,position_objet,4) ;
                break ;
            case SDLK_RIGHT :
             cpt_sound++;
                       if (cpt_sound>=300)    { Mix_PlayChannel(2,musique_run,1);cpt_sound=0; }

              if ( position_objet.x<1300)
                     {
                position_objet.x+= 3 ;}
                mvt_r=1 ;
                mvt_l=0;
                break ;
            case SDLK_LEFT :
             cpt_sound++;
                       if (cpt_sound>=300)    { Mix_PlayChannel(2,musique_run,1);cpt_sound=0; }

              if ( position_objet.x>25)

                position_objet.x-= 3 ;
                else {position_objet.x+= 3 ;}

                mvt_r=0 ;
                mvt_l=1 ;
                break ;
            case SDLK_UP :
                if (!dans_l_air)
                {
                 Mix_PlayChannel(3,musique_jump,1);
                    mvt_up=1;
                }
                if (in_up_down)
                {
                   Mix_PlayChannel(3,musique_jump,1);
                   forsage_jump =1 ;
                }
                break ;
            case SDLK_c :
                key_c=1 ;
                break ;

            }
            break ;
        case SDL_KEYUP :
            switch (event.key.keysym.sym)
            {
            case SDLK_RIGHT :
                 Mix_HaltChannel(2);
                 cpt_sound=300;
                mvt_r_stop=1 ;
                mvt_r=0;
                mvt_l_stop=0;
                break ;
            case SDLK_LEFT  :
                 Mix_HaltChannel(2);
                cpt_sound=300;
                mvt_l_stop=1 ;
                mvt_l=0;
                mvt_r_stop=0;
                break ;
            case SDLK_UP :
                if (!mvt_up_left&& !mvt_up_right) mvt_up=0;
                break ;
            case SDLK_c :
                key_c=0 ;
                break ;
            }
            break ;
        }

        if (mvt_up)
        {
            if (mvt_r ||mvt_r_stop)
            {
                mvt_up_right=1 ;
                mvt_up_left=0;
                dans_l_air=1 ;
            }
            if (mvt_l|| mvt_l_stop)
            {
                mvt_up_right=0 ;
                mvt_up_left=1;
                dans_l_air=1 ;
            }
            mvt_up=0 ;
        }
        if (mvt_up_right && !mvt_up_left)
        {
            if (cpt_u_ll==0)
            {
                j=0 ;
                y = position_objet.y ;
            }

            cpt_u_ll ++ ;
            if (cpt_u_ll<46)
            {
                cpt_u_r++ ;
                if (cpt_u_r==3)
                {
                    position_objet.x+=5;
                    j+=5 ;

                    position_objet.y= y-( 5*j - (j*j)/15 ) ;
                    cpt_u_r=0;
                }
            }
            else if (cpt_u_ll>=46)
            {
                cpt_u_ll=0;
                j=0;
                mvt_up=0;
                mvt_up_right=0;
                dans_l_air=0 ;
            }
        }

        else if (mvt_up_left&& !mvt_up_right)
        {
            if (cpt_u_ll==0)
            {
                j=0 ;
                y = position_objet.y ;
            }
            cpt_u_ll ++ ;
            if (cpt_u_ll<46)
            {
                cpt_u_l++ ;
                if (cpt_u_l==3)
                {
                    position_objet.x-=5;
                    j+=5 ;
                    position_objet.y= y-( 5*j - (j*j)/15 ) ;

                    cpt_u_l=0;
                }
            }

            else if (cpt_u_ll>=46)
            {
                cpt_u_ll=0;
                j=0;
                mvt_up=0;
                mvt_up_left=0;
                dans_l_air=0 ;
            }
        }

        else if ( !mvt_up_left &&! mvt_up_right && !in_up_down)
        {
                    {surf = down_to_Surface4(position_objet,test_m,noir, 20 ) ;
        if ((surf> 10) )
        {
            position_objet.y+=7   ;
            dans_l_air=1;
        }
        else if ((surf<=10 ) && (surf >2 )   )
        {   position_objet.y+=surf ;
            dans_l_air=0 ;
            cpt_u_ll=46 ;
        }
        }

        }

        surf =up_to_Surface4(position_objet,test_m,noir, 20  ) ;
        if ((surf< 5 ) && surf !=0 )
        {
            position_objet.y -=surf ;
            dans_l_air=0 ;
            cpt_u_ll =46 ;
        }
        else if (surf>=5)
        {
            position_objet.y -=5 ;
            cpt_u_ll =46 ;
        }

    if ( (pos_hchich2.x-30<pos_dog.x ) && (pos_hchich2.x+30>pos_dog.x) && rool_back  )
    {
     dead_dog=1 ;
    }

    if  ((!dead_dog)&& (pos_hchich2.x<pos_dog.x )&& rool_back && pos_hchich2.x<10 )
    lose =1 ;
        surf =0 ;

        n++ ;
        if (n==100)
        {
            cpt_lou7a ++ ;
            n=0;
        }



surf = down_to_Surface4(pos_hchich,test_m,noir2, 20 ) ;
        if ((surf> 10) )
        {
 if (pos_hchich.y<680)            pos_hchich.y+=7   ;

        }
        else if ((surf<=10 ) && (surf >2 )   )
        {
          if (pos_hchich.y<680)      pos_hchich.y+=surf ;
        }
     if ( position_objet.x > pos_elvator.x && position_objet.x < pos_elvator.x+100 && position_objet.y< pos_elvator.y && position_objet.y> pos_elvator.y-40 )
 {
    in_up_down=1 ;
       dans_l_air=0 ;
if (!forsage_jump)       {cpt_u_ll=46 ;}

 }
 else {in_up_down=0; forsage_jump=0;}

        SDL_BlitSurface(fond_base,NULL,ecran,NULL) ;
        SDL_SetColorKey(sprite3,SDL_SRCCOLORKEY, SDL_MapRGB(sprite3->format,255, 255,255));
        SDL_BlitSurface(sprite3,&position_sprite3,ecran,&pos_hchich) ;
        SDL_SetColorKey(bermil,SDL_SRCCOLORKEY, SDL_MapRGB(bermil->format,255, 255,255));
        SDL_BlitSurface(bermil,NULL,ecran,&pos_bermil) ;


       if (pos_hchich.x <1400) pos_hchich.x+=4 ;
        time_frame3++;


        switch (cpt_lou7a )

        {
        case 1 :
            pos_elvator.x=X[0] ;
            pos_elvator.y=Y[0] ;
            SDL_SetColorKey(elevator,SDL_SRCCOLORKEY, SDL_MapRGB(elevator->format,255, 255,255));
            SDL_BlitSurface(elevator,NULL,ecran,&pos_elvator) ;
            break ;
        case 2 :
            pos_elvator.x=X[4] ;
            pos_elvator.y=Y[4] ;
            SDL_SetColorKey(elevator,SDL_SRCCOLORKEY, SDL_MapRGB(elevator->format,255, 255,255));
            SDL_BlitSurface(elevator,NULL,ecran,&pos_elvator) ;
            break ;
        case 3:

            pos_elvator.x=X[3] ;
            pos_elvator.y=Y[3] ;
            SDL_SetColorKey(elevator,SDL_SRCCOLORKEY, SDL_MapRGB(elevator->format,255, 255,255));
            SDL_BlitSurface(elevator,NULL,ecran,&pos_elvator) ;
            break ;
        case 4 :
            pos_elvator.x=X[2] ;
            pos_elvator.y=Y[2] ;
             SDL_SetColorKey(elevator,SDL_SRCCOLORKEY, SDL_MapRGB(elevator->format,255, 255,255));
            SDL_BlitSurface(elevator,NULL,ecran,&pos_elvator) ;
            break ;
        case 5 :
            pos_elvator.x=X[1] ;
            pos_elvator.y=Y[1] ;
            SDL_SetColorKey(elevator,SDL_SRCCOLORKEY, SDL_MapRGB(elevator->format,255, 255,255));
            SDL_BlitSurface(elevator,NULL,ecran,&pos_elvator) ;
            if (n ==99) {cpt_lou7a=0 ;}
            break ;
        }


if (key_c && pos_bermil.x>800 && position_objet.x>800 && position_objet.y<350 && position_objet.y>250 )
    {
    pos_bermil.x--;
    }

if (pos_bermil.x==800 && cpt_bermil==0 )
{
    cpt_bermil=1 ;
   SDL_FreeSurface(test_m) ;
test_m =SDL_LoadBMP("map_test_stg4_2.bmp") ;
}

   if ( position_objet.x >= pos_hchich.x-20 && position_objet.x <= pos_hchich.x+20  && (position_objet.y+noir->h-80) < pos_hchich.y+10 &&  (position_objet.y+noir->h-20) > pos_hchich.y-10   )
  lose=1 ;

   if ( tue1 && position_objet.x >= pos_kartouch.x-20 && position_objet.x <= pos_kartouch.x+20  && (position_objet.y+noir->h-50) < pos_kartouch.y+10 &&  (position_objet.y+noir->h-20) > pos_kartouch.y-10   )
lose =1 ;

   if ( (cow_boy && position_objet.x >= pos_cowboy1.x-20 && position_objet.x <= pos_cowboy1.x+20  && (position_objet.y+noir->h-50) < pos_cowboy1.y+10 &&  (position_objet.y+noir->h-20) > pos_cowboy1.y-10  )|| ( cow_boy && position_objet.x >= pos_cowboy2.x-20 && position_objet.x <= pos_cowboy2.x+20  && (position_objet.y+noir->h-50) < pos_cowboy2.y+20 &&  (position_objet.y+noir->h-20) > pos_cowboy2.y-20  ) )
  lose =1 ;

if (dead_dog && dog_cpt <100)
{
    dog_cpt++;
                if (dog_cpt>=100)
           {
               position_objet.x= 1000;
               position_objet.y=10 ;

           }
}
if (!dead_dog)
{

        if (pos_dog.x>705)
        {
            cpt_doggi=0;
        }
        else if (pos_dog.x<=40)
        {
            cpt_doggi=1;
            SDL_FreeSurface(sprite4) ;
            sprite4=SDL_LoadBMP("dog_2.bmp");
        }
        if (cpt_doggi)
        {
            dog_cpt++;
            if (dog_cpt==3)
           {
                      time_frame4 ++ ;
            pos_dog.x+=4 ;
            dog_cpt=0;}
        }
        else if (pos_dog.x>40 )
        {   dog_cpt++ ;
            if (dog_cpt==3)
            {
                     time_frame4 ++ ;
            pos_dog.x-=4 ;
            dog_cpt=0;
            }
            SDL_FreeSurface(sprite4) ;
            sprite4=SDL_LoadBMP("dog_1.bmp");}
    }

if (!tue1)
        {if (pos_cowboy1.x>705)
        {
            cpt_cow_mvt=0 ;
        }
        else if (pos_cowboy1.x<=40)
        {    cpt_cow_mvt=1;

            SDL_FreeSurface(sprite5) ;
            sprite5=SDL_LoadBMP("obstacle.bmp");
        }

        if (cpt_cow_mvt)
        {
         cow_cpt++;

        if(cow_cpt==3)
         {
             time_frame5 ++ ;
         cow_cpt=0 ;

            pos_cowboy1.x+=2 ;

         }
        }
        else if (pos_cowboy1.x>40 )
        {

            cow_cpt++;

        if(cow_cpt==3)
         {
             time_frame5 ++ ;
         cow_cpt=0 ;
         pos_cowboy1.x-=2 ;
         }
             SDL_FreeSurface(sprite5) ;
            sprite5=SDL_LoadBMP("obstacle_2.bmp");
        }
        }
if (!tue2)
        {if (pos_cowboy2.x>1200)
        {
            cpt_cow_mvt2=0 ;
        }
        else if (pos_cowboy2.x<=200)
        {    cpt_cow_mvt2=1;

            SDL_FreeSurface(sprite6) ;
            sprite6=SDL_LoadBMP("obstacle.bmp");
        }
        if (cpt_cow_mvt2)
        {
         cow_cpt2++;

        if(cow_cpt2==3)
         {
             time_frame6 ++ ;
         cow_cpt2=0 ;
            pos_cowboy2.x+=2 ;
         }
        }
        else if (pos_cowboy2.x>200 )
        {

            cow_cpt2++;

        if(cow_cpt2==3)
         {
             time_frame6 ++ ;
         cow_cpt2=0 ;
         pos_cowboy2.x-=2 ;
         }
             SDL_FreeSurface(sprite6) ;
            sprite6=SDL_LoadBMP("obstacle_2.bmp");
        }}




        if (!tue1) {SDL_SetColorKey(sprite5,SDL_SRCCOLORKEY, SDL_MapRGB(sprite5->format,255, 255,255));
        SDL_BlitSurface(sprite5,&position_sprite5,ecran,&pos_cowboy1) ;}

if (!dead_dog)  {SDL_SetColorKey(sprite4,SDL_SRCCOLORKEY, SDL_MapRGB(sprite4->format,255, 255,255));
          SDL_BlitSurface(sprite4,&position_sprite4,ecran,&pos_dog) ;}
         if (!tue2)
         {SDL_SetColorKey(sprite6,SDL_SRCCOLORKEY, SDL_MapRGB(sprite6->format,255, 255,255));
        SDL_BlitSurface(sprite6,&position_sprite6,ecran,&pos_cowboy2) ;}

 if ( !cow_boy &&position_objet.x>= pos_cowboy1.x-300 && position_objet.x<= pos_cowboy1.x+300 && position_objet.y>420 && position_objet.y<500  )
    {tue1 =1 ; cpt_cow_mvt++ ; if (cpt_cow_mvt==2 ||cpt_cow_mvt==1) {cow_cpt=0;} }
else
{tue1=0;if ( cow_cpt>3) { cow_cpt=0 ; } }
if (tue1)
{
    if (position_objet.x>pos_cowboy1.x)
{SDL_FreeSurface(sprite7) ;
sprite7=SDL_LoadBMP("tue.bmp") ;
SDL_FreeSurface(kartouch) ;
kartouch=SDL_LoadBMP("cartoucha.bmp") ;
pos_kartouch.x = pos_cowboy1.x +80+a_kar ;
if (pos_kartouch.x>1400) {pos_kartouch.x=pos_cowboy1.x ;a_kar=0; }
pos_kartouch.y = pos_cowboy1.y+40 ;

}
else if (position_objet.x<pos_cowboy1.x)
{SDL_FreeSurface(sprite7) ;
    sprite7=SDL_LoadBMP("tue_2.bmp") ;
kartouch=SDL_LoadBMP("cartoucha2.bmp") ;
pos_kartouch.x = pos_cowboy1.x +80-a_kar ;
if (pos_kartouch.x<10) {pos_kartouch.x=pos_cowboy1.x ;a_kar=0; }
pos_kartouch.y = pos_cowboy1.y+40 ;
}
    cow_cpt++ ;
if (cow_cpt==6)
{
time_frame7++ ;
 cow_cpt=0;

}


SDL_SetColorKey(kartouch,SDL_SRCCOLORKEY, SDL_MapRGB(kartouch->format,255, 255,255));
          SDL_BlitSurface(kartouch,NULL,ecran,&pos_kartouch) ;

  SDL_SetColorKey(sprite7,SDL_SRCCOLORKEY, SDL_MapRGB(sprite7->format,255, 255,255));
          SDL_BlitSurface(sprite7,&position_sprite7,ecran,&pos_cowboy1) ;

a_kar+=10 ;

}

if (position_objet.x>1100&& (position_objet.y<145)  )
    won=1 ;

 if ( !cow_boy && (position_objet.x+300 > pos_cowboy2.x) && (position_objet.x-300 < pos_cowboy2.x )&& (position_objet.y>280) && (position_objet.y<370)  )
    {tue2 =1 ; cpt_cow_mvt2++ ; if (cpt_cow_mvt2==1) {cow_cpt2=0; cpt_cow_mvt2 =1 ;}  }
else
{tue2=0; if (cow_cpt2>3) {cow_cpt2=0;} }

if (tue2)
{
    if (position_objet.x>pos_cowboy2.x)
{SDL_FreeSurface(sprite7) ;
sprite7=SDL_LoadBMP("tue.bmp") ;
kartouch=SDL_LoadBMP("cartoucha.bmp") ;
pos_kartouch.x = pos_cowboy1.x +80+a_kar ;
if (pos_kartouch.x>1400) {pos_kartouch.x=pos_cowboy1.x ;a_kar=0; }
pos_kartouch.y = pos_cowboy1.y+40 ;
}
else if (position_objet.x<pos_cowboy2.x)
{   SDL_FreeSurface(sprite7) ;
    sprite7=SDL_LoadBMP("tue_2.bmp") ;
    kartouch=SDL_LoadBMP("cartoucha2.bmp") ;
pos_kartouch.x = pos_cowboy1.x +80-a_kar ;
if (pos_kartouch.x<10) {pos_kartouch.x=pos_cowboy1.x ;a_kar=0; }
pos_kartouch.y = pos_cowboy1.y+40 ;
}
    cow_cpt2++ ;
if (cow_cpt2==6)
{
time_frame7++ ;
 cow_cpt2=0;
}

SDL_SetColorKey(kartouch,SDL_SRCCOLORKEY, SDL_MapRGB(kartouch->format,255, 255,255));
          SDL_BlitSurface(kartouch,NULL,ecran,&pos_kartouch) ;
  SDL_SetColorKey(sprite7,SDL_SRCCOLORKEY, SDL_MapRGB(sprite7->format,255, 255,255));
          SDL_BlitSurface(sprite7,&position_sprite7,ecran,&pos_cowboy2) ;

a_kar+=10 ;
}






    if (  pos_hchich2.x>10 )
  {

        SDL_SetColorKey(sprite3,SDL_SRCCOLORKEY, SDL_MapRGB(sprite3->format,255, 255,255));
        SDL_BlitSurface(sprite3,&position_sprite3,ecran,&pos_hchich2) ;


  }







        if       (mvt_l)
        {
            time_frame2++;
            SDL_SetColorKey(sprite2,SDL_SRCCOLORKEY, SDL_MapRGB(sprite2->format,255, 255,255));
            SDL_BlitSurface(sprite2,&position_sprite2,ecran,&position_objet) ;
        }
        else if  (mvt_r)
        {
            time_frame++ ;
            SDL_SetColorKey(sprite,SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format,255, 255,255));
            SDL_BlitSurface(sprite,&position_sprite,ecran,&position_objet) ;
        }
        else  if (mvt_l_stop)
        {
            position_sprite2.x=0;
                SDL_SetColorKey(sprite2,SDL_SRCCOLORKEY, SDL_MapRGB(sprite2->format,255, 255,255));
            SDL_BlitSurface(sprite2,&position_sprite2,ecran,&position_objet) ;
        }
        else  if (mvt_r_stop)
        {
            position_sprite.x=0;
            SDL_SetColorKey(sprite,SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format,255, 255,255));
            SDL_BlitSurface(sprite,&position_sprite,ecran,&position_objet) ;
        }

        SDL_Flip(ecran) ;


        if (time_frame==3)
        {
            position_sprite.x=pos_sprite*75;
            verif_frame=1;
        }
        if (pos_sprite==27)
        {
            pos_sprite=1;
        }

        if (time_frame2==3)
        {
            position_sprite2.x=pos_sprite2*75;
            verif_frame2=1;
        }
        if (pos_sprite2==27)
        {
            pos_sprite2=1;
        }

        if (time_frame3==6)
        {
            position_sprite3.x=pos_sprite3*75;
            verif_frame3=1;
        }
        if (pos_sprite3==12)
        {
            pos_sprite3=1;
        }
        if (time_frame4==6)
        {
            position_sprite4.x=pos_sprite4*96;
            verif_frame4=1;
        }
        if (pos_sprite4==7)
        {
            pos_sprite4=1;
        }


        if (time_frame5==6)
        {
            position_sprite5.x=pos_sprite5*150;
            verif_frame5=1;
        }
        if (pos_sprite5==10)
        {
            pos_sprite5=1;
        }
        if (time_frame6==6)
        {
            position_sprite6.x=pos_sprite6*150;
            verif_frame6=1;
        }
        if (pos_sprite6==10)
        {
            pos_sprite6=1;
        }
                if (time_frame7==6)
        {
            position_sprite7.x=pos_sprite7*150;
            verif_frame7=1;
        }
        if (pos_sprite7==4)
        {
            pos_sprite7=1;
        }
 cpt_hchich ++ ;
 if (cpt_hchich==900)
    {
     pos_hchich.x=0 ;
            pos_hchich.y=650  ;
 cpt_hchich=0 ;
 }

        if(280/FPS > SDL_GetTicks()-start)
        {
            SDL_Delay(330/FPS-(SDL_GetTicks()-start));
        }

  if (position_objet.x<560 && position_objet.x >500 &&  position_objet.y<60  && position_objet.y >10 && key_c)
    {

  rool_back=1 ;
    }
    if (rool_back==1)
    {
        pos_hchich2.x-=3 ;
    }

  if (position_objet.x<120 && position_objet.x >10 &&  position_objet.y<700  && position_objet.y >580 && key_c )
        {   SDL_FreeSurface(sprite) ;
            SDL_FreeSurface(sprite2) ;
            sprite=SDL_LoadBMP("cowboy_1.bmp") ;
            sprite2=SDL_LoadBMP("cowboy_2.bmp") ;
            pos_hchich.x=0 ;
            pos_hchich.y=650  ;
           cow_boy=1 ;

        }
}
}
  if ( won )
  {
      Mix_HaltChannel(2);
   Mix_HaltChannel(3);
              if (*(stage_dispo)<5)     {*stage_dispo=5;}
            SDL_SetColorKey(img_won,SDL_SRCCOLORKEY, SDL_MapRGB(img_won->format,255, 255,255));
            SDL_BlitSurface(img_won,NULL,ecran,NULL) ;
            SDL_Flip(ecran) ;
            SDL_Delay(3000) ;
            continuer=0 ;
  }

  if (lose)
  {
Mix_HaltChannel(2);
   Mix_HaltChannel(3);
            SDL_SetColorKey(img_lose,SDL_SRCCOLORKEY, SDL_MapRGB(img_lose->format,255, 255,255));
            SDL_BlitSurface(img_lose,NULL,ecran,NULL) ;
            SDL_Flip(ecran) ;
            SDL_Delay(3000) ;
      continuer=0 ;
  }
    }


choix_stage(ecran,stage_dispo,difficulter) ;
}




int down_to_Surface4 (SDL_Rect position_objet, SDL_Surface *test_map, SDL_Surface *noir,int max_pix )
{
    int i=0 ,test=0 ;
    _Couleur_ loun;

    for (i=0; i<max_pix; i++ )
    {
        SDL_LockSurface(test_map);
        loun=SDL_LireCouleur(test_map,(position_objet.x+(noir->w)-40),(position_objet.y+(noir->h)+i-5));
        SDL_UnlockSurface(test_map);
        if (loun.r!=0 && loun.g!=0 && loun.b!=0)
        {
            test ++ ;
        }
    }

    return test ;
}


int up_to_Surface4 (SDL_Rect position_objet,  SDL_Surface *test_map, SDL_Surface *noir,int max_pix )
{
    int i=0 ,test=0 ;
    _Couleur_ loun;

    for (i=0; i<max_pix; i++ )
    {
        SDL_LockSurface(test_map);
        if (768>(position_objet.y+(noir->h)-i) && (position_objet.x+(noir->w)+40)<1366 )
            loun=SDL_LireCouleur(test_map,(position_objet.x+(noir->w)+40),(position_objet.y+(noir->h)-i));
        SDL_UnlockSurface(test_map);
        if (loun.r!=0 && loun.g!=0 && loun.b!=0)
        {
            test ++ ;
        }
    }
    test = max_pix-test  ;
    return test ;
}



