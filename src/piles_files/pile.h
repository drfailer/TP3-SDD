/* FICHIER PILE.H
   Contient les déclarations du type
   pile_t ainsi que des fonctions qui
   s'y rapportent
*/
#ifndef __PILE__
#define __PILE__

#define TAILLE 50

#include "data.h"

/* STRUCTURES */




typedef struct{
  data_t * base;
  int taille;
  int sommet;
}pile_t;

/* FONCTIONS */

pile_t * initPile(int taille);
int estVidePile(pile_t pile);
int estPleinePile(pile_t pile);
void empiler(pile_t * pile, data_t valeur);
data_t depiler(pile_t * pile);
data_t sommet(pile_t pile);
void libererPile(pile_t ** pile);

#endif
