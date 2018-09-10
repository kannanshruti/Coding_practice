/*
Ref: 
[1] https://gist.github.com/toboqus/def6a6915e4abd66e922
[2] 
[3] 
*/
#include <iostream>
using namespace std;

struct node {
	int value;
	node *left;
	node *right;
};

class btree {
public:
	btree();
	~btree();
	void insert(int key);
	void print();
	void destroy_tree();
	node *search(int key);

private:
	void insert(int key, node *leaf);
	void print(node *leaf);
	void destroy_tree(node *leaf);
	node *search(int key, node *leaf);
	node *root;
};

btree::btree() {
	root = NULL;
}

btree::~btree() {
	destroy_tree();
}

void btree::destroy_tree(node *leaf) {
	if (leaf != NULL) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::destroy_tree() {
	destroy_tree(root);
}


void btree::insert(int key, node *leaf) {
	if (key < leaf->value) { // If key is lesser than curr node value
		if (leaf->left != NULL) { // Not empty
			insert(key, leaf->left);
		}
		else { // Empty
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if(key >= leaf->value) {
		if (leaf->right != NULL) {
			insert(key, leaf->right);
		}
		else {
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
}


void btree::insert(int key) {
	if (root != NULL) {
		insert(key, root);
	}
	else {
		root = new node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

void btree::print(node *leaf) {
	if (leaf != NULL) {
		print(leaf->left);
		cout << leaf->value << " " << leaf << "\n";
		print(leaf->right);
	}
}

void btree::print() {
	print(root);
	cout << "\n";
}

node *btree::search(int key, node *leaf) {
	if (leaf != NULL) {
		if (leaf->value == key) {
			return leaf;
		}
		else if (leaf->value > key) {
			return search(key, leaf->left);
		}
		else {
			return search(key, leaf->right);
		}
	}
	else {
		return NULL;
	}
}

node *btree::search(int key) {
	return search(key, root);
}

int main() {

	btree *tree = new btree();
	node *search_val1;

	tree->insert(10);
	tree->insert(9);
	tree->insert(15);
	tree->insert(8);
	tree->insert(11);
	tree->print();
	cout << "\n";
	search_val1 = tree->search(10);
	cout << search_val1 << "\n";
	search_val1 = tree->search(15);
	cout << search_val1 << "\n";

	delete tree;
	return 1;
}

/*
1. If object is a pointer, use -> to access class methods
2. If a pointer to a struct is defined, use -> to access its members
3. Creating a pointer to an object, implies that we should make
	sure the pointer points to a class object:
	(a) class1 obj1; obj1.function1()
	(b) class1 *ptr_obj1 = new class1(); ptr.obj1->function1();
	(c) class1 obj1; class1 ptr1; ptr = &obj1  
*/