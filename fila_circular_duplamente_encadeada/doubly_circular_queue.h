#include <stdio.h>
#include <stdlib.h>

struct no{
   int info;
   struct no* elo_anterior;
   struct no* elo_proximo;
};

typedef struct no No;

struct fila{
   No* inicio;
   No* fim;
};

typedef struct fila Fila;

Fila* cria(){
   Fila* fila = (Fila*) malloc(sizeof(Fila));
   fila->inicio = NULL;
   fila->fim = NULL;
   return fila;
}

int verifica_vazia(Fila* fila) {
  if(fila->inicio == NULL) {
    printf("A fila está vazia\n");
    return 0;
  } else {
    return 1;
  }
}

int verifica_memoria(No* no) {
  if(no == NULL) {
    printf("Memoria insuficiente\n");
    return 0;
  } else {
    return 1;
  }
}

No* insere_inicio(No* inicio, No* fim, int info){
  No* no = (No*) malloc(sizeof(No));
  if(!verifica_memoria(no)) {
    return NULL;
  }
  no->info = info;
  if(inicio == NULL){
    no->elo_proximo = no;
    no->elo_anterior = no;
  } else {
    no->elo_anterior = fim;
    fim->elo_proximo = no;
    no->elo_proximo = inicio;
    inicio->elo_anterior = no;    
  }
  return no;
}

void enqueue_inicio(Fila* fila , int info){
   fila->inicio = insere_inicio(fila->inicio, fila->fim, info);
   if(fila->fim == NULL){
      fila->fim = fila->inicio;
   }
}

No* retira_inicio(No* inicio, No* fim){
   No* no = inicio->elo_proximo;
   if (no != inicio){
    no->elo_anterior = fim;
    fim->elo_proximo = no;
   }
   free(inicio);
   return no;
}

int dequeue_inicio(Fila* fila){
  fila->inicio = retira_inicio(fila->inicio, fila->fim);
  if (fila->inicio == NULL){
    fila->fim = NULL;
  }
  return 1;
}

No* insere_fim(No* inicio, No* fim , int info){
   No* no = (No*) malloc(sizeof(No));
   no->info = info;
   if (fim == NULL){
    no->elo_proximo = no;
    no->elo_anterior = no;
   } else {
     fim->elo_proximo = no;
     no->elo_anterior = fim;
     no->elo_proximo = inicio;
     inicio->elo_anterior = no;
   }
   return no;
}

void enqueue_fim(Fila* fila , int info){
   fila->fim = insere_fim(fila->inicio, fila->fim , info);
   if(fila->inicio == NULL){
      fila->inicio = fila->fim;
   }
}

No* retira_fim(No* inicio, No* fim){
   No* no = fim->elo_anterior;
   if (no != fim){
    no->elo_proximo = inicio;
    inicio->elo_anterior = no;  
   }
   free(fim);
   return no;
}

int dequeue_fim(Fila* fila){
   fila->fim = retira_fim(fila->inicio, fila->fim);
   if (fila->fim == NULL){
    fila->inicio = NULL;
   }
   return 1;
}

int imprime(Fila* fila){
   No* no;
   no = fila->inicio;
   if(!verifica_vazia(fila)) {
    return 0;
   }
   do {
    printf("%d\n",no->info);
    no = no->elo_proximo;
   } while(no != fila->inicio);
   printf("\n");
   return 1;
}

int libera(Fila* fila){
   No* no = fila->inicio;
   No* no_anterior;
   if(!verifica_vazia(fila)) {
    return 0;
   }
   do {
      no_anterior = no->elo_proximo;
      free(no);
      no = no_anterior;
   } while(no != fila->inicio);
   free(fila); 
   return 1;
}