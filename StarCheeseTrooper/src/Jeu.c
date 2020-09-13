#include "Jeu.h"
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
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

void jeuInit(Jeu *pJeu)
{
	fromInit(&pJeu->from);
	terInit(&pJeu->ter);
	initialiserTabDyn(&pJeu->Tabdyn);
	
}

void jeuLibere(Jeu *pJeu)
{
	terLibere(&(pJeu->ter));
	free(pJeu->tab_fantomes);
	testamentTabDyn(&(pJeu->Tabdyn));
}

Terrain *jeuGetTerrainPtr(Jeu *pJeu)
{
	return &(pJeu->ter);
}

Fromage *jeuGetFromagePtr(Jeu *pJeu)
{
	return &(pJeu->from);
}

const Terrain *jeuGetConstTerrainPtr(const Jeu *pJeu)
{
	return &(pJeu->ter);
}

const Fromage *jeuGetConstFromagePtr(const Jeu *pJeu)
{
	return &(pJeu->from);
}

void jeuActionClavier(Jeu *pJeu, int touche)
{
	pJeu->from.direction = touche;
		
	if (pJeu->from.direction != AUCUNE_DIRECTION)
	{	
		switch(touche)
		{
			case DIRECTION_GAUCHE :
					fromGauche(&(pJeu->from), &(pJeu->ter));
					pJeu->from.orientation = GAUCHE;
					break;
			case DIRECTION_DROITE :
					fromDroite(&(pJeu->from), &(pJeu->ter));
					pJeu->from.orientation = DROITE;
					break;
			case DIRECTION_HAUT :
					fromHaut(&(pJeu->from),&(pJeu->ter));
					pJeu->from.orientation = HAUT;
					break;
			case DIRECTION_BAS :
					fromBas(&(pJeu->from), &(pJeu->ter));
					pJeu->from.orientation = BAS;
					break;
			case DIRECTION_DIAG_DB :
				     
				     fromDiagDB(&(pJeu->from), &(pJeu->ter));
				     break;
			 case DIRECTION_DIAG_DH :
				     
				     fromDiagDH(&(pJeu->from), &(pJeu->ter));
				     break;
			case DIRECTION_DIAG_GB :
				     
				     fromDiagGB(&(pJeu->from), &(pJeu->ter)); 
				     break; 
			case DIRECTION_DIAG_GH :
				     fromDiagGH(&(pJeu->from), &(pJeu->ter)); 
				     break;
			case ORIENTATION_DROITE :
					pJeu->from.orientation=DROITE;
					initProjo(pJeu);
					break;
			case ORIENTATION_BAS :
					pJeu->from.orientation=BAS;
					initProjo(pJeu);
					break;
			case ORIENTATION_HAUT :
					pJeu->from.orientation=HAUT;
					initProjo(pJeu);
					break;
			case ORIENTATION_GAUCHE :
					pJeu->from.orientation=GAUCHE;
					initProjo(pJeu);
					break;
		}
	}
}
void initProjo(Jeu* pJeu)
{
	Projectile projo;
	projo.tirFrom = 1;
	if(pJeu->from.orientation==GAUCHE)
		{
		projo.orientation = GAUCHE;
		
		projo.x=pJeu->from.x-1;
		projo.y=pJeu->from.y+1;
		}
	if(pJeu->from.orientation==DROITE)
		{
		projo.orientation = DROITE;
		projo.x=pJeu->from.x+1;
		projo.y=pJeu->from.y+1;
		}
	if(pJeu->from.orientation==HAUT)
		{
		projo.orientation=HAUT;
		projo.x=pJeu->from.x;
		projo.y=pJeu->from.y-1;
		}
	if(pJeu->from.orientation==BAS)
		{
		projo.orientation = BAS;
		projo.x=pJeu->from.x+1;
		projo.y=pJeu->from.y;
		}
	ajouterElementTabDyn(&pJeu->Tabdyn, projo);
}

void initProjoRat(Jeu* pJeu, int i)
{
	Projectile projo;
	projo.tirFrom = 0;
	if(pJeu->ter.salle_Perso->fant[i].x>fromGetX(&pJeu->from))
		{
		pJeu->ter.salle_Perso->fant[i].direction = GAUCHE;
		
		projo.x=pJeu->ter.salle_Perso->fant[i].x-1;
		projo.y=pJeu->ter.salle_Perso->fant[i].y;
		}
	if(pJeu->ter.salle_Perso->fant[i].x<fromGetX(&pJeu->from))
		{
		projo.orientation = DROITE;
		projo.x=pJeu->ter.salle_Perso->fant[i].x+1;
		projo.y=pJeu->ter.salle_Perso->fant[i].y;
		}
	if(pJeu->ter.salle_Perso->fant[i].y>fromGetY(&pJeu->from))
		{
		projo.orientation=HAUT;
		projo.x=pJeu->ter.salle_Perso->fant[i].x;
		projo.y=pJeu->ter.salle_Perso->fant[i].y-1;
		}
	if(pJeu->ter.salle_Perso->fant[i].y<fromGetY(&pJeu->from))
		{
		projo.orientation = BAS;
		projo.x=pJeu->ter.salle_Perso->fant[i].x;
		projo.y=pJeu->ter.salle_Perso->fant[i].y+1;
		}
	ajouterElementTabDyn(&pJeu->Tabdyn, projo);
}

void initProjohp(Jeu* pJeu, int i)
{
	Projectile projo;
	projo.tirFrom = 2;
	projo.x=pJeu->ter.salle_Perso->fant[i].x;
	projo.y=pJeu->ter.salle_Perso->fant[i].y;
	
	ajouterElementTabDyn(&pJeu->Tabdyn, projo);
}

void initProjoclef(Jeu* pJeu)
{
	Projectile projo;
	projo.tirFrom = 3;
	projo.x=35;
	projo.y=5;
	ajouterElementTabDyn(&pJeu->Tabdyn, projo);
}

void deplacerProjo(Jeu* pJeu, int i)
{
	int speed=3;
	if (pJeu->Tabdyn.ad[i].tirFrom==0)
		speed=3;
	if (pJeu->Tabdyn.ad[i].tirFrom==2||pJeu->Tabdyn.ad[i].tirFrom==3)
		speed=0;
	if(pJeu->Tabdyn.ad[i].orientation==3)
		pJeu->Tabdyn.ad[i].x-=speed;
	if(pJeu->Tabdyn.ad[i].orientation==1)
		pJeu->Tabdyn.ad[i].x+=speed;
	if(pJeu->Tabdyn.ad[i].orientation==0)
		pJeu->Tabdyn.ad[i].y-=speed;
	if(pJeu->Tabdyn.ad[i].orientation==2)
		pJeu->Tabdyn.ad[i].y+=speed;
}

void persoProchehp(Jeu* pJeu)
{
	int i;
	for (i=0;i<pJeu->Tabdyn.taille_utilisee;++i)
	{
		if(pJeu->Tabdyn.ad[i].tirFrom==2 &&fabs( pJeu->from.x-pJeu->Tabdyn.ad[i].x)<=2 && fabs(pJeu->from.y-pJeu->Tabdyn.ad[i].y)<=2 )
			{fromSethp(fromGethp(&pJeu->from)+1,&pJeu->from);
			supprimerElementTabDyn(&pJeu->Tabdyn, i);}
	}
}


void persoProcheclef(Jeu* pJeu)
{
	int i;
	for (i=0;i<pJeu->Tabdyn.taille_utilisee;++i)
	{
		if(pJeu->Tabdyn.ad[i].tirFrom==3 &&fabs( pJeu->from.x-pJeu->Tabdyn.ad[i].x)<=2 && fabs(pJeu->from.y-pJeu->Tabdyn.ad[i].y)<=2 )
			{fromSethp(fromGethp(&pJeu->from)+1,&pJeu->from);
			supprimerElementTabDyn(&pJeu->Tabdyn, i);
			pJeu->from.c_x=1;}
		
	}
}

void jeuEvolue(Jeu *pJeu)
{
	
    int i_fant,i,j;
	initFant(&pJeu->ter);
	if(!terEstPositionPersoPic(&pJeu->ter, fromGetX(&pJeu->from), fromGetY(&pJeu->from)))
		//pJeu->ter.tab[fromGetX(&pJeu->from)][fromGetY(&pJeu->from)]='1';
		fromSethp(fromGethp(&pJeu->from)-1,&pJeu->from);
	persoProcheRat(&(pJeu->ter), pJeu->from.x, pJeu->from.y);
	for(i_fant=0;i_fant<getnbfant(&pJeu->ter);++i_fant)
		if(pJeu->ter.salle_Perso->fant[i_fant].proche==1)
		{
			modeAgro(&pJeu->ter, pJeu->from.x, pJeu->from.y,i_fant);
			initProjoRat(pJeu, i_fant);
		}

	if(pJeu->Tabdyn.taille_utilisee!=0)
		for(i=0;i<pJeu->Tabdyn.taille_utilisee;i++)
		{
			if(terEstPositionPersoValidePix(&pJeu->ter, pJeu->Tabdyn.ad[i].x, pJeu->Tabdyn.ad[i].y))
			deplacerProjo(pJeu,i);
			else
			supprimerElementTabDyn(&pJeu->Tabdyn, i);
		}
	persoProchehp(pJeu);
	for(i=0;i<pJeu->Tabdyn.taille_utilisee;++i)
			if(pJeu->Tabdyn.ad[i].x==fromGetX(&pJeu->from)&&pJeu->Tabdyn.ad[i].y==fromGetY(&pJeu->from))
				{
				if(pJeu->Tabdyn.ad[i].tirFrom==0)
					fromSethp(fromGethp(&pJeu->from)-1,&pJeu->from);
				supprimerElementTabDyn(&pJeu->Tabdyn, i);
				}
for(i_fant=0;i_fant<getnbfant(&pJeu->ter);++i_fant)
	for(i=0;i<pJeu->Tabdyn.taille_utilisee;++i)
			if((pJeu->Tabdyn.ad[i].tirFrom==1&&fabs(pJeu->Tabdyn.ad[i].x-pJeu->ter.salle_Perso->fant[i_fant].x)<2&&fabs(pJeu->Tabdyn.ad[i].y-pJeu->ter.salle_Perso->fant[i_fant].y)<2)||(pJeu->Tabdyn.ad[i].x==pJeu->ter.salle_Perso->fant[i_fant].x-1&&pJeu->Tabdyn.ad[i].y==pJeu->ter.salle_Perso->fant[i_fant].y-1))
				{
				initProjohp(pJeu, i_fant);
				
				pJeu->ter.salle_Perso->fant[i_fant].x=50;
				pJeu->ter.salle_Perso->fant[i_fant].y=50;
				pJeu->ter.salle_Perso->fant[i_fant].mort=1;
				}

	if(terGetXY(&(pJeu->ter), pJeu->from.x, pJeu->from.y)=='d')
	{
		terActuelInitdroite(&(pJeu->ter));
		pJeu->from.x=2;
		for(i=0;i<pJeu->Tabdyn.taille_utilisee;i++)
			supprimerElementTabDyn(&pJeu->Tabdyn, i);
	}
	if(terGetXY(&(pJeu->ter), pJeu->from.x, pJeu->from.y)=='g')
	{
		terActuelInitgauche(&(pJeu->ter));
		pJeu->from.x=47;	
		for(i=0;i<pJeu->Tabdyn.taille_utilisee;i++)
			supprimerElementTabDyn(&pJeu->Tabdyn, i);
	}
	if(terGetXY(&(pJeu->ter), pJeu->from.x, pJeu->from.y)=='h')
	{
		terActuelInithaut(&(pJeu->ter));
		pJeu->from.y=25;
		for(i=0;i<pJeu->Tabdyn.taille_utilisee;i++)
			supprimerElementTabDyn(&pJeu->Tabdyn, i);
	}
	if(terGetXY(&(pJeu->ter), pJeu->from.x, pJeu->from.y)=='b')
	{
		terActuelInitbas(&(pJeu->ter));
		pJeu->from.y=3;
		for(i=0;i<pJeu->Tabdyn.taille_utilisee;i++)
			supprimerElementTabDyn(&pJeu->Tabdyn, i);
	}
	if(pJeu->ter.tab[0][0]=='4' && pJeu->from.c_x==0)
		{
		initProjoclef(pJeu);
		}
	persoProcheclef(pJeu);
	if(pJeu->ter.tab[0][0]=='2' && pJeu->from.c_x==1)
		for(i=0;i<50;i++)
			for(j=0;j<50;j++)
				if(pJeu->ter.tab[i][j]=='C')
					pJeu->ter.tab[i][j]='d';	
		
}

void afficheElementTD(ElementTD e)
{
  printf("%d ", e);
}

void initialiserTabDyn(TableauDynamique * t)
{
  t->capacite=1;
  t->taille_utilisee=0;
  t->ad=malloc(sizeof(ElementTD));
}

void testamentTabDyn(TableauDynamique *t)

{
	int i;
	for(i=0;i<t->taille_utilisee;i++)
		supprimerElementTabDyn( t, i );
	free(t->ad);
	t->capacite = 0;
	t->taille_utilisee = 0;
}
void ajouterElementTabDyn(TableauDynamique *t, ElementTD e)

{
		int i;
	if (t->capacite == t->taille_utilisee)
	{
		ElementTD* tmp;
		tmp = t->ad;
		t->capacite=2*t->capacite;
		t->ad=(ElementTD*)malloc(t->capacite*sizeof(ElementTD));
		for(i=0;i<t->taille_utilisee;i++)
		{
			t->ad[i]=tmp[i];
		}
	free(tmp);  
	}
	t->ad[t->taille_utilisee]=e;	
	t->taille_utilisee++;
}

ElementTD valeurIemeElementTabDyn(const TableauDynamique *t, unsigned int i)

{
return t->ad[i];
}


void afficherTabDyn(const TableauDynamique *t)


{
	int j=0;
	while(j<=t->taille_utilisee)
	{
		afficheElementTD(t->ad[j]);
		j++;
	}
}

void supprimerElementTabDyn( TableauDynamique *t, int position )

{
	int i=position;
	int j;

		while(i!=t->taille_utilisee-1)
		{
			t->ad[i]=t->ad[i+1];
			i++;
		}
	t->taille_utilisee--;
	if(t->taille_utilisee < t->capacite/3)
	{
		t->capacite=t->capacite/3;

	
			ElementTD* tmp;
		tmp=t->ad;
		t->ad=malloc(t->capacite*sizeof(ElementTD));
		for(j=0;j<t->taille_utilisee;j++)
		{
			t->ad[i]=tmp[i];
			
		}
	free(tmp);
	}
}

void modifierValeurIemeElementTabDyn(TableauDynamique *t, ElementTD e, unsigned int i)
{t->ad[i]=e;
}


