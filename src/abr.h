#ifndef __ABR__
#define __ABR__

/* STRUCTURES: */

typedef struct node {
  int value;
  struct node * ls;
  struct node * rs;
} node_t;


/* FONCTIONS: */

node_t * createNode(int);
node_t * addValue(node_t*, int);
void freeAbr(node_t ** brt);
node_t * deleteNode(node_t * brt, int v);
node_t * abrFromFile(char * fileName);
void display(node_t * r);
int height(node_t * r);

#endif
