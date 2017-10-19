#include "Menu_principale.h"
void menu_principale(SDL_Surface *ecran)
{
SDL_Surface *Menu=NULL,*rec=NULL,*image=NULL;
SDL_Rect position_base,camera,position_rec;
FILE *fichier=NULL;
position_base.x=200;
position_base.y=500;
position_rec.x=1000;
position_rec.y=1000;
SDL_Event event;
int continuer=1,i=1;
//ecran= SDL_SetVideoMode(1366,768,32,SDL_SWSURFACE | SDL_DOUBLEBUF );

	rec=SDL_LoadBMP("new_game.bmp");
	Musique(0);

/*
Musique(1);
for (i=0;i<=47;i++){
position_rec.y-=20;
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL_BlitSurface(rec,NULL,ecran,&position_rec);
SDL_Flip(ecran);
SDL_Delay(5);
}
image=SDL_LoadBMP("new_game_image.bmp");
rec=SDL_LoadBMP("load_game.bmp");
position_rec.y=210;
position_rec.x=100;
//SDL_Delay(1000);
for (i=0;i<=48;i++){
position_rec.x+=20;
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL_BlitSurface(image,NULL,ecran,NULL);
SDL_BlitSurface(rec,NULL,ecran,&position_rec);
SDL_Flip(ecran);
SDL_Delay(5);
}
position_rec.y=320;
position_rec.x=1120;
image=SDL_LoadBMP("new_game_image_2.bmp");
rec=SDL_LoadBMP("option.bmp");
//SDL_Delay(1000);
for (i=0;i<=27;i++){
position_rec.x-=5;
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL_BlitSurface(image,NULL,ecran,NULL);
SDL_BlitSurface(rec,NULL,ecran,&position_rec);
SDL_Flip(ecran);
SDL_Delay(5);
}
image=SDL_LoadBMP("new_game_image_3.bmp");
rec=SDL_LoadBMP("help.bmp");
position_rec.y=430;
position_rec.x=100;
for (i=0;i<=47;i++){
position_rec.x+=20;
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL_BlitSurface(image,NULL,ecran,NULL);
SDL_BlitSurface(rec,NULL,ecran,&position_rec);
SDL_Flip(ecran);
SDL_Delay(5);
}
image=SDL_LoadBMP("new_game_image_4.bmp");
rec=SDL_LoadBMP("exit.bmp");
position_rec.x=1000;
position_rec.y=700;
for (i=0;i<=14;i++){
position_rec.y-=10;
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL_BlitSurface(image,NULL,ecran,NULL);
SDL_BlitSurface(rec,NULL,ecran,&position_rec);
SDL_Flip(ecran);
SDL_Delay(5);
}
image=SDL_LoadBMP("new_game_image_5.bmp");


SDL_BlitSurface(image,NULL,ecran,NULL);
SDL_Flip(ecran);
SDL_Delay(200);


rec=SDL_LoadBMP("next.bmp");
position_rec.x=222;
position_rec.y=692;
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL_BlitSurface(image,NULL,ecran,NULL);
SDL_BlitSurface(rec,NULL,ecran,&position_rec);
SDL_Flip(ecran);
SDL_Delay(200);
image=SDL_LoadBMP("new_game_image_6.bmp");
rec=SDL_LoadBMP("title.bmp");
position_rec.x=9;
position_rec.y=15;
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL_BlitSurface(image,NULL,ecran,NULL);
SDL_BlitSurface(rec,NULL,ecran,&position_rec);
SDL_Flip(ecran);
SDL_Delay(200);
*/


do
{

SDL_WaitEvent(&event);

switch (event.type){
case SDL_QUIT : continuer =0;break;
case SDL_KEYUP :

    switch (event.key.keysym.sym){
case SDLK_UP :
i-- ;
if (i<1)
{
i=5;
}
break;
case SDLK_DOWN :
i++;
if (i>5){
i=1;
}
break ;
    }

    break ;
case SDL_KEYDOWN :

    switch (event.key.keysym.sym)

{


case SDLK_RETURN :
switch (i){
case 1 : Nettoyer(Menu);choix_stage(ecran);
Musique(0) ;
break;
case 3 : Nettoyer(Menu);choix_options(ecran);break;
case 5 : Nettoyer(Menu);exit(1);break;
}
break ;
case SDLK_ESCAPE : exit(1);break;

}
break;




}


switch (i){
case 1 : Menu=SDL_LoadBMP("Menu1.bmp");break;
case 2 : Menu=SDL_LoadBMP("Menu2.bmp");break;
case 3 : Menu=SDL_LoadBMP("Menu3.bmp");break;
case 4 : Menu=SDL_LoadBMP("Menu4.bmp");break;
case 5 : Menu=SDL_LoadBMP("Menu5.bmp");break;
}


SDL_BlitSurface(Menu,NULL,ecran,NULL);
SDL_Flip(ecran);

}
while(continuer!=0) ;

SDL_FreeSurface(Menu);



    SDL_Quit();


}

void Nettoyer(SDL_Surface *Menu){
SDL_FreeSurface(Menu);
}




















