#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Node {
	public:
	int data;
	Node *left;
	Node *right;
	int height;
};

Node* newNode(int data) {
	Node* node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

void printPostorder(Node* node) {
	if (node == NULL) {
		return;
	}

	printPostorder(node->left);
	printPostorder(node->right);

	cout << node->data << " ";
}

void printInorder(Node* node) {
	if (node == NULL) {
		return;
	}

	printInorder(node->left);

	cout << node->data << " ";

	printInorder(node->right);
}

void printPreorder(Node* node) {
	if (node == NULL) {
		return;
	}

	cout << node->data << " ";

	printPreorder(node->left);
	printPreorder(node->right);
}

int height(Node * node) {
	if (node == NULL) {
		return 0;
	}

	return node->height;
}

int max(int a, int b) {
	if (a>b) {
		return a;
	}
	return b;
}

Node *rightRotate(Node *y) {
	Node *x = y->left;
	Node *node = x->right;

	// Perform rotation
	x->right = y;
	y->left = node;

	// Update heights
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	// new root
	return x;
}

Node *leftRotate(Node *x) {
	Node *y = x->right;
	Node *node = y->left;

	// Perform rotation
	y->left = x;
	x->right = node;

	// Update heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	// new root
	return y;
}

int getBalance(Node *node) {
	if (node == NULL) {
		return 0;
	}
	return height(node->left) - height(node->right);
}

Node* insert(Node* node, int data) {
	if (node == NULL) {
		return(newNode(data));
	}

	if (data < node->data) {
		node->left = insert(node->left, data);
	}

	else if (data > node->data) {
		node->right = insert(node->right, data);
	}

	else {
		return node;
	}

	node->height = 1 + max(height(node->left), height(node->right));

	int balance = getBalance(node);

	// If unbalanced

	if (balance > 1 && data < node->left->data) {
		return rightRotate(node);
	}

	if (balance < -1 && data > node->right->data) {
		return leftRotate(node);
	}

	if (balance > 1 && data > node->left->data) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && data < node->right->data) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

bool ifNodeExists(Node* node, int data) {
    if (node == NULL) {
        return false;
	}
    if (node->data == data) {
        return true;
	}

    bool LT = ifNodeExists(node->left, data);

    if(LT) {
        return true;
    }

    bool RT = ifNodeExists(node->right, data);

    return RT;
}

Node * deleteNode(Node *root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left,data);
    }

	else if (data >  root->data) {
        root->right = deleteNode(root->right,data);
    }

	else {
        if (root->left == NULL || root->right == NULL) {
            Node * temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }

			else {
                *root = *temp;
                free(temp);
			}
        }

		else {
			Node * temp = root->left;
			while(temp->right != NULL) {
        		temp = temp->right;
    		}

            root->data = temp->data;
            root->left = deleteNode(root->left,temp->data);
        }
    }

    if (root == NULL) {
		return NULL;
	}

    root->height = 1 + max(height(root->left),height(root->right));
    int balance = getBalance(root);

    //left
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    else if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    //right
    else if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    else if (balance < -1 && getBalance(root->right) > 0 ) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main() {
	Node *root = NULL;
    string rawInput;
    vector<string> input;
    getline(cin, rawInput); //take input including space

	string instruction = "";
    string temp = "";
	// cout << rawInput << endl;
	for(int i=0;i<rawInput.length();i++) {

		// if(!(isdigit(rawInput[i]))){ //add A and D here
		if(rawInput[i]==' ') {
			input.push_back(temp);
			temp = "";
			// inst=1;
		}
		else if((rawInput[i]=='A') || (rawInput[i]=='D')) {
			// temp.push_back(rawInput[i]);
			// input.push_back(temp);
			// temp = "";
			instruction = instruction + rawInput[i];
		}
		// }

		else {
			temp.push_back(rawInput[i]);
		}

	}
	input.push_back(temp);

   int size = input.size();

    // for (int i=0; i<size; i++) {

	// 	cout << input.at(i) << endl;

    // }
	// cout << instruction << endl;

    for (int i=0; i<size-1; i++) { //not counting finishing move
        if(instruction[i]=='A') {
			if(ifNodeExists(root, stoi(input.at(i)))!=true) {
				root = insert(root, stoi(input.at(i)));
			}
		}

		else if(instruction[i]=='D') {
			if(ifNodeExists(root, stoi(input.at(i)))==true) {
				root = deleteNode(root, stoi(input.at(i)));
				// cout << "here";
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

    else if (input.at(size-1) == "IN") {
		// cout << "bruh" << endl;
        printInorder(root);
		cout << '\n';
		// cout << root << endl;
    }

    else if (input.at(size-1) == "PRE") {
		// cout << "saasd" << endl;
        printPreorder(root);
		cout << '\n';
    }

    else if (input.at(size-1) == "POST") {
        printPostorder(root);
		cout << '\n';
    }

	return 0;
}