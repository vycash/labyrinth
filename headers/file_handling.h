/** 
 * @file file_handling.h
 * @author QACH Yahya
 * @date 5 Octobre 2025
 * @brief fichier qui déclare les prototypes des fcts qui gèrent l'ecriture et la lecture des fichiers de l'ensemble du projet.
*/

/**
 * @brief formate le nom du labyrinthe en un chemin relatif cers le fichier contenant le labyrinthe
 *
 * @see constants.h
 *
 * @param nom       le nom du labyrinthe
 * @param dir_name  le nom du dossier où sera enregistré le fichier du labyrinthe
 * @param extension l'extension du fichier d'enregistrement du labyrinthe
 *
 * @return le chemin du fichier contenant le labyrinthe
*/
char* format_name(char* nom,char* dir_name,char* extension);

/**
 * @brief enregistre un labyrinthe en format texte dans un fichier
 * le fichier est nommé <nom_labyrinthe.cfg> l'extension du ficher d'enregistrement est définie 
 * dans constants.h sous le nom MAP_EXTENSION, si le fichier n'existe pas il est créé puis modifié.
 *
 * @see constants.h pour les constantes utilisées dans file_handling.h
 * @see MAP_EXTENSION pour l'extension de fichier qui stocke le labyrinthe
 *
 * @param lab le labyrinthe que l'on souhaite enregistrer dans la mémoire
 */
void enregister_labyrinthe(labyrinthe lab);

/**
 * @brief charge un labyrinthe de son nom
 * la fct cherche le fichier correspondant du labyrinthe et lit son contenu pour reconstruire le labyrinthe et le renvoie
 *
 * @param nom le nom du labyrinthe que l'ont veut charger
 * @return le labyrinthe chargé en mémoire sous forme de matrice
*/
labyrinthe charger_labyrinthe(char* nom);


/**
 * @brief renvoie la taille d'un labyrinthe enregistré dans un fichier (lignes,colonnes)
 *
 * @param nom le nom du labyrinthe que l'ont veut savoir sa taille
 *
 * @return un tableau de deux elements contenant respectivement [lignes,colonnes]
*/
int* taille_labyrinthe(char* nom);

/**
* @brief affiche la liste des labyrinthes enregistrés dans le dossier où sont stockés les labyrinthes
         défini dans constants.h sous le nom de DOSSIER_MAPS
*
* @see constants.h
*
* @return le nombre de labyrinthes trouvés et affichés
*/
int afficher_labyrinthes_disponibles();

/**
 * @brief enregistre le score du joueur dans un fichier
 *
 * @param nom_labyrinthe le nom du labyrinthe sur lequel le joueur a joué et a eu un score dessus
 * @param nom_joueur le nom du joueur 
 * @param score le score qu'a obtenu le joueur sur le labyrinthe
*/
void enregistrer_score(char* nom_labyrinthe,char* nom_joueur,int score);

/**
 * @brief renvoie tout les scores enregistrés pour un labyrinthe
 *
 * @param nom_labyrinthe le nom du labyrinthe duquel on souhaite récupérer les scores
 * @param count pointeur vers une variable de type int où on va stocker le nombre de scores lûs et renvoyés
 * @return tableau contenant tous les scores enregistrés pour un labyrinthe donné
*/
score* get_scores(char* nom_labyrinthe, int* count);

/**
 * @brief trie tous les cores de tous les joueurs d'un labyrinthe en utilisant la fonction qsort (quick sort)
 *
 * @param scores le tableau contenant les scores des joueurs
 * @param count le nombre d'elements dans le tableau scores
*/
void sort_scores(score* scores, int count);

/**
 * @brief compare deux scores en descroissance, utilisée pour qsort
 *
 * @param a 1er element 
 * @param b 2eme element
*/
int compare_scores_desc(const void *a, const void *b);


/**
 * @brief renvoie un nombre spécifique des meilleurs scores des joueurs qui ont joués sur ce labyrinthe
 *
 * @see constants.h, NB_DE_RESULTATS est la macro utilisée par défaut comme nombre de resultats
 * @param nom_labyrinthe le nom du labyrinthe duquel on souhaite récupérer les meilleurs résultats
 * @return un tableau de taille nb_de_resultats correspondants aux meilleurs scores
*/
score* get_best_scores(char* nom_labyrinthe);

/**
 * @brief affiche les meilleurs scores d'un labyrinthe donné
 * @param nom_labyrinthe nom du labyrinthe duquel on souhaite voir les meilleurs résultats
 * @see constants.h, NB_DE_RESULTATS est la valeur utilisée par déafaut 
*/
void afficher_meilleurs_scores(char* nom_labyrinthe);