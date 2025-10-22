/**
* @author QACH Yahya
* @date 5 Octobre 2025
* @file game_handler.c
* @brief Implementation des fonctions de gestion du labyrinthe
*/

#include <stdio.h>
#include <stdlib.h>

#include "constants.h"
#include "structures.h"

#include "labyrinthe.h"
#include "game_handler.h"
#include "file_handling.h"

void jouer(labyrinthe labyrinth){
    joueur j = JOUEUR;
    int running=1;
    while(running){

        if (labyrinth.grille != NULL) {
            afficher_labyrinthe(labyrinth.grille, labyrinth.lignes, labyrinth.colonnes);
        }
        
        printf("se déplacer : \n z : haut\n d : droite\n s : bas\n q : gauche\n");
        printf("%sEst ce que vous avez la clé? : %d%s\n",ANSI_COLOR_GOLD,j.a_cle,ANSI_RESET_ALL);
        printf("%sVotre score : %d%s\n",ANSI_COLOR_BLUE,j.score,ANSI_RESET_ALL);
        
        int res=0;
        while( !res ){
            char line[100]; // buffer pour lire la ligne
            if (fgets(line, sizeof(line), stdin)) {
                char move = line[0]; // prend que le premier char de la ligne
                switch(move){
                    case MOVEMENT_HAUT:
                    res=deplacer_joueur_haut(&j,labyrinth);
                    break;
                    case MOVEMENT_BAS:
                    res=deplacer_joueur_bas(&j,labyrinth);
                    break;
                    case MOVEMENT_DROITE:
                    res=deplacer_joueur_droite(&j,labyrinth);
                    break;
                    case MOVEMENT_GAUCHE:
                    res=deplacer_joueur_gauche(&j,labyrinth);
                    break;
                }
            }
            else {
                printf("%sEntrée incorrecte%s\n",ANSI_COLOR_RED,ANSI_RESET_ALL);
            }

        }
        if ( verifier_victoire(labyrinth) ){
            printf("\n%sFélicitations, vous avez gagné !!! %s\n",ANSI_COLOR_GREEN,ANSI_RESET_ALL);
            printf("%sVotre score : %d%s\n",ANSI_COLOR_BLUE,j.score,ANSI_RESET_ALL);

            if(score_parmi_meilleurs(j.score,labyrinth.nom)){
                printf("\n!! BRAVO vous êtes parmi les %d meilleurs !! \n",NB_DE_RESULTATS);
                printf(" veullez rentrer votre pseudo : ");
                char name[BUFFER_SIZE];
                scanf("%s",name);
                enregistrer_score(labyrinth.nom,name,j.score);
            }
            running=0;
        }
    }
}

int verifier_victoire(labyrinthe labyrinth){
    return labyrinth.grille[labyrinth.lignes-1][labyrinth.colonnes-2]==JOUEUR_ID;
}

int score_parmi_meilleurs(int score,char* nom_labyrinthe){
    int* scores = get_best_scores(nom_labyrinthe,NB_DE_RESULTATS);
    if( scores == NULL ) return 1;
    int max=scores[0];
    for(int i=0 ; i<NB_DE_RESULTATS ; i++){
        if(scores[i]>max){ max=scores[i]; }
    }
    return score <= max;
}

int placer(labyrinthe lab,int sujet_id,int x,int y){
    if( x<1 || x>lab.lignes || y<1 || y>lab.colonnes || lab.grille[x][y] == MUR){
        printf("%sERROR placer : coordonnées invalides%s\n",ANSI_COLOR_RED,ANSI_RESET_ALL);
        return FAILURE;
    }
    lab.grille[x][y]=sujet_id;
    return SUCCESS;
}

int deplacer_joueur(joueur* player,labyrinthe lab,direction d){
    
    int** grille_labyrinthe = lab.grille;

    int offset_x=d.x_offset;
    int offset_y=d.y_offset;

    int lignes = lab.lignes;
    int colonnes = lab.colonnes;

    int new_x = player->x+offset_x;
    int new_y = player->y+offset_y;

    // test si les nouveaux coordonnées sont inclus dans la grille
    if( new_x >= 1 && new_x <= lignes-1 && new_y >= 1 && new_y <= colonnes-1 ){
        int res=0;
        switch(grille_labyrinthe[new_x][new_y]){
            case SORTIE:
                // si le joueur a la clé on le déplace sur la sortie
                if(player->a_cle){ res = placer(lab,player->id,new_x,new_y);}
                else{ printf("%sVous devez récupérer la clé d'abord%s\n",ANSI_COLOR_RED,ANSI_RESET_ALL);}
                break;
            case KEY : 
                player->a_cle=1;
                res = placer(lab,player->id,new_x,new_y);
                printf("\n%sVous avez récupéré la clé.%s\n",ANSI_COLOR_GOLD,ANSI_RESET_ALL);
                break;
            case TRESOR:
                player->score+=BONUS;
                res = placer(lab,player->id,new_x,new_y);
                printf("\n%sVous venez de gagner un point ;) .%s\n",ANSI_COLOR_GREEN,ANSI_RESET_ALL);
                break;
            case PIEGE :
                player->score+=MALUS;
                res = placer(lab,player->id,new_x,new_y);
                printf("\n%sVous venez de perdre un point :( .%s\n",ANSI_COLOR_RED,ANSI_RESET_ALL);
                break;
            default:
                res = placer(lab,player->id,new_x,new_y);
                break;

        }
        // si le joueur a été bien placé on met a jour ses infos
        if (res==SUCCESS){
            printf("GREAT SUCCESS.");
            lab.grille[player->x][player->y]=DEFAULT;
            player->y=new_y;
            player->x=new_x;
            player->score++;
            return res;
        }
    }
    
    else{ 
        printf("%s!!!! Coordonnées invalides !!!!  %s\n",ANSI_COLOR_RED,ANSI_RESET_ALL); 
    }

    return FAILURE;
}

int deplacer_joueur_haut(joueur* j,labyrinthe lab){
    return deplacer_joueur(j,lab,HAUT);
}
int deplacer_joueur_bas(joueur* j,labyrinthe lab){
    return deplacer_joueur(j,lab,BAS);
}
int deplacer_joueur_droite(joueur* j,labyrinthe lab){
    return deplacer_joueur(j,lab,DROITE);
}
int deplacer_joueur_gauche(joueur* j,labyrinthe lab){
    return deplacer_joueur(j,lab,GAUCHE);
}
