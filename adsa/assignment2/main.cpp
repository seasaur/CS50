#include <iostream>
#include <vector>
// #include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node *left;
	Node *right;
	int height;
};

Node* newNode(int data)
{
	Node* node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

void printPostorder(Node* node)
{
	if (node == NULL)
		return;

	printPostorder(node->left);
	printPostorder(node->right);

	cout << node->data << " ";
}

void printInorder(Node* node)
{
	if (node == NULL) {
		return;
	}

	printInorder(node->left);

	cout << node->data << " ";

	printInorder(node->right);
}

void printPreorder(Node* node)
{
	if (node == NULL)
		return;

	cout << node->data << " ";

	printPreorder(node->left);
	printPreorder(node->right);
}

int height(Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b)
{
	return (a > b)? a : b;
}

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

	// new root
	return x;
}

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

	// new root
	return y;
}

int getBalance(Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

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

	/* 3. Get the balance */
	int balance = getBalance(node);

	// If unbalanced

	// Left Left
	if (balance > 1 && data < node->left->data)
		return rightRotate(node);

	// Right Right
	if (balance < -1 && data > node->right->data)
		return leftRotate(node);

	// Left Right
	if (balance > 1 && data > node->left->data)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left
	if (balance < -1 && data < node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* node pointer */
	return node;
}

Node* deleteNode(Node* root, int data)
{

    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller
    // than the root's key, then it lies
    // in left subtree
    if ( data < root->data)
        root->left = deleteNode(root->left, data);

    // If the key to be deleted is greater
    // than the root's key, then it lies
    // in right subtree
    else if( data > root->data)
        root->right = deleteNode(root->right, data);

    // if key is same as root's key, then
    // This is the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) ||
            (root->right == NULL) )
        {
            Node *temp = root->left ?
                         root->left :
                         root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
            *root = *temp; // Copy the contents of
                           // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)

		/* loop down to find the leftmost leaf */
		Node* temp = root->right;
		while (temp->left != NULL) {
			temp = root->left;
		}
		// Copy the inorder successor's
		// data to this node
		root->data = temp->data;

		// Delete the inorder successor
		root->right = deleteNode(root->right,temp->data);
        }
    }

    // If the tree had only one node
    // then return
    if (root == NULL)
    return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF
    // THIS NODE (to check whether this
    // node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced,
    // then there are 4 cases

    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

bool ifNodeExists(struct Node* node, int key)
{
    if (node == NULL)
        return false;

    if (node->data == key)
        return true;

    /* then recur on left subtree */
    bool res1 = ifNodeExists(node->left, key);
    // node found, no need to look further
    if(res1) {
        return true;
    }
    /* node is not found in left,
    so recur on right subtree */
    bool res2 = ifNodeExists(node->right, key);

    return res2;
}

int main()
{
	Node *root = NULL;
    string rawInput;
    vector<string> input;
    getline(cin, rawInput); //take input including space
	int inst = 1; //check if it's A or D
	int end = 0; //end loop
	string ins = "";
    string temp = "";

// 	for(int i=0;i<rawInput.length();i++){

// 		if(rawInput[i]==' '){ //add A and D here
// 			input.push_back(temp);
// 			temp = "";
// 			inst=1;

// 			if((rawInput[i+1]=='P') || (rawInput[i+1]=='I')) {
// 				end=1;
// 			}
// 		}
// 		else{
// 				if ((inst==1) && (end==0)) {
// 					ins=ins+rawInput[i];
// 					inst=0;
// 				}
// 				else {
// 					temp.push_back(rawInput[i]);
// 				}
// 		}

// 	}
// 	input.push_back(temp);

   int size = input.size();

    for (int i=0; i<size; i++) {

		input.at(i) = "1";

    }
	cout << ins << endl;

    for (int i=0; i<size-1; i++) { //not counting finishing move
        if(ins[i]=='A') {
			if(ifNodeExists(root, stoi(input.at(i)))!=true) {
				root = insert(root, stoi(input.at(i)));
			}
		}

		if(ins[i]=='D') {
			if(ifNodeExists(root, stoi(input.at(i)))==true) {
				root = deleteNode(root, stoi(input.at(i)));
			}
		}

		// cout << input.at(i) << endl;
		// cout << root << endl;
    }

	// cout << root << endl;

	// printInorder(root);
	// cout << root << endl;

	if(root==NULL) {
        cout << "EMPTY" << endl;
        return -1;
    }

    if (input.at(size-1) == "IN") {
		// cout << "bruh" << endl;
        printInorder(root);
		cout << '\n';
		// cout << root << endl;
        return 0;
    }

    if (input.at(size-1) == "PRE") {
		// cout << "saasd" << endl;
        printPreorder(root);
		cout << '\n';
        return 0;
    }

    if (input.at(size-1) == "POST") {
        printPostorder(root);
		cout << '\n';
        return 0;
    }

	return 0;
}
