/*
Stacks;
Linear data structure, LIFO, FILO
Basic operations: Push, pop, top, isEmpty
*/

#include <iostream>
using namespace std;

#define MAX 1000

class Stack {
	int top;
public:
	int a[MAX];
	Stack() {top = -1;}
	bool push(int x);
	void print();
	bool pop();
	int top_ele();
	bool isEmpty();
};

bool Stack::push(int x) {
	if (top >= MAX-1) {
		cout << "Stack overflow";
		return false;
	}
	else {
		a[++top] = x;
		return true;
	}
}

bool Stack::pop() {
	if (top < 0) {
		cout << "No elements to pop.\n";
		return false;
	}
	else {
		cout << a[--top] << "\n";
		return true;
	}
}

void Stack::print() {
	for (int i = 0; i <= top; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

int Stack::top_ele() {
	if (top >= 0) 
		return a[top];
	else
		cout << "Stack is empty\n";
}

bool Stack::isEmpty() {
	if (top < 0) {
		return true;
	}
	return false;
}

int main() {
	Stack s;
	s.push(1);
	s.print();
	s.push(2);
	s.print();
	s.push(3);
	s.print();
	s.pop();
	s.print();
	int a = s.top_ele();
	cout << "Top: " << a << "\n";
	s.isEmpty();
}