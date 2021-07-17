#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Undefined reference to createBST() means that you have to create the function
// for that here right?

// Creates the BST. Returns a pointer to the BST.
struct BST* createBST(){
    // Create the first node, root.
    struct Node * root_prt = malloc(sizeof(struct Node*)); // free this malloc!
    root_prt->left = NULL;
    root_prt->right = NULL;

    // Create the BST, tree.
    struct BST * tree = malloc(sizeof(struct BST*)); // free this malloc!
    tree->root = root_prt;
    return tree;
}

void inorderTraversal(struct BST* tree){
    // root head, top, tree,


}

void insert(struct BST* tree, int key){
    return NULL;
}


int height(struct BST* tree){

}

int depth(struct BST* tree, int key){


}


void deleteBST(struct BST* tree){


}
