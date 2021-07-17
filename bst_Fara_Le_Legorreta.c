#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Create function prototypes for the different cases for delete.
void _delete_1();
void _delete_2();
void _delete_3();

// Creates the BST. Returns a pointer to the BST.
struct BST* createBST(){
    // Create the BST, tree.
    struct BST * tree = malloc(sizeof(struct BST*)); // free this malloc!
    tree->root = NULL;
    //return 1;
    return tree;
}

/*
void _inorder(struct Node* Node)
{
	if (Node != NULL)
	{
		_inorder(Node->left);
		printf("%d ", Node->key);
		_inorder(Node->right);
	}
}
*/


void inorderTraversal(struct BST* BST)
{
//	_inorder(BST->root);
	struct Node* Node;
	Node = (*BST).root;

//	while (Node != NULL)
//	{
//		Node = (*Node).left;
//	}

    // Computer-science-student commented out the following
    // printf statement to ensure that inorderTraversal compiles
	//printf("%d ", (*Node).key);
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

// _newNode creates and returns a new node.
// Used by insert function.
struct Node* _newNode(int key)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

	temp->key = key;
	temp->left = temp->right = NULL;

	return temp;
}

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

// Old depth started by Computer-Science-Student.
//int depth(struct BST* tree, int key){}


// the first parameter of depth should be of this type:
// struct BST*
int depth(struct BST* root, int x){
    // TODO for khanhble
	if (root == NULL)
		return -1;

	int dist = -1;

	/*if ((root->key == x)
	    || (dist = depth(root->left, x)) >= 0
	    || (dist = depth(root->right, x)) >=0)
		return dist + 1;*/

	return dist;
}



// Commented out the various ways to delete
/*void _delete_1(){}
void _delete_2(){}
void _delete_3(){}*/

void deleteBST(struct BST* tree){
    // free the other nodes
    free(tree);


}
