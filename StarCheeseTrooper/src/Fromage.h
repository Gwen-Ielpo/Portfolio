#ifndef _Fromage_H
#define _Fromage_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Terrain.h"
typedef struct 
{
	SDL_Rect source;
	SDL_Rect dest;
	SDL_Rect posfrom;
	int largeur, hauteur;
	float x,y;
	float c_x, c_y, c_max_x,c_max_y;
	float acc_x, acc_y;
	int direction;
	int orientation;
	int hp;
	float vitesse;
	int anim;
	int anim_courante;
	int temps_anim;
	int temps_anim_courante;
	int total_anims;	
	
} Fromage;
/**
 @brief Initialise les coordonnées de bases et autres variable de notre personnage
 @param Fromage *
 */
void fromInit(Fromage *);/**
 @brief le personnage vas vers la gauche
 @param Fromage *
 @param const Terrain *
 */
void fromGauche(Fromage *, const Terrain *);
/**
 @brief le personnage vas vers la droite
 @param Fromage *
 @param const Terrain *
 */
void fromDroite(Fromage *, const Terrain *);

/**
 @brief le personnage vas vers le bas
 @param Fromage *
 @param const Terrain *
 */
void fromBas(Fromage *, const Terrain *);
/**
 @brief donne la position en x du perso
 @param Fromage *
 */
int fromGetX(const Fromage *);
/**
 @brief donne la position en y du perso
 @param Fromage *
 */
int fromGetY(const Fromage *);
/**
 @brief donne les point de vie du perso
 @param Fromage *
 */
int fromGethp(const Fromage *);
/**
 @brief change les point de vie du perso
 @param Fromage *
 */
void fromSethp(int,Fromage*);

#endif

























