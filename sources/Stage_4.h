#ifndef STAGE_1_H_INCLUDED
#define STAGE_1_H_INCLUDED
#include "Defs.h"
Uint32 SDL_LireCouleurAux(SDL_Surface* surface, int x, int y);
typedef struct _CouleurRGB_
{ Uint8 r;
  Uint8 g; // Ici c'est une structure de r,g,b de type couleur
  Uint8 b;}
  _Couleur_;
void main_stage_4(SDL_Surface *ecran,int stage, int *stage_dispo, int *difficulter);
_Couleur_ SDL_LireCouleur(SDL_Surface * surface, int x, int y);
int Verif_collision_objet(SDL_Rect position_objet,SDL_Surface *test_map,SDL_Surface *noir);
int up_to_Surface4 (SDL_Rect position_objet,  SDL_Surface *test_map, SDL_Surface *noir,int max_pix ) ;
int down_to_Surface4 (SDL_Rect position_objet,  SDL_Surface *test_map, SDL_Surface *noir,int max_pix ) ;
void cloud_creation ( SDL_Rect *position_cloud ,SDL_Surface *cloud ,SDL_Surface *ecran , int *cpt , int X[20] , int Y[20] , int verif , int *position ,int ajout) ;
void affichage  ( SDL_Surface *ecran,SDL_Surface *effect, int x , int y,int transparance ,int i,SDL_Rect camera,int j );
#endif // STAGE_1_H_INCLUDED
