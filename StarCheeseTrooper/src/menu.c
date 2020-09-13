#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

SDL_Surface *SDL_load_image(const char* filename )
{
	/* Temporary storage for the image that's loaded */
	SDL_Surface* loadedImage = NULL;

	/* The optimized image that will be used */
	SDL_Surface* optimizedImage = NULL;

	/* Load the image */
	loadedImage = SDL_LoadBMP( filename );

	/* If nothing went wrong in loading the image */
	if ( loadedImage != NULL )
	{
		/* Create an optimized image */
		optimizedImage = SDL_DisplayFormat( loadedImage );

		/* Free the old image */
		SDL_FreeSurface( loadedImage );
	}

	/* Return the optimized image */
	return optimizedImage;
}

int main()
{

	SDL_Surface* screen;
	SDL_Surface* surface_menu;
	SDL_Surface* bouton_menu_1;
	SDL_Surface* bouton_menu_2;
	SDL_Surface* bouton_menu_3;
	
	SDL_Rect posBouton1;
	SDL_Rect posBouton2;
	SDL_Rect posBouton3;
	SDL_Rect posFond;

	SDL_Event event;
	SDL_Init( SDL_INIT_EVERYTHING );
	int i = 1;
	int continue_boucle0 = 1;
	int continue_boucle1 = 1;

	
	screen= SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	
	SDL_WM_SetCaption("menu", NULL);
	
	
	posFond.x = 0;
	posFond.y = 0;
	
	posBouton1.x = 300;
	posBouton1.y = 200;
	
	posBouton2.x = 300;
	posBouton2.y = 300;
	
	posBouton3.x = 300;
	posBouton3.y = 400;
	
	surface_menu = SDL_load_image("data/fond_menu.bmp");	
	bouton_menu_1 = NULL;
			bouton_menu_2 = NULL;
			bouton_menu_3 = NULL;	
while ( continue_boucle0 == 1 )
{


		switch(i)
		{
			case 1:
			SDL_FreeSurface(bouton_menu_1);
			SDL_FreeSurface(bouton_menu_2);
			SDL_FreeSurface(bouton_menu_3);
			
			bouton_menu_1 = SDL_load_image("../data/bouton_menu_1_selec.bmp");
			bouton_menu_2 = SDL_load_image("../data/bouton_menu_2.bmp");
			bouton_menu_3 = SDL_load_image("../data/bouton_menu_3.bmp");			
	
			SDL_BlitSurface(surface_menu, NULL, screen, &posFond);
			SDL_BlitSurface(bouton_menu_1, NULL, screen, &posBouton1);
			SDL_BlitSurface(bouton_menu_2, NULL,screen, &posBouton2);
			SDL_BlitSurface(bouton_menu_3, NULL, screen, &posBouton3);
			
			SDL_Flip(screen);
			
			break;
			
			case 2:
			SDL_FreeSurface(bouton_menu_1);
			SDL_FreeSurface(bouton_menu_2);
			SDL_FreeSurface(bouton_menu_3);
			
			bouton_menu_1 = SDL_load_image("../data/bouton_menu_1.bmp");
			bouton_menu_2 = SDL_load_image("../data/bouton_menu_2_selec.bmp");
			bouton_menu_3 = SDL_load_image("../data/bouton_menu_3.bmp");			
	
			SDL_BlitSurface(surface_menu, NULL, screen, &posFond);
			SDL_BlitSurface(bouton_menu_1, NULL, screen, &posBouton1);
			SDL_BlitSurface(bouton_menu_2, NULL,screen, &posBouton2);
			SDL_BlitSurface(bouton_menu_3, NULL, screen, &posBouton3);
			
			SDL_Flip(screen);
			break;
			
			case 3:
			SDL_FreeSurface(bouton_menu_1);
			SDL_FreeSurface(bouton_menu_2);
			SDL_FreeSurface(bouton_menu_3);
			
			
			bouton_menu_1 = SDL_load_image("data/bouton_menu_1.bmp");
			bouton_menu_2 = SDL_load_image("data/bouton_menu_2.bmp");
			bouton_menu_3 = SDL_load_image("data/bouton_menu_3_selec.bmp");			
	
			SDL_BlitSurface(surface_menu, NULL, screen, &posFond);
			SDL_BlitSurface(bouton_menu_1, NULL, screen, &posBouton1);
			SDL_BlitSurface(bouton_menu_2, NULL,screen, &posBouton2);
			SDL_BlitSurface(bouton_menu_3, NULL, screen, &posBouton3);
			
			SDL_Flip(screen);
			break;
			}
			continue_boucle1=1;
			while ( continue_boucle1 ==1 )
			{
				SDL_WaitEvent(&event);
				
				switch(event.type)
				{	
					case SDL_KEYDOWN:
						switch(event.key.keysym.sym)
						{
							
							case SDL_QUIT:
							continue_boucle0 = 0;
							break;
							
							case SDLK_UP:
							switch(i)
							{
								case 1:
								i = 3;
								break;
								
								case 2:
								i = 1;
								break;
								
								case 3:
								i = 2;
								break;
								
								default: 
								break;
							}
							break;
							
							case SDLK_DOWN:
							switch(i)
							{
								case 1:
								i = 2;
								break;
								
								case 2:
								i = 3;
								break;
								
								case 3:
								i = 1;
								break;
								
								default: 
								break;
							}
							break;
																	
							
							case SDLK_ESCAPE:
							continue_boucle0 = 0;
							break;
							
							case SDLK_RETURN:
							switch(i)
							{
								case 1:
								
								break;
								
								case 2:
								/* actions */
								break;
								
								case 3:
								continue_boucle0 = 0;
								break;
								
								default: 
								break;
							}
							break;
							
							default: 
							
							break;
						}
						break;
	
				}
			continue_boucle1=0;
			}

		}	
		
	
	
	SDL_FreeSurface(surface_menu);
	SDL_FreeSurface(bouton_menu_1);
	SDL_FreeSurface(bouton_menu_2);
	SDL_FreeSurface(bouton_menu_3);	
	SDL_Quit();
	return EXIT_SUCCESS;
	
	
}
