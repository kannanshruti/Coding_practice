#include <iostream>
#include <string>
using namespace std;

struct Stack {
	int top;
	unsigned capacity;
	char *arr;
};

class Stack_opn {
public:
	Stack *stack;
	Stack_opn(unsigned capacity);
	bool isEmpty();
	char pop();
	void push(char c);
};

Stack_opn::Stack_opn(unsigned capacity) {
	stack = (struct Stack *) malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->arr = (char*) malloc(stack->capacity * sizeof(char));
}
bool Stack_opn::isEmpty() {
	return stack->top < 0;
}

char Stack_opn::pop() {
	if (isEmpty())
		return -1;
	// cout << "Popping:" << stack->arr[stack->top] << "\n";
	char ch = stack->arr[stack->top];
	--stack->top;
	return ch;
}

void Stack_opn::push(char c) {
	stack->arr[++stack->top] = c;
	cout << stack->top << " ";
	// cout << "Pushing:" << stack->arr[stack->top] << "\n";
}

string reverse(Stack_opn k) {
	string s;
	while(!k.isEmpty()) {
		s += k.pop();
		cout << s << " ";
	}
	return s;
}

int main() {
	string str = "qwerty", str_rev = "";
	Stack_opn s1(str.length());
	cout << s1.stack->capacity << "\n";
	cout << s1.stack->top << "\n";
	
	for (int i = 0; i < str.length(); i++) {
		cout << str[i] << " ";
		s1.push(str[i]);
		cout << "\n";
	}
	str_rev = reverse(s1);
	cout << "Reverse:" << str_rev << "\n";
}