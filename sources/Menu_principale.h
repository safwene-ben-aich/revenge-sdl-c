#ifndef MENU_PRINCIPALE_H_INCLUDED
#define MENU_PRINCIPALE_H_INCLUDED
#include "Defs.h"
#include "Choix_map.h"
#include "Stage_1.h"
#include "stage_2.h"
#include "options.h"
#include "Win_stage_1.h"
void Nettoyer(SDL_Surface *Menu);
void menu_principale(SDL_Surface *ecran,int *stage_dispo, int *difficulter);
#endif // MENU_PRINCIPALE_H_INCLUDED
