#include "Fromage.h"
#include "sdlJeu.h"
#define HAUT	0
#define DROITE	pFrom->vitesse
#define BAS	2
#define GAUCHE	3

#define AUCUNE_DIRECTION	4
#define DIRECTION_HAUT		5
#define DIRECTION_DROITE	6
#define DIRECTION_BAS		7
#define DIRECTION_GAUCHE	8
void fromInit(Fromage *pFrom)
{
	pFrom->largeur = 32;
	pFrom->hauteur = 32;
	pFrom->x=2;
	pFrom->y=2;
	pFrom->hp=5;
	pFrom->c_x=0;
	pFrom->c_y=0;
	pFrom->c_max_y=5;
	pFrom->c_max_x=5;
	pFrom->acc_x=0;
	pFrom->acc_y=0;
	pFrom->direction= DIRECTION_DROITE;
	pFrom->direction= AUCUNE_DIRECTION;
	pFrom->vitesse= 0.1;
	pFrom->orientation=DROITE;

}

void fromDiagGB(Fromage *pFrom, const Terrain *pTer)
{
 if (terEstPositionPersoValide( pTer, pFrom->x-pFrom->vitesse, pFrom->y+pFrom->vitesse))
  {
   pFrom->y+=pFrom->vitesse;
   pFrom->x-=pFrom->vitesse;
  }
}

void fromDiagGH(Fromage *pFrom, const Terrain *pTer)
{
 if (terEstPositionPersoValide( pTer, pFrom->x-pFrom->vitesse, pFrom->y-pFrom->vitesse))
  {
   pFrom->y=pFrom->y-pFrom->vitesse;
   pFrom->x=pFrom->x-pFrom->vitesse;
  }
}

void fromDiagDB(Fromage *pFrom, const Terrain *pTer)
{
 if (terEstPositionPersoValide( pTer, pFrom->x+pFrom->vitesse, pFrom->y+pFrom->vitesse))
  {
   pFrom->y=pFrom->y+pFrom->vitesse;
   pFrom->x=pFrom->x+pFrom->vitesse;
  }
}

void fromDiagDH(Fromage *pFrom, const Terrain *pTer)
{
 if (terEstPositionPersoValide( pTer, pFrom->x+pFrom->vitesse, pFrom->y-pFrom->vitesse))
  {
   pFrom->y=pFrom->y-pFrom->vitesse;
   pFrom->x=pFrom->x+pFrom->vitesse;
  }
}

void fromGauche(Fromage *pFrom, const Terrain *pTer)
{
	if (pFrom->x>0&&terEstPositionPersoValide( pTer, pFrom->x-pFrom->vitesse, pFrom->y))
		{
		pFrom->x -= pFrom->vitesse;
		pFrom->x=pFrom->x-pFrom->vitesse;
		}
}

void fromDroite(Fromage *pFrom, const Terrain *pTer)
{
	if (pFrom->x<50&&terEstPositionPersoValide( pTer, pFrom->x+pFrom->vitesse, pFrom->y))
		{
		pFrom->x += pFrom->vitesse;
		pFrom->x=pFrom->x+pFrom->vitesse;
		}
}



void fromHaut(Fromage *pFrom, const Terrain *pTer)
{
	if (pFrom->y>1&&terEstPositionPersoValide( pTer, pFrom->y+pFrom->vitesse, pFrom->x))
		pFrom->y=pFrom->y-pFrom->vitesse;
}


void fromChute(Fromage *pFrom, const Terrain *pTer)
{
	 	pFrom->c_y++;
		pFrom->y=pFrom->y+(pFrom->vitesse+(pFrom->vitesse/pFrom->c_y));
	
}

void fromBas(Fromage *pFrom, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, pFrom->x, pFrom->y+pFrom->vitesse))
		pFrom->y=pFrom->y+pFrom->vitesse;
}



int fromGetX(const Fromage *pFrom)
{
	return pFrom->x;
}

int fromGetY(const Fromage *pFrom)
{
	return pFrom->y;
}
int fromGethp(const Fromage *pFrom)
{
	return pFrom->hp;
}
void fromSethp(int x,Fromage *pFrom)
{
	pFrom->hp=x;
}
