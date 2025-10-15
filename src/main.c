    /** 
    * @author QACH Yahya
    * @date 5 Octobre 2025
    * @file main.c
    * @brief le fichier qui lance l'execution du jeu
    */

    #include <stdio.h>
    #include <stdlib.h>

    #include "constants.h"
    #include "structures.h"

    #include "labyrinthe.h"
    #include "file_handling.h"
    #include "game_handler.h"


    int menu(){

        printf("Mini-projet : Jeu de labyrinthe\n");
        printf("\n-> Veuillez faire un choix : \n");
        printf("    - 1) Créer un labyrinthe   \n");
        printf("    - 2) Charger un labyrinthe \n");
        printf("    - 3) Jouer                 \n");
        printf("    - 4) Quitter               \n");

        int choix=0;
        scanf("%d",&choix);
        return choix;

    }

    char* recuperer_nom_labyrinthe(){
        char* nom = malloc(100*sizeof(char));
        // Vérification du nom
        int nom_valide = 0;
        while (!nom_valide) {
            printf("\nVeuillez choisir le nom du labyrinthe : ");
            scanf("%s", nom);
            int est_chiffre = 1;
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
        labyrinthe labyrinth={0,0,NULL,NULL};
        int lignes=0;
        int colonnes=0;
        char* nom;

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
                        printf("%s le labyrinthe %s est bien créé et chargé en mémoire !!%s\n",ANSI_COLOR_GREEN,nom,ANSI_RESET_ALL);
                    }
                    else{
                        printf("%sERROR : impossible de créer la labyrinthe le labyrinth%s\n",ANSI_COLOR_RED,ANSI_RESET_ALL);
                    }
                    break;

                case 2: // Charger un labyrinthe
                    afficher_labyrinthes_disponibles();
                    nom=recuperer_nom_labyrinthe();
                    
                    labyrinth = charger_labyrinthe(nom);
                    // si le labyrinth est bien chargé
                    if( labyrinth.grille != NULL){
                        lignes=labyrinth.lignes;
                        colonnes=labyrinth.colonnes;
                        printf("%s le labyrinthe %s est bien chargé!!%s\n",ANSI_COLOR_GREEN,nom,ANSI_RESET_ALL);
                    }
                    else{
                        printf("%sERROR : impossible de charger le labyrinth%s\n",ANSI_COLOR_RED,ANSI_RESET_ALL);
                    }
                    break;

                case 3: // Jouer
                    if (labyrinth.grille != NULL) {
                        jouer(labyrinth);
                        //running=0;
                    }
                    else{ 
                        printf("%sVeuillez charger ou créer un labyrinthe pour jouer%s\n",ANSI_COLOR_RED,ANSI_RESET_ALL);
                    }
                    break;
                case 4: // quitter
                    running=0;
                    printf("%sBye!!%s\n\n",ANSI_COLOR_GREEN,ANSI_RESET_ALL);
            }
        }

        free(nom);
        return 0;
    }