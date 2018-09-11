/*
Ref: https://www.geeksforgeeks.org/cpp-program-for-quicksort/
*/

#include <iostream>
#include <stdio.h>
using namespace std;

class Sorting {
public:
	void print(int *arr, int size1);
	void bubble(int *arr, int size);
	void selection(int *arr, int size);
	void quick(int *arr, int low, int high);
private:
	int partition(int *arr, int low, int high);
	void swap(int *a, int *b);
};

void Sorting::print(int *arr, int size1) {
	/*
	Prints an array
	@param "arr": Pointer to array location
	@param "size1": Length of array
	*/
	for (int i = 0; i < size1; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void Sorting::bubble(int *arr, int size1) {
	/*
	Performs Bubble sorting on array
	@param "arr": Pointer to array location
	@param "size1": Length of array
	*/
	int temp;

	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size1-1; j++) {
			if (arr[j+1] < arr[j]) {
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return;
}

void Sorting::selection(int *arr, int size1) {
	/*
	Performs Selection sorting on array
	@param "arr": Pointer to array location
	@param "size1": Length of array
	*/
	int temp, first;
	for (int i = size1-1; i > 0; i--) {
		first = 0;
		for (int j = 1; j <= i; j++) {
			if (arr[j] > arr[first])
				first = j;
 		}
 		temp = arr[first];
 		arr[first] = arr[i];
 		arr[i] = temp;
	}
	return;
}
void Sorting::quick(int *arr, int low, int high) {
	/*
	Performs Quick sorting on array
	@param "arr": Pointer to array location
	@param "low": Start index of the array to be sorted
	@param "high": End index of the array to be sorted
	*/
	if (low < high) {
		int part = partition(arr, low, high);
		quick(arr, low, part-1);
		quick(arr, part, high);
	}
}

int Sorting::partition(int *arr, int low, int high) {
	/*
	Returns the partitioning element in the array
	@param "arr": Pointer to array location
	@param "low": Start index of the array to be sorted
	@param "high": End index of the array to be sorted
	@return: partitioning element
	*/
	int pivot = arr[high];
	int i = low-1;

	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return i+1;
}

void Sorting::swap(int *a, int *b) {
	/*
	Swaps contents of 2 pointers
	@param  "*a", "*b": Pointers to the content to be swapped
	*/
	int t = *a;
	*a = *b;
	*b = t;
}


int main() {
	Sorting s;
	int a[] = {15,6,31,33,25,13};
	int size1 = sizeof(a) / sizeof(int);
	cout <<  size1 << "\n";
	s.print(a, size1);
	s.bubble(a, size1);
	cout << "Bubble: ";
	s.print(a, size1);

	int b[] = {15,6,31,33,25,13};
	s.selection(b, size1);
	cout << "Selection: ";
	s.print(b, size1);

	int c[] = {15,6,31,33,25,13};
	s.quick(c, 0, size1);
	cout << "Quick: ";
	s.print(c, size1);

	return 1;
}


/*
1. Time and space complexity:
	TC is the amount of time taken by the algorithm to run, 
	function of input length
	SC is the amount of space taken by the algorithm to run,
	function of input length

	Depends on what we're trying to optimize for:
	If time is to be least, then consider TC
	If memory utilization is to be least, then consider SC
	TC:
		1 for loop: check #times it runs
		1 nested for loop: #times outer*#times inner
		Only highest order to be consider
	SC:
		Additional space complexity other, apart from input var
		If 3 function parameters, 1 local variable-> never changes, hence O(1)
		If array, O(n)+other variables
		A calls B 3 times, M+N units (not M+3N)
		A calls B recursively, MN (function is in progress)
*/