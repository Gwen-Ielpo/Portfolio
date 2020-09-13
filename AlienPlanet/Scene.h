
#ifndef _SCENE_H
#define _SCENE_H

#include "Animation.h"
#include "Image.h"

//! The structure Scene stores all texture Id or images used by the sceneDraw fonction
struct Scene
{
    Animation anim;
    Animation anim1;
    Animation anim2;
    Animation anim3;
    Animation anim6;
	unsigned int tex_papillon;

	Image terrain;
	unsigned int tex_terrain;

	Image arbre;
	unsigned int tex_arbre;

	Image cubemap;
	unsigned int tex_cubemap;

	Image eau;
	unsigned int tex_eau;

	Image feu;
	unsigned int tex_fire;

	Image mer;
	unsigned int tex_mer;

	Image zerg;
	unsigned int tex_zerg;

	Image meteore;
	unsigned int tex_meteore;

	Image metal;
	unsigned int tex_metal;

	Image metalS;
	unsigned int tex_metalS;

	Image bronze;
	unsigned int tex_bronze;


};

typedef struct
{
    int active;
    double life;
    double fade;
    double r, g, b;
    double x, y, z;
    double xi, yi, zi;
    double xg, yg, zg;


}particles;


//! Init a Scene
void sceneInit(Scene& sc);

//! Draw the scene
void sceneDraw(const Scene& sc);


//! Draw a cube
void draw_cube();

//! Draw a cylinder
void draw_cylinder();
void draw_cylinder2();
void draw_cylinder3();

//! Draw a cone
void draw_cone();

//! Draw a sphere
void draw_sphere();
void draw_sphere2();

//dessine un cercle
void draw_cercle();


//dessine un carre
void draw_carre();

//dessine le cubemap
void draw_cubemap();

//dessine la mer
void mer();

//dessine un feu
void fire();



//! Draw the X,Y,Z axes
void draw_axes();

//! Draw a grid in the XZ plane
void draw_grid();

//! affiche un terain à partir d'image passé en paramètre
void dessineTerrain(const Image & ter, const Scene& sc);

//dessine les normales du terrain
void terrainNormale(const Image &im, const int i, const int j);

//! affiche les vecteurs normaux... ect
void normal(const Image im, int i, int j);


//anime un objet en fonction du fichier .ani passer en paramètre
void anima(const Animation &anim,float speed);

//dessine un meteore
void meteores(const Scene& sc);

//dessine une explosion à partir d'un systeme de particules
void explode();

// renvoie un nombre compris entre min et max
double myRand(double min, double max);

//initialise tableau de particules
int initParticles();

//dessine les particules
int dessinerParticules();


//fonction constituant l'arbre alien
void draw_feuillage_base();
void draw_base_h();
void draw_base_b();
void draw_feuillage1();
void draw_feuillage2();
void alien_tree();

//fonction dessinant le drone
void draw_branche(const Scene& sc);
void drone(const Scene& sc);

//dessine la fusée
void draw_flyingPen(const Scene& sc);

#endif
