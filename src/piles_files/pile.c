#include <stdio.h>
#include <stdlib.h>
#include "pile.h"



pile_t * initPile(int taille){
  pile_t * new = (pile_t *)malloc(sizeof(pile_t));
  if(new != NULL){
    new->base = (data_t *)malloc(taille * sizeof(data_t));
    if (new->base != NULL){
      new->taille = taille;
      new-> sommet = -1;
    }
    else{
      free(new->base);
      free(new);
      new = NULL;
    }
  }
  return new;
}


int estVidePile(pile_t pile){
  return pile.sommet == -1;
}


int estPleinePile(pile_t pile){
  return pile.sommet == pile.taille - 1;
}



void empiler(pile_t * pile, data_t valeur){
  if(!estPleinePile(*pile)){
    pile->base[pile->sommet + 1] = valeur;
    pile->sommet ++;
  }
}


data_t depiler(pile_t * pile){
  data_t depile = NULLE_DATA;
  if(!estVidePile(*pile)){
    depile = pile->base[pile->sommet];
    pile->sommet --;
  }
  return depile;
}


data_t sommet(pile_t pile){
  return (estVidePile(pile)? NULLE_DATA : pile.base[pile.sommet]);
}

void libererPile(pile_t ** pile){
  free((*pile)->base);
  free(*pile);
  *pile = NULL;
}
