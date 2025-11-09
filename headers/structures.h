/** 
 * @brief Définition de la structure d'un mur pour l'initialisation du labyrinthe.
 * Un mur est défini par les deux céllules qu'il sépare
 */
typedef struct {
    int x1, y1; /** <coordonnées de la première cellule> */
    int x2, y2; /** <coordonnées de la seconde cellule> */
} Mur;

/** 
 * @brief Définition de la structure d'un labyrinthe.
 * la grille du labyrinthe est une grille de valeurs entières, ces valeurs sont les identifiants
 * des différents objets du jeu
 * @see constants.h pour voir les différents identifiants des objets
 * @struct labyrinthe 
 */
typedef struct{
    
    /** @brief le nombre de lignes du labyrinthe */
    int lignes; 
    
    /** @brief le nombre de colonnes du labyrinthe */
    int colonnes;

    /** @brief la grille du labyrinthe */
    int** grille;

    /** @brief le nom du labyrinthe */
    char* nom;

} labyrinthe;

/**
 * @brief structure definissant une direction de mouvement
*/
typedef struct{
    int x_offset;
    int y_offset;
} direction;

/**
 * @brief structure definissant un joueur
*/
typedef struct{
    /** @brief l'identifiant du joueur */
    int id;

    /** @brief booleen definissant si le joueur a la clé ou pas */
    int a_cle;

    /** @brief le score actuel du joueur  */
    int score;

    /** @brief les coordonnées du joueur */
    int x,y;
} joueur;