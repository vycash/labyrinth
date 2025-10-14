/** 
 * @file file_handling.h
 * @author QACH Yahya
 * @date 5 Octobre 2025
 * @brief fichier qui implémente les fcts qui gèrent l'ecriture et la lecture des fichiers contenant les labyrinthes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#include "constants.h"
#include "structures.h"

#include "file_handling.h"
#include "matrix.h"
#include "labyrinthe.h"


FILE *open_file(char* file_name,char *mode) {
    FILE *file = fopen(file_name, mode);
    if (file == NULL) {
        printf("Error: impossible d'ouvrir le fichier <%s>\n", file_name);
        return NULL;
    }
    return file;
}

char* format_name(char* nom){
    char* filename = malloc(BUFFER_SIZE*sizeof(char));
    snprintf(filename, BUFFER_SIZE, "%s/%s.%s", DOSSIER,nom,EXTENSION);
    return filename;
}

void enregister_labyrinthe(labyrinthe lab,char* nom){
    
    int** matrix = lab.grille;
    int lignes = lab.lignes;
    int colonnes = lab.colonnes;

    char* filename= format_name(nom);
    FILE* file = fopen(filename, "w"); 
    
    if (file != NULL) { 

        fprintf(file,"%d\n",lignes);
        fprintf(file,"%d\n",colonnes);

        for( int i=0 ; i<lignes ; i++){
            for( int j=0 ; j<colonnes ; j++){
                fprintf(file,"%d,",matrix[i][j]);
            }   
            fprintf(file,"\n");
        }

        fclose(file);
    }        
    free(filename);
}

labyrinthe charger_labyrinthe(char* nom){

    char* filename= format_name(nom);
    FILE* file = fopen(filename, "r"); 
    if (!file) { free(filename); return (labyrinthe){0,0,NULL}; }

    int lignes,colonnes;
    fscanf(file,"%d",&lignes);
    fscanf(file,"%d",&colonnes);

    int** grille=allocate_matrix(lignes,colonnes,0);

    for(int i=0 ; i<lignes ; i++){
        for(int j=0 ; j<colonnes ; j++){
            fscanf(file,"%d,",&grille[i][j]); // pcq on a ecrit les valeurs séparées par une virgule
        }
    }

    free(filename);
    fclose(file);
    //return grille;
    return (labyrinthe) { lignes,colonnes,grille };
}

void afficher_labyrinthes_disponibles() {
    DIR *dir;
    struct dirent *ent;

    dir = opendir(DOSSIER);
    if (dir == NULL) {
        printf("Erreur : impossible d'ouvrir le dossier des labyrinthes.\n");
        return;
    }

    printf("Labyrinthes disponibles :\n");
    int count = 0;
    while ((ent = readdir(dir)) != NULL) {
        // Vérifie l'extension
        size_t len = strlen(ent->d_name);
        size_t ext_len = strlen(EXTENSION);
        if (len > ext_len + 1) { // Ex : "abc.cfg" >= 5
            if (strcmp(ent->d_name + len - ext_len, EXTENSION) == 0 && ent->d_name[len - ext_len - 1] == '.') {
                // Affiche le nom sans le .cfg
                char lab_name[256];
                strncpy(lab_name, ent->d_name, len - ext_len - 1);
                lab_name[len - ext_len - 1] = '\0';
                printf("- %s\n", lab_name);
                count++;
            }
        }
    }
    if (count == 0) printf("(Aucun labyrinthe trouvé)\n");
    closedir(dir);
}

