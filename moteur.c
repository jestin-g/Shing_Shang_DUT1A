/*******************************************************
Nom ......... : moteur.c
Role ........ : Fonctions motrices
Auteur ...... : Jestin Gabriel / Auty James
********************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h> /* fabs */
#include "proto.h"

/* change le contenu d'une case pour la vider */
void vider_case(Case plateau[10][10], int x, int y)
{
  plateau[x][y].type = VIDE;
  plateau[x][y].equipe = AUCUNE;
}

/* déplace une pièce d'une case à une autre */
void deplacer_piece(Case plateau[10][10], int x1, int y1, int x2, int y2)
{
  plateau[x2][y2].type = plateau[x1][y1].type;
  plateau[x2][y2].equipe = plateau[x1][y1].equipe;
  plateau[x1][y1].type = VIDE;
  plateau[x1][y1].equipe = AUCUNE;
}

/* change la valeur de *jo qui permet de savoir quel joueur doit effectuer un coup */
void changer_joueur(enum equipe *jo)
{
  if (*jo == BLEU ) // si *jo est bleu, le change en rouge
  {
    *jo = ROUGE;
  }
  else // si *jo est rouge, le change en bleu
  {
    *jo = BLEU;
  }
}

/*
** permet de faire bouger un singe d'une case à une autre
** en verifiant que le déplacement est autorisé
*/
int move_singe(Case plateau[10][10], int x1, int y1, int x2, int y2, enum equipe *jo)
{
  int r = -1; // initialisé à un -1, si aucun déplacement n'est effectué sa valeur ne changera pas et l'utilisateur devra resaisir un coup
  if ((fabs(x1-x2) == 2) || (fabs(y1-y2) == 2)) // si le deplacement est de 2 cases
  {
    if (!((fabs(x1-x2) == 1) && (fabs(y1-y2) == 2)) && !((fabs(x1-x2) == 2) && (fabs(y1-y2) == 1))) // si le deplacement est bien linéaire
    {
      if ((plateau[(x1+x2)/2][(y1+y2)/2].type == INEXISTANTE) // si la case du milieu est vide, c'est un déplacement de base pour un singe
      || (plateau[(x1+x2)/2][(y1+y2)/2].type == VIDE))
      {
        deplacer_piece(plateau,x1,y1,x2,y2);
        r = 0;
      }
      else if (plateau[(x1+x2)/2][(y1+y2)/2].type == SINGE) // si la case du milieu est un singe, c'est un saut
      {
        deplacer_piece(plateau,x1,y1,x2,y2);
        r = 1;
        if (plateau[(x1+x2)/2][(y1+y2)/2].equipe != plateau[x2][y2].equipe) // si la piece sautée n'est pas de la mếme équipe que le joueur on la supprime
        {
          vider_case(plateau,(x1+x2)/2,(y1+y2)/2);
          r = 2;
        }
      }
    }
  }
  else
  {
    if ((fabs(x1-x2) <= 2) && (fabs(y1-y2) <= 2)) // si le déplacement est de 1 case
    {
      deplacer_piece(plateau,x1,y1,x2,y2);
      r = 0;
    }
  }
  return r; // retourne la valeur correspondant au type de déplacement que la pièce vient d'effectuer (normal, saut sur un allié, saut sur un ennemi ou erreur)
}

/*
** permet de faire bouger un lion d'une case à une autre
** en verifiant que le déplacement est autorisé
*/
int move_lion(Case plateau[10][10], int x1, int y1, int x2, int y2, enum equipe *jo)
{
  int r = -1; // initialisé à un -1, si aucun déplacement n'est effectué sa valeur ne changera pas et l'utilisateur devra resaisir un coup
  if ((fabs(x1-x2) == 2) || (fabs(y1-y2) == 2)) // si le deplacement est de 2 cases (l utilisateur veut effectuer un saut)
  {
    if (!((fabs(x1-x2) == 1) && (fabs(y1-y2) == 2)) && !((fabs(x1-x2) == 2) && (fabs(y1-y2) == 1))) // si la pièce ne change pas de direction pendant le saut
    {
      if ((plateau[(x1+x2)/2][(y1+y2)/2].type == SINGE) || (plateau[(x1+x2)/2][(y1+y2)/2].type == LION)) // si la case sautée est un singe ou un lion
      {
        deplacer_piece(plateau,x1,y1,x2,y2);
        r = 1;
        if (plateau[(x1+x2)/2][(y1+y2)/2].equipe != plateau[x2][y2].equipe) // si la case sautee n'est pas de la même equipe que le joueur
        {
          vider_case(plateau,(x1+x2)/2,(y1+y2)/2);
          r = 2;
        }
      }
    }
  }
  else if ((fabs(x1-x2) <= 1) && fabs(y1-y2) <= 1) // si le déplacement est de 1 case
  {
    deplacer_piece(plateau,x1,y1,x2,y2);
    r = 0;
  }
  return r; // retourne la valeur correspondant au type de déplacement que la pièce vient d'effectuer (normal, saut sur un allié, saut sur un ennemi ou erreur)
}

/*
** permet de faire bouger un dragon d'une case à une autre
** en verifiant que le déplacement est autorisé
*/
int move_dragon(Case plateau[10][10], int x1, int y1, int x2, int y2, enum equipe *jo)
{
  int r = -1;
  if ((fabs(x1-x2) == 2) || (fabs(y1-y2) == 2)) // si le deplacement est de 2 cases (un dragon doit effectuer un saut)
  {
    if (!((x1-x2 == fabs(1)) && (y1-y2 == fabs(2))) && !((x1-x2 == fabs(2)) && (y1-y2 == fabs(1)))) // si la pièce ne change pas de direction pendant le saut
    {
      if ((plateau[(x1+x2)/2][(y1+y2)/2].type == SINGE)  // si la case sautee est un SINGE
      || (plateau[(x1+x2)/2][(y1+y2)/2].type == LION)    // OU si la case sautee est un LION
      || (plateau[(x1+x2)/2][(y1+y2)/2].type == DRAGON)) // OU si la case sautee est un DRAGON
      {
        deplacer_piece(plateau,x1,y1,x2,y2);
        r = 1;
        if (plateau[(x1+x2)/2][(y1+y2)/2].equipe != plateau[x2][y2].equipe) // si la case sautee n'est pas de la même equipe que le joueur
        {
          vider_case(plateau,(x1+x2)/2,(y1+y2)/2);
          r = 2;
        }
      }
    }
  }
  return r; // retourne la valeur correspondant au type de déplacement que la pièce vient d'effectuer (normal, saut sur un allié, saut sur un ennemi ou erreur)
}
