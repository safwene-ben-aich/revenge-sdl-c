#include "Musique.h"
void Musique(int choix)
{
SDL_Init(SDL_INIT_EVERYTHING);
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
{
printf("%s", Mix_GetError());
}
Mix_Music *musique;
if (choix==0){
musique = Mix_LoadMUS("menu_sound.mp3");
Mix_PlayMusic(musique, -1);
}

if (choix==1){
musique= Mix_LoadMUS("Sound_Stage_1.mp3");
Mix_PlayMusic(musique, -1);
}
if (choix==2){
musique= Mix_LoadMUS("Sound_Stage_2.mp3");
Mix_PlayMusic(musique, -1);
}


}
