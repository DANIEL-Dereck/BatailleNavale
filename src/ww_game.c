#include "ww.h"
#include "my.h"

int correcrand(int nb)
{
  if (nb < 0)
    nb = nb * -1;
  return nb;
}

void place_all(int game[ZMAX][XMAX][YMAX], int z, int x, int y, char sens, int size, int id)
{
  int i = 0;

  x = correcrand(x);
  y = correcrand(y);
  if (sens != SENSV && sens != SENSH)
    sens = SENSV;
  if (sens == SENSV)
    {
      if (x + size < XMAX){
	for (i = 0; i < size; i++)
	  game[z][x++][y] = id;
      }
      else if (x - size >= 0){
	for (i = 0; i < size; i++)
	  game[z][x--][y] = id;
      }
    }
  else if (sens == SENSH)
    {
      if (y + size < YMAX){
	for (i = 0; i < size; i++)
	  game[z][x][y++] = id;
      }
      else if (y - size >= 0){
	for (i = 0; i < size; i++)
	  game[z][x][y--] = id;
      }
    }
}

int VerifBoat(int game[ZMAX][XMAX][YMAX], int z, int x, int y, char sens, int size)
{
  int i = 0;

  x = correcrand(x);
  y = correcrand(y);
  if (sens != SENSV && sens != SENSH)
    sens = SENSV;
  if (sens == SENSV)
    {
      if (x + size < XMAX){
	for (i = 0; i < size; i++)
	  if (game[z][x][y] > 0)
	    return -1;
      }
      else if (x - size >= 0){
	for (i = 0; i < size; i++)
	  if (game[z][x][y] > 0)
	    return -1;
      }
    }
  else if (sens == SENSH)
    {
      if (y + size < YMAX){
	for (i = 0; i < size; i++)
	  if (game[z][x][y] > 0)
	    return -1;
      }
      else if (y - size >= 0){
	for (i = 0; i < size; i++)
	  if (game[z][x][y] > 0)
	    return -1;
      }
    }
  return 0;
}

/*
** Fonction principale du placement de bateau
*/
void place_boat(int game[ZMAX][XMAX][YMAX], int id, int ia, int x, int y, char sens)
{
  if (id == ID_CORVETTE)
    place_all(game, ia, x, y, sens, SIZE_CORVETTE, id);
  else if (id == ID_DESTROYER)
    place_all(game, ia, x, y, sens, SIZE_DESTROYER, id);
  else if (id == ID_CROISEUR)
    place_all(game, ia, x, y, sens, SIZE_CROISEUR, id);
  else if (id == ID_PORTEAVION)
    place_all(game, ia, x, y, sens, SIZE_PORTEAVION, id);
}

/*
** Place les bateau de L'IA en random
*/
void place_Rboat(int game[ZMAX][XMAX][YMAX], int ia)
{
  int rplus = TEMPS_CHARGEMENT * 42;

  if (ia == 1)
    {
      rplus = (XMAX * YMAX * TEMPS_CHARGEMENT) + 1;
      my_printf("Boat IA placed\n");
    }
    placeRBoat(game, NB_CORVETTE, SIZE_CORVETTE, ID_CORVETTE, CORVETTE)
    placeRBoat(game, NB_DESTROYER, SIZE_DESTROYER, ID_DESTROYER, DESTROYER)
    placeRBoat(game, NB_CROISEUR, SIZE_CROISEUR, ID_CROISEUR, CROISEUR)
    placeRBoat(game, NB_PORTEAVION, SIZE_PORTEAVION, ID_PORTEAVION, PORTEAVION)
}


void placeRBoat(int game[ZMAX][XMAX][YMAX], int number, int size, int type, char* name) {
  int x = 0;
  int y = 0;
  int a = 0;
  int r = 0;
  int rplus = TEMPS_CHARGEMENT * 42;
  char sens = SENSV;

  srand(time(NULL));
  for(a = 0; a < number; a++)
    {
      r = (rand() * rand() * rplus) % 2;
      x = (rand() * rand() * rplus) % XMAX;
      y = (rand() * rplus) % YMAX;
      if (r == 0)
	      sens = SENSH;
      else
	      sens = SENSV;
      if (VerifBoat(game, ia, x, y, sens, size) == 0)
	place_all(game, ia, x, y, sens, size, type);
      else
	a--;
    }
  my_printf("%d %s placer\n", a + 1, name);
}