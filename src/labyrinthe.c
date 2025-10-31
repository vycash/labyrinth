/**
* @author QACH Yahya
* @date 5 Octobre 2025
* @file labyrinthe.c
* @brief Implementation des fonctions de gestion du labyrinthe
*/

#include "includes.h"


labyrinthe creer_labyrinthe(int lignes,int colonnes, char* nom){
    int** res = init_grille(lignes,colonnes);
    init_maze(res,lignes,colonnes);
    
    labyrinthe lab = {lignes,colonnes,res,nom};

    place_something(lab,KEY,1); // placer la clé
    place_something(lab,PIEGE,NB_DE_PIEGES); // placer les pièges
    place_something(lab,TRESOR,NB_DE_TRESOR); // placer les trésors

    enregister_labyrinthe(lab);
    
    return lab;
}


void place_something(labyrinthe lab,int value,int number){

    int lignes=lab.lignes;
    int colonnes=lab.colonnes;

    int count=0;
    srand(time(NULL));

    while( count < number ){
        int x = rand() % lignes;
        int y = rand() % colonnes;
        if( x >= 1 && x <= lignes-1 && y >= 1 && y <= colonnes-1 && lab.grille[x][y] > 0){
            lab.grille[x][y]=value;
            count++;
        }
    }
}

/**
 * @brief initialise la grille
 * @return une grille initialisée avec des murs et des cellules non connectées
 */
int** init_grille(int lignes, int colonnes){
    int** matrix = allocate_matrix(lignes,colonnes,MUR);
    int count=1;
    
    for( int i=1 ; i<lignes-1 ; i++){
        for( int j=1 ; j<colonnes-1 ; j++ ){
            if ( j%2 == 1 && i%2 == 1){
                matrix[i][j]=count;
                count++;
            }
        }
    }
    matrix[0][1]=JOUEUR_ID; // mettre le joueur à la case 0,1
    matrix[lignes-1][colonnes-2]=SORTIE; // mettre la sortie tout en bas à droite avent le mur
    return matrix;

}

void afficher_labyrinthe(int** matrix,int lignes,int colonnes){
    printf("\n");
    for( int i=0 ; i<lignes ; i++ ){
        display_vector_as_char(matrix[i],colonnes);
    }
}

void display_vector_as_char(int * vector, int dimension){
    for( int i=0 ; i<dimension ; i++ ){
        switch( vector[i] ){
            case MUR:
                printf("[#]");
                break;
            case JOUEUR_ID:
                printf("%s o %s",ANSI_COLOR_BLUE,ANSI_RESET_ALL);
                break;
            case SORTIE:
                printf("%s---%s",ANSI_COLOR_GREEN,ANSI_RESET_ALL);
                break;
            case KEY:
                printf("%s k %s",ANSI_COLOR_GOLD,ANSI_RESET_ALL);
                break;
            case TRESOR:
                printf("%s + %s",ANSI_COLOR_GREEN,ANSI_RESET_ALL);
                break;
            case PIEGE:
                printf("%s * %s",ANSI_COLOR_RED,ANSI_RESET_ALL);
                break;
            default:
                printf("   ");
        }
    }
    printf("\n");
}


// Fusionne tous les identifiants du chemin2 vers chemin1
void fusionner(int **matrix, int id_source, int id_cible,int lignes,int colonnes) {
    for (int i = 1; i < lignes - 1; i++) {
        for (int j = 1; j < colonnes - 1; j++) {
            if (matrix[i][j] == id_cible) {
                matrix[i][j] = id_source;
            }
        }
    }
}

// Initialisation du labyrinthe parfait
void init_maze(int **matrix,int lignes,int colonnes) {
    // Liste des murs internes exclu les murs externes
    int murs_max = ((lignes - 1) * (colonnes - 1));
    Mur *murs = malloc(murs_max * sizeof(Mur));
    int murs_count = 0;

    // Ajouter tous les murs horizontaux et verticaux entre les cellules
    for (int i = 1; i < lignes - 1; i += 2) {
        for (int j = 1; j < colonnes - 1; j += 2) {
            // Mur horizontal (à droite)
            if (j + 2 < colonnes - 1) {
                murs[murs_count++] = (Mur){i, j, i, j + 2};
            }
            // Mur vertical (en bas)
            if (i + 2 < lignes - 1) {
                murs[murs_count++] = (Mur){i, j, i + 2, j};
            }
        }
    }

    // Mélanger les murs de façon aléatoire
    srand(time(NULL));
    for (int i = murs_count - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Mur temp = murs[i];
        murs[i] = murs[j];
        murs[j] = temp;
    }

    // Pour chaque mur, ouvrir si les identifiants des céllules qu'il sépare sont différents
    for (int k = 0; k < murs_count; k++) {

        // récupère les coordonnées de la 1ère cellule séparée par le mur
        int x1 = murs[k].x1;
        int y1 = murs[k].y1;

        // récupère les coordonnées de la 2eme cellule séparée par le mur
        int x2 = murs[k].x2;
        int y2 = murs[k].y2;

        // récupération des identifiants des céllules qu'il sépare
        int id1 = matrix[x1][y1];
        int id2 = matrix[x2][y2];

        // si ces deux céllules ont deux identifiants différents càd qu'ils ne sont pas reliées alors on les relies en ouvrant le mur
        if (id1 != id2) {
            // Ouvrir le mur (mettre id1 entre les deux cellules pour l'afficher comme ' ' )
            matrix[(x1 + x2) / 2][(y1 + y2) / 2] = id1;

            // Fusionner les chemins
            fusionner(matrix, id1, id2,lignes,colonnes);
        }
    }

    free(murs);
}


