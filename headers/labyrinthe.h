/** 
 * @file labyrinthe.h
 * @author QACH Yahya
 * @date 5 Octobre 2025
 * @brief Fichier de declaration des prototypes des fonctions de gestion du labyrinthe, 
          l'implémentation de ces fonctions se trouve deans le fichier src/labyrinthe.c .
*/

/**
 * @brief crée un labyrinthe parfait de taille lignes x colonnes

 * @param lignes    le nombre de lignes
 * @param colonnes  le nombre de colonnes
 * @param nom       le nom du labyrinthe que l'on souhaite créer
 * @return un objet labyrinthe parfait de taille lignes x colonnes contenant la grille du labyrinthe et les dimensions
 */
labyrinthe creer_labyrinthe(int lignes,int colonnes, char* nom);

/**
 * @brief place dans le labyrinthe un nombre d'occurences d'un objet dans des cases aléatoires

 * @param lab       le labyrinthe dans lequel on veut placer l'objet
 * @param value     l'identifiant de l'objet à placer dans le labyrinthe
 * @param number    le nombre d'occurences de l'objet que l'on veut placer
*/
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
 *
 * @param matrix    la grille à représenter qui contient des valeurs numériques
 * @param lignes    le nombre de lignes
 * @param colonnes  le nombre de colonnes
 */
void afficher_labyrinthe(int** matrix,int lignes,int colonnes);

/**
 * @brief affiche un vectuer donné sous forme de labyrinthe (valeurs numériques -> des chars)
 * @param vector le tableau à représenter qui contient des valeurs numériques
 * @param taille la taille du tableau
 */
void display_vector_as_char(int * vector,int taille);

/**
 * @brief génère un labyrinthe parfait en utilisant l'algorithme de fusions aléatoire de chemins
 *
 * @param matrix    la grille intialisée avec des murs et des céllules (la résultante de la fct init_grille)
 * @param lignes    le nombre de lignes
 * @param colonnes  le nombre de colonnes
 */
void init_maze(int** matrix,int lignes,int colonnes);

/**
 * @brief libère le labyrinthe de la mémoire
 * effectue un free de la grille du labyrinthe ainsi que son nom
 *
 * @param lab le labyrinthe que l'on souhaite libérer de la mémoire
 */
void free_labyrinth(labyrinthe lab);

