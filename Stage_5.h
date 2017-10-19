#ifndef STAGE_1_H_INCLUDED
#define STAGE_1_H_INCLUDED
#include "Defs.h"
Uint32 SDL_LireCouleurAux(SDL_Surface* surface, int x, int y);

typedef struct _CouleurRGB_
{
 Uint8 r;
 Uint8 g; // Ici c'est une structure de r,g,b de type couleur
 Uint8 b;
} _Couleur_;
void main_stage_5(SDL_Surface *ecran, int stage, int *stage_dispo,int *difficulter);
_Couleur_ SDL_LireCouleur5(SDL_Surface * surface, int x, int y);
int Verif_collision_objet5(SDL_Rect position_objet, SDL_Rect camera,SDL_Surface *test_map,SDL_Surface *noir);
int Test_gravite(SDL_Rect position_objet, SDL_Rect camera,SDL_Surface *test_map, SDL_Surface *noir, int mouvement_haut);
int Verif_Collision_Surface5 (SDL_Rect position_objet, SDL_Rect camera, SDL_Surface *test_map, SDL_Surface *noir);
int up_to_Surface5 (SDL_Rect position_objet, SDL_Rect camera, SDL_Surface *test_map, SDL_Surface *noir,int max_pix ) ;
int down_to_Surface5 (SDL_Rect position_objet, SDL_Rect camera, SDL_Surface *test_map, SDL_Surface *noir,int max_pix ) ;
Uint32 SDL_LireCouleurAux5(SDL_Surface* surface, int x, int y);


#endif // STAGE_1_H_INCLUDED
