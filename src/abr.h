#ifndef __ABR__
#define __ABR__

/* STRUCTURES: */

typedef struct node {
  int valeur;
  struct node * fd;
  struct node * fg;
} node_t;


/* FONCTIONS: */

node_t * createNode(int);
node_t * addValue(node_t*, int);
void freeAbr(node_t ** brt);

#endif
