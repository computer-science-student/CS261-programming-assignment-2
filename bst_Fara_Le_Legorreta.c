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
    // Create the BST, tree.
    struct BST * treeRoot = malloc(sizeof(struct BST*)); // free this malloc!
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

    assert(temp); // check if temp got assigned to malloc or not

	temp->key = key;
	temp->left = temp->right = NULL;

	return temp;
}

void insert(struct BST* BST, int key)
{
	struct Node* Node;
	Node = (*BST).root;

	if (Node == NULL){
        // node is root so create root!
        Node = _newNode(key);
        BST -> root = Node;
        printf("%d ", (*Node).key);
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
    struct BST *leftSubtree, *rightSubtree;
	struct Node* Node;
	Node = (*bst).root;

    if (Node == NULL){
        return 0;
    }

    leftSubtree->root = (*Node).left;
    rightSubtree->root = (*Node).right;
    printf("key of node: %d\n", (*Node).key);

    return max( height(leftSubtree), height(rightSubtree ) ) + 1;
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
