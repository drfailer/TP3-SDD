/* FICHIER FILES.H
   Contient les déclarations du type
   file_t ainsi que les fonctions qui
   s'y rapportent
*/

#ifndef __FILES__
#define __FILES__

#include "data.h"



/* STRUCTURES */


typedef struct{
  data_t * base;
  int taille;
  int nb;
  int deb;
  int fin;
}file_t;


/* FONCTIONS */

file_t * initFile(int taille);
void entreeFile(file_t * file, data_t val);
data_t sortieFile(file_t * file);
int estVideFile(file_t file);
int estPleineFile(file_t file);
void libererFile(file_t ** file);
void afficheFile(file_t file);

#endif
