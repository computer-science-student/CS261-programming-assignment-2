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

/*
// Old insertNode
struct Node* _insertNode(struct Node* Node, int key)
{
	if (Node == NULL)
		return _newNode(key);

	if (key < Node->key)
		Node->left = _insertNode(Node->left, key);
	else if (key > Node->key)
		Node->right = _insertNode(Node->right, key);

	return Node;
}
*/

void insert(struct BST* BST, int key)
{
	struct Node* Node;
	Node = (*BST).root;

	while (Node != NULL)
	{
		if (key < (*Node).key)
			Node = (*Node).left;
		else if (key > (*Node).key)
			Node = (*Node).right;
	}

	Node = _newNode(key);

	printf("%d ", (*Node).key);

	return;
}


int height(struct BST* tree){
    // TODO for computer-science-student
    return 123456789;
}

int depth(struct BST* tree, int key){
    // TODO for khanhble


}

// Commented out the various ways to delete
/*void _delete_1(){}
void _delete_2(){}
void _delete_3(){}*/

void deleteBST(struct BST* tree){
    // free the other nodes
    free(tree);


}
