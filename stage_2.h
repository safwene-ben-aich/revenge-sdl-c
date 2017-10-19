#ifndef SATGE_2_H_INCLUDED
#define SATGE_2_H_INCLUDED
#include "Defs.h"
#include "Stage_1.h"
Uint32 SDL_LireCouleurAux2(SDL_Surface* surface, int x, int y);
void main_stage_2(SDL_Surface *ecran,SDL_Rect position_objet_pause, SDL_Rect camera_pause, int stage);
_Couleur_ SDL_LireCouleur2(SDL_Surface * surface, int x, int y);
int Verif_collision_objet2(SDL_Rect position_objet, SDL_Rect camera,SDL_Surface *test_map,SDL_Surface *noir);
int Test_gravite2(SDL_Rect position_objet, SDL_Rect camera,SDL_Surface *test_map, SDL_Surface *noir, int mouvement_haut);
int Verif_Collision_Surface2 (SDL_Rect position_objet, SDL_Rect camera, SDL_Surface *test_map, SDL_Surface *noir);
int up_to_Surface2 (SDL_Rect position_objet, SDL_Rect camera, SDL_Surface *test_map, SDL_Surface *noir,int max_pix ) ;
int down_to_Surface2 (SDL_Rect position_objet, SDL_Rect camera, SDL_Surface *test_map, SDL_Surface *noir,int max_pix ) ;

#endif // SATGE_2_H_INCLUDED
