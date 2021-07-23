#include <stdlib.h>
#include "bst.h"
#include <assert.h>
#include <stdio.h>

// Creates the BST. Returns a pointer to the BST.
struct BST* createBST(){
    // Create the BST, treeRoot.
    struct BST * treeRoot = (struct BST *)malloc(sizeof(struct BST*)); // free this malloc!
    treeRoot->root = NULL;
    return treeRoot;
}

// A function that traverses a BST in order
// and prints the key of each node as it is
// traversed. This method is a method called
// Morris traversal of the tree.
void inorderTraversal(struct BST* BST)
{
	struct Node* current;
	struct Node* parent;

	// Base case. If the BST is empty,
	// there is nothing to print.
	current = BST->root;
	if (current == NULL)
		return;

	while (current != NULL) {
		// current->left == NULL indicates that 
		// the algorithm has reached the next 
		// smallest number. So the algorithm
		// prints current and then continues
		// to the right, if possible. 
		if (current->left == NULL) {
			printf("%d ", current->key);
			current = current->right;
		}

		// else if current->left != NULL, then there
		// is a left branch to traverse. Having 
		// traversed that branch, the algorithm needs
		// to return to current and traverse its
		// right branch. To facilitate this return,
		// the algorithm seeks the immediate 
		// predecessor of current. This immediate
		// predecessor will ultimately be the
		// last node of the left branch that is 
		// traversed. So, a temporary link is formed
		// between this immediate predecessor and
		// current. In this way, the algorithm
		// can return to current after traversing
		// the left branch.
		else {
			// The algorithm seeks the immediate
			// predecessor.
			parent = current->left;
			while (parent->right != NULL
			       && parent->right != current)
				parent = parent->right;
				
				// The algorithm has found the immediate
				// predecessor and creates a temporary
				// link back to current.
				if (parent->right == NULL) {
					parent->right = current; 
					current = current->left;
				}
				
				// If parent->right == current, then the
				// algorithm has traversed the entire
				// left branch and has returned to the root
				// node, i.e. current. So the temporary link
				// is removed and current is printed. The
				// algorithm moves on to the right branch.
				else {
					parent->right = NULL;
					printf("%d ", current->key);
					current = current->right;
				}
		}
	}
}


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
	// This while loop traverses to the right node
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

	// The new node is created as a new leaf
	// on the left or right node under parent.
	// Append the new node to the tree.
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

/*_max is used to get_height*/
int get_height(struct Node* root){

    int left_height = 0;
    int right_height = 0;
 //recursive call keep increment the left and right heigh of tree and sub trees
    if(root->left != NULL){
        left_height = 1 + get_height(root->left);
    }

     if(root->right != NULL){
        right_height = 1 + get_height(root->right);
    }
	//compare height of each possible path
    return _max(left_height, right_height);

}

int height(struct BST* bst){
    printf("height function called\n");
    struct Node* curr = bst->root;
    if (curr == NULL){//if no binary tree exist
        return -1;
    }
    else {
        int max_height = get_height(curr);
    }
	
int depth(struct BST* base, int key) {
    struct Node* curr = base->root; // current node
    int count = 0; // initialize the counter variable

    while (curr != NULL) {
        if (key == curr->key){
                return count;
        }
        else if (key < curr->key) {
            // go left
            ++count;
            curr = curr->left;
        }
        else {
            // go right
            ++count;
            curr = curr->right;
        }
    }
    return count;
}

/*
  DISCLAIMER: I took a standard C program of a post order traversal and replaced the
  print function with a function that frees the node. This works because, by doing a post order
  traversal, I always free a leaf node (case 1 delete).
  This standard C program of a post order traversal was taken from here:
  https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/

  Given a binary tree, free its nodes according to the "bottom-up" post-order traversal.
  */
void freePostorder(struct Node* node)
{
    // Base case. Stop recursive function when
    // the node is null (has reached the bottom of the tree).
    if (node == NULL)
        return;

    // first recur on left subtree
    // Goes through all the nodes on the left side recursively
    freePostorder(node->left);

    // then recur on right subtree
    freePostorder(node->right);

    // Free the node
    free(node);

}


// Deletes all the nodes in a BST.
void deleteBST(struct BST* tree){
    // Traverse through the tree, deleting each and every node.

    // Retrieve the current and set it to be the root.
    struct Node* rootNode = tree->root;
	// Put the current in the function printoPostorder()
	freePostorder(rootNode);

    // free the tree
    free(tree);
}

