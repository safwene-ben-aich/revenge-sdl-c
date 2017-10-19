#ifndef STAGE_1_H_INCLUDED
#define STAGE_1_H_INCLUDED
#include "Defs.h"
//extern Uint32 SDL_LireCouleurAux(SDL_Surface* surface, int x, int y);

typedef struct _CouleurRGB_
{
 Uint8 r;
 Uint8 g; // Ici c'est une structure de r,g,b de type couleur
 Uint8 b;
} _Couleur_;
extern _Couleur_ SDL_LireCouleur(SDL_Surface * surface, int x, int y);
void main_stage_3(SDL_Surface *ecran,int stage, int *stage_dispo, int *difficulter);
#endif // STAGE_1_H_INCLUDED
