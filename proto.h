/*******************************************************
Nom ......... : proto.h
Role ........ : Librairie des fonctions utilisées pour
le projet et définition des énumérations / structures
Auteur ...... : Jestin Gabriel / Auty James
********************************************************/

/**************
** Enumérations
*/

/* enumeration pour les differents types que peut prendre une case */
enum case_type
{
  INEXISTANTE,
  VIDE,
  PORTAIL,
  SINGE,
  LION,
  DRAGON
};

/* enumeration pour les differentes equipes que peut prendre une case */
enum equipe
{
  AUCUNE,
  BLEU,
  ROUGE
};

/************
** Structures
*/

/* structure definissant une case du plateau (un type et une équipe) */
typedef struct
{
  enum case_type type;
  enum equipe equipe;
} Case;

/* structure définissant une coordonnée */
typedef struct
{
  int x;
  int y;
} Coord;

/* structure définissant un couple de coordonnées */
typedef struct
{
  int x1;
  int y1;
  int x2;
  int y2;
} Coord_dep;


/***********
** Fonctions
*/

/* fonctions de déroulement de la partie (jeu.c) */
int jeu();
int fin_partie(Case plateau[][10]);
void changer_joueur(enum equipe *jo);
int compter_nb_dragon_rouge(Case plateau[10][10]);
int compter_nb_dragon_bleu(Case plateau[10][10]);

/* fonctions d'initialisation (initialisation.c) */
void init_plateau(Case plateau[][10]);
void init_plateau_vide(Case plateau[][10]);
void init_plateau_rouge(Case plateau[][10]);
void init_plateau_bleu(Case plateau[][10]);
void choisir_qui_commence(enum equipe *jo);

/* fonctions d'affichage (affichage.c) */
void afficher_titre();
void afficher_jeu(Case plateau[10][10], enum equipe *jo);
void afficher_plateau(Case plateau[][10]);
void afficher_tour_joueur(enum equipe *jo);
#define couleur(param) printf("\033[%sm",param) // change la couleur du texte affiché dans la console apres l'appel de cette fonction
#define clrscr() printf("\033[H\033[2J") // vide la console

/* fonctions d'entrée (input.c) */
int input(Case plateau[10][10], Coord_dep *coord);
int continuer_de_jouer();

/* fonctions de déplacements (move.c) */
int move(Case plateau[10][10], int x1, int y1, int x2, int y2, Coord *prev_coord, enum equipe *jo);
int move_saut_ally(Case plateau[10][10], int x1, int y1, int x2, int y2, Coord *prev_coord, enum equipe *jo);
int move_saut_enemy(Case plateau[10][10], int x1, int y1, int x2, int y2, Coord *prev_coord, enum equipe *jo);

int verif_coord_equipe(Case plateau[10][10], int x, int y, enum equipe *jo);
int verif_coord_vide(Case plateau[10][10], int x, int y);
int verif_coord_vide_portail(Case plateau[10][10], int x, int y);

/* fonctions motrices (moteur.c) */
int move_singe(Case plateau[10][10], int x1, int y1, int x2, int y2, enum equipe *jo);
int move_lion(Case plateau[10][10], int x1, int y1, int x2, int y2, enum equipe *jo);
int move_dragon(Case plateau[10][10], int x1, int y1, int x2, int y2, enum equipe *jo);

void deplacer_piece(Case plateau[10][10], int x1, int y1, int x2, int y2);
void vider_case(Case plateau[10][10], int x, int y);
