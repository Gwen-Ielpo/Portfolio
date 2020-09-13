#ifndef _JEU_H
#define _JEU_H

#include "Fromage.h"
#include "Terrain.h"
typedef struct
{
	int x,y,orientation,tirFrom;
}Projectile;

typedef Projectile ElementTD;

struct sTableauDynamique
{
  unsigned int capacite;
  unsigned int taille_utilisee;
  ElementTD * ad;
};
typedef struct sTableauDynamique TableauDynamique;

typedef struct
{
	Terrain ter;
	Fromage from;
	Fantome *tab_fantomes;
	int nb_fantomes;
	TableauDynamique Tabdyn;
} Jeu;
/**
 @brief initProjo initialise un nouveau projectile en fonction de l'orientation du personnage
 @param Jeu* 
 */
void initProjo(Jeu*);

/**
 @brief deplacerProjo deplace le projectile 
 @param Jeu*
 @param int 

 */
void deplacerProjo(Jeu*, int);

/**
 @brief initialiserTabDyn initialise un tableau dynamique
 @param TableauDynamique * t
  */
void initialiserTabDyn(TableauDynamique * t); 

/**
 @brief testamentTabDyn vide et libère un tableau dynamique
 @param TableauDynamique *t
 */
void testamentTabDyn(TableauDynamique *t);

/**
 @brief affecterTabDyn affecte un tableau dynamique dans un nouveau tableau dynamique
 @param TableauDynamique *t1
 @param const TableauDynamique *t2
 */
void affecterTabDyn(TableauDynamique *t1, const TableauDynamique *t2);

/**
 @brief tailleUtiliseeTabDyn renvoie la taille utilisée par un tableau dynamique
 @param const TableauDynamique *t
 */
unsigned int tailleUtiliseeTabDyn(const TableauDynamique *t);

/**
 @brief valeurIemeElementTabDyn renvoie l'ieme element d'un tableau dynamique
 @param const TableauDynamique *t
 @param unsigned int i
 */
ElementTD valeurIemeElementTabDyn(const TableauDynamique *t, unsigned int i);

/**
 @brief afficherTabDyn affiche les elements du tableau dynamique
 @param const TableauDynamique *t
 */
void afficherTabDyn(const TableauDynamique *t);

/**
 @brief ajouterElementTabDyn ajoute un element a la fin du tableau dynamique 
 @param TableauDynamique *t
 @param ElementTD e
 */
void ajouterElementTabDyn(TableauDynamique *t, ElementTD e);

/**
 @brief supprimerElementTabDyn supprimme un element a la ieme position dans le tableau dynamique
 @param  TableauDynamique *t
 @param int position
 */
void supprimerElementTabDyn( TableauDynamique *t, int position );

/**
 @brief modifierValeurIemeElementTabDyn  modifie l'ieme element du tableau dynamique par celui passer en parametre
 @param TableauDynamique *t
 @param ElementTD e
 @param unsigned int i
 */
void modifierValeurIemeElementTabDyn(TableauDynamique *t, ElementTD e, unsigned int i);

/**
 @brief insererElementTabDyn insere l'element passer en parametre a la ieme place du tableau dynamique
 @param TableauDynamique *t
 @param  ElementTD e
 @param unsigned int i
 */
void insererElementTabDyn(TableauDynamique *t, ElementTD e, unsigned int i);

/**
 @brief trierTabDyn trie un tableau dynamique
 @param TableauDynamique *t
 */
void trierTabDyn(TableauDynamique *t) ;

/**
 @brief rechercherElementTabDyn cherche et renvoie l'element passer en parametre 
 @param const TableauDynamique *t
 @param ElementTD e
 */
int rechercherElementTabDyn(const TableauDynamique *t, ElementTD e);

#endif


















