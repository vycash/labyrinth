/**
* @author QACH Yahya
* @date 5 Octobre 2025
* @file game_handler.h
* @brief Implementation des fonctions de gestion du labyrinthe
*/
void jouer(labyrinthe labyrinth);
int verifier_victoire(labyrinthe labyrinth);
int score_parmi_meilleurs(int score,char* nom_labyrinthe);
int placer(labyrinthe lab,int sujet_id,int x,int y);
int deplacer_joueur(joueur* player,labyrinthe lab,direction d);
int deplacer_joueur_haut(joueur* j,labyrinthe lab);
int deplacer_joueur_bas(joueur* j,labyrinthe lab);
int deplacer_joueur_droite(joueur* j,labyrinthe lab);
int deplacer_joueur_gauche(joueur* j,labyrinthe lab);
