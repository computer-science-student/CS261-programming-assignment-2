#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include <assert.h>

// Create function prototypes for the different cases for delete.
void _delete_1();
void _delete_2();
void _delete_3();


// Creates the BST. Returns a pointer to the BST.
struct BST* createBST(){
    // Create the BST, treeRoot.
    struct BST * treeRoot = (struct BST *)malloc(sizeof(struct BST*)); // free this malloc!
    treeRoot->root = NULL;
    //return 1;
    return treeRoot;
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

// A function that traverses a BST in order
// and prints each key of each node as it is
// traversed.
void inorderTraversal(struct BST* BST)
{
//	_inorder(BST->root);

	struct Node* current;
	struct Node* parent;

	current = BST->root;
	// Base case. If the BST is empty,
	// there is nothing to print.
	if (current == NULL)
		return;

	// While the current node is not empty,
	// traverse left as far as possible, print
	// print that node, and move right.
	while (current != NULL) {
		if (current->left == NULL) {
			printf("%d ", current->key);
			current = current->right;
		}


		else {
			parent = current->left;
			while (parent->right != NULL
			       && parent->right != current)
				parent = parent->right;

				if (parent->right == NULL) {
					parent->right = current;
					current = current->left;
				}

				else {
					parent->right = NULL;
					printf("%d ", current->key);
					current = current->right;
				}
		}
	}
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

// A utility function that allocates memory for a
// new node, stores the value passed as key to that
// new node, and returns the memory address of the
// new node. Used by the insert function.
struct Node* _newNode(int key)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

	assert(temp); // check if temp got assigned to malloc or not

	temp->key = key;
	temp->left = temp->right = NULL;

	return temp;
}


// A function that finds the appropriate leaf
// within BST under which to append a new node
// with the value passed as key.
void insert(struct BST* BST, int key)
{
	struct Node* current;
	struct Node* parent;

	current = BST->root;

	// Base case. If the tree is empty,
	// create a node to store as root.
	if (current == NULL) {
		BST->root = _newNode(key);
		return;
	}

	// Find the appropriate leaf onto which
	// a new node will be appended. The
	// appropriate leaf is found when
	// current == NULL. The leaf is stored
	// as 'parent'.
	while (current != NULL) {
		if (key < current->key) {
			parent = current;
			current = current->left;
		}
		else if (key > current->key) {
			parent = current;
			current = current->right;
		}
	}

	// The new node is created as a new left
	// or right node under parent.
	if (key < parent->key) {
		parent->left = _newNode(key);
		return;
	}
	else if (key > parent->key) {
		parent->right = _newNode(key);
		return;
	}
	return;
}




/* I don't think we need any of the following code anymore! -Tyler

	struct Node* Node;
	Node = (*bst).root;

	if (Node == NULL){
        // node is root so create root!
        bst->root = (struct Node *)malloc(sizeof(struct Node *));
        bst->root = _newNode(key);
        printf("%d\n", (*(bst->root)).key);
        //bst->root = Node; // this is what is causing seg faults
        //printf("%d ", (*Node).key);
        return;
	}

    struct Node* parent = NULL; // prt for parent

	// When node is null, while ends.
	while (Node != NULL) { // ensures that the inserted node is a leaf
		if (key < (*Node).key){ // goes to the left
            parent = Node;
            Node = (*Node).left;
		}
		else if (key > (*Node).key){ // goes to the right
            parent = Node;
		    Node = (*Node).right;
		}
	}

	Node = _newNode(key);

	assert(parent);
    if(key < (*parent).key)
        (*parent).left = Node;
    else
        (*parent).right = Node;

	// not inserting the new node anywhere just printing.

	printf("%d ", (*Node).key);

	return;
}

End of block to be deleted. */


int max(int x, int y)
{
    if(x<y)
        return y;
    else
        return x;
}


int height(struct BST* bst){
    // Returns the height of the tree
    // by counting the amount of times one goes left/right
    // and gets the max.
    // I am still getting seg fault errors from height() function,
    // so I commented out height() for now until I fix these seg fault errors - Computer-Science-Student
    /*
    struct BST *leftSubtree, *rightSubtree;
	struct Node* Node;
	Node = (*bst).root;

    if (Node == NULL){
        return 0;
    }

    leftSubtree->root = (struct Node *)malloc(sizeof(struct Node *));
    rightSubtree->root = (struct Node *)malloc(sizeof(struct Node *));
    leftSubtree->root = (*Node).left;
    rightSubtree->root = (*Node).right;
    printf("key of node: %d\n", (*Node).key);

    return max( height(leftSubtree), height(rightSubtree ) ) + 1;
    */
}

int depth(struct BST* root, int key){
    // Base case checks if root is leaf.
	if (root == NULL){
        return -1;
	}

	int dist = -1;

	//if ((root->key == x)
	  //  || (dist = depth(root->left, x)) >= 0
	   // || (dist = depth(root->right, x)) >=0)
		//return dist + 1;

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

