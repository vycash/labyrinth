/** 
 * @file file_handling.h
 * @author QACH Yahya
 * @date 5 Octobre 2025
 * @brief fichier qui implémente les fcts qui gèrent l'ecriture et la lecture des fichiers contenant les labyrinthes.
*/

#include <string.h>
#include <dirent.h>

#include "includes.h"
#include "matrix.h"

char* format_name(char* nom,char* dir_name,char* extension){
    char* filename = malloc(BUFFER_SIZE*sizeof(char));
    snprintf(filename, BUFFER_SIZE, "%s/%s.%s", dir_name,nom,extension);
    return filename;
}

void enregister_labyrinthe(labyrinthe lab){
    
    int** matrix = lab.grille;
    int lignes = lab.lignes;
    int colonnes = lab.colonnes;
    int difficulte = lab.difficulte;

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
        fprintf(file,"%d\n",difficulte);

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
    if (!file) { free(filename); return DEFAULT_LABYRINTH; }

    int lignes=0;
    int colonnes=0;
    int difficulte=0;

    fscanf(file,"%d",&lignes);
    fscanf(file,"%d",&colonnes);
    fscanf(file,"%d",&difficulte);

    int** grille=allocate_matrix(lignes,colonnes,0);

    for(int i=0 ; i<lignes ; i++){
        for(int j=0 ; j<colonnes ; j++){
            fscanf(file,"%d,",&grille[i][j]); // pcq on a ecrit les valeurs séparées par une virgule
        }
    }

    free(filename);
    fclose(file);
    return (labyrinthe) { lignes,colonnes,grille,nom,difficulte };
    
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

//* returns all the scores and puts the nb of scores read in count
score* get_scores(char* nom_labyrinthe, int* count) {
    
    //* Initialisation
    *count = 0;  // Initialize count
    int capacity = STANDARD_CAPACITY;
    char* filename = format_name(nom_labyrinthe, DOSSIER_SCORE, SCORE_EXTENSION);
    FILE* file = fopen(filename, "r");
    score* scores = malloc(capacity * sizeof(score));
    //* intialiser le tableau avec des valeurs (0,"") pour éviter les comportements inattendus
    memset(scores, 0, capacity * sizeof(score));


    //* gestion des erreurs
    if (!filename) {
        printf("Erreur lors de la generation du nom du fichier!\n");
        return NULL;
    }

    if (!file) {
        printf("Impossible d'ouvrir le fichier: %s\n", filename);
        free(filename);
        return NULL;
    }

    if (!scores) {
        printf("Erreur d'allocation memoire!\n");
        fclose(file);
        free(filename);
        return NULL;
    }

    //* Lecture
    while (fscanf(file, "%[^,],%d", scores[*count].player_name, &scores[*count].score) == 2) {

        (*count)++;
        
        // Redimensionnement du tableau si besoin
        if (*count >= capacity) {
            int old_capacity = capacity;
            capacity *= 2;
            score* temp = realloc(scores, capacity * sizeof(score));
            if (!temp) {
                printf("Erreur de reallocation memoire!\n");
                free(scores);
                fclose(file);
                free(filename);
                return NULL;
            }
            scores = temp;
            //* intialiser le tableau réallocé avec des valeurs (0,"") pour éviter les comportements inattendus
            memset(&scores[old_capacity], 0, (capacity - old_capacity) * sizeof(score));
        }
    }

    fclose(file);
    free(filename);
    
    // If no scores found, return NULL
    if (*count == 0) {
        free(scores);
        return NULL;
    }
    
    return scores;
}
// Comparison function for qsort - sorts in descending order (highest score first)
int compare_scores_desc(const void *a, const void *b) {
    const score *scoreA = (const score*) a;
    const score *scoreB = (const score*) b;
    return scoreA->score - scoreB->score;  // Descending order (best scores first)
}

void sort_scores(score* scores, int count) {
    if (scores == NULL || count <= 1) {
        return;  // Nothing to sort
    }
    
    qsort(scores, count, sizeof(score), compare_scores_desc);
}

score* get_best_scores(char* nom_labyrinthe) {

    //* initalisation
    int count=0;
    score* tous_les_scores = get_scores(nom_labyrinthe,&count);
    if (tous_les_scores == NULL) { return NULL; }

    sort_scores(tous_les_scores,count);

    //* créer et initialiser le tableau des meilleurs scores par (0, chaine vide) pour éviter des comportements inattendus
    score* meilleurs = malloc(NB_DE_RESULTATS * sizeof(score));
    memset(meilleurs, 0, NB_DE_RESULTATS * sizeof(score));
    for ( int i=0 ; i<NB_DE_RESULTATS ; i++ ){
        meilleurs[i]=(score){0,""};
    }


    /*
    *tant que i est plus petit que le NB de resultats que l'on souhaite (par défaut 10)
    *et que i est plus petit que count (le nb de resultats total) car il peut être qu'il y'a moins de 10 résultats
    *meilleurs reçoit l'objet score de tous les scores à l'index i après tri et les autres cases restent à NULL si nb total < 10
    */
    for ( int i=0 ; i<NB_DE_RESULTATS && i<count ; i++){
        meilleurs[i] = tous_les_scores[i];
    }

    free(tous_les_scores);
    return meilleurs;
}

void afficher_meilleurs_scores(char* nom_labyrinthe){
    
    score* meilleurs_scores = get_best_scores(nom_labyrinthe);
    if ( meilleurs_scores == NULL ){ return; }

    printf("%sLes meilleurs scores sont calculés selon celui qui mis le moins de pas pour trouver la clé et atteindre la sortie%s",
    ANSI_COLOR_GREEN,ANSI_RESET_ALL);
    printf("\n=> les meilleurs joueurs du labyrinthe <%s> :\n<nom,score>\n",nom_labyrinthe);
    
    for (int i = 0; i < NB_DE_RESULTATS ; i++) {
        if( meilleurs_scores[i].score > 0 && meilleurs_scores[i].player_name != NULL ){
            printf("%s,%d", meilleurs_scores[i].player_name,meilleurs_scores[i].score); 
        }
    }
    
    printf("\n");
    free(meilleurs_scores);
}
