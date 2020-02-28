#include "affichage.h"

#include "structures.h"

static void afficher_case(Case case_)
{
  couleur("0");
  if (case_.equipe == BLEU)
    couleur("34;1");
  else if (case_.equipe == ROUGE)
    couleur("31;1");
  switch (case_.type)
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
      printf(" P ");
      break;
    case VIDE:
      printf(" . ");
      break;
    case INEXISTANTE:
      printf("   ");
      break;
  }
}

/* affiche le plateau de jeu */
void afficher_plateau(Case plateau[10][10])
{
  for (int i = 0; i < 10; i++)
  {
    couleur("0");
    couleur("33");
    printf("%d  ", i); // affiche les coordonnées de l'ordonnée à gauche du plateau
    for (int j = 0; j < 10; j++)
      afficher_case(plateau[j][i]);
    printf("\n");
  }
  couleur("33");
  printf("    a  b  c  d  e  f  g  h  i  j");
  // affiche les coordonnées de l'abscisse en dessous du plateau
  couleur("0");
  printf("\n");
}


void afficher_tour_joueur(int joueur)
{
  printf("Tour:      ");
  if (joueur == BLEU)
  {
    couleur("44;1");
    printf("Joueur1");
    couleur("0");
    printf("   Joueur2\n\n");
  }
  else
  {
    printf("Joueur1");
    printf("   ");
    couleur("41;1");
    printf("Joueur2");
    couleur("0");
    printf("\n\n");
  }
}

void afficher_jeu(struct jeu jeu)
{
  clrscr();
  afficher_tour_joueur(jeu.joueur),
  afficher_plateau(jeu.plateau);
}
