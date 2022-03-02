#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct nodo{
 Paciente vipd;
 struct nodo *ps;
};

typedef struct nodo Nodo;

struct list {
Nodo *acc;
Nodo *cur;
Nodo *curaux;
};

typedef struct list ListaPac;

void inicioLPac (ListaPac *l)
{
   (*l).acc=NULL;
   (*l).cur=NULL;
   (*l).curaux=NULL;
}

void resetLPac(ListaPac *l)
{
    l->cur=l->acc;
    l->curaux=l->acc;
}

void insertLPac (ListaPac *l, Paciente p)
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
         (l->cur)->vipd=p;
         //Hacer el ingreso del paciente (VER)
                        }
}

void supresLPac(ListaPac *l)
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

void forwardLPac(ListaPac *l)
{
     l->curaux=l->cur;
     l->cur= (l->cur)->ps;
 }

Paciente copyLPac (ListaPac l)
 {
     return (l.cur)->vipd;
 }

 int emptyLPac(ListaPac l)
 {
     if (l.acc==NULL)  return 1;
         else          return 0;
 }

 int fullLPac()
 {Nodo *aux=(Nodo*)malloc(sizeof(Nodo));

     if(aux!=NULL){  free(aux);
                     return 0;}
            else
                 {   return 1;}
 }

int oosLPac(ListaPac l)
{
    if (l.cur==NULL) return 1;
             else    return 0;
}
