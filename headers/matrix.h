/** 
 * @file matrix.h
 * @author QACH Yahya
 * @date 5 Octobre 2025
 * @brief Fichier de declaration des prototypes des fonctions de gestion de matrice/tableaux, 
          l'implémentation de ces fonctions se trouve deans le fichier src/matrix.c.
*/


/** @brief affiche un vecteur.
 * @param vector le vecteur a afficher
 * @param dimension la taille du vecteur à afficher
 */
void display_vector(int * vector, int dimension);



/** @brief fonction qui affiche une matrice
 * @param matrix la matrice à afficher
 * @param lines le nb de lignes de la matrice
 * @param columns le nb de colonnes de la matrice
*/
//La fonction display_matrix utilisera la fonction display_vector.
void display_matrix(int ** matrix, int lines, int columns);



/** @brief fonction qui alloue la mémoire d'un tableau de taille donnée
           et initialise ses cases à une valeur donnée 
 * @param dimension la taille du tableau à allouer
 * @param val la valeur à laquelle seront initialisé toutes les cases du tab
 * @return renvoie un tableau/vecteur de taille dimension où toutes les céllules sont initialisées à la valeur val
*/
int * allocate_vector(int dimension, int val);



/** @brief fonction qui libère la mémoire allouée pour le tableau à une dimension vector :
 * @param vector le tableau à libérer
*/
void free_vector(int * vector);



/** @brief fonction qui alloue la mémoire d'une matrice de taille lines * columns, puis qui
l'initialise à la valeur val
 * @param lines le nb de lignes de la matrice à allouer
 * @param columns le nb de colonnes de la matrice à allouer
 * @param val la valeur à initialiser toutes les cases de la matrice
 * @return renvoie un tableau de tableau/Matrice de taille lines x columns où toutes 
           les céllules sont initialisées à la valeur val
*/
int ** allocate_matrix(int lines, int columns, int val);



/** @brief fonction qui génère une matrice identité en utilisant une simple boucle
 * @param dimension la dimension de la matrice identité à générer
 * @return renvoie une matrice identité de taille dimension
*/
int ** generate_identity_matrix(int dimension);



/** @brief fonction qui libère la matrice matrix de dimensions n
 * @param matrix la matrice à libérer
 * @param n dimension de la matrice à libérer
*/
void free_matrix(int ** matrix, int n);