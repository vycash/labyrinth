/*===================Constantes affichage en couleurs====================*/

#define ANSI_COLOR_RED       "\x1b[31m"
#define ANSI_COLOR_GREEN     "\x1b[32m"
#define ANSI_COLOR_GOLD      "\x1b[33m"
#define ANSI_COLOR_BLUE      "\x1b[36m"

#define ANSI_RESET_ALL       "\x1b[0m"


/*===================Constantes du labyrinthe===========================*/

/** @brief les valeurs des identifiants des differents objets dans le labyrinthe */
#define JOUEUR_ID  0 
#define MUR       -1
#define SORTIE    -2
#define KEY       -3
#define PIEGE     -4
#define TRESOR    -5

/** @brief les constantes qui définissent le malus des pièges et le bonus des trésors*/
#define MALUS    1
#define BONUS   -3

/** @brief valeur par défaut d'une case vide */
#define DEFAULT 99

/** @brief constantes de nombre de pièges et trésors éparpillés dans le labyrinthe lors de la création */
#define NB_DE_PIEGES 10
#define NB_DE_TRESOR 10

/** @brief l'objet joueur par défaut */
#define JOUEUR              (joueur){JOUEUR_ID,0,0,0,1}

/** @brief l'objet labyrinthe null */
#define DEFAULT_LABYRINTH   (labyrinthe) {0,0,NULL,NULL}

/*===================Constantes du game_handler=========================*/

/** @brief constantes de direction de mouvement */
#define HAUT    (direction){-1,0}
#define BAS     (direction){1,0}
#define DROITE  (direction){0,1}
#define GAUCHE  (direction){0,-1}

/** @brief constantes des entrées utilisateur pour déplacement */
#define MOVEMENT_HAUT   'z'
#define MOVEMENT_BAS    's'
#define MOVEMENT_DROITE 'd'
#define MOVEMENT_GAUCHE 'q'


/*===================Constantes du file_handling=========================*/

/** @brief l'extension des fichiers de labyrinthes <.cfg> */
#define MAP_EXTENSION   "cfg"

/** @brief l'extension des fichiers de scores <.score> */
#define SCORE_EXTENSION "score"

/** @brief le nombre de scores à récupérer par défaut */
#define NB_DE_RESULTATS 10

/** @brief le chemin vers le dossier où sont stockés les labyrinthe */
#define DOSSIER_MAPS    "ressources/maps" 

/** @brief le chemin vers le dossier où sont stockés les scores */
#define DOSSIER_SCORE       "ressources/scores"
#define BUFFER_SIZE         256
#define STANDARD_CAPACITY   100

/** @brief constates des valeurs de retour des fonctions */
#define SUCCESS 1
#define FAILURE 0