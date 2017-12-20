#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "ww.h"

int ask_nbplayer()
{
  int nbp = 0;

  do{
  my_printf("Would you play :\n");
  my_printf(" 1) With another player\n");
  my_printf(" 2) With an IA\n");
  my_printf(" 3) Just look 2 IA fight\n");
  my_printf("========> ");
  nbp = my_getnbr(get_next_line(0));
  }while(nbp != 1 && nbp != 2 && nbp != 3);
  return nbp;
}


/* Demande une coordonée à l'utilisateur.
** renvoie une coordonée entré par l'utilisateur
*/
int ask_coord(int coord, char c)
{
  char *tmp;
  int coordmax;

  if (c == 'x')
    coordmax = XMAX;
  else
    coordmax = YMAX;

  do{
    my_printf("Entrer coord %c into A and %c: ==> ", c, coordmax+'A' - 1);
  tmp = get_next_line(0);

  if (my_strcmp(tmp,"CHEAT") == 0)
    return (-42);

  if (my_strcmp(tmp, "NUKE") == 0)
    return (-84);

  if (tmp[0] >= 'A' && tmp[0] <= 'Z')
	coord = tmp[0] - 'A' + 1;
  else
    coord = my_getnbr(tmp);
  coord--;

  }while (coord < 0 || coord >= coordmax);
  return coord;
}

/*
** Demande une entré utilisateur du sens verticale ou horizontale
*/
char ask_sens(char c)
{
  char *tmp;

  do {
    my_printf("Entrer :\n v) Verticale\n h) Horizontale\n : ==> ");
    tmp = get_next_line(0);
    c = tmp[0];
    my_printf("\n");
    if (c != 'h' && c != 'h') {
      my_printf("\033[031m<=o=> Invalide Value <=o=>\033[039m\n");
    }
  } while (c != 'h'  && c != 'h');
  return c;
}

/*
** Demande une entré utilisateur de l'ID du bateau
*/
int ask_boat_id()
{
  int boat = 0;

  do {
    my_printf("Choose the type of boat you want to place\n");
    my_printf(" 1) %s\n", CORVETTE);
    my_printf(" 2) %s\n", DESTROYER);
    my_printf(" 3) %s\n", CROISEUR);
    my_printf(" 4) %s\n", PORTEAVION);
    boat = my_getnbr(get_next_line(0));
    my_printf("\n");
    if (boat != ID_CORVETTE && boat != ID_DESTROYER && boat != ID_CROISEUR && boat != ID_PORTEAVION)
      my_printf("\033[031m<== Invalide Value ==>\033[039m\n");
  }while (boat != ID_CORVETTE && boat != ID_DESTROYER && boat != ID_CROISEUR && boat != ID_PORTEAVION);
  return boat;
}

/*
** Fonction principale pour le placement des bateaux
*/
void ask_boat(int game[ZMAX][XMAX][YMAX], int ia)
{
  int nb_corv = NB_CORVETTE;
  int nb_dest = NB_DESTROYER;
  int nb_croi = NB_CROISEUR;
  int nb_port = NB_PORTEAVION;
  int nb_bot = nb_corv + nb_dest + nb_croi + nb_port;
  int nb = 1;
  int id = 0;
  int x = 0;
  int y = 0;
  char sens;
  int verif = 0;
  int flag = 1;

  do{
    aff_boat(game, 0);
    my_printf("Bateau à placer %d/%d\n", nb, nb_bot);

    affRestant(CORVETTE, nb_corv);
    affRestant(DESTROYER, nb_dest);
    affRestant(CROISEUR, nb_croi);
    affRestant(PORTEAVION, nb_port);
    id = ask_boat_id();
    if ((id == ID_CORVETTE && nb_corv == 0) ||
        (id == ID_DESTROYER && nb_dest == 0) || 
        (id == ID_CROISEUR && nb_croi == 0) ||
        (id == ID_PORTEAVION && nb_port == 0) )
      my_printf("\t\033[031m<== Number of boat exhaust  ==>\033[039m\n");
    else{
      do{
	y = ask_coord(y, 'y');
	x = ask_coord(x, 'x');
	sens = ask_sens(sens);

	if (id == ID_CORVETTE)
	  verif = VerifBoat(game, ia, x, y, sens, SIZE_CORVETTE);
	else if (id == ID_DESTROYER)
	  verif = VerifBoat(game, ia, x, y, sens, SIZE_DESTROYER);
	else if (id == ID_CROISEUR)
	  verif = VerifBoat(game, ia, x, y, sens, SIZE_CROISEUR);
	else if (id == ID_PORTEAVION)
	  verif = VerifBoat(game, ia, x, y, sens, SIZE_PORTEAVION);

	if (verif == 0)
	  {
	    if (((x > XMAX || x < 0) || (y > YMAX || y < 0)) && (sens != SENSV && sens != SENSH))
	      printf("\033[031m <== Coordonee invalide ==> \033[39m\n");
	    else
	      {
		if (id == ID_CORVETTE)
		  nb_corv--;
		else if (id == ID_DESTROYER)
		  nb_dest--;
		else if (id == ID_CROISEUR)
		  nb_croi--;
		else if (id == ID_PORTEAVION)
		  nb_port--;
		place_boat(game, id, ia, x, y, sens);
		nb++;
		flag = 0;
	      }
	  }
	else{
	  printf("\033[031m <== Impossible to place your boat her ==>\n");
      }
      }while(flag);
    }
    flag = 1;
  }while(nb <= nb_bot);
}

void affRestant (char* boat, int nbRest)
{
  if (nbRest != 0)
  {
    my_printf("\033[032m\t%d * %s restant\n\033[039m", nbRest, boat);    
  } else {
    my_printf("\033[031m\t%d * %s restant\n\033[039m", nbRest, boat);        
  }
}
