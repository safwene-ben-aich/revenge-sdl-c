#include "Musique.h"
void Musique(int choix)
{
SDL_Init(SDL_INIT_EVERYTHING);
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
{
printf("%s", Mix_GetError());
}

Mix_AllocateChannels(10);

Mix_Music *musique;

switch (choix)
{case 0:
    musique= Mix_LoadWAV("menu_principal_sound.wav");
Mix_VolumeChunk(musique,MIX_MAX_VOLUME/2);
Mix_PlayChannel(1,musique,-1);
break ;
case 1 :
musique= Mix_LoadWAV("Sound_Stage1.wav");
Mix_VolumeChunk(musique,MIX_MAX_VOLUME/2);
Mix_PlayChannel(1,musique,-1);
break ;
case 2 :
musique= Mix_LoadWAV("Sound_Stage2.wav");
Mix_VolumeChunk(musique,MIX_MAX_VOLUME/2);
Mix_PlayChannel(1,musique,-1);
break ;
case 3 :
musique= Mix_LoadWAV("Sound_Stage3.wav");
Mix_VolumeChunk(musique,MIX_MAX_VOLUME/2);
Mix_PlayChannel(1,musique,-1);
break ;
case 4 :
musique= Mix_LoadWAV("Sound_Stage4.wav");
Mix_VolumeChunk(musique,MIX_MAX_VOLUME/2);
Mix_PlayChannel(1,musique,-1);
break ;
case 5 :
musique= Mix_LoadWAV("Sound_Stage5.wav");
Mix_VolumeChunk(musique,MIX_MAX_VOLUME/2);
Mix_PlayChannel(1,musique,1);
break ;
case 6 :
//musique= Mix_LoadWAV("Running_Sound.wav");
Mix_VolumeChunk(musique,MIX_MAX_VOLUME/2);
Mix_PlayChannel(2,musique,1);
break ;
case 7 :
musique= Mix_LoadWAV("Sound_Stage5.wav");
Mix_VolumeChunk(musique,MIX_MAX_VOLUME/2);
Mix_PlayChannel(2,musique,1);
break ;
}

}
