/**
* @author QACH Yahya
* @date 5 Octobre 2025
* @file game_handler.h
* @brief Implementation des fonctions de gestion du jeu et le joueur et les differents objets dans le labyrinthe
*/

/**
 * @brief fonction qui gère la boucle principale du jeu.
 * demande à l'utilisateur en boucle de saisir un charactère correspondant à un mouvement, puis appelle la fonction
 * qui effectue le mouvement du joueur dans le labyrinthe.
 * la boucle du jeu continue à tourner jusqu'a que le joueur atteint la sortie.
 * à la fin de la boucle si le joueur a un score parmi les 10 meilleur, le programme lui demande de saisir son nom
 * et enregistre son score dans le fichier de score correspondant au labyrinthe
 * @param labyrinth le labyrinthe sur lequel se déroulera le jeu
*/
void jouer(labyrinthe labyrinth);

/**
 * @brief fonction qui vérifie si le joueur a atteint la sortie du labyrinthe
 * @param labyrinth le labyrinthe sur lequel on veut vérifier que le joueur a gagné
 * @return 1 si le joueur est bien sur la case de sortie, 0 sinon
*/
int verifier_victoire(labyrinthe labyrinth);

/**
 * @brief vérifie si un score donné est parmi les NB_DE_RESULTATS meilleurs
 * @param score le score que l'on veut savoir s'il est parmi les meilleurs
 * @param nom_labyrinth le labyrinth sur lequel on va vérifier si score est parmi les meilleurs scores de ce labyrinthe
 * @return 1 si le score est parmi les meilleurs, 0 sinon
 * @see constants.h
*/
int score_parmi_meilleurs(int score,char* nom_labyrinthe);

/**
 * @brief fonction qui place un objet d'identifiant ID dans la case de coordonnées x,y dans le labyrinthe lab
 * @param lab le labyrinthe sur lequel on souhaite placer l'objet
 * @param sujet_id l'identifiant de l'objet que l'on veut placer
 * @param x la coordonnée de lignes
 * @param y la coordonnée de colonnes
 * @return 1 si l'objet a été bien placé aux coordonnées x,y, 0 sinon
*/
int placer(labyrinthe lab,int sujet_id,int x,int y);

/**
 * @brief déplace le joueur d'un pas dans une direction donnée
 * @param player l'objet joueur que l'on utlisera pour stocker les coordonnées actuelles du joueur
 * @param lab le labyrinthe sur lequel on déplace le joueur
 * @param d la direction sur laquelle on souhaite déplacer le joueur
 * @return 1 si le déplacement a été bien effectué, 0 sinon
*/
int deplacer_joueur(joueur* player,labyrinthe lab,direction d);

/**
 * @brief deplace le joueur sur le labyrinthe vers le haut
 * @param j l'objet joueur que l'on utlisera pour stocker les coordonnées actuelles du joueur
 * @param lab le labyrinthe sur lequel on déplace le joueur
 * @return 1 si le déplacement a été bien effectué, 0 sinon
*/
int deplacer_joueur_haut(joueur* j,labyrinthe lab);

/**
 * @brief deplace le joueur sur le labyrinthe vers le bas
 * @param j l'objet joueur que l'on utlisera pour stocker les coordonnées actuelles du joueur
 * @param lab le labyrinthe sur lequel on déplace le joueur
 * @return 1 si le déplacement a été bien effectué, 0 sinon
*/
int deplacer_joueur_bas(joueur* j,labyrinthe lab);

/**
 * @brief deplace le joueur sur le labyrinthe vers la droite
 * @param j l'objet joueur que l'on utlisera pour stocker les coordonnées actuelles du joueur
 * @param lab le labyrinthe sur lequel on déplace le joueur
 * @return 1 si le déplacement a été bien effectué, 0 sinon
*/
int deplacer_joueur_droite(joueur* j,labyrinthe lab);

/**
 * @brief deplace le joueur sur le labyrinthe vers la gauche
 * @param j l'objet joueur que l'on utlisera pour stocker les coordonnées actuelles du joueur
 * @param lab le labyrinthe sur lequel on déplace le joueur
 * @return 1 si le déplacement a été bien effectué, 0 sinon
*/
int deplacer_joueur_gauche(joueur* j,labyrinthe lab);
