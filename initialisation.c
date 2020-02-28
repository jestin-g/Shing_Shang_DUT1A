/*******************************************************
Nom ......... : initialisation.c
Role ........ : Fonctions d'initialisation du plateau
Auteur ...... : Jestin Gabriel / Auty James
********************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h> /* fabs */
#include "proto.h"

/* regroupement des fonctions d'initialisation */
void init_plateau(Case plateau[][10])
{
  init_plateau_vide(plateau);
  init_plateau_bleu(plateau);
  init_plateau_rouge(plateau);
}

/* initialise un plateau vide */
void init_plateau_vide(Case plateau[][10])
{
  for (int i = 0; i < 10; i++) // initialisation des cases vides
  {
    for (int j = 0; j < 10; j++)
    {
      plateau[i][j].type = VIDE;
      plateau[i][j].equipe = AUCUNE;
    }
  }
  for (int i = 0; i < 10; i++) // initialisation des cases inexsitantes
  {
    for (int j = 0; j < 10; j++)
    {
      if ((0 == j && (i < 4 || i > 5)) || (9 == j && (i < 4 || i > 5)))
      {
        plateau[i][j].type = INEXISTANTE;
        plateau[i][j].equipe = AUCUNE;
      }
    }
  }

  /* initialisation des portails */
  plateau[1][4].type = PORTAIL;
  plateau[1][4].equipe = ROUGE;

  plateau[1][5].type = PORTAIL;
  plateau[1][5].equipe = ROUGE;

  plateau[8][4].type = PORTAIL;
  plateau[8][4].equipe = BLEU;

  plateau[8][5].type = PORTAIL;
  plateau[8][5].equipe = BLEU;
}

/* initialise les pièces rouges à leurs emplacements de départ */
void init_plateau_rouge(Case plateau[][10])
{
  /* initialisation des singes rouges */
  plateau[2][1].type = SINGE;
  plateau[2][1].equipe = ROUGE;

  plateau[1][2].type = SINGE;
  plateau[1][2].equipe = ROUGE;

  plateau[0][3].type = SINGE;
  plateau[0][3].equipe = ROUGE;

  plateau[0][6].type = SINGE;
  plateau[0][6].equipe = ROUGE;

  plateau[1][7].type = SINGE;
  plateau[1][7].equipe = ROUGE;

  plateau[2][8].type = SINGE;
  plateau[2][8].equipe = ROUGE;

  /*initialisation des lions rouges */
  plateau[1][1].type = LION;
  plateau[1][1].equipe = ROUGE;

  plateau[0][2].type = LION;
  plateau[0][2].equipe = ROUGE;

  plateau[0][7].type = LION;
  plateau[0][7].equipe = ROUGE;

  plateau[1][8].type = LION;
  plateau[1][8].equipe = ROUGE;

  /* initialisation des dragons rouges */
  plateau[0][1].type = DRAGON;
  plateau[0][1].equipe = ROUGE;

  plateau[0][8].type = DRAGON;
  plateau[0][8].equipe = ROUGE;
}

/* initialise les pièces bleues à leurs emplacements de départ */
void init_plateau_bleu(Case plateau[][10])
{
  /* initialisation des singes bleus */
  plateau[7][1].type = SINGE;
  plateau[7][1].equipe = BLEU;

  plateau[8][2].type = SINGE;
  plateau[8][2].equipe = BLEU;

  plateau[9][3].type = SINGE;
  plateau[9][3].equipe = BLEU;

  plateau[9][6].type = SINGE;
  plateau[9][6].equipe = BLEU;

  plateau[8][7].type = SINGE;
  plateau[8][7].equipe = BLEU;

  plateau[7][8].type = SINGE;
  plateau[7][8].equipe = BLEU;

  /* initialisation des lions bleus */
  plateau[8][1].type = LION;
  plateau[8][1].equipe = BLEU;

  plateau[9][2].type = LION;
  plateau[9][2].equipe = BLEU;

  plateau[9][7].type = LION;
  plateau[9][7].equipe = BLEU;

  plateau[8][8].type = LION;
  plateau[8][8].equipe = BLEU;

  /* initialisation des dragons bleus */
  plateau[9][1].type = DRAGON;
  plateau[9][1].equipe = BLEU;

  plateau[9][8].type = DRAGON;
  plateau[9][8].equipe = BLEU;
}
