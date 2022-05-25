#include <stdio.h>
#include <stdlib.h>
#include "abr.h"
#include "piles_files/pile.h"

int main(void)
{
  node_t * arbre = abrFromFile("./testfile.txt");
  display(arbre);
  printf("height : %d\n", height(arbre));
  freeAbr(&arbre);
  return 0;
}
