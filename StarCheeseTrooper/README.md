# Starcheese Trooper

Implémentation d'un jeu vidéo 2D en C avec la bibliothèque SDL


Le but du jeu est de naviguer dans différentes salles
composant un niveau, en tuant les ennemis, en
récupérant des clés (et en restant en vie!) jusqu'à
atteindre le final du niveau

* Fromage.[hc]  
  * Contient la structure du personnage  
  * Les fonctions de déplacements et des  
accesseurs/mutate

* Jeu.[hc]  
  * Contient les structures des projectiles, du tableau
dynamique ainsi que celle du jeu  
  * Elle contient toutes les fonctions de gestions des
projectiles (initialisation, déplacement, hitbox ..ect)...  
  * … les fonctions de gestion de tableau dynamique...  
  * … ainsi que JeuEvolue et JeuActionClavier qui sont
la base du système d'action du jeu   

* Terrain.[hc]  
  * Contient les structures des ennemis, ainsi qu'un
structure d'arbre à 4 branches pour la gestion des
salles (+ la structures terrain pour pointer la salle
actuelle)  
  * Contient l'IA des ennemis, ainsi que les fonctions de
gestion de la map  

* SdlJeu.[hc]  
  * Contient la structure SdlJeu qui prends en
paramètres l'entièreté des variables SDL
(SDL_Surface, SDL_Rec, Mix_Music..ect)  
  * Elle contient les fonctions d'interface du jeu (menu),
la fonction sdlJeuBoucle qui permet la gestion des
évènements via un tableau de caractères contenant
la totalité des touches SDL  
  * C'est également dans cette fonction que se fait tout
l'affichage et la gestion graphique de notre jeu   
