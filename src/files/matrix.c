/** 
* @author QACH Yahya
* @date 5 Octobre 2025
* @file matrix.c
* @brief Implémentation des fonctions de gestion de matrice/tableaux
*/

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// Revoir le fichier matrix.h pour la documentation des fonction définies dans ce fichier

// afficher un tableau
void display_vector(int * vector, int dimension){
    printf("[ ");
    for( int i=0 ; i<dimension ; i++ ){
        printf("%d ",vector[i]);
    }
    printf("]\n");
}

// afficher une matrice
void display_matrix(int ** matrix, int lines, int columns){
    for( int i=0 ; i<lines ; i++ ){
        display_vector(matrix[i],columns);
    }
}


// alloue la mémoire d'un tableau et initialise toutes les cases à la valeur val
int * allocate_vector(int dimension, int val){
    int* res = malloc(dimension*sizeof(int));
    for ( int i=0 ; i<dimension ; i++ ){
        res[i] = val;
    }
    return res;
}

// libère la mémoire allouée pour un vecteur
void free_vector(int * vector){
    if( vector != NULL ){
        free(vector);
    }
}

// alloue la mémoire pour une matrice de taille columns * lines
int ** allocate_matrix(int lines, int columns, int val){
    int** res = malloc(lines*sizeof(int*));
    for( int i=0 ; i<lines ; i++ ){
        res[i] = allocate_vector(columns,val);
    }
    return res;
}

// génére une matrice identité
int ** generate_identity_matrix(int dimension){
    int** matrix = allocate_matrix(dimension,dimension,0);
    for( int i=0 ; i<dimension ; i++){
        matrix[i][i] = 1;
    }
    return matrix;
}


// libère la mémoire allouée pour la matrice
void free_matrix(int ** matrix, int n){
    if( matrix != NULL ){
        for( int i=0 ; i<n ; i++ ){
            free_vector(matrix[i]);
        }
        free(matrix);
    }
}





