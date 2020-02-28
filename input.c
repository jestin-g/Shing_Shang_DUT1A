/*******************************************************
Nom ......... : input.c
Role ........ : Fonctions d'entrées de l'utilisateur
Auteur ...... : Jestin Gabriel / Auty James
********************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "proto.h"

/* lis l'entrée de l'utilisateur */
int input(Case plateau[][10], Coord_dep *coord)
{
  int r = -1;
  char saisie[6];
  int test = 0;
  couleur("1");
  printf("\nEntrez votre coups");
  couleur("0");
  printf(" (ex: a6 a7) ou \"stop\" pour passer votre tour\n");
  do {
    fgets(saisie, 6, stdin); // entrée de l'utilisateur
    if (saisie[0] == 's' && saisie[1] == 't' && saisie[2] == 'o' && saisie[3] == 'p') // si l'entrée est "stop"
    {
      r = 0; // la fonction renvoi FAUX
      test = 1; // permet de sortir de la boucle
    }
    else //si l'entrée n'est pas "stop", on la traduit en coordonnées
    {
      coord->x1 = saisie[0] - 'a';
      coord->x2 = saisie[3] - 'a';
      coord->y1 = saisie[1] - '0';
      coord->y2 = saisie[4] - '0';
      if ((coord->x1 < 10) && (coord->x1 > -1) && (coord->y1 < 10) // on vérifie si les coordonnées sont valides
        && (coord->y1 > -1) && (coord->x2 < 10) && (coord->x2 > -1)
        && (coord->y2 < 10) && (coord->y2 > -1) && saisie[2] == ' ')
      {
        r = 1; // la fonction renvoi VRAI
        test = 1; // permet de sortir de la boucle
      }
    }
  } while (test != 1); // si l'entrée n'est pas "stop" et ne correspond pas à des coordonnées du tableau, recommence la boucle
  return r; // renvoi FAUX si l'utilisateur veut stopper son tour et VRAI si il a entré un coup à effectuer
}

/* demande au joueur si il souhaite continuer de jouer */
int continuer_de_jouer()
{
  int r = 0;
  char choix[2];
  printf("\nVoulez vous continuer votre tour (o/n)?\n");
  do {
    fgets(choix, 2, stdin); // l'utilisateur entre 'o' pour oui ou 'n' pour non
  } while ((choix[0] != 'o') && (choix[0] != 'n'));
  if (choix[0] == 'o')
  {
    r = 1; // renvoi VRAI si il veut rejouer
  }
  else if (choix[0] == 'n')
  {
    r = 0; // renvoi FAUX si il souhaite stopper son tour
  }
  return r;
}

/* demande à l'utilisateur quel joueur commence */
void choisir_qui_commence(enum equipe *jo)
{
  clrscr();
  int choix = 0;
  printf("\n   Quel joueur commence ?\n\n        1. ");
  couleur("34");
  printf("Joueur1\n\n");
  couleur("0");
  printf("        2. ");
  couleur("31");
  printf("Joueur2\n\n");
  couleur("0");
  while (1 != choix && 2 != choix)
  {
    scanf("%d", &choix);
    if (1 != choix && 2 != choix)
    {
      printf("(Vous devez entrez 1 ou 2 puis valider)\n");
    }
  }
  switch (choix)
  {
  case 1: *jo = BLEU; // change la valeur de *jo pour BLEU si il veut que le joueur 1 commence
    break;
  case 2: *jo = ROUGE; // change la valeur de *jo pour ROUGE si il veut que le joueur 2 commence
    break;
  }
}
