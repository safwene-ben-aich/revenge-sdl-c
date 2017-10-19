#include "options.h"
void choix_options(SDL_Surface *ecran){
int continuer=1,i_video=1,i_audio=1,i_menu=1,i_langage=1,i_difficulty=1,verif_video,verif_audio,verif_langage,verif_difficulty;
SDL_Event event;
SDL_Surface *choix_options=NULL;

FILE *fichier=NULL;
fichier=fopen("options","r");
fscanf(fichier,"%d\n%d\n%d\n%d\n",&verif_video,&verif_audio,&verif_langage,&verif_difficulty);

const SDL_VideoInfo* myPointer = SDL_GetVideoInfo();
while (continuer)
{
SDL_WaitEvent(&event);
switch(i_menu){
case 1 :
switch (i_video){
case 1 : choix_options=SDL_LoadBMP("option_full_screen.bmp");break;
case 2 : choix_options=SDL_LoadBMP("option_1366.bmp");break;
case 3 : choix_options=SDL_LoadBMP("option_800.bmp");break;
case 4 : choix_options=SDL_LoadBMP("option_640.bmp");break;
}
break;
case 2 :
switch (i_audio){
case 1 : choix_options=SDL_LoadBMP("option_audio_1.bmp");break;
case 2 : choix_options=SDL_LoadBMP("option_audio_2.bmp");break;
case 3 : choix_options=SDL_LoadBMP("option_audio_3.bmp");break;
case 4 : choix_options=SDL_LoadBMP("option_audio_4.bmp");break;


}
break;
case 3 :
switch (i_langage){
case 1 :choix_options=SDL_LoadBMP("option_langage_1.bmp");break;
case 2 :choix_options=SDL_LoadBMP("option_langage_2.bmp");break;

}
break;
case 4 :
switch (i_difficulty){
case 1 : choix_options=SDL_LoadBMP("option_difficulty_1.bmp");break;
case 2 : choix_options=SDL_LoadBMP("option_difficulty_2.bmp");break;
case 3 : choix_options=SDL_LoadBMP("option_difficulty_3.bmp");break;

}
break;

}

switch (event.type){
case SDL_QUIT : continuer =0 ;break;
case SDL_KEYDOWN :

    switch (event.key.keysym.sym){

case SDLK_ESCAPE : continuer=0;break;
case SDLK_BACKSPACE :
 continuer =0 ;
 /*
fichier=fopen("options","w");
fprintf(fichier,"%d\n%d\n%d\n%d\n",verif_video,verif_audio,verif_langage,verif_difficulty);
fclose(fichier);
Lire_options();
*/
break;


case SDLK_UP :
switch (i_menu){
case 1 : i_video--;
if (i_video<1){
i_video=4;
}
break;
case 2 :
i_audio--;
if (i_audio<1){
i_audio=4;
}
break;
case 3 : i_langage--;
if (i_langage<1){
i_langage=2;
}
break;
case 4 : i_difficulty--;
if (i_difficulty<1){
i_difficulty=3;
}
break;
}
break;
case SDLK_DOWN :

switch (i_menu){
case 1 : i_video++;
if (i_video>4){
i_video=1;
}
break;
case 2 :
i_audio++;
if (i_audio>4){
i_audio=1;
}
break;
case 3 : i_langage++;
if (i_langage>2){
i_langage=1;
}
break;
case 4 : i_difficulty++;
if (i_difficulty>3){
i_difficulty=1;
}
break;
}
break;
case SDLK_RIGHT :
i_menu--;
if (i_menu<1){
i_menu=4;
}
break;

case SDLK_LEFT :
i_menu++;
if (i_menu>4){
i_menu=1;
}
break;
case SDLK_RETURN :

switch (i_menu){
case 1 :
switch (i_video){
case 1 :
SDL_SetVideoMode(myPointer->current_w, myPointer->current_h, myPointer->vfmt->BitsPerPixel, SDL_DOUBLEBUF|SDL_FULLSCREEN);
verif_video=1;
break;
case 2 :
ecran= SDL_SetVideoMode(1366,768,32,SDL_SWSURFACE | SDL_DOUBLEBUF );
verif_video=2;
break;
case 3 :
ecran= SDL_SetVideoMode(800,600,32,SDL_SWSURFACE | SDL_DOUBLEBUF );
verif_video=3;
case 4 :
ecran= SDL_SetVideoMode(640,400,32,SDL_SWSURFACE | SDL_DOUBLEBUF );
verif_video=4;
break;
}
case 2 :
switch (i_audio){
case 1 :
// Audio muet
verif_audio=1;
break;
case 2 :
// audio normal
verif_audio=2;
break;
case 3 :
// audio moyen
verif_audio=3;
break;
case 4 :
// audio max
verif_audio=4;
break;
}
break;
case 3 :
switch (i_langage){
case 1 :
// charger les images en anglais
verif_langage=1;
break;
case 2 :
// charger les images en français
verif_langage=2;
break;
}
break;
case 4 :
switch (i_difficulty){
case 1 :
// L'IA normal
verif_difficulty=1;
break;
case 2 :
// L'IA moyenne
verif_difficulty=2;
break;
case 3 :
// L'IA difficile
verif_difficulty=3;
break;
}
break;
}

break;

}
break;
}


SDL_BlitSurface(choix_options,NULL,ecran,NULL);
SDL_Flip(ecran);
SDL_FreeSurface(choix_options);
}

}
