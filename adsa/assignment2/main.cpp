#include <iostream>
#include <vector>
using namespace std;


/* A binary tree node has data, pointer to left child
and a pointer to right child */

class Node
{
	public:
	int data;
	Node *left;
	Node *right;
	int height;
};

/* Helper function that allocates a
new node with the given data and
NULL left and right pointers. */
Node* newNode(int data)
{
	Node* node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}


/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void printPostorder(Node* node)
{
	if (node == NULL)
		return;

	// first recur on left subtree
	printPostorder(node->left);

	// then recur on right subtree
	printPostorder(node->right);

	// now deal with the node
	cout << node->data << " ";
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(Node* node)
{
	if (node == NULL) {
		return;
	}

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	cout << node->data << " ";

	/* now recur on right child */
	printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(Node* node)
{
	if (node == NULL)
		return;

	/* first print data of node */
	cout << node->data << " ";

	/* then recur on left subtree */
	printPreorder(node->left);

	/* now recur on right subtree */
	printPreorder(node->right);
}

// C++ program to insert a node in AVL tree
#include<bits/stdc++.h>
using namespace std;

// An AVL tree node


// A utility function to get maximum
// of two integers
int max(int a, int b);

// A utility function to get the
// height of the tree
int height(Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum
// of two integers
int max(int a, int b)
{
	return (a > b)? a : b;
}


// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
Node *rightRotate(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left),
					height(y->right)) + 1;
	x->height = max(height(x->left),
					height(x->right)) + 1;

	// Return new root
	return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// Recursive function to insert a data
// in the subtree rooted with node and
// returns the new root of the subtree.
Node* insert(Node* node, int data)
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return(newNode(data));

	if (data < node->data)
		node->left = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);
	else // Equal datas are not allowed in BST
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
						height(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && data < node->left->data)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && data > node->right->data)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && data > node->left->data)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && data < node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

// bool ifNodeExists(struct Node* node, int key)
// {
//     if (node == NULL)
//         return false;

//     if (node->data == key)
//         return true;

//     /* then recur on left subtree */
//     bool res1 = ifNodeExists(node->left, key);
//     // node found, no need to look further
//     if(res1) {
//         return true;
//     }
//     /* node is not found in left,
//     so recur on right subtree */
//     bool res2 = ifNodeExists(node->right, key);

//     return res2;
// }


// Driver Code
int main()
{
	Node *root = NULL;
    string rawInput;
    vector<string> input;
    getline(cin, rawInput); //take input including space

    //converting to string vector separated by space
    string temp = "";
	for(int i=0;i<rawInput.length();i++){

		if(rawInput[i]==' '){
			input.push_back(temp);
			temp = "";
		}
		else{
			temp.push_back(rawInput[i]);
		}

	}
	input.push_back(temp);

   int size = input.size();

    for (int i=0; i<size-1; i++) { //not counting finishing move

        // if(ifNodeExists(root, stoi(input.at(i)))!=true) {
            root = insert(root, stoi(input.at(i)));
        // }
		// cout << input.at(i) << endl;
		// cout << root << endl;
    }

	printInorder(root);

    if(root=NULL) {
        cout << "EMPTY" << endl;
        return -1;
    }

    if (input.at(size-1) == "IN") {
		cout << "bruh" << endl;
        printInorder(root);
        // return 0;
    }

    if (input.at(size-1) == "PRE") {
		cout << "saasd" << endl;
        printPreorder(root);
        // return 0;
    }

    if (input.at(size-1) == "POST") {
        printPostorder(root);
        // return 0;
    }


	return 0;
}
