/*******************************************************
Nom ......... : affichage.c
Role ........ : Fonctions d'affichage
Auteur ...... : Jestin Gabriel / Auty James
********************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h> /* fabs */
#include "proto.h"

/* affiche l'écran d'acceuil */
void afficher_titre()
{
  clrscr();
  printf("\n");
  couleur("1");
  printf("      SHING SHANG");
  couleur("0");
  printf("\n   G.JESTIN - J.AUTY");
  printf("\n\n");
  printf("       1. Jouer\n");
  printf("      2. Quitter\n");
}

/* vide la console, appel afficher_tour_joueur() et afficher_plateau() */
void afficher_jeu(Case plateau[10][10], enum equipe *jo)
{
  clrscr();
  afficher_tour_joueur(jo),
  afficher_plateau(plateau);
}

/* affiche le plateau de jeu */
void afficher_plateau(Case plateau[10][10])
{
  for (int i = 0; i < 10; i++) // parcours les lignes du plateau
  {
    couleur("0");
    couleur("33");
    printf("    %d  ", i); // affiche les coordonnées de l'ordonnée à gauche du plateau
    couleur("0");
    for (int j = 0; j < 10; j++) // parcours les colonnes du plateau
    {
      if (plateau[j][i].equipe == BLEU) // si la case appartient à l'équipe bleue
      {
        couleur("34;1");
        switch (plateau[j][i].type) // écris le symbole de la case en fonction de son type
        {
        case SINGE:
          printf(" S ");
          break;
        case LION:
          printf(" L ");
          break;
        case DRAGON:
          printf(" D ");
          break;
        case PORTAIL:
            couleur("0");
            couleur("34");
            printf(" P ");
            break;
        }
      }
      else if (plateau[j][i].equipe == ROUGE) // si la case appartient à l'équipe rouge
      {
        couleur("31;1");
        switch (plateau[j][i].type) // écris le symbole de la case en fonction de son type
        {
        case SINGE:
          printf(" S ");
          break;
        case LION:
          printf(" L ");
          break;
        case DRAGON:
          printf(" D ");
          break;
        case PORTAIL:
            couleur("0");
            couleur("31");
            printf(" P ");
            break;
        }
      }
      else if (plateau[j][i].equipe == AUCUNE) // si la case n'appartient à aucune équipe
      {
        couleur("0");
        switch (plateau[j][i].type) // écris le symbole de la case en fonction de son type
        {
        case VIDE:
          printf(" . ");
          break;
        case INEXISTANTE:
          printf("   ");
          break;
        }
      }
    }
    printf("\n");
  }
  couleur("33");
  printf("\n        a  b  c  d  e  f  g  h  i  j"); // affiche les coordonnées de l'abscisse en dessous du plateau
  couleur("0");
  printf("\n");
}

/* affiche le joueur qui doit jouer */
void afficher_tour_joueur(enum equipe *jo)
{
  if (BLEU == *jo) // si la valeur de jo est BLEU affiche le joueur bleu (1) doit jouer
  {
    printf("\n             ");
    couleur("44;1");
    printf("Joueur1");
    couleur("0");
    printf("    Joueur2\n\n");
  }
  else if (ROUGE == *jo) // si la valeur de jo est ROUGE affiche le joueur rouge (2) doit jouer
  {
    printf("\n             ");
    printf("Joueur1    ");
    couleur("41;1");
    printf("Joueur2\n\n");
    couleur("0");
  }
}
