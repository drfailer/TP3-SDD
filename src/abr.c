#include <stdio.h>
#include <stdlib.h>
#include "abr.h"
#include "piles_files/pile.h"
#include "piles_files/files.h"

/* Allocate new tree node and initialize it with `v` */
node_t * createNode(int v)
{
  node_t * newnode = (node_t*) malloc(sizeof(node_t));
  if (newnode) {
    newnode->fd = NULL;
    newnode->fg = NULL;
    newnode->valeur = v;
  }
  return newnode;
}

node_t **searchPrev(node_t * brt, int v)
{
  node_t ** prev = NULL;
  node_t * cur = brt;

  while (cur) {
    if (cur->valeur > v) {
      prev = &(cur->fg);
      cur = cur->fg;
    }
    else {
      prev = &(cur->fd);
      cur = cur->fd;
    }
  }
  return prev;
}

/* add a value v to the given tree */
node_t * addValue(node_t* brt, int v)
{
  node_t ** prev = searchPrev(brt, v);
  node_t * newnode = NULL;

  if (prev) {
    newnode = createNode(v);
    if (newnode)
      *prev = newnode;
  }
  else {
    brt = createNode(v);
  }
  return brt;
}

void freeAbr(node_t ** brt)
{
  if ((*brt)->fg)
    freeAbr(&(*brt)->fg);
  if ((*brt)->fg)
    freeAbr(&(*brt)->fd);
  free(*brt);
  *brt = NULL;
}
