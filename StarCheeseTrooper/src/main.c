#include <stdio.h>

/*#define JEU_NCURSES */
#define JEU_SDL 

#ifdef JEU_NCURSES
#include "ncursJeu.h"
#endif

#ifdef JEU_SDL
#include "sdlJeu.h"
#endif


int main ( int argc, char** argv )
{


#ifdef JEU_SDL
	sdlJeu sj;
	sdljeuInit( &sj );
	sdlMenuJeu( &sj );
	if(sj.jeuON == 1)
		sdljeuBoucle(&sj);
	sdljeuLibere( &sj );
#endif

	printf("Fin\n");
	return 0;
}
