/** 
 * @file file_handling.h
 * @author QACH Yahya
 * @date 5 Octobre 2025
 * @brief fichier qui implémente les fcts qui gèrent l'ecriture et la lecture des fichiers contenant les labyrinthes.
*/

#include "includes.h"

char* format_name(char* nom,char* dir_name,char* extension){
    char* filename = malloc(BUFFER_SIZE*sizeof(char));
    snprintf(filename, BUFFER_SIZE, "%s/%s.%s", dir_name,nom,extension);
    return filename;
}

void enregister_labyrinthe(labyrinthe lab){
    
    int** matrix = lab.grille;
    int lignes = lab.lignes;
    int colonnes = lab.colonnes;

    char* filename= format_name(lab.nom,DOSSIER_MAPS,MAP_EXTENSION);
    FILE* file = fopen(filename, "w");

    // création du fichier qui contiendra les scores des joueurs sur ce labyrinthe
    char* filename_score= format_name(lab.nom,DOSSIER_SCORE,SCORE_EXTENSION);
    FILE* file_score = fopen(filename_score, "w"); 
    fclose(file_score);
    free(filename_score);
    // fin 

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

    char* filename= format_name(nom,DOSSIER_MAPS,MAP_EXTENSION);
    FILE* file = fopen(filename, "r"); 
    if (!file) { free(filename); return (labyrinthe){0,0,NULL,NULL}; }

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
    return (labyrinthe) { lignes,colonnes,grille,nom };
}

int afficher_labyrinthes_disponibles() {
    DIR *dir;
    struct dirent *ent;

    dir = opendir(DOSSIER_MAPS);
    if (dir == NULL) {
        printf("Erreur : impossible d'ouvrir le dossier des labyrinthes.\n");
        return 0;
    }

    printf("Labyrinthes disponibles :\n");
    int count = 0;
    while ((ent = readdir(dir)) != NULL) {
        // Vérifie l'extension
        size_t len = strlen(ent->d_name);
        size_t ext_len = strlen(MAP_EXTENSION);
        if (len > ext_len + 1) { // Ex : "abc.cfg" >= 5
            if (strcmp(ent->d_name + len - ext_len, MAP_EXTENSION) == 0 && ent->d_name[len - ext_len - 1] == '.') {
                // Affiche le nom sans le .cfg
                char lab_name[256];
                strncpy(lab_name, ent->d_name, len - ext_len - 1);
                lab_name[len - ext_len - 1] = '\0';
                printf("- %s\n", lab_name);
                count++;
            }
        }
    }
    if (count == 0) printf("%s(Aucun labyrinthe trouvé)%s\n",ANSI_COLOR_RED,ANSI_RESET_ALL);
    closedir(dir);
    return count;
}


void enregistrer_score(char* nom_labyrinthe,char* nom_joueur,int score){
    char* filename= format_name(nom_labyrinthe,DOSSIER_SCORE,SCORE_EXTENSION);
    FILE* file = fopen(filename, "a"); 
    if (file != NULL) { 
        fprintf(file,"%s,%d\n",nom_joueur,score);
    }        
    free(filename);
    fclose(file);
}

//! à corriger : renvoie une liste de scores, pas forcément les meilleurs !!
//! trier tous les scores et récuperer un nb spécifique d'eux
int* get_best_scores(char* nom_labyrinthe) {

    int* res = allocate_vector(NB_DE_RESULTATS, 0);
    char* filename = format_name(nom_labyrinthe, DOSSIER_SCORE, SCORE_EXTENSION);

    if (!filename) {
        printf("Erreur lors de la generation du nom du fichier!\n");
        return res;
    }

    FILE* file = fopen(filename, "r+");
    if (!file) {
        printf("Impossible d'ouvrir le fichier: %s\n", filename);
        return res;
    }
    int c = fgetc(file);
    if (c == EOF){ // file is empty
        printf("Fichier %s vide",filename);
        free(filename);
        fclose(file);
        return NULL;
    } 
    for (int i = 0; i < NB_DE_RESULTATS && !feof(file); i++) {
        if (fscanf(file, "%*[^,],%d", &res[i]) != 1) {
            printf("impossible de lire le fichier à l'index %d\n", i);
            break;
        }
    }

    fclose(file);
    return res;
}

void afficher_meilleurs_scores(char* nom_labyrinthe){
    char* filename = format_name(nom_labyrinthe, DOSSIER_SCORE, SCORE_EXTENSION);
    if (!filename) {
        printf("Erreur lors de la generation du nom du fichier!\n");
    }
    FILE* file = fopen(filename, "r+");
    if (!file) {
        printf("Impossible d'ouvrir le fichier: %s\n", filename);
        return ;
    }
    printf("\n=> les meilleurs joueurs du labyrinthe <%s> :\n",nom_labyrinthe);
    char line[BUFFER_SIZE];
    for (int i = 0; i < NB_DE_RESULTATS && !feof(file); i++) {
        if (fgets(line, sizeof(line), file) == NULL){ break;}
        printf("    -> %s", line); 
    }
    printf("\n");
    fclose(file);
}
