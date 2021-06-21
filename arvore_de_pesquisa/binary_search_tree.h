#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* left;
    struct node* right;
};

typedef struct node Node;
typedef struct node Bst;


Bst* create() {
  return NULL;
}

Bst* insert(Bst* tree, int info) {

    Node* new_node = (Node*) malloc(sizeof(Node));
    
    if(new_node == NULL) {
      return NULL;
    }

    new_node->info = info;
    new_node->left = NULL;
    new_node->right = NULL;

    Node* curr_node = tree;
    Node* prev_node = NULL;

    if(tree == NULL) {
      tree = new_node;
      return tree;
    }

    while (curr_node != NULL) {
        prev_node = curr_node;
        
        if(curr_node->info == info) {
          free(new_node);
          return tree;
        }
        
        if(curr_node->info > info) {
          curr_node = curr_node->left;
        } else {
          curr_node = curr_node->right;
        }
    }

    if(prev_node->info > info) {
        prev_node->left = new_node;
    } else {
        prev_node->right = new_node;
    }
    return tree;    
}


Bst* min_node(Bst* tree) {
  if(tree == NULL){
    return NULL;
  }
  
  if(tree->left != NULL){
    return min_node(tree->left);
  }

  return tree;
}

Bst* remove_node(Bst* tree, int info) {
    if(tree==NULL) {
      return NULL;
    }

    if (info > tree->info) {
      tree->right = remove_node(tree->right, info);
      return tree;
    } 
    
    if(info < tree->info) {
      tree->left = remove_node(tree->left, info);
      return tree;
    }

    if(tree->left == NULL && tree->right == NULL) {
      free(tree);
      return NULL;
    } 

    if(tree->left == NULL || tree->right == NULL) {
      Bst* aux_tree;
      if(tree->left == NULL) {
        aux_tree = tree->right;
      } else {
        aux_tree = tree->left;
      }
      free(tree);
      return aux_tree;
    } 

    Bst* aux_tree = min_node(tree->right);
    tree->info = aux_tree->info;
    tree->right = remove_node(tree->right, aux_tree->info);

    return tree;
}

void dimensional_print(Bst* tree) {
    if(tree == NULL) {
        return;
    }  
    dimensional_print(tree->left);
    printf("%d ", tree->info);
    dimensional_print(tree->right);
}

void print_tree(Bst* tree) {
  dimensional_print(tree);
  printf("\n");
}

