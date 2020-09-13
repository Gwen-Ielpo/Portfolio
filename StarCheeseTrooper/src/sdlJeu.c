
#include <assert.h>
#include <time.h>
#include "sdlJeu.h"
#define HAUT	0
#define DROITE	1
#define BAS	2
#define GAUCHE	3

#define AUCUNE_DIRECTION	4
#define DIRECTION_HAUT		5
#define DIRECTION_DROITE	6
#define DIRECTION_BAS		7
#define DIRECTION_GAUCHE	8
#define DIRECTION_DIAG_DB   	9
#define DIRECTION_DIAG_DH 	10
#define DIRECTION_DIAG_GB 	11
#define DIRECTION_DIAG_GH 	12
#define ORIENTATION_DROITE	13
#define ORIENTATION_HAUT	14
#define ORIENTATION_BAS		15
#define ORIENTATION_GAUCHE	16

const int TAILLE_SPRITE=32;

SDL_Surface *SDL_load_image(const char* filename );
void SDL_apply_surface( SDL_Surface* source, SDL_Surface* destination, int x, int y );

void sdljeuInit(sdlJeu *pSdlJeu)
{
	Jeu *pJeu;
	int dimx, dimy;
	pSdlJeu->jeuON = 0;
	pJeu = &(pSdlJeu->jeu);
	jeuInit(pJeu);

		
	
	assert(   SDL_Init( SDL_INIT_EVERYTHING )!= -1 );

	dimx = getDimX( jeuGetConstTerrainPtr(pJeu) );
	dimy = getDimY( jeuGetConstTerrainPtr(pJeu) );
	dimx = dimx * TAILLE_SPRITE;
	dimy = dimy * TAILLE_SPRITE;
	pSdlJeu->surface_ecran = SDL_SetVideoMode(1532, 860, 32, SDL_HWSURFACE | SDL_DOUBLEBUF /*| SDL_FULLSCREEN*/);
	assert( pSdlJeu->surface_ecran!=NULL);
	SDL_WM_SetCaption( "Starcheese Trooper v0.1", NULL );
 Mix_Volume(1, MIX_MAX_VOLUME/4);
	 if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   {
      printf("%s", Mix_GetError());
   }
Mix_VolumeMusic(60);
	
	pSdlJeu->posFond.x = 250;
	pSdlJeu->posFond.y = 0;
	
	pSdlJeu->Fond.x = 0;
	pSdlJeu->Fond.y = 100;
	

	pSdlJeu->posBouton1.x = 350;
	pSdlJeu->posBouton1.y = 300;
	
	pSdlJeu->posBouton2.x = 350;
	pSdlJeu->posBouton2.y = 450;
	
	pSdlJeu->posBouton3.x = 350;
	pSdlJeu->posBouton3.y = 600;
	
	
	
	

	
	pSdlJeu->surface_fromage_gauche = SDL_load_image("data/fromage_gauche.bmp");
	if (pSdlJeu->surface_fromage_gauche==NULL)
		pSdlJeu->surface_fromage_gauche = SDL_load_image("../data/fromage_gauche.bmp");
	assert( pSdlJeu->surface_fromage_gauche!=NULL);

		pSdlJeu->surface_fromage_gauche1 = SDL_load_image("data/surface_fromage_gauche1.bmp");
	if (pSdlJeu->surface_fromage_gauche1==NULL)
		pSdlJeu->surface_fromage_gauche1 = SDL_load_image("../data/surface_fromage_gauche1.bmp");
	assert( pSdlJeu->surface_fromage_gauche1!=NULL);

		pSdlJeu->surface_fromage_droite1 = SDL_load_image("data/surface_fromage_droite1.bmp");
	if (pSdlJeu->surface_fromage_droite1==NULL)
		pSdlJeu->surface_fromage_droite1 = SDL_load_image("../data/surface_fromage_droite1.bmp");
	assert( pSdlJeu->surface_fromage_droite1!=NULL);


	pSdlJeu->fond_sombre = SDL_load_image("data/fond_sombre.bmp");
	if (pSdlJeu->fond_sombre==NULL)
		pSdlJeu->fond_sombre = SDL_load_image("../data/fond_sombre.bmp");
	assert( pSdlJeu->fond_sombre!=NULL);


	pSdlJeu->projo_gauche = SDL_load_image("data/laser_gauche.bmp");
	if (pSdlJeu->projo_gauche==NULL)
		pSdlJeu->projo_gauche = SDL_load_image("../data/laser_gauche.bmp");
	assert( pSdlJeu->projo_gauche!=NULL);

	pSdlJeu->projo_droite = SDL_load_image("data/laser_droite.bmp");
	if (pSdlJeu->projo_droite==NULL)
		pSdlJeu->projo_droite = SDL_load_image("../data/laser_droite.bmp");
	assert( pSdlJeu->projo_droite!=NULL);
	

	pSdlJeu->projo_haut = SDL_load_image("data/laser_haut.bmp");
	if (pSdlJeu->projo_haut==NULL)
		pSdlJeu->projo_haut = SDL_load_image("../data/laser_haut.bmp");
	assert( pSdlJeu->projo_haut!=NULL);

	pSdlJeu->projo_bas = SDL_load_image("data/laser_bas.bmp");
	if (pSdlJeu->projo_bas==NULL)
		pSdlJeu->projo_bas = SDL_load_image("../data/laser_bas.bmp");
	assert( pSdlJeu->projo_bas!=NULL);
/*****/
	pSdlJeu->projo_blue_gauche = SDL_load_image("data/blue_laser_gauche.bmp");

	if (pSdlJeu->projo_blue_gauche==NULL)
		pSdlJeu->projo_blue_gauche = SDL_load_image("../data/blue_laser_gauche.bmp");
	assert( pSdlJeu->projo_blue_gauche!=NULL);

	pSdlJeu->projo_blue_droite = SDL_load_image("data/blue_laser_droite.bmp");
	if (pSdlJeu->projo_blue_droite==NULL)

		pSdlJeu->projo_blue_droite = SDL_load_image("../data/blue_laser_droite.bmp");
	assert( pSdlJeu->projo_blue_droite!=NULL);
	

	pSdlJeu->projo_blue_haut = SDL_load_image("data/blue_laser_haut.bmp");
	if (pSdlJeu->projo_blue_haut==NULL)
		pSdlJeu->projo_blue_haut = SDL_load_image("../data/blue_laser_haut.bmp");
	assert( pSdlJeu->projo_blue_haut!=NULL);

	pSdlJeu->projo_blue_bas = SDL_load_image("data/blue_laser_bas.bmp");
	if (pSdlJeu->projo_blue_bas==NULL)
		pSdlJeu->projo_blue_bas = SDL_load_image("../data/blue_laser_bas.bmp");
	assert( pSdlJeu->projo_blue_bas!=NULL);
/****/


	pSdlJeu->fond_base = SDL_load_image("data/fond_base.bmp");
	if (pSdlJeu->fond_base==NULL)
		pSdlJeu->fond_base = SDL_load_image("../data/fond_base.bmp");
	assert( pSdlJeu->fond_base!=NULL);

	pSdlJeu->surface_mur = SDL_load_image("data/mur.bmp");
	if (pSdlJeu->surface_mur==NULL)
		pSdlJeu->surface_mur = SDL_load_image("../data/mur.bmp");
	assert( pSdlJeu->surface_mur!=NULL);

	pSdlJeu->surface_porte = SDL_load_image("data/porte.bmp");
	if (pSdlJeu->surface_porte==NULL)
		pSdlJeu->surface_porte = SDL_load_image("../data/porte.bmp");
	assert( pSdlJeu->surface_porte!=NULL);

	pSdlJeu->surface_fantome = SDL_load_image("data/fantome.bmp");
	if (pSdlJeu->surface_fantome==NULL)
		pSdlJeu->surface_fantome = SDL_load_image("../data/fantome.bmp");
	assert( pSdlJeu->surface_fantome!=NULL);
	
	pSdlJeu->surface_hp = SDL_load_image("data/hp.bmp");
	if (pSdlJeu->surface_hp==NULL)
		pSdlJeu->surface_hp = SDL_load_image("../hp.bmp");
	assert( pSdlJeu->surface_hp!=NULL);

	pSdlJeu->surface_clef = SDL_load_image("data/clef.bmp");
	if (pSdlJeu->surface_clef==NULL)
		pSdlJeu->surface_clef = SDL_load_image("../clef.bmp");
	assert( pSdlJeu->surface_clef!=NULL);

	pSdlJeu->fenetre = SDL_load_image("data/fenetre.bmp");
	if (pSdlJeu->fenetre==NULL)
		pSdlJeu->fenetre = SDL_load_image("../fenetre.bmp");
	assert( pSdlJeu->fenetre!=NULL);
	
		pSdlJeu->lumiere = SDL_load_image("data/lumiere.bmp");
	if (pSdlJeu->lumiere==NULL)
		pSdlJeu->lumiere = SDL_load_image("../lumiere.bmp");
	assert( pSdlJeu->lumiere!=NULL);

		pSdlJeu->gandalf = SDL_load_image("data/gandalf.bmp");
	if (pSdlJeu->gandalf==NULL)
		pSdlJeu->gandalf = SDL_load_image("../gandalf.bmp");
	assert( pSdlJeu->gandalf!=NULL);

		pSdlJeu->pic = SDL_load_image("data/pic.bmp");
	if (pSdlJeu->pic==NULL)
		pSdlJeu->pic = SDL_load_image("../pic.bmp");
	assert( pSdlJeu->pic!=NULL);
/****/
		pSdlJeu->surface_fromage_mort_droite = SDL_load_image("data/surface_fromage_mort_droite.bmp");
	if (pSdlJeu->surface_fromage_mort_droite==NULL)
		pSdlJeu->surface_fromage_mort_droite = SDL_load_image("../surface_fromage_mort_droite.bmp");
	assert( pSdlJeu->surface_fromage_mort_droite!=NULL);

		pSdlJeu->surface_fromage_mort_gauche = SDL_load_image("data/surface_fromage_mort_gauche.bmp");
	if (pSdlJeu->surface_fromage_mort_gauche==NULL)
		pSdlJeu->surface_fromage_mort_gauche = SDL_load_image("../surface_fromage_mort_gauche.bmp");
	assert( pSdlJeu->surface_fromage_mort_gauche!=NULL);
/****/

		pSdlJeu->main_theme = Mix_LoadMUS("data/musique/main_theme.mp3");
		pSdlJeu->menu_theme = Mix_LoadMUS("data/musique/musique_menu.mp3");
		assert( pSdlJeu->main_theme!=NULL);
		Mix_AllocateChannels(15); 

		pSdlJeu->laser1 = Mix_LoadWAV("data/musique/laser_1.wav");
		pSdlJeu->son_mort = Mix_LoadWAV("data/musique/son_mort.wav");
		pSdlJeu->bip_menu = Mix_LoadWAV("data/musique/bip_menu.wav");
}		


void sdljeuAff(sdlJeu *pSdlJeu)
{
	pSdlJeu->jeu.ter.tab[6][6]='F';
	int x,y,i_fant;
        const Jeu *pJeu = &(pSdlJeu->jeu);
	const Terrain *pTer = jeuGetConstTerrainPtr(pJeu);
	const Fromage *pFrom = jeuGetConstFromagePtr(pJeu);
	SDL_SetColorKey( pSdlJeu->projo_droite, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->projo_droite->format, 255, 174, 201 ) );
	SDL_SetColorKey( pSdlJeu->projo_gauche, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->projo_gauche->format, 255, 174, 201 ) );
	SDL_SetColorKey( pSdlJeu->gandalf, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->gandalf->format, 255, 174, 201 ) );
	SDL_SetColorKey( pSdlJeu->projo_haut, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->projo_haut->format, 255, 174, 201 ) );
	SDL_SetColorKey( pSdlJeu->projo_bas, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->projo_bas->format, 255, 174, 201 ) );
	SDL_SetColorKey( pSdlJeu->projo_blue_droite, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->projo_blue_droite->format, 255,255,255 ) );
	SDL_SetColorKey( pSdlJeu->projo_blue_gauche, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->projo_blue_gauche->format, 255,255,255 ) );
	SDL_SetColorKey( pSdlJeu->projo_blue_haut, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->projo_blue_haut->format, 255,255,255 ) );
	SDL_SetColorKey( pSdlJeu->projo_blue_bas, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->projo_blue_bas->format, 255,255,255 ) );
	SDL_SetColorKey( pSdlJeu->surface_fromage_gauche, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->surface_fromage_gauche->format, 255, 255, 255 ) );
	SDL_SetColorKey( pSdlJeu->surface_fantome, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->surface_fantome->format, 255, 255, 255 ) );
	SDL_SetColorKey( pSdlJeu->surface_fromage_gauche1, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->surface_fromage_gauche1->format, 255, 255, 255 ) );
	SDL_SetColorKey( pSdlJeu->surface_fromage_mort_droite, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->surface_fromage_mort_droite->format, 255, 255, 255 ) );
	SDL_SetColorKey( pSdlJeu->surface_fromage_mort_gauche, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->surface_fromage_mort_gauche->format,255, 255, 255 ) );
SDL_SetColorKey( pSdlJeu->surface_fromage_droite1, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->surface_fromage_droite1->format, 255,255,255 ) );
SDL_SetColorKey( pSdlJeu->surface_clef, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->surface_clef->format, 255,255,255 ) );
SDL_SetColorKey( pSdlJeu->pic, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->pic->format, 255,255,255 ) );
SDL_SetColorKey( pSdlJeu->surface_hp, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->surface_hp->format, 0,0,0 ) );
	
	for (x=0;x<getDimX(pTer);++x)
  for (y=0;y<getDimY(pTer);++y)
   {if (terGetXY(pTer,x,y)=='1')
    SDL_apply_surface(  pSdlJeu->surface_mur, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);
   if (terGetXY(pTer,x,y)=='0')
    SDL_apply_surface(  pSdlJeu->fond_sombre, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);
   if (terGetXY(pTer,x,y)=='F')
    SDL_apply_surface(  pSdlJeu->fenetre, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);
   if (terGetXY(pTer,x,y)=='L')
    SDL_apply_surface(  pSdlJeu->lumiere, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);
   if (terGetXY(pTer,x,y)=='P')
   { 
	SDL_apply_surface(  pSdlJeu->fond_sombre, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);
SDL_apply_surface(  pSdlJeu->pic, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);
	}
   if (terGetXY(pTer,x,y)=='5'||terGetXY(pTer,x,y)=='M'||terGetXY(pTer,x,y)=='5'||terGetXY(pTer,x,y)=='C')
    SDL_apply_surface(  pSdlJeu->fond_base, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);
    if (terGetXY(pTer,x,y)=='d'||terGetXY(pTer,x,y)=='g'||terGetXY(pTer,x,y)=='b'||terGetXY(pTer,x,y)=='h')
    SDL_apply_surface(  pSdlJeu->surface_porte, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);
    }
    for (i_fant=0; i_fant<pJeu->ter.salle_Perso->nb_fantome; i_fant++)
	if(pSdlJeu->jeu.ter.salle_Perso->fant[i_fant].mort==0)
        SDL_apply_surface(pSdlJeu->surface_fantome, pSdlJeu->surface_ecran, (pJeu->ter.salle_Perso->fant[i_fant].x)*TAILLE_SPRITE, (pJeu->ter.salle_Perso->fant[i_fant].y)*TAILLE_SPRITE);

for (i_fant=0; i_fant<pJeu->ter.salle_Perso->nb_fantome; i_fant++)
	if(pSdlJeu->jeu.ter.salle_Perso->fant[i_fant].mort==1){
		Mix_PlayChannel(2, pSdlJeu->son_mort, 0);
		pSdlJeu->jeu.ter.salle_Perso->fant[i_fant].mort++;}
 for (x=0;x<fromGethp(pFrom);++x)
  SDL_apply_surface(  pSdlJeu->surface_hp, pSdlJeu->surface_ecran, (x+35)*TAILLE_SPRITE,0);

if(pSdlJeu->jeu.ter.tab[0][0]=='9')
	{
	SDL_apply_surface(  pSdlJeu->gandalf, pSdlJeu->surface_ecran, 45*TAILLE_SPRITE,13*TAILLE_SPRITE);
	if(fromGetX(pFrom)==43&&fromGetY(pFrom)==11)
		sdlMenuFin(pSdlJeu);
	if(fromGetX(pFrom)==43&&fromGetY(pFrom)==12)
		sdlMenuFin(pSdlJeu);
	if(fromGetX(pFrom)==43&&fromGetY(pFrom)==13)
		sdlMenuFin(pSdlJeu);
		
	}

switch(pSdlJeu->jeu.from.orientation)
	{case DROITE:
		if(fromGethp(pFrom)<=0)
				SDL_apply_surface(  pSdlJeu->surface_fromage_mort_droite, pSdlJeu->surface_ecran, fromGetX(pFrom)*TAILLE_SPRITE,  fromGetY(pFrom)*TAILLE_SPRITE );
		else
				SDL_apply_surface(  pSdlJeu->surface_fromage_droite1, pSdlJeu->surface_ecran, fromGetX(pFrom)*TAILLE_SPRITE,  fromGetY(pFrom)*TAILLE_SPRITE );
			break;
			
	case GAUCHE:
		if(fromGethp(pFrom)<=0)
				SDL_apply_surface(  pSdlJeu->surface_fromage_mort_gauche, pSdlJeu->surface_ecran, fromGetX(pFrom)*TAILLE_SPRITE,  fromGetY(pFrom)*TAILLE_SPRITE );
		else
				SDL_apply_surface(  pSdlJeu->surface_fromage_gauche1, pSdlJeu->surface_ecran, fromGetX(pFrom)*TAILLE_SPRITE,  fromGetY(pFrom)*TAILLE_SPRITE );
			
			break;
	default:
	if(fromGethp(pFrom)<=0)
				SDL_apply_surface(  pSdlJeu->surface_fromage_mort_droite, pSdlJeu->surface_ecran, fromGetX(pFrom)*TAILLE_SPRITE,  fromGetY(pFrom)*TAILLE_SPRITE );
		else
				SDL_apply_surface(  pSdlJeu->surface_fromage_droite1, pSdlJeu->surface_ecran, fromGetX(pFrom)*TAILLE_SPRITE,  fromGetY(pFrom)*TAILLE_SPRITE );
			break;}
	

for(x=0; x<pJeu->Tabdyn.taille_utilisee;x++)
	{
	if(pJeu->Tabdyn.ad[x].tirFrom==2)
	SDL_apply_surface(  pSdlJeu->surface_hp, pSdlJeu->surface_ecran,pJeu->Tabdyn.ad[x].x*TAILLE_SPRITE,pJeu->Tabdyn.ad[x].y*TAILLE_SPRITE);
	if(pJeu->Tabdyn.ad[x].tirFrom==3)
	SDL_apply_surface(  pSdlJeu->surface_clef, pSdlJeu->surface_ecran,pJeu->Tabdyn.ad[x].x*TAILLE_SPRITE,pJeu->Tabdyn.ad[x].y*TAILLE_SPRITE);
	if(pJeu->Tabdyn.ad[x].tirFrom==1){
		if(pJeu->Tabdyn.ad[x].orientation==GAUCHE)
			SDL_apply_surface( pSdlJeu->projo_gauche, pSdlJeu->surface_ecran, pJeu->Tabdyn.ad[x].x*TAILLE_SPRITE,  pJeu->Tabdyn.ad[x].y*TAILLE_SPRITE);
		if(pJeu->Tabdyn.ad[x].orientation==BAS)
			SDL_apply_surface( pSdlJeu->projo_bas, pSdlJeu->surface_ecran, pJeu->Tabdyn.ad[x].x*TAILLE_SPRITE,  pJeu->Tabdyn.ad[x].y*TAILLE_SPRITE);
		if(pJeu->Tabdyn.ad[x].orientation==HAUT)
			SDL_apply_surface( pSdlJeu->projo_haut, pSdlJeu->surface_ecran, pJeu->Tabdyn.ad[x].x*TAILLE_SPRITE,  pJeu->Tabdyn.ad[x].y*TAILLE_SPRITE);
		if(pJeu->Tabdyn.ad[x].orientation==DROITE)
			SDL_apply_surface( pSdlJeu->projo_droite, pSdlJeu->surface_ecran, pJeu->Tabdyn.ad[x].x*TAILLE_SPRITE,  pJeu->Tabdyn.ad[x].y*TAILLE_SPRITE);}
	if(pJeu->Tabdyn.ad[x].tirFrom==0){
		if(pJeu->Tabdyn.ad[x].orientation==GAUCHE)
			SDL_apply_surface( pSdlJeu->projo_blue_gauche, pSdlJeu->surface_ecran, pJeu->Tabdyn.ad[x].x*TAILLE_SPRITE,  pJeu->Tabdyn.ad[x].y*TAILLE_SPRITE);
		if(pJeu->Tabdyn.ad[x].orientation==BAS)
			SDL_apply_surface( pSdlJeu->projo_blue_bas, pSdlJeu->surface_ecran, pJeu->Tabdyn.ad[x].x*TAILLE_SPRITE,  pJeu->Tabdyn.ad[x].y*TAILLE_SPRITE);
		if(pJeu->Tabdyn.ad[x].orientation==HAUT)
			SDL_apply_surface( pSdlJeu->projo_blue_haut, pSdlJeu->surface_ecran, pJeu->Tabdyn.ad[x].x*TAILLE_SPRITE,  pJeu->Tabdyn.ad[x].y*TAILLE_SPRITE);
		if(pJeu->Tabdyn.ad[x].orientation==DROITE)
			SDL_apply_surface( pSdlJeu->projo_blue_droite, pSdlJeu->surface_ecran, pJeu->Tabdyn.ad[x].x*TAILLE_SPRITE,  pJeu->Tabdyn.ad[x].y*TAILLE_SPRITE);}

	}

}
void sdlMenuFin(sdlJeu *pSdlJeu)
{

	SDL_Event event;
	
	int i = 1;
	int continue_boucle0 = 1;
	int continue_boucle1 = 1;
	
	pSdlJeu->surface_menu = SDL_load_image("data/menu/fond_menu.bmp");
	pSdlJeu->surface_fond = SDL_load_image("data/menu/fond.bmp");
	pSdlJeu->bouton_menu_3 = NULL;	

	Mix_PlayMusic(pSdlJeu->menu_theme, -1);		

	while ( continue_boucle0 ==1 )
	{
		SDL_WaitEvent(&event);
				
				switch(event.type)
				{	
					case SDL_KEYDOWN:
						switch(event.key.keysym.sym)
						{
							case SDLK_ESCAPE:
								sdljeuLibere(pSdlJeu);
								continue_boucle0 = 0;
								break;
								
							case SDLK_RETURN:
								sdljeuLibere(pSdlJeu);
								continue_boucle0 = 0;
								break;
								
						}
				break;
				}
		SDL_FreeSurface(pSdlJeu->bouton_menu_3);
		SDL_FillRect( pSdlJeu->surface_ecran, &pSdlJeu->surface_ecran->clip_rect, SDL_MapRGB( pSdlJeu->surface_ecran->format, 0, 0, 0 ) );
			pSdlJeu->bouton_menu_3 = SDL_load_image("data/menu/bouton_menu_3_selec.bmp");   


		SDL_SetColorKey( pSdlJeu->bouton_menu_3, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->bouton_menu_3->format, 255,255,255 ) );
		SDL_SetColorKey( pSdlJeu->surface_menu, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->surface_menu->format, 255,255,255 ) ); 
		SDL_BlitSurface(pSdlJeu->surface_fond, NULL, pSdlJeu->surface_ecran, &pSdlJeu->Fond);
		SDL_BlitSurface(pSdlJeu->surface_menu, NULL, pSdlJeu->surface_ecran, &pSdlJeu->posFond);
		SDL_BlitSurface(pSdlJeu->bouton_menu_3, NULL, pSdlJeu->surface_ecran, &pSdlJeu->posBouton3);
   
   SDL_Flip(pSdlJeu->surface_ecran);
		}
	
	SDL_FreeSurface(pSdlJeu->surface_fond);
	SDL_FreeSurface(pSdlJeu->surface_menu);
	SDL_FreeSurface(pSdlJeu->bouton_menu_3);
	Mix_FreeMusic( pSdlJeu->menu_theme );
}


void sdlMenuJeu(sdlJeu *pSdlJeu)
{

	SDL_Event event;
	
	int i = 1;
	int continue_boucle0 = 1;
	int continue_boucle1 = 1;
	
	pSdlJeu->surface_menu = SDL_load_image("data/menu/fond_menu.bmp");
	pSdlJeu->surface_fond = SDL_load_image("data/menu/fond.bmp");
	pSdlJeu->bouton_menu_1 = NULL;
	pSdlJeu->bouton_menu_2 = NULL;
	pSdlJeu->bouton_menu_3 = NULL;	

	Mix_PlayMusic(pSdlJeu->menu_theme, -1);		

	while ( continue_boucle0 ==1 )
	{
		
		SDL_FreeSurface(pSdlJeu->bouton_menu_1);
		SDL_FreeSurface(pSdlJeu->bouton_menu_2);
		SDL_FreeSurface(pSdlJeu->bouton_menu_3);
		SDL_FillRect( pSdlJeu->surface_ecran, &pSdlJeu->surface_ecran->clip_rect, SDL_MapRGB( pSdlJeu->surface_ecran->format, 0, 0, 0 ) );
		switch(i)
		{
			case 1: 
			pSdlJeu->bouton_menu_1 = SDL_load_image("data/menu/bouton_menu_1_selec.bmp");
			pSdlJeu->bouton_menu_2 = SDL_load_image("data/menu/bouton_menu_2.bmp");
			pSdlJeu->bouton_menu_3 = SDL_load_image("data/menu/bouton_menu_3.bmp");
			break;
   
			case 2:
			pSdlJeu->bouton_menu_1 = SDL_load_image("data/menu/bouton_menu_1.bmp");
			pSdlJeu->bouton_menu_2 = SDL_load_image("data/menu/bouton_menu_2_selec.bmp");
			pSdlJeu->bouton_menu_3 = SDL_load_image("data/menu/bouton_menu_3.bmp");   
			break;
   
			case 3: 
			pSdlJeu->bouton_menu_1 = SDL_load_image("data/menu/bouton_menu_1.bmp");
			pSdlJeu->bouton_menu_2 = SDL_load_image("data/menu/bouton_menu_2.bmp");
			pSdlJeu->bouton_menu_3 = SDL_load_image("data/menu/bouton_menu_3_selec.bmp");   
			break;
		}
		SDL_SetColorKey( pSdlJeu->bouton_menu_1, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->bouton_menu_1->format, 255,255,255 ) );
		SDL_SetColorKey( pSdlJeu->bouton_menu_2, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->bouton_menu_2->format, 255,255,255 ) );
		SDL_SetColorKey( pSdlJeu->bouton_menu_3, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->bouton_menu_3->format, 255,255,255 ) );
		SDL_SetColorKey( pSdlJeu->surface_menu, SDL_SRCCOLORKEY, SDL_MapRGB( pSdlJeu->surface_menu->format, 255,255,255 ) ); 
		SDL_BlitSurface(pSdlJeu->surface_fond, NULL, pSdlJeu->surface_ecran, &pSdlJeu->Fond);
		SDL_BlitSurface(pSdlJeu->surface_menu, NULL, pSdlJeu->surface_ecran, &pSdlJeu->posFond);
		SDL_BlitSurface(pSdlJeu->bouton_menu_1, NULL, pSdlJeu->surface_ecran, &pSdlJeu->posBouton1);
		SDL_BlitSurface(pSdlJeu->bouton_menu_2, NULL, pSdlJeu->surface_ecran, &pSdlJeu->posBouton2);
		SDL_BlitSurface(pSdlJeu->bouton_menu_3, NULL, pSdlJeu->surface_ecran, &pSdlJeu->posBouton3);
   
   SDL_Flip(pSdlJeu->surface_ecran);
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
							Mix_PlayChannel(3, pSdlJeu->bip_menu, 0);	
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
								
								
							}
							break;
							
							case SDLK_DOWN:
							Mix_PlayChannel(3, pSdlJeu->bip_menu, 0);	
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
								
								
							}
							break;
																	
							
							case SDLK_ESCAPE:
							continue_boucle0 = 0;
							break;
							
							case SDLK_RETURN:
							switch(i)
							{
								case 1:
								Mix_PauseMusic();	
								continue_boucle0 = 0;
								pSdlJeu->jeuON = 1;
								
								break;
								
								case 2:
								/* actions */
								break;
								
								case 3:
								continue_boucle0 = 0;
								break;
								
							}
							break;
							
							
						}
				break;	
				}
			continue_boucle1=0;
			}

			
		}
	
	SDL_FreeSurface(pSdlJeu->surface_fond);
	SDL_FreeSurface(pSdlJeu->surface_menu);
	SDL_FreeSurface(pSdlJeu->bouton_menu_1);
	SDL_FreeSurface(pSdlJeu->bouton_menu_2);
	SDL_FreeSurface(pSdlJeu->bouton_menu_3);
	Mix_FreeMusic( pSdlJeu->menu_theme );
}


void UpdateEvents(Input* in)
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			in->key[event.key.keysym.sym]=1;
			break;
		case SDL_KEYUP:
			in->key[event.key.keysym.sym]=0;
			break;
		
		default:
			break;
		}
	}
}

void sdljeuBoucle(sdlJeu *pSdlJeu)
{
	SDL_Event event;
	int continue_boucle = 1;
	int compt;
	Input in;
	// init SDL, chargement, tout ce que vous faites avant la boucle.
	
    /* Horloges (en secondes) */
    float horloge_courante, horloge_precedente;

    /* Intervalle de temps (en secondes) entre deux évolutions du jeu */
    /* Changer la valeur pour ralentir ou accélérer le déplacement des fantomes */
    float intervalle_horloge = 0.1f;

    int rafraichissement;

	sdljeuAff(pSdlJeu);
	assert( SDL_Flip( pSdlJeu->surface_ecran )!=-1 );

    /* Récupère l'horloge actuelle et la convertit en secondes */
    /* clock() retourne le nombre de tops horloge depuis le lancement du programme */
    horloge_precedente = (float)clock()/(float)CLOCKS_PER_SEC;
	memset(&in,0,sizeof(in));

	Mix_PlayMusic(pSdlJeu->main_theme, -1);
	/* Tant que ce n'est pas la fin ... */
	while ( continue_boucle == 1 )
	{
		if(pSdlJeu->jeu.from.hp==0)
			continue_boucle=0;
	    rafraichissement = 0;

	     /* Récupère l'horloge actuelle et la convertit en secondes */
        horloge_courante = (float)clock()/(float)CLOCKS_PER_SEC;

        /* Si suffisamment de temps s'est écoulé depuis la dernière prise d'horloge */
        if (horloge_courante-horloge_precedente>=intervalle_horloge)
        {
                jeuEvolue(&(pSdlJeu->jeu));
                rafraichissement = 1;
                horloge_precedente = horloge_courante;
        }
	compt = 1;
		/* tant qu'il y a des evenements à traiter : cette boucle n'est pas bloquante */
		while(compt == 1)
		{
			UpdateEvents(&in);
			if (!in.key[SDLK_z])
			     if (pSdlJeu->jeu.from.direction == DIRECTION_HAUT)
			      {
				jeuActionClavier( &pSdlJeu->jeu, AUCUNE_DIRECTION );
			     }
			    
			    if (!in.key[SDLK_d])
			    { if (pSdlJeu->jeu.from.direction == DIRECTION_DROITE)
			      jeuActionClavier( &pSdlJeu->jeu, AUCUNE_DIRECTION );
			    }
			    
			    if (!in.key[SDLK_s])
				{
			     		if (pSdlJeu->jeu.from.direction == DIRECTION_BAS)
			      		jeuActionClavier( &pSdlJeu->jeu, AUCUNE_DIRECTION );
			     	}
			    
			   if (!in.key[SDLK_q])
				{
			     		if (pSdlJeu->jeu.from.direction == DIRECTION_GAUCHE)
			      	jeuActionClavier( &pSdlJeu->jeu, AUCUNE_DIRECTION );
			     	}
			if (in.key[SDLK_d])
			{
			
			jeuActionClavier( &pSdlJeu->jeu, DIRECTION_DROITE);
			rafraichissement = 1;
			}
			
			if (in.key[SDLK_z])
			{
			
			jeuActionClavier( &pSdlJeu->jeu, DIRECTION_HAUT);
			rafraichissement = 1;
			}
			
			if (in.key[SDLK_s])
			{
			
			jeuActionClavier( &pSdlJeu->jeu, DIRECTION_BAS);
			rafraichissement = 1;
			}
			
			if (in.key[SDLK_q])
			{
			
			jeuActionClavier( &pSdlJeu->jeu, DIRECTION_GAUCHE);
			rafraichissement = 1;
			}
			
			 if (in.key[SDLK_d] && in.key[SDLK_s])
			   {
				
			   	jeuActionClavier( &pSdlJeu->jeu, DIRECTION_DIAG_DB );
			   	rafraichissement = 1;
			   }
			   
			   if (in.key[SDLK_d] && in.key[SDLK_z])
			   {
			   	jeuActionClavier( &pSdlJeu->jeu, DIRECTION_DIAG_DH);
			   	rafraichissement = 1;
			   }
			   
			   if (in.key[SDLK_q] && in.key[SDLK_s])
			   {
			   	jeuActionClavier( &pSdlJeu->jeu, DIRECTION_DIAG_GB);
			   	rafraichissement = 1;
			   }
			   
			   if (in.key[SDLK_q] && in.key[SDLK_z])
			   {
			   	jeuActionClavier( &pSdlJeu->jeu, DIRECTION_DIAG_GH);
			   	rafraichissement = 1;
			   }
			
					if (in.key[SDLK_RIGHT])
			{
			Mix_PlayChannel(1, pSdlJeu->laser1, 0);
			jeuActionClavier( &pSdlJeu->jeu,  ORIENTATION_DROITE);
			rafraichissement = 1;
			in.key[SDLK_UP] = 0;
			in.key[SDLK_LEFT] = 0;
			in.key[SDLK_DOWN] = 0;
			in.key[SDLK_RIGHT] = 0;
			}

			if (in.key[SDLK_UP])
			{
			Mix_PlayChannel(1, pSdlJeu->laser1, 0);
			jeuActionClavier( &pSdlJeu->jeu, ORIENTATION_HAUT);
			rafraichissement = 1;
			in.key[SDLK_UP] = 0;
			in.key[SDLK_LEFT] = 0;
			in.key[SDLK_DOWN] = 0;
			in.key[SDLK_RIGHT] = 0;
			
}

			if (in.key[SDLK_DOWN])
			{
			Mix_PlayChannel(1, pSdlJeu->laser1, 0);
			jeuActionClavier( &pSdlJeu->jeu, ORIENTATION_BAS);
			rafraichissement = 1;
			in.key[SDLK_UP] = 0;
			in.key[SDLK_LEFT] = 0;
			in.key[SDLK_DOWN] = 0;
			in.key[SDLK_RIGHT] = 0;
			}

			
			if (in.key[SDLK_LEFT])
			{
			/*pSdlJeu->jeu.ter.tab[6][6]='1';
			*/
			
			Mix_PlayChannel(1, pSdlJeu->laser1, 0);
			jeuActionClavier( &pSdlJeu->jeu, ORIENTATION_GAUCHE);
			rafraichissement = 1;
			in.key[SDLK_UP] = 0;
			in.key[SDLK_LEFT] = 0;
			in.key[SDLK_DOWN] = 0;
			in.key[SDLK_RIGHT] = 0;
			}
			
			if (in.key[SDLK_ESCAPE])
       			continue_boucle = 0;				
	
			compt = 0;
		
		}
	

        if (rafraichissement==1)
        {
            
            sdljeuAff(pSdlJeu);

            /* on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans a boucle) */
            SDL_Flip( pSdlJeu->surface_ecran );
        }
	}
	sdlMenuFin(pSdlJeu);
	
	
}


void sdljeuLibere( sdlJeu *pSdlJeu)
{
	SDL_FreeSurface(  pSdlJeu->surface_ecran );
	SDL_FreeSurface(  pSdlJeu->surface_fromage_gauche );
	SDL_FreeSurface(  pSdlJeu->surface_fromage_droite );

	SDL_FreeSurface(  pSdlJeu->surface_fromage_droite1 );
	
	SDL_FreeSurface(  pSdlJeu->surface_fromage_gauche1 );
	 
	SDL_FreeSurface(  pSdlJeu->surface_hp);
	
	SDL_FreeSurface(  pSdlJeu->projo_gauche);
	SDL_FreeSurface(  pSdlJeu->projo_haut);
	SDL_FreeSurface(  pSdlJeu->projo_bas);
	SDL_FreeSurface(  pSdlJeu->projo_droite);
	SDL_FreeSurface(  pSdlJeu->surface_clef);

	SDL_FreeSurface(  pSdlJeu->projo_blue_gauche);
	SDL_FreeSurface(  pSdlJeu->projo_blue_haut);
	SDL_FreeSurface(  pSdlJeu->projo_blue_bas);
	SDL_FreeSurface(  pSdlJeu->projo_blue_droite);

	SDL_FreeSurface(  pSdlJeu->surface_fond);
	SDL_FreeSurface(  pSdlJeu->surface_menu);
	SDL_FreeSurface(  pSdlJeu->bouton_menu_1);
	SDL_FreeSurface(  pSdlJeu->bouton_menu_2);
	SDL_FreeSurface(  pSdlJeu->bouton_menu_3);

	SDL_FreeSurface( pSdlJeu->surface_fromage_gauche);
	SDL_FreeSurface( pSdlJeu->surface_fromage_droite );
	SDL_FreeSurface( pSdlJeu->surface_fromage_saut );
	SDL_FreeSurface( pSdlJeu->surface_fromage_tir );
	SDL_FreeSurface( pSdlJeu->surface_fromage_mort_gauche );
	SDL_FreeSurface( pSdlJeu->surface_fromage_mort_droite );
	SDL_FreeSurface( pSdlJeu->surface_fromage_saut_tir );

	SDL_FreeSurface( pSdlJeu->surface_mur );
	SDL_FreeSurface( pSdlJeu->surface_porte );
	SDL_FreeSurface( pSdlJeu->surface_fantome );
	SDL_FreeSurface(  pSdlJeu->fond_base );	
	SDL_FreeSurface(  pSdlJeu->fond_sombre);
	SDL_FreeSurface(  pSdlJeu->sol );
	SDL_FreeSurface(  pSdlJeu->lumiere);
	SDL_FreeSurface(  pSdlJeu->fenetre );

	Mix_FreeMusic( pSdlJeu->main_theme );
	Mix_FreeChunk( pSdlJeu->laser1 );
	Mix_FreeChunk( pSdlJeu->son_mort );
	Mix_FreeChunk( pSdlJeu->bip_menu );
	jeuLibere(&(pSdlJeu->jeu));
	Mix_CloseAudio();
	SDL_Quit();
}

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

void SDL_apply_surface( SDL_Surface* source, SDL_Surface* destination, int x, int y )
{
	/* Make a temporary rectangle to hold the offsets */
	SDL_Rect offset;

	/* Give the offsets to the rectangle */
	offset.x = x;
	offset.y = y;

	/* Blit the surface */
	SDL_BlitSurface( source, NULL, destination, &offset );
}
