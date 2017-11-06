/* Name: Kanokpatai Kanato
 * ID: 5680412
 */
#include <stdlib.h>
#include <stdio.h>
#include "btree.h"

void insert(Node **tree, int val) {
  Node *temp = NULL;

  if (*tree == NULL ){
    temp = (Node *)malloc(sizeof(Node));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = val;
    *tree = temp;
  }

  if ( val > (*tree)->data){
    insert(&(*tree)->right, val);
  }

  else if ( val < (*tree)->data) {
    insert(&(*tree)->left , val);
  }

    // IMPLEMENT
}

void walk(Node *tree, int depth){
  if (tree == NULL){
    return ;
  }

  for (int i =0; i<depth; i++ ){
    printf("  ");
  }
  printf("|-" );
  printf("%d\n",tree->data );

  walk(tree->left, depth+1);
  walk(tree->right, depth+1);
}


void print(Node *tree) {
  if (!tree){
    return;
    }
  if (tree != NULL){
    printf("%d\n", tree->data);
  }
  walk(tree->left, 1);
  walk(tree->right, 1);

    // IMPLEMENT
}

void delete(Node *tree) {
  if (tree != NULL){
    delete(tree->left);
    delete(tree->right);
    free(tree);
  }
}

Node *lookup(Node ** tree, int val) {
  if (!(*tree) ){
    return NULL;
  }
  if ((*tree)->data == val){
    return *tree;
  }
  else if ((*tree)->data < val){
    return lookup(&((*tree)->right), val);
  }
  else if ((*tree)->data > val){
    return lookup(&((*tree)->left), val);
  }
  return NULL;
    // IMPLEMENT
}


/***** Expected output: *****
7
|-2
  |-1
  |-4
|-10
  |-15
    |-12
      |-11
Found
Not Found
 *****************************/
int main(int argc, char **argv)
{
    Node *root = NULL;
    Node *target = NULL;

    // add nodes
    insert(&root, 7);


    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 10);
    insert(&root, 1);
    insert(&root, 15);
    insert(&root, 12);
    insert(&root, 11);
    //
    // // Lets see how the tree looks
    print(root);
    //
    // // Check if 4 in the tree
    target = lookup(&root, 4);
    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }
    //
    // Check if 44 in the tree
    target = lookup(&root, 44);
    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }
    //
    // // Now let's free up the space
    delete(root);
    printf("===========delete======\n" );

    // print(root);

}
