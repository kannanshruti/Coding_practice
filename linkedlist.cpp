#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node {
	int data;
	node *next;
};

class list {
private:
	node *head, *tail;
public:
	list();
	void printList();
	node *createNode(int value);
	void insertBegin();
	void insertEnd();
	void insertPosition();
	void deletePosition();
	void updatePosition();
	void searchElement();
};

list::list() {
	head = NULL;
	tail = NULL;
}

void list::printList() {
	node *current;
	current = head;
	while (current) {
		cout << " " << current->data << "\n";
		current = current->next;
	}
}

node *list::createNode(int value) {
	node *temp = new node; // Pointer to a new struct_node
	if (temp == NULL) {
		cout << "Memory not allocated\n";
		return 0;
	}
	else {
		temp->data = value;
		temp->next = NULL;
		return temp;
	}
}

void list::insertBegin() {
	node *temp, *temp1;
	int value;

	cout << " Enter value: ";
	cin >> value;

	temp = createNode(value);
	if (head == NULL) {
		head = temp;
		head->next = NULL;
	}
	else {
		temp1 = head;
		head = temp;
		head->next = temp1;
	}
}

void list::insertEnd() {
	node *temp, *temp_new;
	int value;

	cout << " Enter value: ";
	cin >> value;
	temp_new = createNode(value);

	temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = temp_new;
	temp_new->next = NULL;	
}

void list::insertPosition() {
	node *temp, *temp_new, *temp_swap;
	int value, position, count = 0;

	cout << " Enter position & value:\n";
	cin >> position >> value;
	temp_new = createNode(value);

	temp = head;
	while(temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
		count++;
	}
	if (position == 1) {
		if (head == NULL) {
			head = temp_new;
			head->next = NULL;
		}
		else {
			temp_swap = head;
			head = temp_new;
			head->next = temp_swap;
			temp_swap->next = NULL;
		}
	}
	else if (position > 0 && position <= count) {
		temp = head;
		for (int i = 1; i <= count; i++) {
			if (i == position-1) {
				temp_swap = temp->next;
				temp->next = temp_new;
				temp_new->next = temp_swap;
				break;
			}
			temp = temp->next;
		}
	}
	else {
		cout << "Out of range\n";
	}
}

void list::deletePosition() {
	node *temp, *temp_del;
	int position, count = 0;
	cout << "Enter position: ";
	cin >> position;
	cout << "\n";

	temp = head;
	while(temp != NULL) {
		temp = temp->next;
		count++;
	}


	if (position == 1) {
		if (head == NULL) cout << "No element";
		else {
			head = head->next;
		}
	}
	else if (position>0 && position<=count){
		temp = head;
		for (int i = 1; i <= count; i++) {
			if (i == position-1) {
				temp_del = temp->next;
				break;
			}
			temp = temp->next;
		}
		temp->next = temp_del->next;
	}
	else {
		cout << "Out of range\n";
	}
}

void list::updatePosition() {
	node *temp;
	int position, count=0, value;

	cout << "Enter position to be updated, and value: ";
	cin >> position >> value;
	cout << "\n";

	temp = head;
	while(temp != NULL) {
		temp = temp->next;
		count++;
	}
	temp = head;
	for (int i = 1; i <= count; i++) {
		if (i == position) {
			temp->data = value;
		}
		temp = temp->next;
	}
}

void list::searchElement() {
	node *temp;
	int value, count = 0, flag = 0;

	cout << "Enter value to be searched: ";
	cin >> value;
	cout << "\n";

	temp = head;
	while (temp != NULL) {
		temp = temp->next;
		count++;
	}
	temp = head;
	for (int i = 0; i <= count; i++) {
		if (temp->data == value) {
			cout << "Element @: " << i+1 << "\n";
			flag = 1;
			break;
		}
		temp = temp->next;
	}
	if (flag == 0) {
		cout << "Element not found.\n";
	}
}

int main() {
	list list1;
	int choice = 0;
	
	while(1) {		
		cout << "\n1. Print\n";
		cout << "2. Insert @beginning\n";
		cout << "3. Insert @end\n";
		cout << "4. Insert @position\n";
		cout << "5. Delete @position\n";
		cout << "6. Update @position\n";
		cout << "7. Search @value\n";
		cout << "10. Exit\n";
		cout << "Option:";

		cin >> choice;
		
		switch(choice) {
			case 1:
				list1.printList(); break;
			case 2:
				list1.insertBegin(); break;
			case 3:
				list1.insertEnd(); break;
			case 4:
				list1.insertPosition(); break;
			case 5:
				list1.deletePosition(); break;
			case 6:
				list1.updatePosition(); break;
			case 7:
				list1.searchElement(); break;
			case 10:
				exit(1);
				break;	
		}
	}
}