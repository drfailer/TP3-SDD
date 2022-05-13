#include <stdio.h>
#include <stdlib.h>
#include "files.h"




file_t * initFile(int taille){
  file_t * new = (file_t *)malloc(sizeof(file_t));
  if(new != NULL){
    new->base = (data_t *)malloc(taille * sizeof(data_t));
    if(new->base != NULL){
      new->taille = taille;
      new->deb = -1;
      new->fin = -1;
      new->nb = 0;
    }
    else{
      free(new->base);
      free(new);
      new = NULL;
    }
  }
  return new;
}

int estVideFile(file_t file){
  return file.nb == 0;
}

int estPleineFile(file_t file){
  return file.nb == file.taille;
}

void entreeFile(file_t * file, data_t val){
  if (!estPleineFile(*file)){
    if(estVideFile(*file)){
      file->deb = 0;
    }
    file->fin = (file->fin + 1) % file->taille;
    file->nb ++;
    file->base[file->fin] = val;
  }
}

data_t sortieFile(file_t * file){
  data_t sortie = NULLE_DATA;
  if(!estVideFile(*file)){
    file->nb --;
    sortie = file->base[file->deb];
    if(file->nb == 0){
      file->deb = -1;
      file->fin = -1;
    }
    else{
      file->deb = (file->deb + 1) % file->taille;
    }
  }
  return sortie;
}

void libererFile(file_t ** file){
  free((*file)->base);
  free(*file);
  *file = NULL;
}


void afficheFile(file_t file){
  int i = file.deb;
  printf("Taille : %d\n", file.taille);
  printf("Debut : %d\n", file.deb);
  printf("Fin : %d\n", file.fin);
  printf("Nombre d'elements : %d\n\n", file.nb);
  printf("File :\n");
  if(i != -1){
     while(i != file.fin){
       printf("[%d] <- ", file.base[i].valeur);
       i = (i + 1) % file.taille;
     }
     printf("[%d]\n\n", file.base[i].valeur); 
  }
  else{
    printf("Attention c'est vide !\n\n");
  }
}
