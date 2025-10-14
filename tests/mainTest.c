#include "constants.h"
#include "structures.h"

#include "minunit.h"
#include "file_handling.h"
#include "labyrinthe.h"
#include "matrix.h"
#include "game_handler.h"

static int lignes = 3;
static int colonnes = 3;
static char nom[] = "minunit_lab";

MU_TEST(test_init_grille) {
    int **mat = allocate_matrix(5, 5, -1);
    
    // Remplissage de la matrice
    int val = 1;
    for (int i = 1; i < 5; i+=2){
        for (int j = 1; j < 5; j+=2){
            mat[i][j] = val++;
        }
    }
    mat[0][1]=0;
    mat[4][3]=-2;

    int** mat2 = init_grille(5,5);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            mu_assert_int_eq(mat[i][j], mat2[i][j]);

    free_matrix(mat,5);
    free_matrix(mat2,5);
}

MU_TEST(test_write_and_read_labyrinthe) {
    int **mat = allocate_matrix(lignes, colonnes, 0);

    // Remplissage de la matrice
    int val = 1;
    for (int i = 0; i < lignes; i++){
        for (int j = 0; j < colonnes; j++){
            mat[i][j] = val++;
        }
    }

    // Ecriture
    enregister_labyrinthe((labyrinthe){lignes, colonnes,mat}, nom);

    // Lecture
    labyrinthe l= charger_labyrinthe(nom);
    int** mat2 = l.grille;

    mu_assert_int_eq(lignes, l.lignes);
    mu_assert_int_eq(colonnes, l.colonnes);

    for (int i = 0; i < lignes; i++)
        for (int j = 0; j < colonnes; j++)
            mu_assert_int_eq(mat[i][j], mat2[i][j]);

    free_matrix(mat, lignes);
    free_matrix(mat2, l.lignes);
}

MU_TEST(test_placer){
    int** mat = init_grille(5,5);
    init_maze(mat,5,5);
    labyrinthe lab = {5,5,mat};
    // Initialiser le joueur à la position de départ du labyrinthe
    joueur j = JOUEUR;

    int mouvement = placer(lab,0,1,1);
    mu_assert_int_eq(mouvement, 1);
    mu_assert_int_eq(mat[1][1], 0); // Le joueur doit être à sa nouvelle position

    free_matrix(mat,5);    
}

MU_TEST(test_movement){
    int** mat = init_grille(5,5);
    init_maze(mat,5,5);
    labyrinthe lab = {5,5,mat};
    // Initialiser le joueur à la position de départ du labyrinthe
    joueur j = JOUEUR;

    int mouvement = deplacer_joueur(&j, lab, BAS);
    mu_assert_int_eq(mouvement, 1);
    mu_assert_int_eq(mat[1][1], 0); // Le joueur doit être à sa nouvelle position

    free_matrix(mat,5);
}

MU_TEST(test_movement_bas) {
    int** mat = init_grille(5,5);
    init_maze(mat,5,5);
    labyrinthe lab = {5,5,mat};
    // Initialiser le joueur à la position de départ du labyrinthe
    joueur j = JOUEUR;

    int mouvement = deplacer_joueur_bas(&j, lab);
    mu_assert_int_eq(mouvement, 1);
    mu_assert_int_eq(mat[1][1], 0); // Le joueur doit être à sa nouvelle position

    free_matrix(mat,5);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_write_and_read_labyrinthe);
    MU_RUN_TEST(test_init_grille);
    MU_RUN_TEST(test_placer);
    MU_RUN_TEST(test_movement);
    MU_RUN_TEST(test_movement_bas);
}

int main() {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}