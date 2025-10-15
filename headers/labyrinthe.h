/** 
 * @file labyrinthe.h
 * @author QACH Yahya
 * @date 5 Octobre 2025
 * @brief Fichier de declaration des prototypes des fonctions de gestion du labyrinthe, 
          l'implémentation de ces fonctions se trouve deans le fichier src/labyrinthe.c .
*/

/**
 * @brief crée un labyrinthe parfait de taille ligns x colonnes
 * @param lignes le nombre de lignes
 * @param colonnes le nombre de colonnes
 * @return un objet labyrinthe parfait de taille lignes x colonnes contenant la grille du labyrinthe et les dimensions
 */
labyrinthe creer_labyrinthe(int lines,int colonnes, char* nom);

void place_something(labyrinthe lab,int value,int number);

/**
 * @brief initialise la grille
 * @param lignes le nombre de lignes
 * @param colonnes le nombre de colonnes
 * @return une grille initialisée avec des murs et des cellules non connectées
 */
int** init_grille(int lignes,int colonnes);

/**
 * @brief affiche une matrice donnée sous forme de labyrinthe (valeurs numériques -> des chars)
 * @param lignes le nombre de lignes
 * @param colonnes le nombre de colonnes
 * @param la grille à représenter qui contient des valeurs numériques
 */
void afficher_labyrinthe(int** matrix,int lignes,int colonnes);

/**
 * @brief affiche un vectuer donné sous forme de labyrinthe (valeurs numériques -> des chars)
 * @param taille la taille du tableau
 * @param le tableau à représenter qui contient des valeurs numériques
 */
void display_vector_as_char(int * vector,int taille);

/**
 * @brief génère un labyrinthe parfait en utilisant l'algorithme de fusions aléatoire de chemins
 * @param la grille intialisée avec des murs et des céllules (la résultante de la fct init_grille)
 * @param lignes le nombre de lignes
 * @param le nombre de colonnes
 */
void init_maze(int** matrix,int lignes,int colonnes);

