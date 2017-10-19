#include "Menu_principale.h"
void menu_principale(SDL_Surface *ecran,int *stage_dispo ,int *difficulter)
{
SDL_Surface *Menu=NULL,*rec=NULL,*image=NULL;
SDL_Rect position_base,camera,position_rec;
position_base.x=200;
position_base.y=500;
position_rec.x=1000;
position_rec.y=1000;
SDL_Event event;
FILE * fichier =NULL ;
int continuer=1,i=1;

	if ( ecran== NULL )
	{
	    fprintf(stderr,"Erreur lors de l'ouverture de la fenetre\n");
	    SDL_Quit();
        return -2;
	}
Musique(0);

/*
rec=SDL_LoadBMP("new_game.bmp");
Musique();
for (i=0;i<=47;i++){
position_rec.y-=20;
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL_BlitSurface(rec,NULL,ecran,&position_rec);
SDL_Flip(ecran);
SDL_Delay(5);
}
SDL_FreeSurface(image);
image=SDL_LoadBMP("new_game_image.bmp");
SDL_FreeSurface(rec);
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
SDL_FreeSurface(image);
image=SDL_LoadBMP("new_game_image_2.bmp");
SDL_FreeSurface(rec);
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
SDL_FreeSurface(image);
image=SDL_LoadBMP("new_game_image_3.bmp");
SDL_FreeSurface(rec);
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
SDL_FreeSurface(image);
image=SDL_LoadBMP("new_game_image_4.bmp");
SDL_FreeSurface(rec);
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
SDL_FreeSurface(image);
image=SDL_LoadBMP("new_game_image_5.bmp");


SDL_BlitSurface(image,NULL,ecran,NULL);
SDL_Flip(ecran);
SDL_Delay(200);

SDL_FreeSurface(rec);
rec=SDL_LoadBMP("next.bmp");
position_rec.x=222;
position_rec.y=692;
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL_BlitSurface(image,NULL,ecran,NULL);
SDL_BlitSurface(rec,NULL,ecran,&position_rec);
SDL_Flip(ecran);
SDL_Delay(200);
SDL_FreeSurface(image);
image=SDL_LoadBMP("new_game_image_6.bmp");
rec=SDL_LoadBMP("title.bmp");
position_rec.x=9;
position_rec.y=15;
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL_BlitSurface(image,NULL,ecran,NULL);
SDL_BlitSurface(rec,NULL,ecran,&position_rec);
SDL_Flip(ecran);
SDL_Delay(200);

//Nettoyage de l'animation en utilisant les Free_surface
SDL_FreeSurface(image);
SDL_FreeSurface(rec);
*/


i=1;
SDL_EnableKeyRepeat(100, 100);
while (continuer)
{
SDL_WaitEvent(&event);
switch (i){
case 1 : Menu=SDL_LoadBMP("Menu1.bmp");break;
case 2 : Menu=SDL_LoadBMP("Menu2.bmp");break;
case 3 : Menu=SDL_LoadBMP("Menu3.bmp");break;
case 4 : Menu=SDL_LoadBMP("Menu4.bmp");break;
case 5 : Menu=SDL_LoadBMP("Menu5.bmp");break;
}
switch (event.type){
case SDL_QUIT : continuer =0;break;
case SDL_KEYDOWN :

switch (event.key.keysym.sym){

case SDLK_ESCAPE : continuer=0;break;
case SDLK_UP :
i--;
if (i<1){
i=5;
    }
break;
case SDLK_DOWN :
i++;
if (i>5){
i=1;
}
break;
case SDLK_RETURN :
switch (i){
case 1 : Nettoyer(Menu);choix_stage(ecran,stage_dispo,difficulter);break;
case 2 :
    fichier=fopen ("save.txt","r");
    fscanf(fichier,"%d",stage_dispo) ;
    fclose(fichier) ;
    break ;
case 3 : Nettoyer(Menu);choix_options(ecran,stage_dispo,difficulter);break;
case 5 : exit(1);
}
break;



}
break;
}


SDL_BlitSurface(Menu,NULL,ecran,NULL);
SDL_Flip(ecran);
SDL_FreeSurface(Menu);
}




    SDL_Quit();


}
void Nettoyer(SDL_Surface *Menu){
SDL_FreeSurface(Menu);
}




















