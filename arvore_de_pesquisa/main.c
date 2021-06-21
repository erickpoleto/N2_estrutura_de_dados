#include "binary_search_tree.h"

Bst* insert_controller(Bst* tree); 
Bst* remove_controller(Bst* tree);

int main() {
  Bst* tree = NULL;

  int option;
  while ( 0==0 ) {
    printf("-- Arvore de pesquisa --\n");
    printf("-- Operações --\n");
    printf("1 - inserir valor\n");
    printf("2 - remover valor \n");
    printf("3 - printar \n");
    printf("8 - sair \n");
    printf("opção: ");
    scanf("%d", &option);
    switch (option) {
      case 1:
        tree = insert_controller(tree);
        break;
      case 2:
        tree = remove_controller(tree);
        break;
      case 3:
        print_tree(tree);
        break;
      case 8: 
        exit(0);
      default:
        printf("Opção inválida");
        break;
    }  
  }
  return 0;
}

Bst* insert_controller(Bst* tree) {
  int value;
  printf("valor: ");
  scanf("%d", &value);
  tree = insert(tree, value);
  printf("valor inserido!\n");
  printf("\n");
  return tree;  
}

Bst* remove_controller(Bst* tree) {
  int value;
  printf("valor: ");
  scanf("%d", &value);
  tree = remove_node(tree, value);
  printf("\n");
  return tree;
}