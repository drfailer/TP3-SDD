/* FICHIER DATA.H
   Contient la déclaration du type
   data_t, un type global pour gérer
   facilement n'importe quel autre type dans
   la file ou la pile
*/

#ifndef __DATA__
#define __DATA__


#define NULLE_DATA ((data_t) {.valeur = NULL})

#include "../abr.h"

typedef struct{
  node_t * valeur;
  int i;
}data_t;

#endif
