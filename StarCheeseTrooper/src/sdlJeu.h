
#ifndef _SDLJEU_H
#define _SDLJEU_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "Jeu.h"

typedef struct
{
	char key[SDLK_LAST];
} Input;

typedef struct
{
	int jeuON;
	Jeu jeu;
	SDL_Surface* surface_ecran;
	SDL_Surface* surface_fromage_gauche;
	SDL_Surface* surface_fromage_droite;

	SDL_Surface* surface_fromage_droite1;
	
	SDL_Surface* surface_fromage_gauche1;

	SDL_Surface* surface_fromage_saut;
	SDL_Surface* surface_fromage_tir;
	SDL_Surface* surface_fromage_mort_droite;
	SDL_Surface* surface_fromage_mort_gauche;
	SDL_Surface* surface_fromage_saut_tir;
	SDL_Surface* surface_mur;
	SDL_Surface* surface_fantome;
	SDL_Surface* surface_fantome_mort_droite;
	SDL_Surface* surface_fantome_mort_gauche;
	SDL_Surface* surface_porte;
	SDL_Surface* surface_hp;
	SDL_Surface* fond_base;	
	SDL_Surface* fond_sombre;
	SDL_Surface* sol;
	SDL_Surface* lumiere;
	SDL_Surface* fenetre;
	SDL_Surface* gandalf;
	SDL_Surface* pic;

	SDL_Surface* projo_gauche;
	SDL_Surface* projo_haut;
	SDL_Surface* projo_bas;
	SDL_Surface* projo_droite;
	SDL_Surface* surface_clef;

	SDL_Surface* projo_blue_gauche;
	SDL_Surface* projo_blue_haut;
	SDL_Surface* projo_blue_bas;
	SDL_Surface* projo_blue_droite;

	SDL_Surface* surface_fond;
	SDL_Surface* surface_menu;
	SDL_Surface* bouton_menu_1;
	SDL_Surface* bouton_menu_2;
	SDL_Surface* bouton_menu_3;
	
	SDL_Rect posFond;
	SDL_Rect Fond;
	SDL_Rect posBouton1;
	SDL_Rect posBouton2;
	SDL_Rect posBouton3;

	Mix_Music *main_theme;
	Mix_Music *menu_theme;
	Mix_Chunk *laser1;
	Mix_Chunk *son_mort;
	Mix_Chunk *bip_menu;
} sdlJeu;
/**
 @brief sdljeuInit charge les image les sons ect
 @param sdlJeu*
 */
void sdljeuInit(sdlJeu *);
/**
 @brief sdlMenuJeu affiche le menu
 @param sdlJeu *
 */
void sdlMenuJeu(sdlJeu *);
/**
 @brief sdljeuBoucle attend des actions du joueur, appel jeuEvolue, appel la fin du jeu...
 @param sdlJeu *
 */
void sdljeuBoucle(sdlJeu *);
/**
 @brief Libere toutes les fonctions du jeu
 @param sdlJeu*
 */
void sdljeuLibere(sdlJeu *);

#endif














