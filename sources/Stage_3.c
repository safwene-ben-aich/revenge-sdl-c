

#include "Stage_3.h"
#define speed 2
#define TIME_BEETWEN_TWO_FRAME 3
#define TIME_BEETWEN_TWO_FRAME_POLICE 30
#define TIME_BEETWEN_TWO_FRAME_ELEVATOR 5
#define TIME_BEETWEN_TWO_FRAME_EXIT 5
#define NOMBRE_DE_SAUT 13
#define FPS 30
#define NOMBRE_ESCALIER 44
void deplacement_sprite_police(SDL_Surface *ecran, SDL_Rect *position_police, int *nombre_sprite_police,int *nombre_frame_police,int *direction_police, int nombre_police);
void deplacement_sprite_personnage (SDL_Surface *ecran,int *nombre_sprite,int *nombre_frame,SDL_Rect *position_personnage,int direction_sprite);
int Test_collision_map(SDL_Rect position_personnage, int direction_personnage,SDL_Surface *sprite_test,SDL_Surface *map_test);

void main_stage_3(SDL_Surface *ecran, int stage, int *stage_dispo, int *difficulter)
{
    Mix_AllocateChannels(10);
    Mix_Music *musique_run, *musique_water,*musique_jump;
    musique_run= Mix_LoadWAV("run.wav");
    Mix_VolumeChunk(musique_run,MIX_MAX_VOLUME/2);
    musique_jump =Mix_LoadWAV("jump.wav");
    Mix_VolumeChunk(musique_jump,(MIX_MAX_VOLUME));

    SDL_Rect position_personnage,position_texte,position_police,position_police_2,position_police_3,position_police_4,position_elevator_1,position_exit,position_efface_1,position_efface_2;

    position_efface_1.x=1200;
    position_efface_1.y=489;

    position_efface_2.x=1166;
    position_efface_2.y=165;

    position_exit.x=500;
    position_exit.y=480;

    position_elevator_1.x=1200;
    position_elevator_1.y=730;
    position_police.x=100;
    position_police.y=701;

    position_police_2.x=800;
    position_police_2.y=571;

    position_police_3.x=200;
    position_police_3.y=380;

    position_police_4.x=820;
    position_police_4.y=171;

    position_personnage.x=1285; //20
    position_personnage.y=704;    //740
    SDL_Event event;
    int continuer=1,cpt_sound=300,nombre_sprite=0,nombre_frame=1,verif_direction=3,nombre_sprite_police=0,nombre_frame_police=1,direction_police=6,direction_police_2=6,direction_police_3=6,direction_police_4=6;
    int etat_bouton_1=0,etat_bouton_2=0,direction_elevator=1,nombre_frame_elevator=1,nombre_frame_exit=1,mouvement_exit=0,speed_mouvement_exit=1,verif_kill=0;
    int compteur_saut=0,jouer=0,cpt_jeu=0,cpt_aide=0,mouvement_haut=0,verif_gravite=0,mouvement_escalier=0,compteur_escalier=0,num_elevator=1,verif_changement_elevator=0,verif_direction_2,volume=30;
Mix_Music *musique_1=NULL;

   char text_aide [1000] ="" ;
    SDL_Surface *fond_base=NULL,*texte=NULL,*sprite=NULL,*sprite_test=NULL,*map_test=NULL,*you_win=NULL,*you_lose=NULL;
    you_lose=SDL_LoadBMP("gameover_5.bmp");
    you_win=SDL_LoadBMP("win_avion.bmp");
    Uint32 start;

    map_test=SDL_LoadBMP("Airport_test.bmp");
    sprite_test=SDL_LoadBMP("sprite_test.bmp");
    fond_base=SDL_LoadBMP("matar.bmp");
    SDL_BlitSurface(fond_base,NULL,ecran,NULL);
    SDL_Flip(ecran);


//Musique(3);
Mix_CloseAudio();
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
        TTF_Font *police = NULL;
    TTF_Init();
    police = TTF_OpenFont("aaa.ttf", 25);


Musique(3);
if (*(difficulter)==3 ) {jouer =1 ;}


    while (continuer)
    {
        start=SDL_GetTicks();
        SDL_PollEvent(&event);
if (!jouer )
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
  sprintf(text_aide,"you should avoid cops ");
  break ;
  case 1 :
      position_texte.x-=70;
  sprintf(text_aide," use the key 'b' to activate the elevator and 'c' to active the switcher ");
  break ;

  case 2 :
      position_texte.x+=160;
  sprintf(text_aide,"good luck !");
    break ;
  case 3 :
    jouer=1 ;
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
  sprintf(text_aide,"you are the mais suspect for the crime ");
  break ;
  case 1 :
      position_texte.x-=30;
  sprintf(text_aide,"i gess you should be carful to rich the airplan ");
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

       else if (jouer)
         {switch (event.type)
        {
        case SDL_QUIT :
            exit(1);
            break;
        case SDL_KEYDOWN :

            switch (event.key.keysym.sym)
            {
            case SDLK_RIGHT :
 if (Test_collision_map(position_personnage,6,sprite_test,map_test)==1)
{                       cpt_sound++;
                       if (cpt_sound>=300)    { Mix_PlayChannel(2,musique_run,1);cpt_sound=0; }


Test_gravite_surface(&position_personnage,sprite_test,map_test,&mouvement_haut,&verif_gravite,6);
position_personnage.x+=speed;
verif_direction=4;
}
                break;
            case SDLK_LEFT :
    if (Test_collision_map(position_personnage,4,sprite_test,map_test)==1)
    {
        cpt_sound++;
                       if (cpt_sound>=300)    { Mix_PlayChannel(2,musique_run,1);cpt_sound=0; }

Test_gravite_surface(&position_personnage,sprite_test,map_test,&mouvement_haut,&verif_gravite,4);
        position_personnage.x-=speed;
        verif_direction=6;
    }
                break;
case SDLK_c :
    Activate_bouton(position_personnage,&etat_bouton_1,&etat_bouton_2,&mouvement_exit,&num_elevator,&verif_changement_elevator);

break;
case SDLK_b :
 Activate_escalier(position_personnage,&mouvement_escalier);
break;

case SDLK_UP :
Mix_PlayChannel(3,musique_jump,1);
mouvement_haut=1;
break;
            }
            break;
            case SDL_KEYUP :
        switch (event.key.keysym.sym)
            {
case SDLK_RIGHT :
                  Mix_HaltChannel(2);
       cpt_sound=300;

            verif_direction=1;
            verif_direction_2=4;
            break;
case SDLK_LEFT :
      Mix_HaltChannel(2);
       cpt_sound=300;

       verif_direction=3;
       verif_direction_2=6;
       break;


            }
        break;
        }


if (mouvement_haut==1)
{
if (verif_gravite==0)
{
Test_collision_ciel(&position_personnage,sprite_test,map_test,&compteur_saut,&verif_gravite);
}
else
{
Test_gravite_surface(&position_personnage,sprite_test,map_test,&mouvement_haut,&verif_gravite,6);
}
}




        Afficage_fond_de_base(ecran);
    if (etat_bouton_1==1 || etat_bouton_2==1)
       {
        Deplacement_elevator(ecran,&position_elevator_1,&nombre_frame_elevator,num_elevator,&direction_elevator);
        Mise_a_jour_map_test(map_test,position_elevator_1,&position_efface_1,num_elevator);
        if (verif_changement_elevator==1)
        {
        Changement_position_elevator(position_personnage,etat_bouton_1,etat_bouton_2,&position_elevator_1,&num_elevator,&verif_changement_elevator,&direction_elevator,map_test);
        }
       }



        Affichage_bouton(ecran,&etat_bouton_1,&etat_bouton_2,1);
        Affichage_bouton(ecran,&etat_bouton_1,&etat_bouton_2,2);
        Affichage_exit(ecran,&position_exit,&nombre_frame_exit,&mouvement_exit,&speed_mouvement_exit);



if (mouvement_escalier==1)
{
Deplacement_personnage_escalier(&position_personnage,&mouvement_escalier,&compteur_escalier,verif_direction);
}



        deplacement_sprite_police(ecran,&position_police,&nombre_sprite_police,&nombre_frame_police,&direction_police,1);
        if (verif_kill==0)
        {
        Verif_collision_police_exit(position_police_2,position_exit,&etat_bouton_1,&mouvement_exit,&verif_kill);
        deplacement_sprite_police(ecran,&position_police_2,&nombre_sprite_police,&nombre_frame_police,&direction_police_2,2);
        }


        deplacement_sprite_police(ecran,&position_police_3,&nombre_sprite_police,&nombre_frame_police,&direction_police_3,3);
        deplacement_sprite_police(ecran,&position_police_4,&nombre_sprite_police,&nombre_frame_police,&direction_police_4,4);

    Test_gravite_surface_2(&position_personnage,sprite_test,map_test);
    deplacement_sprite_personnage(ecran,&nombre_sprite,&nombre_frame,&position_personnage,verif_direction);

    if (Test_mourir(position_police,position_police_2,position_police_3,position_police_4,position_personnage,direction_police,direction_police_2,direction_police_3,verif_direction_2,verif_kill)==1)
    {
    Mix_HaltChannel(2);
    SDL_SetColorKey(you_lose, SDL_SRCCOLORKEY, SDL_MapRGB(you_lose->format,255, 255,255));
    SDL_BlitSurface(you_lose,NULL,ecran,NULL);
    SDL_Flip(ecran);
    SDL_Delay(2000);
    continuer =0 ;
    }


 Test_distance_personnage_police(position_police,position_police_2,position_police_3,position_police_4,position_personnage,&volume,verif_kill);

    if (Test_fin(position_personnage)==1)
    {
        Mix_HaltChannel(2);
  if (*(stage_dispo)<4)     {    *stage_dispo=4;}
    SDL_SetColorKey(you_win, SDL_SRCCOLORKEY, SDL_MapRGB(you_win->format,255, 255,255));
    SDL_BlitSurface(you_win,NULL,ecran,NULL);
    SDL_Flip(ecran);
    SDL_Delay(2000);
    continuer=0;
    choix_stage(ecran);
    }
//Mix_VolumeChunk(musique_1,volume);
    SDL_Flip(ecran);

        if(280/FPS > SDL_GetTicks()-start)
        {
            SDL_Delay(280/FPS-(SDL_GetTicks()-start));
        }
    }
}


}


void Test_distance_personnage_police(SDL_Rect police_1,SDL_Rect police_2,SDL_Rect police_3,SDL_Rect police_4,SDL_Rect position_personnage, int *volume, int verif_kill)
{
if (position_personnage.y>600)
{
*(volume)=abs(position_personnage.x-police_1.x);
}
else if (position_personnage.y<600 && position_personnage.y>400 && verif_kill==0)
{
*(volume)=abs(position_personnage.x-police_2.x);
}
else if ( position_personnage.y<200 && position_personnage.y>150)
{
*(volume)=abs(position_personnage.x-police_4.x);
}
else if (position_personnage.y>300 && position_personnage.y<450)
{
*(volume)=abs(position_personnage.x-police_3.x);
}
else
{
*(volume)=30;
}
}





int Test_mourir (SDL_Rect police_1,SDL_Rect police_2,SDL_Rect police_3,SDL_Rect police_4,SDL_Rect position_personnage, int direction_police_1,int direction_police_2,int direction_police_3,int direction_personnage,int verif_kill)
{
if (abs(position_personnage.x-police_1.x)<250&& position_personnage.y>600)
{
return 1;
}
else if ((abs(position_personnage.x-police_2.x)<220 && position_personnage.y<600 && position_personnage.y>400 && verif_kill==0))
{
return 1;
}
else if (abs(position_personnage.x-police_4.x)<220 && position_personnage.y<200 && position_personnage.y>150)
{
return 1;
}

else if (abs(position_personnage.x-police_3.x)<100 && position_personnage.y>300 && position_personnage.y<450)
{
return 1;
}
}


int Test_fin(SDL_Rect position_personnage)
{
if (position_personnage.x>10 && position_personnage.x<30 && position_personnage.y>10 && position_personnage.y<50)
{
return 1;
}


}





void Activate_bouton(SDL_Rect position_personnage, int *etat_bouton_1, int *etat_bouton_2, int *mouvement_exit, int *num_elevator, int *verif_changement_elevator)
{
if (position_personnage.x>700 && position_personnage.x<750)
{
*(verif_changement_elevator)=1;
*(etat_bouton_1)=1;
*(mouvement_exit)=1;
}
if (position_personnage.x<40 && position_personnage.x>20)
{
*(verif_changement_elevator)=1;
*(etat_bouton_2)=1;
*(num_elevator)=3;
*(etat_bouton_1)=0;
}
}

void Affichage_bouton(SDL_Surface *ecran,int *etat_bouton_1, int *etat_bouton_2, int num_bouton)
{
SDL_Surface *bouton;
SDL_Rect position_bouton;
switch (num_bouton)
{
case 1 :
position_bouton.x=700;
position_bouton.y=673;
switch(*etat_bouton_1)
{
case 0: bouton=SDL_LoadBMP("bouton_1_etat_0.bmp");break;
case 1 : bouton=SDL_LoadBMP("bouton_1_etat_1.bmp");break;
}
break;
case 2 :
position_bouton.x=26;
position_bouton.y=249;
switch(*etat_bouton_2)
{
case 0 : bouton=SDL_LoadBMP("bouton_2_etat_0.bmp");break;
case 1 : bouton=SDL_LoadBMP("bouton_2_etat_1.bmp");break;
}
break;
}
SDL_SetColorKey(bouton, SDL_SRCCOLORKEY, SDL_MapRGB(bouton->format,255, 255,255));
SDL_BlitSurface(bouton,NULL,ecran,&position_bouton);
SDL_FreeSurface(bouton);
}







void Mise_a_jour_map_test(SDL_Surface *map_test,SDL_Rect position_objet,SDL_Rect *position_efface_1,int Num_elevator)
{

SDL_Surface *objet=NULL,*efface=NULL;
switch (Num_elevator){
case 1 :efface=SDL_LoadBMP("efface_elevator_1.bmp");
position_efface_1->x=1200;
position_efface_1->y=489;
break;
case 2 :efface=SDL_LoadBMP("efface_elevator_2.bmp");
position_efface_1->x=14;
position_efface_1->y=377;
break;
case 3 :efface=SDL_LoadBMP("efface_elevator_3.bmp");
position_efface_1->x=1166;
position_efface_1->y=165;
break;
}

objet=SDL_LoadBMP("elevator_1_test.bmp");
SDL_BlitSurface(efface,NULL,map_test,position_efface_1);
SDL_BlitSurface(objet,NULL,map_test,&position_objet);
SDL_FreeSurface(objet);
SDL_FreeSurface(efface);
}


void Activate_escalier(SDL_Rect position_personnage, int *mouvement_escalier)
{
if ((position_personnage.x<1200 && position_personnage.x>1150) || (position_personnage.x<950 && position_personnage.x>870))
{
*(mouvement_escalier)=1;
}
}


void Deplacement_personnage_escalier(SDL_Rect *position_personnage, int *mouvement_escalier, int *compteur_escalier,int direction)
{
(*compteur_escalier)++;
if (*compteur_escalier!=NOMBRE_ESCALIER)
{
if (direction==1)
{
position_personnage->y-=2;
position_personnage->x+=2;
}
else if (direction==3)
{
position_personnage->y-=2;
position_personnage->x-=2;
if (*compteur_escalier>42)
{
position_personnage->x-=2;
}
}
}
else
{
*(compteur_escalier)=0;
*(mouvement_escalier)=0;
}
}


void Test_collision_ciel(SDL_Rect *position_personnage,SDL_Surface *sprite_test,SDL_Surface *map_test, int *compteur_saut,int *verif_gravite)
{
(*compteur_saut)++;
_Couleur_ loun;
SDL_LockSurface(map_test);
loun=SDL_LireCouleur(map_test,(position_personnage->x)+(sprite_test->w/2),position_personnage->y);
SDL_UnlockSurface(map_test);
if ((loun.r==0 && loun.g==0 && loun.b==0) || (*(compteur_saut)==NOMBRE_DE_SAUT))
{
*(verif_gravite)=1;
*(compteur_saut)=0;
}
else
{
position_personnage->y-=10;
}
}

void Test_gravite_surface_2(SDL_Rect *position_personnage, SDL_Surface *sprite_test, SDL_Surface *map_test)
{
_Couleur_ loun;
SDL_LockSurface(map_test);
loun=SDL_LireCouleur(map_test,(position_personnage->x)+(sprite_test->w/2),position_personnage->y+(sprite_test->h));
SDL_UnlockSurface(map_test);
if (loun.r==0 && loun.g==0 && loun.b==0)
{
SDL_LockSurface(map_test);
loun=SDL_LireCouleur(map_test,(position_personnage->x)+(sprite_test->w/2),position_personnage->y+(sprite_test->h)-4);
SDL_UnlockSurface(map_test);
if (loun.r==0 && loun.g==0 && loun.b==0)
position_personnage->y-=1;
}
else
{
position_personnage->y+=1;
}
}

void Test_gravite_surface(SDL_Rect *position_personnage, SDL_Surface *sprite_test, SDL_Surface *map_test,int *mouvement_haut, int *verif_gravite, int verif_direction)
{
_Couleur_ loun;
SDL_LockSurface(map_test);
loun=SDL_LireCouleur(map_test,(position_personnage->x)+(sprite_test->w/2),position_personnage->y+(sprite_test->h));
SDL_UnlockSurface(map_test);
if (loun.r==0 && loun.g==0 && loun.b==0)
{
*(mouvement_haut)=0;
*(verif_gravite)=0;
}
else
{
if (verif_direction==6)
{
position_personnage->y+=10;
}
else
{
position_personnage->y+=2;
}
}
}



int Test_collision_map(SDL_Rect position_personnage, int direction_personnage,SDL_Surface *sprite_test,SDL_Surface *map_test)
{
_Couleur_ loun;
SDL_LockSurface(map_test);
switch (direction_personnage)
{
case 4 :
loun=SDL_LireCouleur(map_test,(position_personnage.x),position_personnage.y+(sprite_test->h/2));
break;
case 6 :
loun=SDL_LireCouleur(map_test,(position_personnage.x+(sprite_test->w)),position_personnage.y+(sprite_test->h/2));
break;
}
SDL_UnlockSurface(map_test);
if ((loun.r!=0 && loun.g!=0 && loun.b!=0))
{
return 1;
}

}


void Verif_collision_police_exit(SDL_Rect position_police,SDL_Rect position_exit,int *etat_bouton_1, int *mouvment_exit, int *verif_kill)
{
if (abs(position_exit.x-position_police.x)<70 && *(etat_bouton_1)==1 && position_exit.y>550 && *(mouvment_exit)==1)
{
*(verif_kill)=1;
}
}



void Affichage_exit(SDL_Surface *ecran, SDL_Rect *position_exit,int *nombre_frame_exit,int *mouvement_exit,int *speed_mouvement_exit)
{
SDL_Surface *EXIT=NULL;
EXIT=SDL_LoadBMP("exit3.bmp");
if (position_exit->y<595)
{
if (*mouvement_exit==1){
(*speed_mouvement_exit)++;
(*nombre_frame_exit)++;
if (*(nombre_frame_exit)==TIME_BEETWEN_TWO_FRAME_EXIT)
{
*(nombre_frame_exit)=1;
position_exit->y+=(*speed_mouvement_exit)*2;
}
}
}
else
(*mouvement_exit)=0;
SDL_SetColorKey(EXIT, SDL_SRCCOLORKEY, SDL_MapRGB(EXIT->format,255, 255,255));
SDL_BlitSurface(EXIT,NULL,ecran,position_exit);
SDL_FreeSurface(EXIT);
}

void Changement_position_elevator(SDL_Rect position_personnage, int etat_bouton_1,int etat_bouton_2,SDL_Rect *position_elevator_1, int *num_elevator, int *verif_changement_elevator,int *direction_elevator,SDL_Surface *map_test)
{
if (position_personnage.x<600 && position_personnage.y>450 && etat_bouton_1==1)
{
*(verif_changement_elevator)=0;
*(num_elevator)=2;
map_test=SDL_LoadBMP("Airport_test.bmp");
position_elevator_1->x=17;
position_elevator_1->y=540;

}
else if (etat_bouton_1==0 && *(num_elevator)==3)
{
map_test=SDL_LoadBMP("Airport_test.bmp");
*(verif_changement_elevator)=0;
position_elevator_1->x=1166;
position_elevator_1->y=200;
}


}

void Deplacement_elevator(SDL_Surface *ecran,SDL_Rect *position_elevator_1,int *nombre_frame_elevator,int num_elevator,int *direction_elevator)
{
SDL_Surface *elevator=NULL;
elevator=SDL_LoadBMP("elevator_1.bmp");
switch (num_elevator)
{
case 1 :
if (position_elevator_1->y<550)
{
*(direction_elevator)=2;
}
else if (position_elevator_1->y>730)
{
*direction_elevator=1;
}
break;
case 2 :
if (position_elevator_1->y<434)
{
*direction_elevator=2;
}
else if (position_elevator_1->y>540)
{
*direction_elevator=1;
}
break;
case 3 :
if (position_elevator_1->y<220)
{
*direction_elevator=2;
}
else if (position_elevator_1->y>400)
{
*direction_elevator=1;
}
}
(*nombre_frame_elevator)++;
if (*(nombre_frame_elevator)==TIME_BEETWEN_TWO_FRAME_ELEVATOR)
{
*(nombre_frame_elevator)=1;
switch (*direction_elevator)
{
case 1 :
position_elevator_1->y-=1;
break;
case 2 :
position_elevator_1->y+=1;
break;
}
}
SDL_SetColorKey(elevator, SDL_SRCCOLORKEY, SDL_MapRGB(elevator->format,255, 255,255));
SDL_BlitSurface(elevator,NULL,ecran,position_elevator_1);
SDL_FreeSurface(elevator);
}











void deplacement_sprite_police(SDL_Surface *ecran, SDL_Rect *position_police, int *nombre_sprite_police,int *nombre_frame_police,int *direction_police, int nombre_police)
{
    SDL_Surface *sprite_police=NULL;
    SDL_Rect position_sprite_police;

    switch (nombre_police)
    {
    case 1 :
        if (position_police->x>805 && *(direction_police)==6)
        {
            Remise_zero_police(nombre_frame_police,nombre_sprite_police,direction_police);
        }
        else if (position_police->x<65 && *(direction_police)==4)
        {
            Remise_zero_police(nombre_frame_police,nombre_sprite_police,direction_police);
        }
        break;
    case 2 :
        if (position_police->x>805 && *(direction_police)==6)
        {
            Remise_zero_police(nombre_frame_police,nombre_sprite_police,direction_police);
        }
        else if (position_police->x<65 && *(direction_police)==4)
        {
            Remise_zero_police(nombre_frame_police,nombre_sprite_police,direction_police);
        }
        break;
    case 3 :
    if (position_police->x>820 && *(direction_police)==6)
    {
            Remise_zero_police(nombre_frame_police,nombre_sprite_police,direction_police);
    }
    else if (position_police->x<130 && *(direction_police)==4)
        {
            Remise_zero_police(nombre_frame_police,nombre_sprite_police,direction_police);
        }

    case 4 :
          if (position_police->x>820 && *(direction_police)==6)
    {
            Remise_zero_police(nombre_frame_police,nombre_sprite_police,direction_police);
    }
    else if (position_police->x<215 && *(direction_police)==4)
        {
            Remise_zero_police(nombre_frame_police,nombre_sprite_police,direction_police);
        }


    }

    (*nombre_frame_police)++;
    if (*(nombre_frame_police)==TIME_BEETWEN_TWO_FRAME_POLICE)
    {
        (*nombre_sprite_police)++;
        *(nombre_frame_police)=1;
    }
    if (*(nombre_sprite_police)==8)
    {
        *(nombre_sprite_police)=1;
    }

position_sprite_police.w=54.25;
position_sprite_police.h=65;
position_sprite_police.y=0;

    switch (*direction_police)
    {
    case 4 :

        position_sprite_police.x=379.75;

        position_sprite_police.x=position_sprite_police.x-(*nombre_sprite_police*(54.25));
        position_police->x-=1;
        sprite_police=SDL_LoadBMP("police_left.bmp");
        break;
    case 6 :


        position_sprite_police.x=54.25;

        position_sprite_police.x=*(nombre_sprite_police)*54.25;
        position_police->x+=1;
        sprite_police=SDL_LoadBMP("police_right.bmp");
        break;
    }


    SDL_SetColorKey(sprite_police, SDL_SRCCOLORKEY, SDL_MapRGB(sprite_police->format,255, 255,255));
    SDL_BlitSurface(sprite_police,&position_sprite_police,ecran,position_police);
    SDL_FreeSurface(sprite_police);

}

void deplacement_sprite_personnage (SDL_Surface *ecran,int *nombre_sprite,int *nombre_frame,SDL_Rect *position_personnage,int direction_sprite)
{
SDL_Rect position_sprite;
SDL_Surface *sprite=NULL;
if (direction_sprite==6 || direction_sprite==4)
{
(*nombre_frame)++;
if (*(nombre_sprite)==26)
{
*(nombre_sprite)=1;
}
if (*(nombre_frame)==TIME_BEETWEN_TWO_FRAME)
{
*(nombre_frame)=1;
(*nombre_sprite)++;
}

position_sprite.w=75;
position_sprite.h=52.5;
position_sprite.y=0;
switch (direction_sprite)
{

case 4 : sprite=SDL_LoadBMP("sprite_matar_rigth.bmp");
position_sprite.x=75;
position_sprite.x=*(nombre_sprite)*75;
break;
case 6 : sprite=SDL_LoadBMP("sprite_matar_left.bmp");
position_sprite.x=1950;
position_sprite.x=position_sprite.x-(*nombre_sprite*(75));
break;
}
SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format,255, 255,255));
SDL_BlitSurface(sprite,&position_sprite,ecran,position_personnage);
}
else
{
switch (direction_sprite)
{
case 3 : sprite=SDL_LoadBMP("personnage_repos_left.bmp");break;
case 1 : sprite=SDL_LoadBMP("personnage_repos_rigth.bmp");break;
}

SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format,255, 255,255));
SDL_BlitSurface(sprite,NULL,ecran,position_personnage);

}

SDL_FreeSurface(sprite);
}




void Remise_zero_police(int *nombre_frame_police, int *nombre_sprite_police, int *direction_police)
{
    *(nombre_frame_police)=1;
    *(nombre_sprite_police)=0;
    if (*(direction_police)==4)
    {
        *(direction_police)=6;
    }
    else
    {
        *(direction_police)=4;
    }


}

void Afficage_fond_de_base(SDL_Surface *ecran)
{
    SDL_Surface *fond_base=NULL;
    fond_base=SDL_LoadBMP("matar.bmp");
    SDL_BlitSurface(fond_base,NULL,ecran,NULL);
    SDL_FreeSurface(fond_base);
}








