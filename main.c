/*******************************************************
Nom ......... : main.c
Role ........ : Lancer le jeu et le quitter
Auteur ...... : Jestin Gabriel / Auty James

Compilation : $ gcc *.c -o prog
Système d'exploitation: ubuntu 17.04
Pour exécuter : ./prog
********************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "proto.h"



int main(void)
{
  afficher_titre();

  int choix_titre= 0;
  while (choix_titre != 1 && choix_titre != 2) {
    scanf("%d", &choix_titre);
  }
  if (choix_titre == 1) {
    int jo = jeu();
    if (jo == BLEU)
    {
      printf("Le joueur 1 remporte la partie\n");
    }
    else if (jo == ROUGE)
    {
      printf("Le joueur 2 remporte la partie\n");
    }
    else if (jo == AUCUNE)
    {
      printf("Egalité, il ne reste que des dragons\n");
    }
  }
  else
  {
    clrscr();
  }
}
