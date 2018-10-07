#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
	int data;
	node *left;
	node *right;
};

class BST {
public:
	node *root;
	BST();
	void insert(node *ptr, int level);
	void display(node *leaf, int level);
};

BST::BST() {
	root = NULL;
}

void BST::insert(node *leaf, int value) {
	if (root == NULL) {
		root = new node;
		root->data = value;
		root->left = NULL;
		root->right = NULL;
		cout << "Root!\n";
	}
	else if (value == leaf->data) {
		cout << "Element exists\n";
		return;
	}
	else if (value < leaf->data) {
		if (leaf->left != NULL) {
			insert(leaf->left, value);
		}
		else {
			leaf->left = new node;
			leaf->left->data = value;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else {
		if (leaf->right != NULL) {
			insert(leaf->right, value);
		}
		else {
			leaf->right = new node;
			leaf->right->data = value;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
}

void BST::display(node *leaf, int level) {
	if (leaf != NULL) {
		display(leaf->right, level+1);
		for (int i = 0; i < level; i++)
			cout << " ";
		cout << leaf->data << "\n";
		display(leaf->left, level+1);
	}
}

void BST::preorder(bst.root) {

}

int main() {
	int choice, value;

	BST bst;
	while(1) {
		cout << "Options: \n";
		cout << "1. Insert element \n";
		cout << "2. Display graphically\n";
		cout << "3. Pre-order traversal\n";
		cout << "3. Delete element\n";
		cout << "20. Exit \n";
		cin >> choice;

		switch(choice) {
			
			case 1:
				cout << "Enter value:\n";
				cin >> value; 
				bst.insert(bst.root, value); break;
			case 2: bst.display(bst.root, 1); break;
			case 3: bst.preorder(bst.root); break;
			case 20: exit(1); 
			default: "Choose from options.\n"; break;
		}
	}

	return 1;
}