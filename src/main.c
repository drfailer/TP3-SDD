#include <stdio.h>
#include "abr.h"

node_t * abrFromFile(char * fileName)
{
  FILE * f;
  int v = 0;
  node_t * racine = NULL;

  f = fopen(fileName, "r");
  if(f != NULL){
    while(!feof(f)){
      fscanf(f, "%d\n", &v);
      racine = addValue(racine, v);
      // printf("%d\n", v);
    }
  }
  fclose(f);
  
  return racine;
}

int main(void)
{
  node_t * arbre = abrFromFile("./testfile.txt");
  printf("%d %d\n", arbre->valeur, arbre->fd->valeur);
  freeAbr(&arbre);
  return 0;
}



















































  /* node_t * brt = createNode(3); */
  /* brt = addValue(brt, 2); */
  /* brt = addValue(brt, 4); */
  /* printf("%d %d %d\n", brt->valeur, brt->fg->valeur, brt->fd->valeur); */
  /* freeAbr(&brt); */
