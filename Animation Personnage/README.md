# TP Animation Personnage

Implémentation de l'animation de déplacement d'un personnage et de sa gestion de collision avec d'autres objets en C++ avec la librairie Gkit (une surcouche d'OpenGL)

### Code:
* Classe Skeleton : tableau de toutes les articulations (SkeletonJoint) du squelette, pour chaque articulation stocke l'identifiant de l'articulation parent.
* Classe CharAnimController : contrôle le déplacement du personnage à partir du clavier et a pour paramètres la position ett la vitesse de l'objet  à déplacer.

### Interpolation entre les différents mouvements d'un personnage
<img src="https://github.com/Gwen-Ielpo/Portfolio/blob/master/Animation%20Personnage/data/charanim_interpolation.png" width="500" height="300" />

### Gestion de la collision avec des balles
<img src="https://github.com/Gwen-Ielpo/Portfolio/blob/master/Animation%20Personnage/data/charanim_ball.png" width="500" height="300" />
