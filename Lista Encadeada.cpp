#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

typedef int TipoChave; 
typedef struct { 
  int Chave; 
  /* outros componentes */ 
} TipoItem; 

typedef struct Celula_str *Apontador; 
typedef struct Celula_str { 
  TipoItem Item; 
  Apontador Prox; 
} Celula; 

typedef struct { 
  Apontador Primeiro, Ultimo; 
} TipoLista; 

/* ========================================================================= */ 
void FLVazia(TipoLista *Lista) 
{ 
  Lista->Primeiro = (Apontador) malloc(sizeof(Celula)); 
  Lista->Ultimo = Lista->Primeiro; 
  Lista->Primeiro->Prox = NULL; 
} 

int Vazia(TipoLista Lista) 
{ 
  return (Lista.Primeiro == Lista.Ultimo); 
} 

void Insere(TipoItem x, TipoLista *Lista) 
{ 
  Lista->Ultimo->Prox = (Apontador) malloc(sizeof(Celula)); 
  Lista->Ultimo = Lista->Ultimo->Prox; 
  Lista->Ultimo->Item = x; 
  Lista->Ultimo->Prox = NULL; 
} 

void Retira(Apontador p, TipoLista *Lista, TipoItem *Item) 
{ 
  /*  ---   Obs.: o item a ser retirado e  o seguinte ao apontado por  p --- */ 
  Apontador q; 
  if (Vazia(*Lista) || p == NULL || p->Prox == NULL) 
  { printf(" Erro   Lista vazia ou posi  c   a o n  a o existe\n"); 
    return; 
  } 
  q = p->Prox; 
  *Item = q->Item; 
  p->Prox = q->Prox; 
  if (p->Prox == NULL) Lista->Ultimo = p; 
  free(q); 
} 

void Imprime(TipoLista Lista) 
{ 
  Apontador Aux; 
  Aux = Lista.Primeiro->Prox; 
  while (Aux != NULL) 
    { printf("%d\n", Aux->Item.Chave); 
      Aux = Aux->Prox; 
    } 
} 

getch();
return 0;
