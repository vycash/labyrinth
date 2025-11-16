/** 
* @author QACH Yahya
* @date 5 Octobre 2025
* @file main.c
* @brief le fichier qui lance l'execution du jeu
*/

#include "includes.h"

/** 
*@brief renvoie un choix de l'utilisateur
*@return valeur int correspondant à une action parmi celles possibles
*/
int menu(){
    
    printf("\n======= Menu Jeu de labyrinthe =======\n");
    printf("\n-> Veuillez faire un choix :        \n");
    printf("    - 1) Créer un labyrinthe          \n");
    printf("    - 2) Charger un labyrinthe        \n");
    printf("    - 3) Jouer                        \n");
    printf("    - 4) Afficher les meilleurs scores\n");        
    printf("    - 5) Quitter                      \n");
    
    int choix=0;
    while ( scanf("%d",&choix) != 1 ){
        printf("%sEntree non valide%s",ANSI_COLOR_RED,ANSI_RESET_ALL);
    }
    
    return choix;
}

/** 
*@brief renvoie un nom de labyrinthe entré par l'utilsateur
*@return chaine de charactère 
*/
char* recuperer_nom_labyrinthe(){
    
    char* nom = malloc( BUFFER_SIZE * sizeof(char) );
    
    // Vérification du nom
    int nom_valide = 0;

    while (!nom_valide) {
        
        printf("\nVeuillez choisir le nom du labyrinthe : ");
        scanf("%255s", nom);
        
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

/** 
*@brief renvoie un choix de difficulté que choisi l'utilisateur
*@return valeur int correspondant à une difficulté
*/
int get_difficulte(){
    int difficulte=0;
    printf("\nVeuillez choisir une difficuleté (0 : pour Facile / 1 : pour difficile):\n");
    while ( scanf("%d",&difficulte) != 1 ){
        printf("%sEntree non valide%s",ANSI_COLOR_RED,ANSI_RESET_ALL);
    }
    return difficulte;
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

                /*
                si un labyrinthe est déja en mémoire et que 'on veut créer un nouveau, le labyrinthe chargé est libéré
                pour éviter les fuites de mémoire
                */
                if(labyrinth.grille!=NULL){ free_labyrinth(labyrinth); }
                
                // Boucle de vérification pour lignes et colonnes
                while (lignes <= 2 || lignes % 2 == 0) {
                    printf("\nVeuillez choisir le nb de lignes du labyrinthe (impair et > 3): ");
                    scanf("%d", &lignes);
                } 

                while (colonnes <= 2 || colonnes % 2 == 0) {
                    printf("Veuillez choisir le nb de colonnes du labyrinthe (impair et > 3): ");
                    scanf("%d", &colonnes);
                } 

                int difficulte = get_difficulte();
                nom=recuperer_nom_labyrinthe();

                labyrinth = creer_labyrinthe(lignes, colonnes, nom, difficulte);

                if( labyrinth.grille != NULL){
                    printf("%s\n========== !! le labyrinthe %s est bien chargé en mémoire !! ==========\n%s",ANSI_COLOR_GREEN,nom,ANSI_RESET_ALL);
                }
                else{
                    printf("%sERROR : impossible de créer la labyrinthe le labyrinth%s\n",ANSI_COLOR_RED,ANSI_RESET_ALL);
                    free(nom); // libérer la mémoire de nom si erreur  
                }
                break;

            case 2: // Charger un labyrinthe

                /*
                si un labyrinthe est déja en mémoire et que 'on veut charger un nouveau, le labyrinthe chargé est libéré
                pour éviter les fuites de mémoire
                */
                if(labyrinth.grille!=NULL){ 
                    free_labyrinth(labyrinth);
                }

                // si il existe des labyrinthes déja créés on récupère le nom de celui que le joueur veut jouer               
                if ( afficher_labyrinthes_disponibles() > 0){
                    nom=recuperer_nom_labyrinthe();   
                    labyrinth = charger_labyrinthe(nom);
                }
                // si le labyrinth est bien chargé
                if( labyrinth.grille != NULL){
                    printf("%s\n========== !! le labyrinthe %s est bien chargé en mémoire !! ==========%s\n",ANSI_COLOR_GREEN,nom,ANSI_RESET_ALL);
                }
                else{
                    printf("%sERROR : impossible de charger la labyrinthe le labyrinth%s\n",ANSI_COLOR_RED,ANSI_RESET_ALL);
                    free(nom);// libérer la mémoire de nom si erreur 
                }
                break;

            case 3: // Jouer
                if (labyrinth.grille != NULL) {
                    jouer(labyrinth);
                    // à la fin du jeu, quand la fonction jouer a fini de se dérouler, on libère la mémoire du labyrinthe
                    free_labyrinth(labyrinth);
                    labyrinth=DEFAULT_LABYRINTH;
                }
                else{ 
                    printf("%sVeuillez charger ou créer un labyrinthe pour jouer%s\n",ANSI_COLOR_RED,ANSI_RESET_ALL);
                }
                break;
            case 4: // afficher les meilleurs scores
                afficher_labyrinthes_disponibles();
                char* nom_tmp = recuperer_nom_labyrinthe();
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