#include "Terrain.h"
#include <malloc.h>
#include <assert.h>


void terInit(/*Terrain *pTer*/Terrain* pNiv)
{
	/*	
	forme du Terrain
	    [4 ]
	    [3 ]
	[1 ][2 ][8 ][9 ]
	    [5 ]
	    [6 ][7 ]
	*/
	int x,y,i;
	Salle* salle1;
	Salle* salle2;
	Salle* salle3;
	Salle* salle4;
	Salle* salle5;
	Salle* salle6;
	Salle* salle7;
	Salle* salle8;
	Salle* salle9;

		/*salle1*/
	salle1 = malloc(sizeof(Salle));	
	salle2 = malloc(sizeof(Salle));	
	salle3 = malloc(sizeof(Salle));	
	salle4 = malloc(sizeof(Salle));	
	salle5 = malloc(sizeof(Salle));	
	salle6 = malloc(sizeof(Salle));	
	salle7 = malloc(sizeof(Salle));	
	salle8 = malloc(sizeof(Salle));	
	salle9 = malloc(sizeof(Salle));
	FILE* fichier = NULL;
	fichier = fopen("data/salle1.txt", "r+");
	if (fichier == NULL)
		{
		fichier = fopen("../data/salle1.txt", "r+");
	assert(fichier!=NULL);
	}
	
	salle1->salle_actuelle = fichier;
	salle1->nb_fantome = 5;
	salle1->salle_gauche = NULL;
	salle1->salle_haut = NULL;
	salle1->salle_bas = NULL;
	salle1->salle_droite = salle2;
	pNiv->salle_Perso=salle1;
	creerTabFich(pNiv);
	salle1->fant = malloc(salle1->nb_fantome*sizeof(Fantome));

	for (i=0; i<salle1->nb_fantome; i++)
	{
              do {
                        x = 2*i+2;
                        y = 2*i+2;
              } while (!terEstPositionPersoValide(pNiv, x, y));

              salle1->fant[i].x = x;
              salle1->fant[i].y = y;
	salle1->fant[i].mort=0;
	salle1->fant[i].proche=0;
        salle1->fant[i].direction = rand()%4;
	}
	
	fichier = fopen("data/salle2.txt", "r+");
	if (fichier == NULL)
		{
		fichier = fopen("../data/salle2.txt", "r+");
	
	assert(fichier!=NULL);
	}
	
	salle2->salle_actuelle = fichier;
	salle2->nb_fantome = 5;
	salle2->salle_gauche = salle1;
	salle2->salle_haut = salle3;
	salle2->salle_bas = salle5;
	salle2->salle_droite = salle8;
	
	salle2->fant = malloc(salle2->nb_fantome*sizeof(Fantome));

	for (i=0; i<salle2->nb_fantome; i++)
	{
              do {
                        x = 2*i+2/*rand()%pJeu->ter.dimx*/;
                        y = 2*i+2/*rand()%pJeu->ter.dimy*/;
              } while (!terEstPositionPersoValide(pNiv, x, y));

              salle2->fant[i].x = x;
              salle2->fant[i].y = y;
	salle2->fant[i].mort=0;
	salle2->fant[i].proche=0;
              salle2->fant[i].direction = rand()%4;
	}
	fichier = fopen("data/salle3.txt", "r+");
	if (fichier == NULL)
		{
		fichier = fopen("../data/salle3.txt", "r+");
	
	assert(fichier!=NULL);
	}
	salle3->salle_actuelle = fichier;
	salle3->nb_fantome = 7;
	salle3->salle_gauche = NULL;
	salle3->salle_haut = salle4;
	salle3->salle_bas = salle2;
	salle3->salle_droite = NULL;
	salle3->fant = malloc(salle3->nb_fantome*sizeof(Fantome));

	for (i=0; i<salle3->nb_fantome; i++)
	{
              do {
                        x = 2*i+2/*rand()%pJeu->ter.dimx*/;
                        y = 2*i+2/*rand()%pJeu->ter.dimy*/;
              } while (!terEstPositionPersoValide(pNiv, x, y));

              salle3->fant[i].x = x;
              salle3->fant[i].y = y;
	salle3->fant[i].mort=0;
	salle3->fant[i].proche=0;
              salle3->fant[i].direction = rand()%4;
	}
	fichier = fopen("data/salle4.txt", "r+");
	if (fichier == NULL)
	{	
		fichier = fopen("../data/salle4.txt", "r+");
	
	assert(fichier!=NULL);
	}
	salle4->salle_actuelle = fichier;
	salle4->nb_fantome = 11;
	salle4->salle_gauche = NULL;
	salle4->salle_haut = NULL;
	salle4->salle_bas = salle3;
	salle4->salle_droite = NULL;
	salle4->fant = malloc(salle4->nb_fantome*sizeof(Fantome));

	for (i=0; i<salle4->nb_fantome; i++)
	{
              do {
                        x = 2*i+2/*rand()%pJeu->ter.dimx*/;
                        y = 2*i+2/*rand()%pJeu->ter.dimy*/;
              } while (!terEstPositionPersoValide(pNiv, x, y));

              salle4->fant[i].x = x;
              salle4->fant[i].y = y;
	salle4->fant[i].mort=0;
	salle4->fant[i].proche=0;
              salle4->fant[i].direction = rand()%4;
	}		
	fichier = fopen("data/salle5.txt", "r+");
	if (fichier == NULL)
	{	
		fichier = fopen("../data/salle5.txt", "r+");
	
	assert(fichier!=NULL);
	}
	salle5->salle_actuelle = fichier;
	salle5->nb_fantome = 8;
	salle5->salle_gauche = NULL;
	salle5->salle_haut = salle2;
	salle5->salle_bas = salle6;
	salle5->salle_droite = NULL;
	salle5->fant = malloc(salle5->nb_fantome*sizeof(Fantome));

	for (i=0; i<salle5->nb_fantome; i++)
	{
              do {
                        x = 2*i+2/*rand()%pJeu->ter.dimx*/;
                        y = 2*i+2/*rand()%pJeu->ter.dimy*/;
              } while (!terEstPositionPersoValide(pNiv, x, y));

              salle5->fant[i].x = x;
              salle5->fant[i].y = y;
	salle5->fant[i].mort=0;
	salle5->fant[i].proche=0;
              salle5->fant[i].direction = rand()%4;
	}

	fichier = fopen("data/salle6.txt", "r+");
	if (fichier == NULL)
	{	
		fichier = fopen("../data/salle6.txt", "r+");
	
	assert(fichier!=NULL);
	}
	salle6->salle_actuelle = fichier;
	salle6->nb_fantome = 5;
	salle6->salle_gauche = NULL;
	salle6->salle_haut = salle5;
	salle6->salle_bas = NULL;
	salle6->salle_droite = salle7;
	salle6->fant = malloc(salle6->nb_fantome*sizeof(Fantome));

	for (i=0; i<salle6->nb_fantome; i++)
	{
              do {
                        x = 2*i+2/*rand()%pJeu->ter.dimx*/;
                        y = 2*i+2/*rand()%pJeu->ter.dimy*/;
              } while (!terEstPositionPersoValide(pNiv, x, y));

              salle6->fant[i].x = x;
              salle6->fant[i].y = y;
	salle6->fant[i].mort=0;
	salle6->fant[i].proche=0;
              salle6->fant[i].direction = rand()%4;
	}	
		
	fichier = fopen("data/salle7.txt", "r+");
	if (fichier == NULL)
	{	
		fichier = fopen("../data/salle7.txt", "r+");
	
	assert(fichier!=NULL);
	}
	salle7->salle_actuelle = fichier;
	salle7->nb_fantome = 6;
	salle7->salle_gauche = salle6;
	salle7->salle_haut = NULL;
	salle7->salle_bas = NULL;
	salle7->salle_droite = NULL;
	salle7->fant = malloc(salle7->nb_fantome*sizeof(Fantome));

	for (i=0; i<salle7->nb_fantome; i++)
	{
              do {
                        x = 2*i+2/*rand()%pJeu->ter.dimx*/;
                        y = 2*i+2/*rand()%pJeu->ter.dimy*/;
              } while (!terEstPositionPersoValide(pNiv, x, y));

              salle7->fant[i].x = x;
              salle7->fant[i].y = y;
	salle7->fant[i].mort=0;
	salle7->fant[i].proche=0;
              salle7->fant[i].direction = rand()%4;
}	
		
	fichier = fopen("data/salle8.txt", "r+");
	if (fichier == NULL)
	{	
		fichier = fopen("../data/salle8.txt", "r+");
	
	assert(fichier!=NULL);
	}
	salle8->salle_actuelle = fichier;
	salle8->nb_fantome = 5;
	salle8->salle_gauche = salle2;
	salle8->salle_haut = NULL;
	salle8->salle_bas = NULL;
	salle8->salle_droite = salle9;
	salle8->fant = malloc(salle8->nb_fantome*sizeof(Fantome));

	for (i=0; i<salle8->nb_fantome; i++)
	{
              do {
                        x = 2*i+2/*rand()%pJeu->ter.dimx*/;
                        y = 2*i+2/*rand()%pJeu->ter.dimy*/;
              } while (!terEstPositionPersoValide(pNiv, x, y));

              salle8->fant[i].x = x;
              salle8->fant[i].y = y;
	salle8->fant[i].mort=0;
	salle8->fant[i].proche=0;
              salle8->fant[i].direction = rand()%4;
	}
		
	fichier = fopen("data/salle9.txt", "r+");
	if (fichier == NULL)
	{	
		fichier = fopen("../data/salle9.txt", "r+");
	
	assert(fichier!=NULL);
	}
	salle9->salle_actuelle = fichier;
	salle9->nb_fantome = 1;
	salle9->salle_gauche = salle8;
	salle9->salle_haut = NULL;
	salle9->salle_bas = NULL;
	salle9->salle_droite = NULL;
	salle9->fant = malloc(salle9->nb_fantome*sizeof(Fantome));

	for (i=0; i<salle9->nb_fantome; i++)
	{
              do {
                        x = 2*i+2/*rand()%pJeu->ter.dimx*/;
                        y = 2*i+2/*rand()%pJeu->ter.dimy*/;
              } while (!terEstPositionPersoValide(pNiv, x, y));
	
              salle9->fant[i].x = x;
              salle9->fant[i].y = y;
		salle9->fant[i].mort=0;
		salle9->fant[i].proche=0;
              salle9->fant[i].direction = rand()%4;
	}	
}

void initFant(Terrain* pNiv)
{
	int x,y,i;
	Fantome *p_fant;
	int depx[] = {-1, 1, 0, 0};
	int depy[] = {0, 0, -1, 1};
	
	for (i=0; i<pNiv->salle_Perso->nb_fantome; i++)
	{
	if(pNiv->salle_Perso->fant[i].proche==0&&pNiv->salle_Perso->fant[i].mort==0){
              p_fant = &(pNiv->salle_Perso->fant[i]);
              x = p_fant->x + depx[p_fant->direction];
              y = p_fant->y + depy[p_fant->direction];

              if (terEstPositionPersoValide(pNiv, x, y)&&MarqueurPresent(pNiv, x,y)&&posRat(pNiv,i))
              {
                        p_fant->x = x;
                        p_fant->y = y;
              }
              else {
                        /* Changement de direction */
                        p_fant->direction = rand()%4;
              }
	}
	}
}
void terActuelInitdroite(Terrain* pNiv)
{
	int i,j;


	pNiv->salle_Perso=pNiv->salle_Perso->salle_droite;



	fseek(pNiv->salle_Perso->salle_actuelle, 0, SEEK_SET) ;
	for(i=0;i<50;++i)
		for(j=0;j<50;++j)
			fscanf(pNiv->salle_Perso->salle_actuelle,"%c",&pNiv->tab[i][j]);
}

void terActuelInitgauche(Terrain* pNiv)
{
	int i,j;
	pNiv->salle_Perso=pNiv->salle_Perso->salle_gauche;
	fseek(pNiv->salle_Perso->salle_actuelle, 0, SEEK_SET) ;
	for(i=0;i<50;++i)
		for(j=0;j<50;++j) 
			fscanf(pNiv->salle_Perso->salle_actuelle,"%c",&pNiv->tab[i][j]);
}

void terActuelInithaut(Terrain* pNiv)
{
	int i,j;

	pNiv->salle_Perso=pNiv->salle_Perso->salle_haut;
	fseek(pNiv->salle_Perso->salle_actuelle, 0, SEEK_SET) ;
	for(i=0;i<50;++i)
		for(j=0;j<50;++j)
			fscanf(pNiv->salle_Perso->salle_actuelle,"%c",&pNiv->tab[i][j]);
}

void terActuelInitbas(Terrain* pNiv)
{
	int i,j;
	pNiv->salle_Perso=pNiv->salle_Perso->salle_bas;
	fseek(pNiv->salle_Perso->salle_actuelle, 0, SEEK_SET) ;
	for(i=0;i<50;++i)
		for(j=0;j<50;++j)
			fscanf(pNiv->salle_Perso->salle_actuelle,"%c",&pNiv->tab[i][j]);
}

void creerTabFich(Terrain*t)
{
	int j,i;
	int y;
	t->tab = (char **)malloc(sizeof(char *)*50);
	for (y=0; y<50; y++)
		t->tab[y] = (char *)malloc(sizeof(char)*50);
	for(i=0;i<50;++i)
		for(j=0;j<50;++j)
			fscanf(t->salle_Perso->salle_actuelle,"%c",&t->tab[i][j]);		
}

void terLibere(Terrain *pNiv)
{
	vider(pNiv->salle_Perso);
}

void vider(Salle *n)
{
    if(n != NULL)
    {		
		n->salle_actuelle=NULL;
              	vider(n->salle_gauche);
		vider(n->salle_droite);
		vider(n->salle_haut);
		vider(n->salle_bas);
              free(n);
    }
}

int terEstPositionPersoValide(const Terrain *pTer, const int x, const int y)
{
	if (x>=0 && x<50 && y>=0 && y<50 && pTer->tab[y][x]!='1')
		return 1;
	else
		return 0;
}

int terEstPositionPersoPic(const Terrain *pTer, const int x, const int y)
{
	if ( pTer->tab[y][x]!='P')
		return 1;
	else
		return 0;
}

int terEstPositionPersoValidePix(const Terrain *pTer, const int x, const int y)
{
	if (x>=0 && x<1600 && y>=0 && y<1200/* && pTer->tab[y][x]!='1'*/)
		return 1;
	else
		return 0;
}

void persoProcheRat(const Terrain *pTer, const int x, const int y)
{
	int i_fant;
	for (i_fant=0;i_fant<pTer->salle_Perso->nb_fantome;++i_fant)
	{
		if(fabs(x-pTer->salle_Perso->fant[i_fant].x)<10 && fabs(y-pTer->salle_Perso->fant[i_fant].y)<10 )
			pTer->salle_Perso->fant[i_fant].proche=1;
		else	pTer->salle_Perso->fant[i_fant].proche=0;
	}
}
int posRat(const Terrain *pTer,int num_rat)
{
	int i_fant;
	int somme=0;
	for(i_fant=0;i_fant<pTer->salle_Perso->nb_fantome;++i_fant)
	somme=somme+((i_fant!=num_rat && pTer->salle_Perso->fant[i_fant].x+1 != pTer->salle_Perso->fant[num_rat].x && pTer->salle_Perso->fant[i_fant].y != pTer->salle_Perso->fant[num_rat].y)||(i_fant!=num_rat && pTer->salle_Perso->fant[i_fant].x-1 != pTer->salle_Perso->fant[num_rat].x && pTer->salle_Perso->fant[i_fant].y != pTer->salle_Perso->fant[num_rat].y)||(i_fant!=num_rat && pTer->salle_Perso->fant[i_fant].x != pTer->salle_Perso->fant[num_rat].x && pTer->salle_Perso->fant[i_fant].y+1 != pTer->salle_Perso->fant[num_rat].y)||(i_fant!=num_rat && pTer->salle_Perso->fant[i_fant].x != pTer->salle_Perso->fant[num_rat].x && pTer->salle_Perso->fant[i_fant].y-1 != pTer->salle_Perso->fant[num_rat].y)
|| (pTer->salle_Perso->fant[i_fant].y != pTer->salle_Perso->fant[num_rat].y && pTer->salle_Perso->fant[i_fant].x != pTer->salle_Perso->fant[num_rat].x));
	if (somme<1)	
	return 1;
	return somme;
	
}
void modeAgro(const Terrain *pTer, const int x, const int y, const int i_fant)
{
	if(posRat(pTer,i_fant)){
			pTer->tab[3][3]='1';
		if (x<pTer->salle_Perso->fant[i_fant].x)
			pTer->salle_Perso->fant[i_fant].x--;
		else {pTer->salle_Perso->fant[i_fant].x++;}}
}
int MarqueurPresent(const Terrain *pTer, const int x, const int y)
{
	if (x>=0 && x<50 && y>1 && y<50 && pTer->tab[y][x]!='M')
		return 1;
	else
		return 0;
}
const char terGetXY(const Terrain *pTer, const int x, const int y)
{
	assert( x>=0) ;
	assert( y>=0) ;
	assert( x<50 ) ;
	assert( y<50 ) ;
	return pTer->tab[y][x];
}

void terSetXY(const Terrain *pTer, const int x, const int y, const char val)
{
	assert( x>=0) ;
	assert( y>=0) ;
	assert( x>50 ) ;
	assert( y<50 ) ;
	pTer->tab[y][x] = val;
}

const int getDimX(const Terrain *pTer)
{
	return 50;
}

const int getDimY(const Terrain *pTer)
{
	return 50;
}

const int getnbfant(const Terrain *pTer)
{
	return pTer->salle_Perso->nb_fantome;
}
