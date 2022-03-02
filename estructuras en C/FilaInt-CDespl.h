#include <stdio.h>
#define N 10

struct fi { int info[N];
            int ult; };

typedef struct fi filaInt;

void inicioF(filaInt *fi)
{   (*fi).ult=-1;   }

int emptyF(filaInt fi)
{
    if (fi.ult==-1)  return 1;
              else    return 0;
}

int fullF(filaInt fi)
{
    if (fi.ult==N-1)  return 1;
              else     return 0;
}

int copyF (filaInt fi)
{
    return fi.info[0];
}

void insertF(filaInt *fi, int nvo)
{
    (*fi).info[++(*fi).ult]=nvo;
}

void supresF(filaInt *fi)
{int i;
   for(i=0;i<(*fi).ult;i++) (*fi).info[i]=(*fi).info[i+1];
   (*fi).ult--;
}
