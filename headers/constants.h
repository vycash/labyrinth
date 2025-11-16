/** 
* @file constants.h
* @author QACH Yahya
* @date 5 Octobre 2025
* @brief fichier qui déclare les constantes utilisées dans tout le programme
*/

/**===================Constantes d'affichage en couleur===========================*/

/**
* @defgroup Constantes affichage en couleurs dans le terminal
* @brief codes des couleurs ANSI pour affichage en terminal
* @{
*/
#define ANSI_COLOR_RED       "\x1b[31m"///< Texte rouge
#define ANSI_COLOR_GREEN     "\x1b[32m"///< Texte vert
#define ANSI_COLOR_GOLD      "\x1b[33m"///< Texte doré
#define ANSI_COLOR_BLUE      "\x1b[36m"///< Texte bleu
#define ANSI_COLOR_MAGENTA   "\x1b[35m"///< Texte mauve/magenta
#define ANSI_COLOR_WHITE     "\x1b[37m"///< Texte blanc
#define ANSI_COLOR_YELLOW    "\x1b[93m"///< Texte jaune
#define ANSI_RESET_ALL       "\x1b[0m"///< remise de couleur par défaut
/** @} */


/** @brief ===================Constantes du labyrinthe===========================
* les différentes valeurs utilisées dans le labyrinthe
*/

/**
* @defgroup Constantes de difficulté
* @brief 
* @{
*/
#define DIFFICILE 1 ///< Difficulté difficile lors du choix
#define FACILE    0 ///< Difficulté facile lors du choix
/** @} */

/** @brief le pourcentage des murs à supprimer quand le labyrinthe est difficile */
#define WALL_REMOVAL_RATIO 25

/**
* @defgroup Identifiants
* @brief les valeurs des identifiants des differents objets dans le labyrinthe
* @{
*/
#define JOUEUR_ID   0 ///< Identifiant du joueur
#define MUR        -1 ///< Identifiant d'un mur
#define SORTIE     -2 ///< Identifiant de la sortie du labyrinthe
#define KEY        -3 ///< Identifiant de la clé
#define PIEGE      -4 ///< Identifiant d'un piège
#define TRESOR     -5 ///< Identifiant d'un trésor
#define FANTOME    -6 ///< Identifiant d'un fantôme
#define OGRE       -7 ///< Identifiant d'un ogre
#define DEFAULT    99 ///< Identifiant d'une case vide par défaut
/** @} */

/**
* @defgroup Constantes de bonus/malus
* @brief les constantes qui définissent le malus des pièges/monstres et le bonus des trésors
* @{
*/
#define MALUS    1 ///< Malus des pièges
#define BONUS   -3 ///< Bonus des trésors

#define MALUS_OGRE    2 ///< Malus lors de la rencontre d'un ogre
#define MALUS_FANTOME 2 ///< Malus lors de la rencontre d'un fantôme
/** @} */

/** 
* @defgroup Constantes de création de labyrinthe
*@brief constantes de nombre de pièges et trésors éparpillés dans le labyrinthe lors de la création
* @{
*/
#define NB_DE_PIEGES 10 ///< nombre de pièges à mettre dans le labyrinthe lor sde la création
#define NB_DE_TRESOR 10 ///< nombre de trésors à mettre dans le labyrinthe lor sde la création
#define NB_OGRES     7  ///< nombre d'ogres à mettre dans le labyrinthe lor sde la création
#define NB_FANTOMES  7  ///< nombre de fantômes à mettre dans le labyrinthe lor sde la création
/** @} */


/**
* @brief Initialisation par défaut d'un objet joueur
* @details Structure (id, clé, score, x, y)
*/
#define JOUEUR              (joueur){JOUEUR_ID,0,0,0,1}
/**
* @brief Initialisation par défaut d'un objet labyrinthe
* @details Structure (nb_lignes, nb_colonnes, grille, nom_labyrinthe, difficulté)
*/
#define DEFAULT_LABYRINTH   (labyrinthe){0,0,NULL,NULL,0}



/** @brief ===================Constantes du game_handler=========================*/

/** 
*@defgroup Constantes de direction
*@brief constantes de direction de mouvement utilisées lors du déplacement du joueur
*@{
*/
#define HAUT    (direction){-1,0} ///< Direction Haut
#define BAS     (direction){1,0}  ///< Direction Bas
#define DROITE  (direction){0,1}  ///< Direction Droite
#define GAUCHE  (direction){0,-1} ///< Direction Gauche
/** @} */

/** 
*@defgroup Constantes de direction input
*@brief constantes des entrées utilisateur pour déplacement que l'utilisateur va entrer, chaque entrée correspond à un mouvement
*@{
*/
#define MOVEMENT_HAUT   'z' ///< Input pour le mouvement vers le haut
#define MOVEMENT_BAS    's' ///< Input pour le mouvement vers le bas
#define MOVEMENT_DROITE 'd' ///< Input pour le mouvement vers la droite
#define MOVEMENT_GAUCHE 'q' ///< Input pour le mouvement vers la gauche
/** @} */


/** @brief===================Constantes du file_handling=========================*/


/** 
*@defgroup Constantes d'extensions de fichiers 
*@brief constantes que va utiliser le file_handling pour gérer l'enregistrment des scores et des labyrinthes
*@{
*/
#define MAP_EXTENSION   "cfg"   ///< l'extension des fichiers de labyrinthes <.cfg>
#define SCORE_EXTENSION "score" ///< l'extension des fichiers de scores <.score>
/** @} */

/** @brief le nombre de scores à récupérer par défaut */
#define NB_DE_RESULTATS 10

/** @brief le chemin vers le dossier où sont stockés les labyrinthe */
#define DOSSIER_MAPS   "ressources/maps" 

/** @brief le chemin vers le dossier où sont stockés les scores */
#define DOSSIER_SCORE  "ressources/scores"

/** 
*@defgroup Constantes de lecture 
*@brief constantes de lecture, buffer size, et standard capacity (nombre de scores à récupérer à la fois)
*@{
*/
#define BUFFER_SIZE         256
#define STANDARD_CAPACITY   100
/** @} */

/** @brief valeur de retour de succès */
#define SUCCESS 1
/** @brief valeur de retour d'échec */
#define FAILURE 0