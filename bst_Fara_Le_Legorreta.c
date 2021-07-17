#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Create function prototypes for the different cases for delete.
void _delete_1();
void _delete_2();
void _delete_3();

// _newNode creates and returns a new node.
// Used by insert function.
struct Node* _newNode(int key)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

	temp->key = key;
	temp->left = temp->right = NULL;

	return temp;
}


// Creates the BST. Returns a pointer to the BST.
struct BST* createBST(){
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
