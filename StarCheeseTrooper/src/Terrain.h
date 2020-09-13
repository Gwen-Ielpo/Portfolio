#ifndef _TERRAIN_H
#define _TERRAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>

/**
@brief Starcheese_Trooper
@author Ambrosino Gwenaël Lebrun Enzo
@version 1.0
@date 2015/01/06
*/
typedef struct
{
	int x, y;
	int mort;
	int proche;
	enum {DROITE, GAUCHE, HAUT, BAS} direction;
}Fantome;


typedef struct _Salle
{
	
	FILE* salle_actuelle;
	int nb_fantome;
	Fantome * fant;
	struct _Salle* salle_bas;
	struct _Salle* salle_haut;
	struct _Salle* salle_droite;
	struct _Salle* salle_gauche;
} Salle;

typedef struct
{	
	int dimx;
	int dimy;
	char **tab;
	Salle* salle_Perso;
}Terrain;

/**
 @brief terInit initialise le terrain
 @param Terrain * 

 */
void terInit(Terrain *);
/**
 @brief initFant initialise les ennemis
 @param Terrain *
 */
void initFant(Terrain *);
/**
 @brief libere le terrain
 @param Terrain * 
 */
void terLibere(Terrain *);
/**
 @brief terEstPosPersoValide regarde si la position d'une entite est conforme au décors
 @param Terrain * 
 @param int 
 @param int 
 */
int terEstPositionPersoValide(const Terrain *, const int , const int );
/**
 @brief terActuelInitdroite actualise le terrain si le personage est passe pas la porte de droite
 @param Terrain * 
 */
void terActuelInitdroite(Terrain *);
/**
 @brief terActuelInitdroite actualise le terrain si le personage est passe pas la porte de gauche
 @param Terrain * 
 */
void terActuelInitgauche(Terrain *);
/**
 @brief terActuelInitdroite actualise le terrain si le personage est passe pas la porte de haut
 @param Terrain * 
 */
void terActuelInithaut(Terrain *);
/**
 @brief terActuelInitdroite actualise le terrain si le personage est passe pas la porte de bas
 @param Terrain * 
 */
void terActuelInitbas(Terrain *);
/**
 @brief MarqueurPresent regarde si il y a un marqueur dans une case precise du tableau
	si oui, les enemis ne pas peuvent passer
 @param Terrain *
 @param int
 @param int 
 */
int MarqueurPresent(const Terrain *, const int , const int );
/**
 @brief donne le contenu de la case xy
 @param Terrain * 
 @param int 
 @param int 
 */
const char terGetXY(const Terrain *, const int , const int );
/**
 @brief change le contenu de la case xy
 @param Terrain * 
 @param int 
 @param char
 */
void terSetXY(const Terrain *, const int , const int , const char);
/**
 @brief donne la taille du terrain
 @param Terrain *
 */
const int getDimX(const Terrain *);
/**
 @brief donne la taille du terrain
 @param Terrain *
 */
const int getDimY(const Terrain *);
/**
 @brief regarde si le personnage est proche des ennemis
 @param Terrain *
 @param int 
 @param int 
 */
void persoProcheRat(const Terrain *, const int, const int);
/**
 @brief fait en sorte que les ennemis attaquent le personnage
 @param Terrain *
 @param int 
 @param int 
 @param int 
 */
void modeAgro(const Terrain *, const int, const int, const int);
/**
 @brief regarde le nombre d'ennemis dans une salle
 @param Terrain *
 */
const int getnbfant(const Terrain *);
/**
 @brief regarde si le personnage marche sur un pique
 @param Terrain*
 @param const int
 @param const int
 */
int terEstPositionPersoPic(const Terrain*, const int, const int);
#endif

















