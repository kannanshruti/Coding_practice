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
	void midList();
	void deleteMid();
	void reverse();
	void addOne();
	int countElementOccurences();
	void pop();
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
	node *temp, *new_node, *next;
	int position, value, count = 0;

	cout << "Enter position, value: ";
	cin >> position >> value;
	cout << "\n";

	new_node = createNode(value);

	temp = head;
	while (temp != NULL) {
		temp = temp->next;
		++count; // Length of list
	}
	if (position == 1) { // Insert @ head
		if (count == 0) {
			head = new_node;
			head->next = NULL;
		}
		else if (count > 0) {
			temp = createNode(value);
			temp->next = head;
			head = temp;
		}
	}
	else if (position > 0 && position <= count) { // Insert in between
		temp = head;
		for (int i = 1; i <= count-1; i++) {
			if (i+1 == position) {
				next = temp->next;
				new_node->next = next;
				temp->next = new_node;
			}
			temp = temp->next;
		}
	}
	else if (position == count+1) { // Insert at end
		temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new_node;
	}
	else {
		cout << "Out of range.";
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

void list::midList() {
	node *temp1, *temp2;
	temp1 = head;
	temp2 = head;
	if (head != NULL) {
		while (temp2 != NULL && temp2->next != NULL) {
			temp1 = temp1->next;
			temp2 = temp2->next->next;
		}
		cout << "Element at the middle: " << temp1->data << "\n";
	}
}

void list::deleteMid() {
	node *temp1, *temp2, *prev;
	temp1 = head;
	temp2 = head;
	if (head != NULL) {
		while(temp2 != NULL && temp2->next != NULL) {
			prev = temp1;
			temp1 = temp1->next;
			temp2 = temp2->next->next;
		}
		prev->next = temp1->next;
	}
}

void list::reverse() {
	node *prev = NULL, *curr = head, *next = NULL; 

	if (head != NULL) {
		while(curr != NULL) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}
}

void list::addOne() {
	node *temp;
	int carry = 1, sum = 0;
	reverse();
	temp = head;
	if (head != NULL) {
		while (temp != NULL) {
			sum = carry + temp->data;
			if (sum > 9) {
				carry = 1;
				temp->data = 0;
			}
			else {
				carry = 0;
				temp->data = sum;
			}
			temp = temp->next;
		}
		reverse();
	}
}

int list::countElementOccurences() {
	node *temp;
	temp = head;
	int num, count = 0;
	
	cout << "Enter the number to be counted: ";
	cin >> num;

	while (temp != NULL) {
		if (temp->data == num) {
			++count;
		}
		temp = temp->next;
	}
	cout << "\nOccurences: " << count << "\n";
}

void list::pop() {
	node *temp;
	int value;
	if (head == NULL) {
		cout << "No elements to pop.";
		return;
	}
	value = head->data;
	free(head); 
	head = head->next;
	cout << value << "\n";
}

// void reverse_group() {
// 	node *temp;
// 	int group;

// 	cout << "Enter group number: ";
// 	cin >> group;

	
// }

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
		cout << "8. Print mid value\n";
		cout << "9. Delete mid value\n";
		cout << "10. Reverse list\n";
		cout << "11. Add 1 to number repr. by list\n";
		cout << "12. Count #occurences of element\n";
		cout << "13. Pop value\n";
		// cout << "12. Reverse in groups of k\n";
		cout << "20. Exit\n";
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
			case 8:
				list1.midList(); break;
			case 9:
				list1.deleteMid(); break;
			case 10:
				list1.reverse(); break;
			case 11:
				list1.addOne(); break;
			case 12:
				list1.countElementOccurences(); break;
			case 13:
				list1.pop(); break;
				// list1.reverse_group(); break;
			case 20:
				exit(1); break;	
		}
	}
}