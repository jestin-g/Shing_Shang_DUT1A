/*******************************************************
Nom ......... : main.c
Role ........ : Fonctions de déroulement du jeu
Auteur ...... : Jestin Gabriel / Auty James
********************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "proto.h"

/* fonction de jeu, gère le tour de jeu et les conditons de victoire */
int jeu()
{
  Case plateau[10][10]; // déclare le tableau de Case servant de plateau
  Coord_dep coord; // déclare le couple de coordonnées "coord"
  Coord prev_coord; // déclare le couple de coordonnées "prev_coord" (prev = previous)
  enum equipe jo; // déclare la variable jo
  int r = 0; // initialise la variable permettant de savoir quelle fonction move appellé (0 pour un coup "normal")

  choisir_qui_commence(&jo);

  init_plateau(plateau); // initialise toute les cases du plateau à leur emplacements par défaut

  while (!fin_partie(plateau)) // début de la boucle de jeu
  {
    clrscr();
    do { // début de la saisie du coup
      switch (r)
      {
        case 0:
        do {
          afficher_jeu(plateau, &jo);
          if (input(plateau, &coord)) // si VRAI on effectue le coup
          {
            r = move(plateau,coord.x1,coord.y1,coord.x2,coord.y2,&prev_coord,&jo);
          }
          else // si FAUX on fini son tour
          {
            r = 0;
          }
        } while (r == -1);
        break;
        case 1:
        do {
          afficher_jeu(plateau, &jo);
          if (continuer_de_jouer()) // si VRAI on continue
          {
            afficher_jeu(plateau, &jo);
            if (input(plateau, &coord)) // si VRAI on effectue le coup
            {
              r = move_saut_ally(plateau,coord.x1,coord.y1,coord.x2,coord.y2,&prev_coord,&jo);
            }
            else // si FAUX on fini son tour
            {
              r = 0;
            }
          }
          else // si FAUX on fini son tour
          {
            r = 0;
          }
        } while (r == -1);
        break;
        case 2:
        do {
          afficher_jeu(plateau, &jo);
          if (continuer_de_jouer()) // si VRAI on continue
          {
            afficher_jeu(plateau, &jo);
            if (input(plateau, &coord)) // si VRAI on effectue le coup
            {
              r = move_saut_enemy(plateau,coord.x1,coord.y1,coord.x2,coord.y2,&prev_coord,&jo);
            }
            else // si FAUX on fini son tour
            {
              r = 0;
            }
          }
          else // si FAUX on fini son tour
          {
            r = 0;
          }
        } while (r == -1);
        break;
      }
    } while (r != 0);
    changer_joueur(&jo); // on change de joueur à la fin du tour
    if (!compter_nb_dragon_bleu(plateau)) // si les bleus n'ont plus de dragons, les rouges gagnent
    {
      return ROUGE;
    }
    if (!compter_nb_dragon_rouge(plateau)) // si les rouges n'ont plus de dragons, les bleus gagnent
    {
      return BLEU;
    }
  }
  return jo; // retourne la valeur jo du gagnant
}

/* vérifie la condition de victoire classique */
int fin_partie(Case plateau[10][10])
{
  return (plateau[1][4].type == DRAGON || plateau[1][5].type == DRAGON
       || plateau[8][4].type == DRAGON || plateau[8][5].type == DRAGON);
}

/* compte le nombre bleu de dragon restant */
int compter_nb_dragon_bleu(Case plateau[10][10])
{
  int r = 1;
  int nb_dragon = 0;
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (plateau[j][i].equipe == BLEU)
      {
        if (plateau[j][i].type == DRAGON)
        {
          nb_dragon++;
        }
      }
    }
  }
  if (nb_dragon == 0)
  {
    r = 0;
  }
  return r; // VRAI si il reste des dragons, FAUX si il ne reste plus de dragons
}

/* compte le nombre rouge de dragon restant */
int compter_nb_dragon_rouge(Case plateau[10][10])
{
  int r = 1;
  int nb_dragon = 0;
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (plateau[j][i].equipe == ROUGE)
      {
        if (plateau[j][i].type == DRAGON)
        {
          nb_dragon++;
        }
      }
    }
  }
  if (nb_dragon ==0)
  {
    r = 0;
  }
  return r; // VRAI si il reste des dragons, FAUX si il ne reste plus de dragons
}
