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
 * Un par sa grille, et les dimensions de cette grille.
 */
typedef struct{
    int lignes;
    int colonnes;
    int** grille;
} labyrinthe;


typedef struct{
    int x_offset;
    int y_offset;
} direction;

typedef struct{
    int id;
    int a_cle;
    int score;
    int x;
    int y;
} joueur;