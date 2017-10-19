#include "Lire_options.h"

void Lire_options(){
SDL_Surface *ecran=NULL;
int stage_dispo=1 ;
FILE *fichier=NULL;
int options_tab[10];
int var;
int difficulter =3;
fichier=fopen("options","r");

if (fichier==NULL){
exit(1);
}

fscanf(fichier,"%d\n",&var);

switch (var){
case 1 :
ecran= SDL_SetVideoMode(1366,768,32,SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN );
break;

case 2 :
ecran= SDL_SetVideoMode(1366,768,32,SDL_SWSURFACE | SDL_DOUBLEBUF);
break;
case 3 :
ecran= SDL_SetVideoMode(800,600,32,SDL_SWSURFACE | SDL_DOUBLEBUF);
break;
case 4 :
ecran= SDL_SetVideoMode(640,400,32,SDL_SWSURFACE | SDL_DOUBLEBUF);
break;
}
menu_principale(ecran,&stage_dispo,&difficulter);
}
