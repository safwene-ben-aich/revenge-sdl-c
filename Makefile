prog:main.o Choix_map.o Lire_options.o Menu_principale.o Musique.o options.o Pause.o Stage_1.o stage_2.o
		gcc main.o Choix_map.o Lire_options.o Menu_principale.o Musique.o options.o Pause.o Stage_1.o stage_2.o -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -g
Choix_map.o:Choix_map.c
	gcc -c Choix_map.c -g
Lire_options.o:Lire_options.c
	gcc -c Lire_options.c -g
Menu_principale.o:Menu_principale.c
	gcc -c Menu_principale.c -g
Musique.o:Musique.c
	gcc -c Musique.c -g
options.o:options.c
	gcc -c options.c -g
Pause.o:Pause.c
	gcc -c Pause.c -g
Stage_1.o:Stage_1.c
	gcc -c Stage_1.c -g
stage_2.o:stage_2.c
	gcc -c stage_2.c -g
clean:
	rm -fr *.o
mrproper:clean
	rm -f prog
