/** 
 * @file file_handling.h
 * @author QACH Yahya
 * @date 5 Octobre 2025
 * @brief fichier qui déclare les prototypes des fcts qui gèrent l'ecriture et la lecture des fichiers contenant les labyrinthes.
*/

/**
 * @brief formate le nom du labyrinthe en un chemin relatif cers le fichier contenant le labyrinthe
 * @param nom le nom du labyrinthe
 * @return le chemin du fichier contenant le labyrinthe
*/
char* format_name(char* nom,char* dir_name,char* extension);


/**
 * @brief enregistre un labyrinthe en format texte dans un fichier
 * le fichier est nommé <nom_labyrinthe.cfg> si il n'existe pas il est créé puis modifié
 * les deux premières lignes indiquent respectivement le nb de lignes et le nb de colonnes
 * @param matrix le labyrinthe à enregistrer
 * @param lignes le nb de lignes du labyrinthe
 * @param colonnes le nb de colonnes du labyrinthe
 * @param nom le nom du labyrinthe à enregistrer
 */
void enregister_labyrinthe(labyrinthe lab);

/**
 * @brief charge un labyrinthe de son nom
 * la fct cherche le fichier correspondant du labyrinthe et lit son contenu pour reconstruire le labyrinthe et le renvoie
 * @param nom le nom du labyrinthe que l'ont veut charger
 * @return la labyrinthe chargé en mémoire sous forme de matrice
*/
labyrinthe charger_labyrinthe(char* nom);


/**
 * @brief renvoie la taille d'un labyrinthe enregistré dans un fichier (lignes,colonnes)
 * @param nom le nom du labyrinthe que l'ont veut savoir sa taille
 * @return un tableau de deux elements contenant respectivement [lignes,colonnes]
*/
int* taille_labyrinthe(char* nom);


int afficher_labyrinthes_disponibles();
void enregistrer_score(char* nom_labyrinthe,char* nom_joueur,int score);
int* get_best_scores(char* nom_labyrinthe,int nb_de_resultats);
void afficher_meilleurs_scores(char* nom_labyrinthe);