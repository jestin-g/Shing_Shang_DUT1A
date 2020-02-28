/*******************************************************
Nom ......... : move.c
Role ........ : Fonctions liées aux déplacements de pièces
Auteur ...... : Jestin Gabriel / Auty James
********************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h> /* fabs */
#include "proto.h"

/* définit le deplacement d'une pièce au début d'un tour */
int move(Case plateau[10][10], int x1, int y1, int x2, int y2, Coord *prev_coord, enum equipe *jo)
{
  int r = -1;
  if (verif_coord_equipe(plateau,x1,y1,jo)) // verifie que la piece jouées est bien de l'equipe du joueur courant
  {
    if (plateau[x1][y1].type == SINGE && (verif_coord_vide(plateau,x2,y2))) // applique les règles de déplacement des singes si la piece est un SINGE
    {
      r = move_singe(plateau,x1,y1,x2,y2,jo);
    }
    else if (plateau[x1][y1].type == LION && (verif_coord_vide(plateau,x2,y2))) // applique les règles de déplacement des lions si la piece est un LION
    {
      r = move_lion(plateau,x1,y1,x2,y2,jo);
    }
    else if (plateau[x1][y1].type == DRAGON && (verif_coord_vide_portail(plateau,x2,y2))) // applique les règles de déplacement des dragons si la piece est un DRAGON
    {
      r = move_dragon(plateau,x1,y1,x2,y2,jo);
    }
  }
  if (r > -1) // si le coup est valide, enregistre les coordonnées de la pièce jouée
  {
    prev_coord->x = x2;
    prev_coord->y = y2;
  }
  return r;
}

/* définit le deplacement après un saut sur une pièce alliée */
int move_saut_ally(Case plateau[10][10], int x1, int y1, int x2, int y2, Coord *prev_coord, enum equipe *jo)
{
  int r = -1;
  if ((x1 == prev_coord->x) && (y1 == prev_coord->y) && (verif_coord_equipe(plateau,x1,y1,jo))) // verifie que la piece jouées est la même pièce qu'au précédent coup
  {
    if (plateau[x1][y1].type == SINGE && (verif_coord_vide(plateau,x2,y2))) // applique les règles de déplacement des singes si la piece est un SINGE
    {
      r = move_singe(plateau,x1,y1,x2,y2,jo);
    }
    else if (plateau[x1][y1].type == LION && (verif_coord_vide(plateau,x2,y2))) // applique les règles de déplacement des lions si la piece est un LION
    {
      r = move_lion(plateau,x1,y1,x2,y2,jo);
    }
    else if (plateau[x1][y1].type == DRAGON && (verif_coord_vide_portail(plateau,x2,y2))) // applique les règles de déplacement des dragons si la piece est un DRAGON
    {
      r = move_dragon(plateau,x1,y1,x2,y2,jo);
    }
  }
  if (r > -1) // si le coup est valide, enregistre les coordonnées de la pièce jouée
  {
    prev_coord->x = x2;
    prev_coord->y = y2;
  }
  return r;
}

/* définit le deplacement d'une pièce après un saut sur une pièce ennemie */
int move_saut_enemy(Case plateau[10][10], int x1, int y1, int x2, int y2, Coord *prev_coord, enum equipe *jo)
{
  int r = -1;
  if ((x1 != prev_coord->x) || (y1 != prev_coord->y) && (verif_coord_equipe(plateau,x1,y1,jo))) // verifie que la piece jouée n'est pas la même pièce qu'au précédent coup
  {
    if (plateau[x1][y1].type == SINGE && (verif_coord_vide(plateau,x2,y2))) // applique les règles de déplacement des singes si la piece est un SINGE
    {
      r = move_singe(plateau,x1,y1,x2,y2,jo);
    }
    else if (plateau[x1][y1].type == LION && (verif_coord_vide(plateau,x2,y2))) // applique les règles de déplacement des lions si la piece est un LION
    {
      r = move_lion(plateau,x1,y1,x2,y2,jo);
    }
    else if (plateau[x1][y1].type == DRAGON && (verif_coord_vide_portail(plateau,x2,y2))) // applique les règles de déplacement des dragons si la piece est un DRAGON
    {
      r = move_dragon(plateau,x1,y1,x2,y2,jo);
    }
  }
  if (r > -1) // si le coup est valide, enregistre les coordonnées de la pièce jouée
  {
    prev_coord->x = x2;
    prev_coord->y = y2;
  }
  return r;
}

/* vérifie si une case appartient à l'équipe du joueur entré en paramètre */
int verif_coord_equipe(Case plateau[10][10], int x, int y, enum equipe *jo)
{
  return (plateau[x][y].equipe == *jo);
}

/* vérifie si une case est vide */
int verif_coord_vide(Case plateau[10][10], int x, int y)
{
  return (plateau[x][y].type == VIDE);
}

/* verifie si une case est vide ou est un portail */
int verif_coord_vide_portail(Case plateau[10][10], int x, int y)
{
  return (plateau[x][y].type == VIDE || plateau[x][y].type == PORTAIL);
}
