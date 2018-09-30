#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack <char> s;

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
	char ch = stack->arr[stack->top];
	--stack->top;
	return ch;
}

void Stack_opn::push(char c) {
	stack->arr[++stack->top] = c;
}

string reverse(Stack_opn k) {
	string s;
	while(!k.isEmpty()) {
		s += k.pop();
	}
	return s;
}

char insertAtBottom(char x) {
	// 1. If stack empty, i.e. latest element, push to stack
	// 2. else pop top element, call same at latest element, push top element
	// 1 inserted, return to reverse, get 2, remove 1, insert 2, push 1, now stack: 1,2. return to reverse
	// now x is 3, stack not empty, so remove 1, call, remove 2, call, stack empty, push 3
	// return to 2, push 2, return to 1, push 1. now stack: 1,2,3 ETC.
	
	if (s.empty()) { // 1.
		s.push(x);
	}
	else {
		char a = s.top(); // 2.
		s.pop();
		insertAtBottom(x);
		s.push(a);
	}
}

char reverse2() {
	// If stack size > 0, pop char, reverse
	// Last one, call isnert at bottom
	// if orig 4,3,2,1, first go into 4, go into 3, go into 2, go into 1
	if (!s.empty()) {
		char x = s.top(); // first 4, next 3, ..
		s.pop();
		reverse2();
		insertAtBottom(x);
	}
}


int main() {
	string str = "1234", str_rev = "", stack_ip = "";
	Stack_opn s1(str.length());
	
	for (int i = 0; i < str.length(); i++) {
		s1.push(str[i]);
		s.push(str[str.length()-i-1]);
	}

	str_rev = reverse(s1);
	cout << "Reverse:" << str_rev << "\n";

	cout << "Reverse2:";
	reverse2();
	while (!s.empty()) {
		char c = s.top();
		s.pop();
		cout << c;
	}
	cout << "\n";
}