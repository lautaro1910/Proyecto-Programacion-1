#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct nod{
 Paciente vipd;
 struct nod *ps;
};

typedef struct nod Nod;

struct lista {
Nod *acc;
Nod *cur;
Nod *curaux;
};

typedef struct lista ListaPrio;

void inicioLPrio (ListaPrio *l)
{
   (*l).acc=NULL;
   (*l).cur=NULL;
   (*l).curaux=NULL;
}

void resetLPrio(ListaPrio *l)
{
    l->cur=l->acc;
    l->curaux=l->acc;
}

void insertLPrio (ListaPrio *l, Paciente p)
{  Nod *aux=(Nod*)malloc(sizeof(Nod));

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
         //Hace el ingreso del paciente
                        }
}

void supresLPrio(ListaPrio *l)
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

void forwardLPrio(ListaPrio *l)
{
     l->curaux=l->cur;
     l->cur= (l->cur)->ps;
 }

//Cambiamos a tipo paciente
 Paciente copyLPrio (ListaPrio l)
 {
     return (l.cur)->vipd;
 }

 int emptyLPrio(ListaPrio l)
 {
     if (l.acc==NULL)  return 1;
         else          return 0;
 }

 int fullLPrio()
 {Nod *aux=(Nod*)malloc(sizeof(Nod));

     if(aux!=NULL){  free(aux);
                     return 0;}
            else
                 {   return 1;}
 }

int oosLPrio(ListaPrio l)
{
    if (l.cur==NULL) return 1;
             else    return 0;
}

