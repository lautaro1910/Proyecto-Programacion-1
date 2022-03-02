#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Paciente.h"

struct nod{
 Paciente vipd;
 struct nodo *ps;
};

typedef struct nod Nodo;

struct list {
Nodo *acc;
Nodo *cur;
Nodo *curaux;
};

typedef struct list listaP;

void inicioL (listaP *l)
{
   (*l).acc=NULL;
   (*l).cur=NULL;
   (*l).curaux=NULL;
}

void resetL(listaP *l)
{
    l->cur=l->acc;
    l->curaux=l->acc;
}

void insertL (listaP *l, Paciente p)
{  Nodo *aux=(Nodo*)malloc(sizeof(Nodo));

     if(aux!=NULL){
                   if((l->cur)==(l->acc))  { l->acc=aux;
                                             (*aux).ps=l->cur; //PREGUNTAR ESTE WARNING
                                             l->cur=l->acc;
                                             l->curaux=l->acc;
                                            }
                           else{      (l->curaux)->ps=aux;
                                      (*aux).ps=l->cur;
                                      l->cur=aux;
                               }
         (l->cur)->vipd=p;
         //Hacer el ingreso del paciente (VER)
                        }
}

void supresL(listaP *l)
{
    if ((l->cur)==(l->acc)) {
                              (*l).acc=((*l).cur)->ps;
                              free((*l).cur);
                              (*l).cur=(*l).acc;
                              (*l).curaux=(*l).acc;
                             }
              else {
                         (l->curaux)->ps=(l->cur)->ps;
                          free((*l).cur);
                         (*l).cur=(l->curaux)->ps;
                      }
}

void forwardL(listaP *l)
{
     l->curaux=l->cur;
     l->cur= (l->cur)->ps;
 }

//Cambiar a tipo paciente (VER)
 Paciente copyL (listaP l)
 {
     return (l.cur)->vipd;
 }

 int emptyL(listaP l)
 {
     if (l.acc==NULL)  return 1;
         else          return 0;
 }

 int fullL()
 {Nodo *aux=(Nodo*)malloc(sizeof(Nodo));

     if(aux!=NULL){  free(aux);
                     return 0;}
            else
                 {   return 1;}
 }

int oosL(listaP l)
{
    if (l.cur==NULL) return 1;
             else    return 0;
}
