/** 
 * @file file_handling.h
 * @author QACH Yahya
 * @date 5 Octobre 2025
 * @brief fichier qui déclare les prototypes des fcts qui gèrent l'ecriture et la lecture des fichiers contenant les labyrinthes.
*/

/**
 * @brief ouvre un fichier selon le mode donné en parametres (lecture/ecriture)
 * @param file_name le nom du fichier à ouvrir
 * @param mode le mode d'ouverture du fichier (lecture/ecriture)
 * @return un pointeur su fichier
 */
FILE *open_file(char* file_name,char *mode);

/**
 * @brief formate le nom du labyrinthe en un chemin relatif cers le fichier contenant le labyrinthe
 * @param nom le nom du labyrinthe
 * @return le chemin du fichier contenant le labyrinthe
*/
char* format_name(char* nom);


/**
 * @brief enregistre un labyrinthe en format texte dans un fichier
 * le fichier est nommé <nom_labyrinthe.cfg> si il n'existe pas il est créé puis modifié
 * les deux premières lignes indiquent respectivement le nb de lignes et le nb de colonnes
 * @param matrix le labyrinthe à enregistrer
 * @param lignes le nb de lignes du labyrinthe
 * @param colonnes le nb de colonnes du labyrinthe
 * @param nom le nom du labyrinthe à enregistrer
 */
void enregister_labyrinthe(labyrinthe lab,char* nom);


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


void afficher_labyrinthes_disponibles();