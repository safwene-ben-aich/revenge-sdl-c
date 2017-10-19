#include "stage_5.h"
#define TIME_BEETWEN_2_FRAMES 8

void main_stage_5(SDL_Surface *ecran, int stage, int *stage_dispo, int *difficulter )
{
  Mix_AllocateChannels(10);
    Mix_Music *musique_run, *musique_water,*musique_jump;
    musique_run= Mix_LoadWAV("run.wav");
    Mix_VolumeChunk(musique_run,MIX_MAX_VOLUME/2);
    musique_jump =Mix_LoadWAV("jump.wav");
    Mix_VolumeChunk(musique_jump,(MIX_MAX_VOLUME));

       char text_aide [1000] ="" ;
FILE *fichier=NULL;
SDL_Rect position_base , camera ,position_objet,position_texte;
position_texte.x=80;
position_texte.y=50;
int compteur=0,cpt_sound=300,surf=0,dans_l_air=0  ,jouer=0,cpt_jeu=0,cpt_aide=0,ending=0 , fix_map=0,cpt_map=0 ,cpt_u_r=0 ,mvt_up_right=0 ;
char temps[20]="";
Uint8 g=0,r=255;
SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};


_Couleur_ loun;

TTF_Font *police = NULL;
TTF_Init();
police = TTF_OpenFont("aaa.ttf", 25);
sprintf(temps, "Temps : %d", compteur);


SDL_Surface *win2=NULL, *arrested_map=NULL ,*test_map=NULL,*fond_base=NULL,*noir=NULL,*sprite=NULL,*texte=NULL;

position_objet.x=100; position_objet.y=610;

sprite=SDL_LoadBMP("sprite5.bmp");
SDL_Rect position_sprite;

SDL_Event event,event2;
int arrested=0, continuer=1,i=0,cpt=0,mvt_up=0,i_pause=1;

int FPS=30;
int speed=4;
Uint32 start ;

int x=0,y=0,time_frame=0,verif_frame=0;
Musique(5);

       test_map=SDL_LoadBMP("map_test5.bmp");
	   fond_base=SDL_LoadBMP("map_zoom_15.bmp");
       noir=SDL_LoadBMP("noir.bmp");
       arrested_map=SDL_LoadBMP("gameover_5.bmp") ;
       win2=SDL_LoadBMP("win2.bmp") ;
camera.x=0;
camera.y=0;
camera.w=1366;
camera.h=768;
int pos_sprite=0;
SDL_EnableKeyRepeat(10,10);

position_sprite.w=150;
position_sprite.h=105;
position_sprite.x=150;
position_sprite.y=0;
if (*(difficulter)==3) {jouer=1;}
while (continuer)
{

if (verif_frame){
time_frame=0;
pos_sprite++;
verif_frame=0;
}
time_frame++;


start=SDL_GetTicks();
SDL_PollEvent(&event);
if (!jouer)
{

 if (*(difficulter)==1)
  {   position_texte.x=500;
   position_texte.y=350;
   cpt_jeu++ ;
  if (cpt_jeu==600)
  {
   cpt_aide++ ;
   cpt_jeu=0;
  }
  switch (cpt_aide)
  {case 0 :
      position_texte.x+=5;
  sprintf(text_aide,"you should avoid the obstacles ");
  break ;
  case 1 :
      position_texte.x-=20;
  sprintf(text_aide,"jump before you rich the obstacles ");
  break ;
  case 2 :
      position_texte.x-=100;
  sprintf(text_aide,"you can use the key 'space ' to esquive when you get stuck");
    break ;
  case 3 :
      position_texte.x+=160;
  sprintf(text_aide,"good luck !");

    break ;
  case 4 :
    jouer=1 ;
    position_texte.x=80;
    position_texte.y=50;
    time_frame=0;
    break ;
  }
        SDL_BlitSurface(fond_base,&camera,ecran,NULL) ;
       texte = TTF_RenderText_Shaded(police, text_aide ,couleurBlanche, couleurNoire);
       SDL_BlitSurface(texte,NULL,ecran,&position_texte);

   SDL_Flip(ecran) ;
  }
  else if (*(difficulter)==2)
  {
   position_texte.x=500;
   position_texte.y=350;
   cpt_jeu++ ;
  if (cpt_jeu==500)
  {
   cpt_aide++ ;
   cpt_jeu=0;
  }
  switch (cpt_aide)
  {case 0 :
  sprintf(text_aide,"you should run from police ");
  break ;
  case 1 :
      position_texte.x+=20;
  sprintf(text_aide,"jumping may help you  ");
  break ;
  case 2 :
      position_texte.x+=80;
  sprintf(text_aide,"good luck !! ");
    break ;
  case 3 :
    jouer=1 ;
    position_texte.x=80;
    position_texte.y=50;
    time_frame=0;
    break ;
  }
        SDL_BlitSurface(fond_base,&camera,ecran,NULL) ;
      texte = TTF_RenderText_Shaded(police, text_aide ,couleurBlanche, couleurNoire);
       SDL_BlitSurface(texte,NULL,ecran,&position_texte);

   SDL_Flip(ecran) ;
  }
}
else if (jouer)
{
             cpt_sound++;
                       if (cpt_sound>=300)    { Mix_PlayChannel(2,musique_run,1);cpt_sound=0; }

    switch (event.type){
case SDL_QUIT : exit(1);break;

case SDL_KEYDOWN :
    switch (event.key.keysym.sym)
    {

 case SDLK_ESCAPE :
   Pause(ecran,camera,position_objet,5) ;
    break ;

case SDLK_UP :
if ((position_objet.y>300)&& !dans_l_air)
{if (!mvt_up) // && (!mvt_up_right))
{
 Mix_PlayChannel(3,musique_jump,1);
mvt_up=1;
mvt_up_right=0 ;
}
}
break ;
case SDLK_SPACE :
    position_objet.y=630 ;
 break ;

 case SDLK_RIGHT :

if (!Verif_collision_objet5(position_objet,camera,test_map,noir))
        position_objet.x += 2 ;
     if (position_objet.x>=1000)
     {
         camera.x+=2 ;
         position_objet.x-=2;
     }
surf =up_to_Surface5(position_objet,camera,test_map,noir, 100  ) ;
 if ((surf< 100 ) && surf !=0 )
 { position_objet.y -=surf ;}
surf =0 ;
     break ;

 case SDLK_LEFT :
        position_objet.x-=(position_objet.w+10 ) ;
       if (!Verif_collision_objet5(position_objet,camera,test_map,noir))
        position_objet.x -= 2 ;
       position_objet.x+=(position_objet.w+10 ) ;

    break ;
    }
    break ;
   }
if ( (Verif_collision_objet5(position_objet,camera,test_map,noir)) && (position_objet.x>0 ) && (!mvt_up) )
 {
   position_objet.x-= speed ;
 }

surf = down_to_Surface5(position_objet,camera,test_map,noir, 600- position_objet.y  ) ;

if ((surf> 15) && !mvt_up && !mvt_up_right )
{
  position_objet.y+=15 ;
  dans_l_air=1 ;
}
else if ((surf<15 )&& !mvt_up && !mvt_up_right )
{
  position_objet.y+=surf ;
  dans_l_air=0 ;
}


surf =up_to_Surface5(position_objet,camera,test_map,noir, 50  ) ;
 if ((surf< 50 ) && surf !=0 )
 {  position_objet.y -=surf ; }
surf =0 ;
if (mvt_up)
{
    cpt++ ;
if (cpt < 17)
{
    position_objet.y-=noir->h ;
  if (!Verif_Collision_Surface5(position_objet,camera,test_map,noir))
   position_objet.y-=15 ;
   if (Verif_Collision_Surface5(position_objet,camera,test_map,noir))
    cpt=17 ;
   position_objet.y+=noir->h ;
  if (Verif_collision_objet5(position_objet,camera,test_map,noir) )
    position_objet.x-=speed ;
}
else if ( cpt>= 17 )
{  surf = down_to_Surface5(position_objet,camera,test_map,noir, 15) ;
    if (surf!=0)
    {  dans_l_air=1 ;}
   cpt=0 ;
   mvt_up=0 ;}
}

if  ((camera.x >=12296-1369 ) &&( cpt_map==1)  ) { fix_map=1;}
if ((fix_map!=1)) {camera.x+=speed;}
if ((camera.x>=9562 )&& (cpt_map!=1) )
{
cpt_map ++;
camera.x=0;
fond_base=SDL_LoadBMP("map_zoom_25.bmp");
test_map=SDL_LoadBMP("map_test_25.bmp");
}
if (position_objet.x==0)
{
    arrested=1 ;
}
if ( (fix_map==1 )&& ( position_objet.x >= (210) ) )  { ending = 1 ;}//908

    SDL_BlitSurface(fond_base,&camera,ecran,NULL);
if ( (ending==1) && (arrested !=1))
    {
         Mix_HaltChannel(2);
	fond_base=SDL_LoadBMP("maps25_end.bmp");
	SDL_BlitSurface(fond_base,&camera,ecran,NULL);

    SDL_Flip(ecran);
SDL_Delay(5000) ;
       	SDL_BlitSurface(win2,NULL,ecran,NULL);
    SDL_Flip(ecran);


    SDL_Delay(5000) ;
    continuer=0 ;

    }

g=(position_objet.x*255)/1250;
if (g>255){
g=255;
}
r=255-g;

compteur=position_objet.x;
if (compteur<0){
compteur=0;
r=255;
g=0;
}


SDL_Color couleurBlanche = {r,g,0};

 if ((ending!=1) && (arrested!=1))
{
sprintf(temps, "Distance : %d", compteur);
texte = TTF_RenderText_Shaded(police, temps,couleurBlanche, couleurNoire);
 SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format,255, 255,255));
 SDL_BlitSurface(sprite,&position_sprite,ecran,&position_objet);
SDL_BlitSurface(texte,NULL,ecran,&position_texte);

 SDL_Flip(ecran);}
if  ((camera.x >=10245-1369 ) &&( cpt_map==1)  ) { fix_map=1;}

if (arrested==1)
{
 Mix_HaltChannel(2);
 fix_map=1;
SDL_BlitSurface(fond_base,&camera,ecran,NULL);
 SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format,255, 255,255));
 SDL_BlitSurface(sprite,&position_sprite,ecran,&position_objet);
 SDL_SetColorKey(arrested_map, SDL_SRCCOLORKEY, SDL_MapRGB(arrested_map->format,255, 255,255));
 SDL_BlitSurface(arrested_map,NULL,ecran,NULL);

 SDL_Flip(ecran);

    SDL_Delay(3000) ;
    continuer=0 ;

}


if (time_frame==3){
position_sprite.x=pos_sprite*150;
verif_frame=1;}

if (pos_sprite==27){ pos_sprite=1;}
 if(280/FPS > SDL_GetTicks()-start) { SDL_Delay(330/FPS-(SDL_GetTicks()-start)); }



}
}
choix_stage(ecran,stage_dispo,difficulter) ;
/*
if (stage){
fichier=fopen("pause","r");
rewind(fichier);

fscanf(fichier,"%d\n",&camera.x);
fscanf(fichier,"%d\n",&position_objet.x);
fscanf(fichier,"%d\n",&position_objet.y);
if(position_objet.y<615)
cpt=15;
}
//Musique(2);
while (continuer)
{

if (verif_frame){
time_frame=0;
pos_sprite++;
verif_frame=0;
}
time_frame++;

start=SDL_GetTicks();
SDL_PollEvent(&event);

switch (event.type){
case SDL_QUIT : exit(1);break;
case SDL_KEYDOWN :

    switch (event.key.keysym.sym){

case SDLK_UP :
if (!mvt_up)
{
mvt_up=1;
}
break ;

case SDLK_RIGHT :
if (!Verif_collision_objet(position_objet,camera,test_map,noir))
{
position_objet.x+=1;
}
break ;
case SDLK_ESCAPE :
Pause(ecran,camera,position_objet);

break;

case SDLK_SPACE :
    if ( arrested==1 )
        menu_principale(ecran) ;
  break ;
}
break;
}



if (mvt_up==1 )
{
cpt++ ;
if(cpt<15)
{
position_objet.y-=15 ;
}

else if (cpt >=15 && position_objet.y<615)
{
//test collision surface

cpt++ ;
surf=up_to_Surface (position_objet, camera, test_map, noir,15 ) ;

position_objet.y += surf ;
if ( surf<15)
 cpt=28 ;
surf =0 ;

/*
position_objet.y+=15 ;

if (!Verif_Collision_Surface(position_objet,camera,test_map,noir))
{
mvt_up=0;
}




}

}
if (cpt== 28)
{
cpt=0 ;
mvt_up = 0 ;
}
// Test gravité


/*
if (!Test_gravite(position_objet,camera,test_map,noir,mvt_up))
{
mvt_up=1;
}


x+=speed;

if ((camera.x<11611-1369)&& (fix_map!=1))
camera.x+=speed;
//position_objet.x+=0.7 ;

if ((camera.x>=11611-1369 )&& (cpt_map!=1) )
{
cpt_map ++;
camera.x=0;
fond_base=SDL_LoadBMP("map_zoom_2.bmp");
test_map=SDL_LoadBMP("map_test_2.bmp");
}

if (position_objet.x==0)
{
    arrested=1 ;
}

if ( ((camera.x >=10245-1369 ) &&( cpt_map==1)  ) || ( arrested==1))
{
fix_map=1;

}

if (Verif_collision_objet(position_objet,camera,test_map,noir))
{
position_objet.x-=speed;
}
SDL_BlitSurface(fond_base,&camera,ecran,NULL);

//position_objet.x-=1;

g=(position_objet.x*255)/1250;
if (g>255){
g=255;
}
r=255-g;

compteur=position_objet.x;
if (compteur<0){
compteur=0;
r=255;
g=0;
}

if ( (fix_map==1 )&& ( position_objet.x >= (940) ) )
{
 ending = 1 ;
}


SDL_Color couleurBlanche = {r,g,0};
if ((ending!=1) && (arrested!=1))
{

sprintf(temps, "Distance : %d", compteur);
texte = TTF_RenderText_Shaded(police, temps,couleurBlanche, couleurNoire);
 SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format,255, 255,255));
 SDL_BlitSurface(texte, NULL, ecran, &position_texte);
 SDL_BlitSurface(sprite,&position_sprite,ecran,&position_objet);
 SDL_Flip(ecran);
}


if ( (ending==1) && (arrested !=1))
    {

	fond_base=SDL_LoadBMP("maps2_end.bmp");
	SDL_BlitSurface(fond_base,&camera,ecran,NULL);
    sprintf(temps, "YOU WIN ! ", compteur);
    texte = TTF_RenderText_Shaded(police, temps,couleurBlanche, couleurNoire);
    position_texte.x=768/2;
    position_texte.y=500;
    SDL_BlitSurface(texte, NULL, ecran, &position_texte);
    SDL_Flip(ecran);

    }

if (arrested==1)
{

SDL_BlitSurface(fond_base,&camera,ecran,NULL);
 SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format,255, 255,255));
 SDL_BlitSurface(sprite,&position_sprite,ecran,&position_objet);
 SDL_SetColorKey(arrested_map, SDL_SRCCOLORKEY, SDL_MapRGB(arrested_map->format,255, 255,255));
 SDL_BlitSurface(arrested_map,NULL,ecran,NULL);

 SDL_Flip(ecran);



}


if (time_frame==3){
position_sprite.x=pos_sprite*150;
verif_frame=1;
}

if (pos_sprite==27){
pos_sprite=1;
}

  if(280/FPS > SDL_GetTicks()-start) {
 SDL_Delay(280/FPS-(SDL_GetTicks()-start));
  }

}



 TTF_CloseFont(police);
    TTF_Quit();
   SDL_Quit();
*/



}











int down_to_Surface5 (SDL_Rect position_objet, SDL_Rect camera, SDL_Surface *test_map, SDL_Surface *noir,int max_pix )
{
int i=0 ,test=0 ;
_Couleur_ loun;

for (i=0;i<max_pix;i++ )
{
SDL_LockSurface(test_map);
loun=SDL_LireCouleur5(test_map,(position_objet.x+camera.x+(noir->w)-20),(position_objet.y+(noir->h)+i-5));
SDL_UnlockSurface(test_map);
if (loun.r!=0 && loun.g!=0 && loun.b!=0) {test ++ ; }
}

return test ;
}


int up_to_Surface5 (SDL_Rect position_objet, SDL_Rect camera, SDL_Surface *test_map, SDL_Surface *noir,int max_pix )
{
int i=0 ,test=0 ;
_Couleur_ loun;

for (i=0;i<max_pix;i++ )
{
SDL_LockSurface(test_map);
loun=SDL_LireCouleur5(test_map,(position_objet.x+camera.x+(noir->w)+10),(position_objet.y+(noir->h)-i));
SDL_UnlockSurface(test_map);
if (loun.r!=0 && loun.g!=0 && loun.b!=0) {test ++ ;}
}
test = max_pix-test  ;
return test ;
}

int Verif_Collision_Surface5 (SDL_Rect position_objet, SDL_Rect camera, SDL_Surface *test_map, SDL_Surface *noir)
{
_Couleur_ loun;
int i =0 ,j=0,test =0 ;
for (i=0 ; i<50 ;i++ )
{
SDL_LockSurface(test_map);
loun=SDL_LireCouleur5(test_map,(position_objet.x+camera.x+(noir->w/2)-30 + i ),(position_objet.y+(noir->h)));
SDL_UnlockSurface(test_map);
if (loun.r!=0 && loun.g!=0 && loun.b!=0)
{test++ ;}
}
if (test==50)
 return 0;
else if (test<50)
return 1 ;
}



int Verif_collision_objet5(SDL_Rect position_objet, SDL_Rect camera,SDL_Surface *test_map,SDL_Surface *noir)
{
    int i=0 , test =0 ;
_Couleur_ loun;
 for (i=0;i<50;i++)
{SDL_LockSurface(test_map);
loun=SDL_LireCouleur5(test_map,(position_objet.x+noir->w+camera.x+10),position_objet.y+(noir->h)-i);
SDL_UnlockSurface(test_map);
if (loun.r!=0 && loun.g!=0 && loun.b!=0)
{ test ++ ;}}

if ( test==50 )
return 0;

}






/* Lit la couleur en Uint32 (c'est peut être ce que tu veux)*/
Uint32 SDL_LireCouleurAux5(SDL_Surface* surface, int x, int y)
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


/* Lit la couleur dans mon format, utile pour faire des manipulations sur les couleurs*/
_Couleur_ SDL_LireCouleur5(SDL_Surface * surface, int x, int y)
{
 _Couleur_ couleur;

 SDL_GetRGB(SDL_LireCouleurAux(surface, x, y), surface->format,
                                      (Uint8*)   &couleur.r, (Uint8*) &couleur.g, (Uint8*) &couleur.b);
 return couleur;


}

//
