#include <stdio.h>
#include <stdlib.h>
#include "abr.h"
#include "piles_files/data.h"
#include "piles_files/pile.h"
#include "piles_files/files.h"

/* Allocate new tree node and initialize it with `v`
 * returns NULL if the allocaton failed.
 */
node_t * createNode(int v)
{
  node_t * newnode = (node_t*) malloc(sizeof(node_t));
  if (newnode) {
    newnode->rs = NULL;
    newnode->ls = NULL;
    newnode->value = v;
  }
  return newnode;
}

/* return the adress of the leaf that should contain the given value `v` */
node_t **searchPrev(node_t * brt, int v)
{
  node_t ** prev = NULL;
  node_t * cur = brt;

  while (cur) {
    if (cur->value > v) {
      prev = &(cur->ls);
      cur = cur->ls;
    }
    else {
      prev = &(cur->rs);
      cur = cur->rs;
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

/* free memory allocated to a tree */
void freeAbr(node_t ** brt)
{
  pile_t * pile = initPile(100);
  node_t * cur = *brt;

  while (cur != NULL) {
    if (cur->rs) // save right son
      empiler(pile, (data_t) { .valeur = cur->rs });
    if (cur->ls) // save left son
      empiler(pile, (data_t) { .valeur = cur->ls });
    free(cur);
    cur = NULL; // free doesn't set cur to NULL

    // withdraw saved nodes
    if (!estVidePile(*pile)) {
      cur = depiler(pile).valeur;
    }
  }
  libererPile(&pile);
  *brt = NULL;
}

/* Search the father of the node containing the given value `v` */
node_t ** searchFather(node_t ** brt, int v)
{
  node_t ** prev = brt;

  if (prev) {
    while (*prev && (*prev)->value != v) {
      if ((*prev)->value > v) {
	prev = &(*prev)->ls;
      }
      else if ((*prev)->value < v) {
	prev = &(*prev)->rs;
      }
    }
  }
  
  return prev;
}

/* Delete the node containing the value `v` in `brt` */
node_t * deleteNode(node_t * brt, int v)
{
  node_t ** prev = searchFather(&brt, v);
  node_t * tmp;
  node_t * ls;
  node_t * rs;

  if (*prev) { // if the node that contains `v` exists
    tmp = *prev;
    ls = tmp->ls;
    rs = tmp->rs;
    *prev = rs;

    // adding the left tree of the deleted node to the left of its right tree.
    while (*prev) {
      prev = &(*prev)->ls;
    }
    *prev = ls;
    free(tmp);
  }
  return brt;
}

/* Create a new brt using values inside of a file. */
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
    }
    fclose(f);
  }
  return racine;
}

/* Returns the height of the given tree. */
int height(node_t * brt)
{
  pile_t * p = initPile(100);
  int h = 0, h_max = 0;
  node_t * cour = brt;
  data_t depile;

  if (p){
    while (cour){
      while(cour){
	empiler(p, (data_t) {.valeur = cour->ls, .i = h + 1});
	cour = cour->rs;
	h++;
      }
      if (h > h_max)
	h_max = h;
      if(!estVidePile(*p)){
	depile = depiler(p);
	cour = depile.valeur;
	h = depile.i;
      }
    }
    libererPile(&p);
  }
  else printf("Y a pas de problem :/\n");
  return h_max;
}

/* Display the given tree. */
void display(node_t * brt)
{
  pile_t * p = initPile(100);
  int i = 0;
  node_t * cour = brt;
  data_t depile;
  int fin = 0;
  
  if (p){
    while (!fin){
      while(cour != NULL){
	empiler(p, (data_t) {.valeur = cour, .i = i});
	cour = cour->rs;
	i++;
      }
      if(!estVidePile(*p)){
	depile = depiler(p);
	cour = depile.valeur;
	i = depile.i;
	for (int tab = 0; tab < i; tab++){
	  printf("\t");
	}
	printf("%d\n", cour->value);
	i ++;
	cour = cour->ls;
      }
      else fin = 1;
    }
    libererPile(&p);
  }
  else printf("Erreur allocation de la pile\n");
}
