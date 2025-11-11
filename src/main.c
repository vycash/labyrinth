/** 
* @author QACH Yahya
* @date 5 Octobre 2025
* @file main.c
* @brief le fichier qui lance l'execution du jeu
*/

#include "includes.h"

int menu(){
    
    printf("\n======= Menu Jeu de labyrinthe =======\n");
    printf("\n-> Veuillez faire un choix :        \n");
    printf("    - 1) Créer un labyrinthe          \n");
    printf("    - 2) Charger un labyrinthe        \n");
    printf("    - 3) Jouer                        \n");
    printf("    - 4) Afficher les meilleurs scores\n");        
    printf("    - 5) Quitter                      \n");
    
    int choix=0;
    scanf("%d",&choix);
    
    return choix;
}

char* recuperer_nom_labyrinthe(){
    
    char* nom = malloc( BUFFER_SIZE * sizeof(char) );
    
    // Vérification du nom
    int nom_valide = 0;

    while (!nom_valide) {
        
        printf("\nVeuillez choisir le nom du labyrinthe : ");
        scanf("%s", nom);
        
        int est_chiffre = 1;
        
        //vérifie si le nom saisi n'est pas un chiffre
        for (int i = 0; nom[i] != '\0'; i++) {
            if (nom[i] < '0' || nom[i] > '9') {
                est_chiffre = 0;
                break;
            }
        }
        
        if (!est_chiffre) nom_valide = 1;
        else printf("Erreur : le nom ne doit pas être un nombre uniquement !\n");
    
    } 
    
    return nom;
}

int main() {

    labyrinthe labyrinth=DEFAULT_LABYRINTH;
    int lignes=0;
    int colonnes=0;
    char* nom=NULL;

    int running=1;
    
    while (running){
        int choix = menu();
        switch (choix) {

            case 1: // Créer un labyrinthe

                // Boucle de vérification pour lignes et colonnes
                while (lignes <= 0 || lignes % 2 == 0) {
                    printf("\nVeuillez choisir le nb de lignes du labyrinthe (impair et > 0): ");
                    scanf("%d", &lignes);
                } 

                while (colonnes <= 0 || colonnes % 2 == 0) {
                    printf("\nVeuillez choisir le nb de colonnes du labyrinthe (impair et > 0): ");
                    scanf("%d", &colonnes);
                } 

                nom=recuperer_nom_labyrinthe();

                labyrinth = creer_labyrinthe(lignes, colonnes, nom);

                if( labyrinth.grille != NULL){
                    lignes=labyrinth.lignes;
                    colonnes=labyrinth.colonnes;
                    printf("%s\n========== !! le labyrinthe %s est bien chargé en mémoire !! ==========\n%s",ANSI_COLOR_GREEN,nom,ANSI_RESET_ALL);
                }
                else{
                    printf("%sERROR : impossible de créer la labyrinthe le labyrinth%s\n",ANSI_COLOR_RED,ANSI_RESET_ALL);
                }
                break;

            case 2: // Charger un labyrinthe
                if ( afficher_labyrinthes_disponibles() > 0){
                    nom=recuperer_nom_labyrinthe();   
                    labyrinth = charger_labyrinthe(nom);
                }
                // si le labyrinth est bien chargé
                if( labyrinth.grille != NULL){
                    lignes=labyrinth.lignes;
                    colonnes=labyrinth.colonnes;
                    printf("%s\n========== !! le labyrinthe %s est bien chargé en mémoire !! ==========%s\n",ANSI_COLOR_GREEN,nom,ANSI_RESET_ALL);
                }
                break;

            case 3: // Jouer
                if (labyrinth.grille != NULL) {
                    jouer(labyrinth);
                    free_labyrinth(labyrinth);
                    labyrinth=DEFAULT_LABYRINTH;
                }
                else{ 
                    printf("%sVeuillez charger ou créer un labyrinthe pour jouer%s\n",ANSI_COLOR_RED,ANSI_RESET_ALL);
                }
                break;
            case 4: // afficher les meilleurs scores
                afficher_labyrinthes_disponibles();
                char* nom_tmp = malloc(BUFFER_SIZE*sizeof(char));
                nom_tmp = recuperer_nom_labyrinthe();
                afficher_meilleurs_scores(nom_tmp);
                free(nom_tmp);
                break;
            case 5: // quitter
                running=0;
                printf("%sBye!!%s\n\n",ANSI_COLOR_GREEN,ANSI_RESET_ALL);
        }
    }
    
    free_labyrinth(labyrinth);
    return 0;
}