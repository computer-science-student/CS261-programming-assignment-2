#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Create function prototypes for the different cases for delete.
void _delete_1(); \\hi khanh
void _delete_2();
void _delete_3();

// Undefined reference to createBST() means that you have to create the function
// for that here right?

// Creates the BST. Returns a pointer to the BST.
struct BST* createBST(){
    // Create the first node, root.
    //struct Node * root_prt = malloc(sizeof(struct Node*)); // free this malloc!
    //root_prt->left = NULL;
    //root_prt->right = NULL;

    // Create the BST, tree.
    struct BST * tree = malloc(sizeof(struct BST*)); // free this malloc!
    tree->root = NULL;
    //return 1;
    return tree;
}

void inorderTraversal(struct BST* tree){
    // root head, top, tree,


}
//test editing. Yay!
void insert(struct BST* tree, int key){
    return NULL;
}


int height(struct BST* tree){
    return 123456789;
}

int depth(struct BST* tree, int key){


}

void _delete_1(){

}

void _delete_2(){

}

void _delete_3(){

}

void deleteBST(struct BST* tree){
    // free the other nodes
    free(tree);


}
