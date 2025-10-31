/**
 * name=file_handling.h
 * @file file_handling.h
 * @author QACH Yahya
 * @date 5 Octobre 2025
 * @brief Prototypes et documentation des fonctions gérant la lecture/écriture
 *        des fichiers de labyrinthes, scores et utilitaires associés.
 *
 * Remarques générales :
 *  - Ce header expose les fonctions de lecture/écriture utilisées par le projet.
 *  - Les fonctions qui allouent de la mémoire (ex. format_name, taille_labyrinthe,
 *    get_best_scores) documentent qui est responsable du free() de la mémoire
 *    retournée : c'est l'appelant qui doit libérer la mémoire.
 *  - Les chemins/fichiers utilisent les constantes DOSSIER, EXTENSION, etc. définies
 *    dans constants.h : s'assurer qu'elles sont disponibles lors de la compilation.
 */

#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

/* --------------------------------------------------------------------------
 * Constantes liées aux scores/dossiers (définies ailleurs, ex. constants.h)
 * --------------------------------------------------------------------------
 * Exemples attendus dans constants.h :
 *   #define DOSSIER "ressources"
 *   #define EXTENSION "cfg"
 *   #define DOSSIER_SCORE "scores"
 *   #define SCORE_EXTENSION "score"
 *   #define BUFFER_SIZE 256
 *   #define NB_DE_RESULTATS 10
 * -------------------------------------------------------------------------- */

/**
 * @brief Construit un nom de fichier complet à partir d'un nom de labyrinthe,
 *        d'un répertoire et d'une extension.
 *
 * Exemple retourné : "ressources/mon_labyrinthe.cfg" (terminé par '\0').
 *
 * @param nom Nom du labyrinthe (ex: "lab1"). Doit être une chaîne NUL-terminée.
 * @param dir_name Nom du répertoire (ex: DOSSIER ou DOSSIER_SCORE).
 * @param extension Extension sans point (ex: "cfg" ou "score").
 * @return Chaîne allouée dynamiquement contenant le chemin complet. L'appelant
 *         est responsable d'appeler free() sur le pointeur retourné.
 *         Retourne NULL en cas d'erreur d'allocation.
 */
char* format_name(const char* nom, const char* dir_name, const char* extension);

/**
 * @brief Enregistre un labyrinthe dans un fichier texte.
 *
 * Si le fichier n'existe pas, il est créé. S'il existe, il est remplacé.
 *
 * @param lab Structure labyrinthe à sauvegarder (contient dimensions et grille).
 * @param nom Nom du labyrinthe utilisé pour construire le nom du fichier.
 *            La fonction n'essaie pas de modifier la chaîne passée.
 */
void enregister_labyrinthe(labyrinthe lab, const char* nom);

/**
 * @brief Charge un labyrinthe depuis un fichier identifié par son nom.
 *
 * Cherche le fichier correspondant (format retourné par format_name) et
 * reconstruit la structure labyrinthe en mémoire (allocations pour la grille).
 *
 * @param nom Nom du labyrinthe (sans chemin ni extension).
 * @return labyrinthe rempli (lignes, colonnes, grille allouée). En cas d'erreur
 *         (fichier introuvable ou lecture invalide), renvoie {0,0,NULL}.
 *         L'appelant est responsable d'appeler free_matrix (ou l'équivalent)
 *         pour libérer lab.grille lorsque ce n'est plus nécessaire.
 */
labyrinthe charger_labyrinthe(const char* nom);

/**
 * @brief Lit uniquement les deux entiers (lignes, colonnes) enregistrés pour un
 *        labyrinthe et retourne un tableau de deux entiers.
 *
 * Utilité : éviter de charger toute la grille si seules les dimensions sont
 * nécessaires.
 *
 * @param nom Nom du labyrinthe (sans chemin ni extension).
 * @return Pointeur vers un tableau de deux entiers alloué dynamiquement :
 *         result[0] = lignes, result[1] = colonnes.
 *         L'appelant doit free() le pointeur retourné. En cas d'erreur,
 *         retourne NULL.
 */
int* taille_labyrinthe(const char* nom);

/**
 * @brief Affiche (sur stdout) la liste des fichiers de labyrinthes disponibles
 *        dans le dossier `DOSSIER` et ayant l'extension `EXTENSION`.
 *
 * Le nom affiché est celui sans extension.
 *
 * @return Le nombre de labyrinthes trouvés (>= 0). En cas d'erreur d'ouverture
 *         du dossier, retourne -1.
 */
int afficher_labyrinthes_disponibles(void);

/**
 * @brief Enregistre un score pour un labyrinthe donné.
 *
 * Le fichier de score associé est typiquement : <DOSSIER_SCORE>/<nom_labyrinthe>.SCORE_EXTENSION
 * Format libre (ex. "nom_joueur;score\n") mais doit être compatible avec get_best_scores/
 * afficher_meilleurs_scores si vous utilisez ces fonctions.
 *
 * @param nom_labyrinthe Nom du labyrinthe (sans chemin ni extension).
 * @param nom_joueur Nom du joueur (NUL-terminé).
 * @param score Valeur entière du score à enregistrer.
 */
void enregistrer_score(const char* nom_labyrinthe, const char* nom_joueur, int score);

/**
 * @brief Récupère les meilleurs scores pour un labyrinthe sous forme d'un tableau
 *        d'entiers (ou structure selon implémentation).
 *
 * Exemple d'utilisation simple : le fichier de scores contient des lignes
 * "nom,score". Cette fonction pourrait retourner uniquement un tableau d'entiers
 * représentant les scores, ou un tableau structuré (nom+score) selon ton besoin.
 *
 * @param nom_labyrinthe Nom du labyrinthe (sans chemin ni extension).
 * @param nb_de_resultats Nombre maximum de résultats à retourner.
 * @return Pointeur vers un tableau d'entiers dynamiquement alloué contenant les
 *         meilleurs scores triés décroissants. L'appelant doit free() ce
 *         tableau. Retourne NULL en cas d'erreur ou si aucun score disponible.
 *
 * Remarque : si tu préfères retourner des paires (nom,score), change le type
 *           et la documentation en conséquence.
 */
int* get_best_scores(const char* nom_labyrinthe, int nb_de_resultats);

/**
 * @brief Affiche les meilleurs scores du labyrinthe (sur stdout), jusqu'à
 *        NB_DE_RESULTATS (constante) résultats.
 *
 * Affiche un message informatif si le fichier de scores n'existe pas ou est vide.
 *
 * @param nom_labyrinthe Nom du labyrinthe (sans chemin ni extension).
 */
void afficher_meilleurs_scores(const char* nom_labyrinthe);

#endif /* FILE_HANDLING_H */