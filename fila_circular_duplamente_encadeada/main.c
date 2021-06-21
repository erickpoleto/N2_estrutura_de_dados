#include <stdio.h>
#include "doubly_circular_queue.h"

void insere_controlador(Fila* fila, char pos);
void remove_controlador(Fila* fila, char pos);

int main(void) {
  
  Fila* fila = cria();
  
  int option;
  while ( 0==0 ) {
    printf("-- Fila --\n");
    printf("-- Operações --\n");
    printf("1 - inserir no inicio\n");
    printf("2 - remover do inicio \n");
    printf("3 - inserir no fim \n");
    printf("4 - remover do fim \n");
    printf("5 - imprimir \n");
    printf("6 - liberar \n");
    printf("8 - sair \n");
    printf("opção: ");
    scanf("%d", &option);
    switch (option) {
      case 1:
        insere_controlador(fila, 'i');
        break;
      case 2:
        remove_controlador(fila, 'i');
        break;
      case 3:
        insere_controlador(fila, 'f');
        break;
      case 4:
        remove_controlador(fila, 'f');
        break;
      case 5:
        imprime(fila);
        printf("\n");
        break;
      case 6:
        libera(fila);
        fila = cria();
        printf("\n");
        break;
      case 8:
        libera(fila);
        exit(0);
        break;
      default:
        printf("Opção inválida");
        break;
    }  
  }
  return 0;
}

void insere_controlador(Fila* fila, char pos) {
  int valor;
  printf("valor: ");
  scanf("%d", &valor);
  if(pos == 'i') {
    enqueue_inicio(fila, valor);
  } else {
    enqueue_fim(fila, valor);
  }
  printf("valor inserido!\n");
  printf("\n");  
}

void remove_controlador(Fila* fila, char pos) {
  if(pos == 'i') {
    dequeue_inicio(fila);
  } else {
    dequeue_fim(fila);
  }
  printf("valor removido!\n");
  printf("\n");
}