#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct nod{
 int vipd;
 struct nodo *ps;
};

typedef struct nod Nodo;

struct list {
Nodo *acc;
Nodo *cur;
Nodo *curaux;
};

typedef struct list listaU;

void inicioL (listaU *l)
{
   (*l).acc=NULL;
   (*l).cur=NULL;
   (*l).curaux=NULL;
}

void resetL(listaU *l)
{
    l->cur=l->acc;
    l->curaux=l->acc;
}

void insertL (listaU *l, int d)
{  Nodo *aux=(Nodo*)malloc(sizeof(Nodo));

     if(aux!=NULL){
                   if((l->cur)==(l->acc))  { l->acc=aux;
                                             (*aux).ps=l->cur;
                                             l->cur=l->acc;
                                             l->curaux=l->acc;
                                            }
                           else{      (l->curaux)->ps=aux;
                                      (*aux).ps=l->cur;
                                      l->cur=aux;
                               }
         (l->cur)->vipd=d;
                        }
}

void supresL(listaU *l)
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

void forwardL(listaU *l)
{
     l->curaux=l->cur;
     l->cur= (l->cur)->ps;
 }


 int copyL (listaU l)
 {
     return (l.cur)->vipd;
 }

 int emptyL(listaU l)
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

int oosL(listaU l)
{
    if (l.cur==NULL) return 1;
             else    return 0;
}
