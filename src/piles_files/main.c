#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "files.h"


int main(int argc, char *argv[])
{
  /* TEST PILE : */
  pile_t * p = initPile(2);
  printf("Pointeur = %p\n", p);
  printf("La pile est vide : %d\n", estVidePile(*p));
  printf("La pile est pleine : %d\n", estPleinePile(*p));
  empiler(p,(data_t) {.valeur = 1});
  printf("Sommet : %d\n", sommet(*p).valeur);
  empiler(p, (data_t) {.valeur = 2});
  printf("Est pleine : %d\n", estPleinePile(*p));
  printf("La dépilation : %d\n", depiler(p).valeur);
  printf("Est pleine : %d\n", estPleinePile(*p));
  libererPile(&p);
  printf("Pointeur : %p\n", p);

  printf("\n__________________________FILES___________________________\n\n");
  file_t * f = initFile(2);
  printf("Pointeur = %p\n", f);
  printf("La file est vide : %d\n", estVideFile(*f));
  printf("La file est pleine : %d\n", estPleineFile(*f));
  entreeFile(f,(data_t) {.valeur = 1});
  afficheFile(*f);
  entreeFile(f, (data_t) {.valeur = 2});
  afficheFile(*f);
  printf("Est pleine : %d\n", estPleineFile(*f));
  printf("La défilation : %d\n", sortieFile(f).valeur);
  afficheFile(*f);
  printf("La défilation : %d\n", sortieFile(f).valeur);
  afficheFile(*f);
  printf("Est pleine : %d\n", estPleineFile(*f));
  libererFile(&f);
  printf("Pointeur : %p\n", f);
  return 0;
}
