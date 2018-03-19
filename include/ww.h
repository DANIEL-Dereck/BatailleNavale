#ifndef WW_H_
# define WW_H_

/*
** Aide memo
** nbp 1 = JCJ
** nbp 2 = JCIA
** nbp 3 = IACIA
*/

/* Valeur possible a modifier pour s'amuser */

/* Le Lapours */
/* L'Ourpin  */
/*  (\_/)  */
/*  (*o*)  */
/*  (/|\)  */
/*  ()-()  */


/* name */
#define CORVETTE "Corvette"
#define DESTROYER "Destroyer"
#define CROISEUR "Croiseur"
#define PORTEAVION "PorteAvion"

/* nombre de bateau */
#define NB_CORVETTE 1
#define NB_DESTROYER 2
#define NB_CROISEUR 2
#define NB_PORTEAVION 1

/* taille de bateau */
#define SIZE_CORVETTE 1
#define SIZE_DESTROYER 3
#define SIZE_CROISEUR 4
#define SIZE_PORTEAVION 6

/* ID de bateau */
#define ID_CORVETTE 1
#define ID_DESTROYER 2
#define ID_CROISEUR 3
#define ID_PORTEAVION 4

/* taille de la carte */
/* 26 / 26 maximum recomander */
/* 10 / 10 minimum recomander */
#define XMAX 18
#define YMAX 24

/* ia */
/* Passer IA à 0 pour IA random */
/* Passer IA à 1 pour IA stupide */
#define AI 1

/* Temps par default 500000 */
#define TEMPSIA 500000
/*  (\_/)  */
/*  (*o*)  */
/*  (/|\)  */
/*  ()-()  */

/* Ne pas modifier */
/*    En desous    */

/* Temps chargement par default*/
#define TEMPS_CHARGEMENT 42

/* Temps par default */
#define TEMPS 500

/* nombre de carte */
#define ZMAX 1


/* Couleur d'affichage de text */
#define C_RED "\033[031m"
#define C_GREEN "\033[032m"
#define C_CYAN "\033[036m"
#define C_WHITE "\033[039m"

#define SENSV 'v'
#define SENSH 'h'

#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "my.h"

int main();
void loadingue();
void CapRandom();
void presentation();
void delir_ending(int play, int count);
int correcrand(int nb);

void init_map(int map[ZMAX][XMAX][YMAX]);
int start_game(int game[ZMAX][XMAX][YMAX]);
void player_play(int player, int enm, int game[ZMAX][XMAX][YMAX]);
void ia_play(int player, int enm, int game[ZMAX][XMAX][YMAX], int *x, int *y, int nbp);
void play_game(int map[ZMAX][XMAX][YMAX], int nbp);
void nuke_map(int map[ZMAX][XMAX][YMAX], int z);



int chech_boat(int map[ZMAX][XMAX][YMAX], int z);

void aff_boat(int map[ZMAX][XMAX][YMAX], int z);
void aff_boat_enm(int map[ZMAX][XMAX][YMAX], int z);
void affRestant (char* boat, int nbRest);

int ask_boat_id();
int ask_coord(int coord, char c);
char ask_sens(char c);
int ask_nbplayer();
void ask_boat(int game[ZMAX][XMAX][YMAX], int ia);

int VerifBoat(int game[ZMAX][XMAX][YMAX], int z, int x, int y, char sens, int size);
void place_boat(int game[ZMAX][XMAX][YMAX], int id, int ia, int x, int y, char sens);
void place_Rboat(int game[ZMAX][XMAX][YMAX], int ia);
void place_all(int game[ZMAX][XMAX][YMAX], int z, int x, int y, char sens, int size, int id);
void placeRBoat(int game[ZMAX][XMAX][YMAX], int number, int size, int type, char* name, int ia);

#endif

