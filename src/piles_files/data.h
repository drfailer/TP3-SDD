/* FICHIER DATA.H
   Contient la déclaration du type
   data_t, un type global pour gérer
   facilement n'importe quel autre type dans
   la file ou la pile
*/

#ifndef __DATA__
#define __DATA__


#define NULLE_DATA ((data_t) {.valeur = 0})

typedef struct{
  int valeur;
  
}data_t;

#endif
