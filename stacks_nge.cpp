/*
Prints the next greatest element for every element (greatest element 
to the right of an element).

*/
#include <iostream>
#include <stack>

using namespace std;

void nge(int *arr, int n) {
	stack <int> s;
	s.push(arr[0]);
	// vector<int> nge;

	for (int i = 1; i < n; i++) {
		if (s.empty()) {
			s.push(arr[i]);
			continue;
		}
		while (!s.empty() && s.top() < arr[i]) {
			cout << s.top() << "-->" << arr[i] << "\n";
			s.pop();
		}
		s.push(arr[i]);
	}
	while(!s.empty()) {
		cout << s.top() << "-->" << -1 << "\n";
		s.pop();
	}
}

int main() {
	int arr[] = {13,11,21,3};
	int n = sizeof(arr) / sizeof(int);
	nge(arr, n);
	return 1;
}