# TP Animation Physique

Implémentation de lois physiques sur un tissu (friction, gravité, ressort et équilibre) en C++ avec la librairie Gkit (une surcouche d'OpenGL).

### Code
* data/textures : pour placer des textures  
* data/CreateMesh : programme pour créer des maillages de tissu ou convertir des fichiers .obj .off en fichiers pour l'application  
* data/drap70 : fichiers de données d'un tissu de 70 * 70 particules  

Dans data/drap70:
* faceset.eti : définition des facettes triangulaires de l'objet  
* masses.eti : définition des masses associées aux sommets de l'objet  
* points.eti : définition des coordonnées (x,y,z) des sommets de l'objet  
* texcoord.eti : définition des coordonnées de textures des sommets de l'objet  

Dans src-etudiant:  
* ObjetSimuleMSS : Affichage du drap, calcul de la force de gravité et d'accélération, calcul des vitesses et des positions  
* CalculsMSS : calcul des forces des ressorts  

#### Dans gkit2light/master_meca_sim/exec/:
Fichier_Param.simu : paramètres de la simulation - gravité, viscosité, nb itérations
Fichier_Param.objet : paramètres de l'objet simulé - données, k, nu, dt, etc.

### Affichage tissu plein
<img src="https://github.com/Gwen-Ielpo/Portfolio/blob/master/Animation%20Physique/data/tissu-plein.jpg" width="500" height="300" />

### Affichage en fil de fer
<img src="https://github.com/Gwen-Ielpo/Portfolio/blob/master/Animation%20Physique/data/wire.jpg" width="500" height="300" />
