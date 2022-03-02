#include <stdio.h>
#define N 10

struct p { int info[N];
           int tope; };

typedef struct p pilaInt;

void inicioP(pilaInt *pi)
{   (*pi).tope=-1;   }

int emptyP(pilaInt pi)
{
    if (pi.tope==-1)  return 1;
              else    return 0;
}

int fullP(pilaInt pi)
{
    if (pi.tope==N-1)  return 1;
              else     return 0;
}

int copyP (pilaInt pi)
{
    return pi.info[pi.tope];
}

void insertP(pilaInt *pi, int nvo)   //PUSH
{
    (*pi).info[++(*pi).tope]=nvo;
}

void supresP(pilaInt *pi) //POP
{
    (*pi).tope--;
}
