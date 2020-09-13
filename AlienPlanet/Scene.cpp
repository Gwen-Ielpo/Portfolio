#include "Scene.h"
#include <GL/gl.h>
#include "opengl.h"
#define MAX_PARTICLES 1000

particles particle[MAX_PARTICLES];

//*************************************************
void draw_axes()
{
    glLineWidth(5);
    glBegin( GL_LINES );

    glColor3f( 1.f, 0.f, 0.f);
    glVertex3f( 0.f, 0.f, 0.f);
    glVertex3f( 1.f, 0.f, 0.f);

    glColor3f( 0.f, 1.f, 0.f);
    glVertex3f( 0.f, 0.f, 0.f);
    glVertex3f( 0.f, 1.f, 0.f);

    glColor3f( 0.f, 0.f, 1.f);
    glVertex3f( 0.f, 0.f, 0.f);
    glVertex3f( 0.f, 0.f, 1.f);

    glEnd();
}

//*************************************************
void draw_grid()
{
    int i;
    glLineWidth(1);
    glColor3f( 1.f, 1.f, 1.f);

    glPushMatrix();
    glTranslatef( -5, 0, -5);

    glBegin( GL_LINES );

    for (i=0;i<=10;++i)
    {
        glVertex3f( i, 0, 0);
        glVertex3f( i, 0, 10);
    }

    for (i=0;i<=10;++i)
    {
        glVertex3f( 0, 0, i);
        glVertex3f( 10, 0, i);
    }

    glEnd();
    glPopMatrix();
}
//*************************************************
void draw_cercle()
{
        int i, a, N;
        glBegin(GL_TRIANGLE_FAN);//cercle haut
        for(i=0; i<N; i++)
          {
            a = 2.0*M_PI*i/N;
            glNormal3f(cos(a),0,sin(a));
            glVertex3f( cos(a),0.4, sin(a));

          }
        glEnd();

}
//*************************************************
void draw_cube()
{
    static float pt[8][3] = { {0,0,0}, {1,0,0}, {1,0,1}, {0,0,1}, {0,1,0}, {1,1,0}, {1,1,1}, {0,1,1} };
    static int f[6][4] = { {0,1,2,3}, {5,4,7,6}, {1,5,6,2}, {0,3,7,4}, {3,2,6,7}, {0,4,5,1} };
    static float n[6][3] = { {0,-1,0}, {0,1,0}, {1,0,0}, {-1,0,0}, {0,0,1}, {0,0,-1} };
    static float uv[6][4][2] = { { {0,0}, {1,0}, {1,1}, {0,1} },
                                 { {0,0}, {1,0}, {1,1}, {0,1} },
                                 { {0,0}, {1,0}, {1,1}, {0,1} },
                                 { {0,0}, {1,0}, {1,1}, {0,1} },
                                 { {0,0}, {1,0}, {1,1}, {0,1} },
                                 { {0,0}, {1,0}, {1,1}, {0,1} } };
    int i,j;

    glTranslatef(-0.5,-0.5,-0.5);
    glBegin(GL_QUADS);
    for (i=0;i<6;i++)
    {
        glNormal3f( n[ i ][0], n[ i ][1], n[ i ][2] );
        for (j=0;j<4;j++)
        {
            glTexCoord2f( uv[i][j][0], uv[i][j][1] );
            glVertex3f( pt[ f[i][j] ][0], pt[ f[i][j] ][1], pt[ f[i][j] ][2] );
        }
    }
    glEnd();
}


//*************************************************
void draw_sphere()
{
	int i, j;
	float a, a2, b;
	int N=20;
	for(i=0; i <= N ; i++)
	{
		a =10* M_PI*i/N;
		a2 = 10*M_PI*(i+1)/N;
		glBegin(GL_TRIANGLE_STRIP);
		for(j=0; j <= N ; j++)
		{
			b = 2.0*M_PI*j/N;
			glNormal3f(sin(a)*cos(b),cos(a),sin(a)*sin(b));
			glVertex3f(sin(a)*cos(b),cos(a),sin(a)*sin(b));
			glNormal3f(sin(a2)*cos(b),cos(a2),sin(a2)*sin(b));
			glVertex3f(sin(a2)*cos(b),cos(a2),sin(a2)*sin(b));
		}
		glEnd();
	}


}
//*************************************************
void draw_sphere2()
{
	int i, j;
	float a, a2, b;
	int N=20;
	for(i=0; i <= N ; i++)
	{
		a = M_PI*i/N;
		a2 = M_PI*(i+1)/N;
		glBegin(GL_TRIANGLE_STRIP);
		for(j=0; j <= N ; j++)
		{
			b = 2.0*M_PI*j/N;
			glNormal3f(sin(a)*cos(b),cos(a),sin(a)*sin(b));
			glTexCoord2f( b/(M_PI),0.5+a/(M_PI));
			glVertex3f(sin(a)*cos(b),cos(a),sin(a)*sin(b));
			glNormal3f(sin(a2)*cos(b),cos(a2),sin(a2)*sin(b));
			glTexCoord2f( b/(M_PI),0.5+a2/(M_PI));
			glVertex3f(sin(a2)*cos(b),cos(a2),sin(a2)*sin(b));
		}
		glEnd();
	}


}

//*************************************************
void draw_cylinder()
{
	int i; float a; int N=20;
	glBegin(GL_TRIANGLE_STRIP);
	for(i=0; i <= N ; i++)
	{
		a = 2.0*M_PI*i/N;
		glNormal3f(cos(a)/10,0,sin(a)/10);
		glVertex3f(cos(a)/10,0,sin(a)/10);
		glNormal3f(cos(a)/10,0,sin(a)/10);
		glVertex3f(cos(a)/10,1,sin(a)/10);
		}
	glEnd();

}
//*************************************************
void draw_cylinder2()
{
	int i; float a; int N=20;
	glBegin(GL_TRIANGLE_STRIP);
	for(i=0; i <= N ; i++)
	{
		a = 2.0*M_PI*i/N;
		glNormal3f(cos(a)/5,0,sin(a)/5);
		glVertex3f(cos(a)/5,0,sin(a)/5);
		glNormal3f(cos(a)/5,0,sin(a)/5);
		glVertex3f(cos(a)/5,1,sin(a)/5);
		}
	glEnd();
}
//*************************************************
void draw_cylinder3()
{
	int i; float a; int N=20;
	glBegin(GL_TRIANGLE_STRIP);
	for(i=0; i <= N ; i++)
	{
		a = 2.0*M_PI*i/N;
		glNormal3f(cos(a),0,sin(a));
		glVertex3f(cos(a),-4,sin(a));
		glNormal3f(cos(a),0,sin(a));
		glVertex3f(cos(a),1,sin(a));
		}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	for(i=0; i<N; i++)
	  {
	    a = 2.0*M_PI*i/N;
	    glVertex3f( cos(a),-4, sin(a) );

	  }
	glEnd();
}
//*************************************************
void draw_cone()
{
	int i; float a; int N=20;
	glBegin(GL_TRIANGLE_STRIP);
	for(i=0; i <= N ; i++)
	{
		a = 2.0*M_PI*i/N;
		glNormal3f(cos(a),0,sin(a));
		glVertex3f(cos(a)/5,0,sin(a)/5);
		glVertex3f(0,1,0);
	}
	glEnd();


}
//*************************************************
void draw_carre()
{
	glBegin(GL_QUADS);
	glTexCoord2f(1,0);
	glVertex3f(1,0,1);
	glTexCoord2f(1,1);
	glVertex3f(-1,0,1);
	glTexCoord2f(0,1);
	glVertex3f(-1,0,-1);
	glTexCoord2f(0,0);
	glVertex3f(1,0,-1);
	glEnd();
}
//************************************************************************
//************************************************************************
//CUBEMAP

void draw_cubemap()
{
    glBegin(GL_QUADS);

			glNormal3f(0,0,-1);
			glTexCoord2f(0.0,0.33);
            glVertex3f(0,0,0);
            glTexCoord2f(0.25,0.33);
            glVertex3f(1,0,0);
            glTexCoord2f(0.25,0.66);
            glVertex3f(1,1,0);
            glTexCoord2f(0.0,0.66);
            glVertex3f(0,1,0);


			glNormal3f(0,1,0);
			glTexCoord2f(0.25,0.0);
            glVertex3f(0,0,0);
            glTexCoord2f(0.5,0.0);
            glVertex3f(1,0,0);
            glTexCoord2f(0.5,0.33);
            glVertex3f(1,0,-1);
            glTexCoord2f(0.25,0.33);
            glVertex3f(0,0,-1);

			glNormal3f(1,0,0);
			glTexCoord2f(1,0.33);
            glVertex3f(0,0,0);
            glTexCoord2f(0.75,0.33);
            glVertex3f(0,0,-1);
            glTexCoord2f(0.75,0.66);
            glVertex3f(0,1,-1);
            glTexCoord2f(1,0.66);
            glVertex3f(0,1,0);

			glNormal3f(-1,0,0);
			glTexCoord2f(0.25,0.33);
            glVertex3f(1,0,0);
            glTexCoord2f(0.5,0.33);
            glVertex3f(1,0,-1);
            glTexCoord2f(0.5,0.66);
            glVertex3f(1,1,-1);
            glTexCoord2f(0.25,0.66);
            glVertex3f(1,1,0);

			glNormal3f(0,0,1);
			glTexCoord2f(0.5,0.33);
            glVertex3f(0,0,-1);
            glTexCoord2f(0.75,0.33);
            glVertex3f(1,0,-1);
            glTexCoord2f(0.75,0.66);
            glVertex3f(1,1,-1);
            glTexCoord2f(0.5,0.66);
            glVertex3f(0,1,-1);

			glNormal3f(0,-1,0);
			glTexCoord2f(0.25,0.66);
            glVertex3f(1,1,0);
            glTexCoord2f(0.5,0.66);
            glVertex3f(0,1,0);
            glTexCoord2f(0.25,1.0);
            glVertex3f(0,1,-1);
            glTexCoord2f(0.5,1.0);
            glVertex3f(1,1,-1);

	glEnd();

}
//************************************************************************
//************************************************************************
//MER
void mer()
{
	float t=20*temps();
	glPushMatrix();
        glTranslatef(0,-8+(sin(t*(2*M_PI/180))),0);
        glScalef(200,0,200);
        draw_carre();
	glPopMatrix();
}
//************************************************************************
//************************************************************************
//FEU
void fire()
{
    float t=10*temps();
    int im=(int)(t)%16;
	float part=1.0/16.0;

	glBegin(GL_QUADS);
	glTexCoord2f(part*float(im),0.f);
	glVertex3f(0,0,0);
	glTexCoord2f(part*float(im),1.f);
	glVertex3f(0,1,0);
	glTexCoord2f(part*float(im+1),1.f);
	glVertex3f(1,1,0);
	glTexCoord2f(part*float(im+1),0.f);
	glVertex3f(1,0,0);
    glEnd();

    glBegin(GL_QUADS);
	glTexCoord2f(part*float(im),0.f);
	glVertex3f(0.5,0,0.5);
	glTexCoord2f(part*float(im),1.f);
	glVertex3f(0.5,1,0.5);
	glTexCoord2f(part*float(im+1),1.f);
	glVertex3f(0.5,1,-0.5);
	glTexCoord2f(part*float(im+1),0.f);
	glVertex3f(0.5,0,-0.5);
    glEnd();

}

//************************************************************************
//************************************************************************
//FONCTIONS TERRAIN

void terrainNormale(const Image &im, const int i, const int j)
{
    Vec3f a,b,c,d;
    Vec3f n, AB, CD;

	if(i!=0)

    vecInit(a, i-1, getPixConst(im, i-1, j)/10.0, j);

    else
    vecInit(a, i-1, getPixConst(im, i, j)/10.0, j);

    if(i!=imGetDimX(im)-1)

    vecInit(b, i+1, getPixConst(im,i+1, j)/10.0, j);

    else

    vecInit(b, i+1, getPixConst(im,i, j)/10.0, j);

    if(j!=0)

    vecInit(c, i, getPixConst(im, i, j-1)/10.0,j-1);

    else

    vecInit(c, i, getPixConst(im, i, j)/10.0,j-1);

    if(j!=imGetDimY(im)-1)

    vecInit(d, i, getPixConst(im, i, j+1)/10.0, j+1);

    else

	vecInit(d, i, getPixConst(im, i, j)/10.0, j+1);

    AB.x = b.x - a.x;
    AB.y = b.y - a.y;
    AB.z = b.z - a.z;

    CD.x = d.x - c.x;
    CD.y = d.y - c.y;
    CD.z = d.z - c.z;

    vecCross(n, CD, AB);
    vecNormalize(n);
    glNormal3f(n.x, n.y, n.z);
}



void draw_terrain(Image im)
{
    for(int i=0; i<imGetDimX(im)-1; i++)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for(int j=0; j<imGetDimY(im); j++)
        {
            terrainNormale(im,i,j);
            glTexCoord2f ((float) i / (imGetDimX(im) - 2), (float) j / (imGetDimY(im)));
            glVertex3f(i, getPixConst(im, i, j)/10, j);
            terrainNormale(im,i+1,j);
            glTexCoord2f ((float) (i+1) / (imGetDimX(im) - 2), (float) j / (imGetDimY(im)));
            glVertex3f(i+1, getPixConst(im, i+1, j)/10, j);
        }
        glEnd();
    }
}

//************************************************************************
//************************************************************************
//FONCTION ANIMATION
void anima(const Animation &anim,float speed)
{
    Vec3f pos,pos_suivante,dir,V,codir;
    float t=temps()*speed;
    int temps_entier=(int)t;
    int cible=(temps_entier+1)%anim.nbp;
    float poids=t-temps_entier;
    int temps_entier_ok=temps_entier%anim.nbp;

    Vec3f a,b,c,d;
    vecSub(a,anim.P[cible],anim.P[temps_entier_ok]);
    vecMul(b,poids,a);
    vecAdd(pos,anim.P[temps_entier_ok],b);
    glTranslatef(pos.x,pos.y,pos.z);

    vecSub(c,anim.P[(cible+1)%anim.nbp],anim.P[cible]);
    vecNormalize(c);
    vecMul(d,poids,c);
    vecAdd(pos_suivante,anim.P[cible],d);
    vecSub(dir,pos_suivante,pos);
    vecNormalize(dir);
    vecInit(V,0,1,0);
    vecCross(codir,dir,V);
    float matrice[16]={dir.x,dir.y,dir.z,0,
                        0,1,0,0,
                        codir.x,codir.y,codir.z,0
                        ,pos.x,pos.y,pos.z,1};
    glMultMatrixf(matrice);
}

//************************************************************************
//************************************************************************
//INITIALISATION
void sceneInit(Scene& sc)
{
	animInit( sc.anim1, "data/anim1.ani" );
	animInit( sc.anim2, "data/anim2.ani" );
	animInit( sc.anim3, "data/anim3.ani" );

	imInitPPM(sc.arbre, "data/billboard/arbre.ppm");
	imInitPPM(sc.terrain, "data/terrain/terrain.ppm");
	imInitPPM(sc.cubemap, "data/cubemap/cubemap_BlueSkyRainbow.ppm");

    sc.tex_terrain = LoadGLTexture("data/terrain/terrain_mars.ppm", false/*, 230, 230, 230, LOADGLTEX_GREATER*/);
    sc.tex_arbre = LoadGLTexture("data/billboard/arbre_extra.ppm", true, 230, 230, 230, LOADGLTEX_GREATER);
    sc.tex_zerg = LoadGLTexture("data/lordo.ppm", true, 230, 230, 230, LOADGLTEX_GREATER);
    sc.tex_cubemap = LoadGLTexture("data/cubemap/mars.ppm", false, 230, 230, 230, LOADGLTEX_GREATER);
    sc.tex_mer = LoadGLTexture("data/mer.ppm", true, 230, 230, 230, LOADGLTEX_GREATER);
	sc.tex_fire = LoadGLTexture("data/feu.ppm", true, 100, 100, 100, LOADGLTEX_LOWER);
	sc.tex_meteore = LoadGLTexture("data/meteore.ppm", false, 100, 100, 100, LOADGLTEX_GREATER);
	sc.tex_metal = LoadGLTexture("data/metal.ppm", false, 100, 100, 100, LOADGLTEX_GREATER);
	sc.tex_metalS = LoadGLTexture("data/metalS.ppm", false, 100, 100, 100, LOADGLTEX_GREATER);
	sc.tex_bronze = LoadGLTexture("data/metal2.ppm", false, 100, 100, 100, LOADGLTEX_GREATER);
}
//************************************************************************
//************************************************************************
//ZERG

void draw_zerg()
{
	glPushMatrix();
        glRotatef(90,1,0,0);
        glRotatef(270,0,1,0);
        draw_carre();
	glPopMatrix();

}

//************************************************************************
//************************************************************************
//METEORE
void meteores(const Scene& sc)
{
    float t=50*temps();

    glRotatef(50,1,1,0);
    glTranslatef(0,70,0);
    glTranslatef(0,-t/10,0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, sc.tex_meteore);
    glScalef(2,2,2);
    draw_sphere2();
    glScalef(7,7,7);
    glTranslatef(-0.5,-0.3,0);
    glBindTexture( GL_TEXTURE_2D, sc.tex_fire );
    fire();
    glDisable(GL_TEXTURE_2D);
}

void explode()
{
    float t = temps();
if (t>13)
    {
    initParticles();
    dessinerParticules();
    }
}

//************************************************************************
//************************************************************************
//PARTICULES

double myRand(double min, double max)
{  return (double) (min + ((float) rand() / RAND_MAX * (max - min + 1.0)));
}
 int initParticles()
{   for(int i=0; i<MAX_PARTICLES; i++)   //Boucle sur toutes les particules
    {   particle[i].active = 1;       //Particule vivante
        particle[i].life = 1.0;   //Maximum de vie

        particle[i].fade = myRand(0.01,0.05);   //Vitesse de disparition aleatoire

        particle[i].r=0.36;
        particle[i].g=0.25;
        particle[i].b=0.20;

        particle[i].xi = myRand(-10.0,10.0);   //Vitesse aleatoire
        particle[i].yi = myRand(-10.0,10.0);
        particle[i].zi = myRand(10.0,20.0);

        particle[i].xg = 0.0;       //orientation gravite
        particle[i].yg = 0.0;
        particle[i].zg = -1.0;
    }
    return 0;
}

int dessinerParticules()
{   glPushMatrix();
    for(int i=0; i<MAX_PARTICLES; i++)
    {   if(particle[i].active)
        {   float x = particle[i].x;  //position
            float y = particle[i].y;
            float z = particle[i].z;

            // Couleur
            glColor4d(particle[i].r, particle[i].g, particle[i].b, particle[i].life);


            glPointSize(2.5);//taille point
            //antialiasing et gestionde la transparence
            glEnable(GL_BLEND);
            glEnable (GL_POINT_SMOOTH);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            glBegin (GL_POINTS);
                glVertex3f(x,y,z);
            glEnd ();


            // Deplacement
            particle[i].x += particle[i].xi/50;
            particle[i].y += particle[i].yi/50;
            particle[i].z += particle[i].zi/50;

            // Gravity
            particle[i].xi += particle[i].xg;
            particle[i].yi += particle[i].yg;
            particle[i].zi += particle[i].zg;

            //alive
            particle[i].life -= particle[i].fade;

            //if dead
            if (particle[i].life < 0.0)
            {   particle[i].life = 1.0;    // Maximum de vie
                particle[i].fade = myRand(0.01,0.05);

                particle[i].x = 0.0; // On renvoie la particule au centre
                particle[i].y = 0.0;
                particle[i].z = 0.0;

                particle[i].xi = myRand(-10.0,10.0);   // Vitesse aleatoire
                particle[i].yi = myRand(-10.0,10.0);
                particle[i].zi = myRand(10.0,20.0);

                particle[i].r=myRand(0.0,1.0);
                particle[i].g=myRand(0.0,1.0);
                particle[i].b=myRand(0.0,1.0);
            }
        }
    }
    glPopMatrix();
    return 0;
}



//************************************************************************
//************************************************************************

void draw_feuillage_base()
{
    glPushMatrix();
        glColor3f( 1 , 0.5, 0);
        int i; float a; int N=20;

        glBegin(GL_TRIANGLE_STRIP);//base
        for(i=0; i <= N ; i++)
        {
            a = 2.0*M_PI*i/N;
            glNormal3f(cos(a)/5,0,sin(a)/5);
            glVertex3f(cos(a)/5,0,sin(a)/5);
            glNormal3f(cos(a)/5,0,sin(a)/5);
            glVertex3f(cos(a)/5,0.3,sin(a)/5);

        }
        glEnd();
        glBegin(GL_TRIANGLE_STRIP);//haut
        for(i=0; i <= N ; i++)
        {
            a = 2.0*M_PI*i/N;
            glNormal3f(cos(a)/5,0,sin(a)/5);
            glVertex3f(cos(a)/5,0.3,sin(a)/5);
            glNormal3f(cos(a)/5,0,sin(a)/5);
            glVertex3f(cos(a)/8,0.4,sin(a)/8);

        }
        glEnd();
        glBegin(GL_TRIANGLE_FAN);//cercle haut
        for(i=0; i<N; i++)
          {
            a = 2.0*M_PI*i/N;
            glNormal3f(cos(a)/5,0,sin(a)/5);
            glVertex3f( cos(a)/8,0.4, sin(a)/8 );

          }
        glEnd();

        glBegin(GL_TRIANGLE_STRIP);//bas
        for(i=0; i <= N ; i++)
        {
            a = 2.0*M_PI*i/N;
            glNormal3f(cos(a)/5,0,sin(a)/5);
            glVertex3f(cos(a)/5,0,sin(a)/5);
            glNormal3f(cos(a)/5,0,sin(a)/5);
            glVertex3f(cos(a)/8,-0.1,sin(a)/8);

        }
        glEnd();

        glBegin(GL_TRIANGLE_FAN);//cercle bas
        for(i=0; i<N; i++)
          {
            a = 2.0*M_PI*i/N;
            glNormal3f(cos(a)/5,0,sin(a)/5);
            glVertex3f( cos(a)/8,-0.1, sin(a)/8 );

          }
        glEnd();
	glPopMatrix();


}

void draw_base_h()
{
    glPushMatrix();
        glColor3f( 0.89, 0.47, 0.20);
        int i; float a; int N=20;
        glScalef(0.3,0.3,0.3);
        glRotatef(15,0,0,1);
        glBegin(GL_TRIANGLE_STRIP);//base
        for(i=0; i <= N ; i++)
        {
            a = 2.0*M_PI*i/N;
            glNormal3f(cos(a)/5,0,sin(a)/5);
            glVertex3f(cos(a)/5,0,sin(a)/5);
            glNormal3f(cos(a)/5,0,sin(a)/5);
            glVertex3f(cos(a)/7,0.3,sin(a)/7);

        }
        glEnd();
     glPopMatrix();
}


void draw_base_b()
{
    glPushMatrix();
        glColor3f( 0.89, 0.47, 0.20);
        int i; float a; int N=20;
        glScalef(0.6,0.6,0.6);
        glBegin(GL_TRIANGLE_STRIP);//base
        for(i=0; i <= N ; i++)
        {
            a = 2.0*M_PI*i/N;
            glNormal3f(cos(a)/5,0,sin(a)/5);
            glVertex3f(cos(a)/5,0,sin(a)/5);
            glNormal3f(cos(a)/5,0,sin(a)/5);
            glVertex3f(cos(a)/10,0.2,sin(a)/10);

        }
        glEnd();
     glPopMatrix();
}


void draw_feuillage1()//droit
{
    glPushMatrix();
        glRotatef(-17,0,0,1);
        draw_feuillage_base();
        glTranslatef(0,-0.4,0);
        glScalef(0.5,0.5,0.5);
        glColor3f( 0.89, 0.47, 0.20);
        draw_cylinder();
    glPopMatrix();
}


void draw_feuillage2()//gauche
{
    glPushMatrix();
        glScalef(0.5,0.5,0.5);
        glRotatef(23,0,0,1);
        draw_feuillage_base();
        glTranslatef(0,-0.8,0);
        glScalef(0.5,1,0.5);
        glColor3f( 0.89, 0.47, 0.20);
        draw_cylinder();
    glPopMatrix();
}


void alien_tree()
{
    draw_feuillage1();
    glTranslatef(-0.3,0,0);
    draw_feuillage2();
    glTranslatef(0.2,-0.44,0);
    draw_base_h();
    glTranslatef(0,-0.1,0);
    draw_base_b();
}
//************************************************************************
//************************************************************************
//FORME COMPLEXE
void draw_branche(const Scene& sc)
{
    int i,j,k;
    float t= temps();

    glPushMatrix();//premier cylindre
        glColor3f( 1, 1, 1);
        glTranslatef( 0, 8, 0);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, sc.tex_metal);
        draw_cylinder3();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glColor3f(0.71, 0.65, 0.26);
    glTranslatef( 0, 8, 0);
    draw_cercle();
    glTranslatef( 0, 1, 0);
    glRotatef(-t*40*M_PI,0,1,0);
    for(i=0; i<3; i++)//reste branche
	    {
	      draw_cylinder();
	      glTranslatef( 0, 0.20, 0);

	      glPushMatrix();
              glRotatef(90,-1,0,0);
              draw_cylinder();
              glTranslatef( 0 ,1.9, 0);
              draw_sphere();
	      glPopMatrix();

	      glPushMatrix();
              glRotatef(90,1,0,0);
              draw_cylinder();
              glTranslatef( 0 ,1.9, 0);
              draw_sphere();
	      glPopMatrix();

	      glPushMatrix();
              glRotatef(90,0,0,-1);
              draw_cylinder();
              glTranslatef( 0 ,1.9, 0);
              draw_sphere();
	      glPopMatrix();

	      glPushMatrix();
              glRotatef(90,0,0,1);
              draw_cylinder();
              glTranslatef( 0 ,1.9, 0);
              draw_sphere();
	      glPopMatrix();

	      glTranslatef( 0, 1.7, 0);
	      draw_sphere();
	      glTranslatef( 0 , 0.9, 0);
	    }

    glPopMatrix();
//glPopMatrix();


}

void drone(const Scene& sc)
{
    float t = temps();
    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, sc.tex_bronze);
        glRotatef(90,0,0,1);
        glScalef(4.2,4.2,4.2);
        draw_sphere2();
        glEnable(GL_TEXTURE_2D);
    glPopMatrix();

    glRotatef(-t*10*M_PI,0,0,1);

    glPushMatrix();
        draw_branche(sc);
        glRotatef(180,0,0,1);
        glRotatef(t*40*M_PI,0,0,1);
        draw_branche(sc);
    glPopMatrix();
   }

void draw_flyingPen(const Scene& sc)
{

	glPushMatrix();
        glTranslatef(0,7.5,0);
        glScalef(0.5,3,0.5);
        glColor3f(0.71, 0.65, 0.26);
        draw_cone();
	glPopMatrix();


	glPushMatrix();
        glScalef(0.5,6,0.5);
        glTranslatef(0,0.25,0);
        glColor3f( 0.137255, 0.419608, 0.556863);
        draw_cylinder2();
	glPopMatrix();



	glPushMatrix();
        glScalef(1,3,1);
        glColor3f(0.71, 0.65, 0.26);
        draw_cone();
        glColor3f( 1,1,1);
    glPopMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture( GL_TEXTURE_2D, sc.tex_fire );
        glTranslatef(-1,-2,0);
        glScalef(2,3,2);
        fire();
        glDisable(GL_TEXTURE_2D);


}

//************************************************************************
//************************************************************************


void sceneDraw(const Scene& sc)
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glColor3f(1,1,1);

//cubemap
glPushMatrix();
	glScalef(180,180,180);
	glTranslatef(-0.5,-0.5,0.5);
	glEnable(GL_TEXTURE_2D);
	glBindTexture( GL_TEXTURE_2D, sc.tex_cubemap);
	draw_cubemap();
	glDisable(GL_TEXTURE_2D);
glPopMatrix();

//meteore
glPushMatrix();
    meteores(sc);
glPopMatrix();

//drone
glPushMatrix();
	glTranslatef(0,20,0);
	anima(sc.anim3,1);
    glRotatef(90,1,0,0);
    glPushMatrix();
    drone(sc);
    glPopMatrix();
glPopMatrix();

//fusee
glPushMatrix();
	glTranslatef(20,15,40);
	anima(sc.anim1,1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture( GL_TEXTURE_2D, sc.tex_metal );
    glRotatef(90,0,0,-1);
    glRotatef(90,0,1,0);
    glScalef(5,1,5);
    draw_flyingPen(sc);
    glDisable(GL_TEXTURE_2D);
glPopMatrix();

//zerg infestor
glPushMatrix();
	glTranslatef(-90,-10,-90);
	glEnable(GL_TEXTURE_2D);
    glBindTexture( GL_TEXTURE_2D, sc.tex_zerg );
	glPushMatrix();
	glTranslatef(90,5+getPixConst(sc.terrain,90,90)/10,90)	;
	glRotatef(90,1,0,0);
	glRotatef(270,0,1,0);
	glScalef(10,10,15);
	draw_carre();
glPopMatrix();

//terrain
    glBindTexture( GL_TEXTURE_2D, sc.tex_terrain );
	draw_terrain(sc.terrain);
	glDisable(GL_TEXTURE_2D);
    srand(1500);

//forest
	for(int i=0;i<300;i++)
	{
		glPushMatrix();
            float y=rand()%190;
            float x=rand()%190;
            glTranslatef(x,2+getPixConst(sc.terrain,x,y)/10,y);
            glScalef(2,4,2);
            alien_tree();
		glPopMatrix();
	}

	glPopMatrix();


//explosion
glPushMatrix();
    glTranslatef(0,4,0);
    explode();
glPopMatrix();
    glFlush();


//mer
glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture( GL_TEXTURE_2D, sc.tex_mer );
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4ub(255,255,255,100);
    mer();
    glDisable(GL_TEXTURE_2D);
glPopMatrix();
 }
