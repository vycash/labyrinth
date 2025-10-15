/*===================Constantes affichage en couleurs====================*/

#define ANSI_COLOR_RED       "\x1b[31m"
#define ANSI_COLOR_GREEN     "\x1b[32m"
#define ANSI_COLOR_GOLD      "\x1b[33m"
#define ANSI_COLOR_BLUE      "\x1b[36m"

#define ANSI_RESET_ALL       "\x1b[0m"


/*===================Constantes du labyrinthe===========================*/

#define JOUEUR_ID 0 

#define MUR -1
#define SORTIE -2
#define KEY -3
#define PIEGE -4
#define TRESOR -5

#define MALUS 1
#define BONUS -1

#define DEFAULT 99

#define NB_DE_PIEGES 10
#define NB_DE_TRESOR 10

#define JOUEUR (joueur){JOUEUR_ID,0,0,0,1}

/*===================Constantes du game_handler=========================*/

#define HAUT (direction){-1,0}
#define BAS (direction){1,0}
#define DROITE (direction){0,1}
#define GAUCHE (direction){0,-1}

#define MOVEMENT_HAUT 'z'
#define MOVEMENT_BAS 's'
#define MOVEMENT_DROITE 'd'
#define MOVEMENT_GAUCHE 'q'


/*===================Constantes du file_handling=========================*/

#define EXTENSION "cfg"
#define DOSSIER "ressources"
#define BUFFER_SIZE 256

#define SUCCESS 1
#define FAILURE 0