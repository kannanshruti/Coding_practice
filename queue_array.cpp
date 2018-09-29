/*
Queue: Linear structure, FIFO
Operations: Enqueue (Add item, if full, overflow), 
			Dequeue (Remove item, if empty, underflow)
			Front (Get first item)
			Rear (Get last item)
*/
#include <iostream>
using namespace std;

struct Queue {
	int front, rear, size;
	unsigned capacity;
	int *arr;
};

class Queue_opn {
public:
	Queue *queue;
	Queue_opn(unsigned capacity);
	bool isFull();
	bool isEmpty();
	void enqueue(int i);
	int dequeue();
	int front1();
	int rear1();
	void print();
};

Queue_opn::Queue_opn(unsigned capacity) {
	queue = (Queue*) malloc(sizeof(Queue));
	queue->front = 0;
	queue->rear = 0;
	queue->capacity = capacity;
	queue->arr = (int*) malloc(capacity * sizeof(int));
}

bool Queue_opn::isFull() {
	return (queue->rear - queue->front == queue->capacity);
}

bool Queue_opn::isEmpty() {
	return (queue->rear - queue->front == 0);
}

void Queue_opn::enqueue(int i) {
	if (isFull())
		return;
	queue->arr[queue->rear] = i;
	++queue->rear;
	
}

int Queue_opn::dequeue() {
	if (isEmpty())
		return -1;
	int i = queue->arr[queue->front];
	++queue->front;
	return i;
}

int Queue_opn::front1() {
	return queue->arr[queue->front];
}

int Queue_opn::rear1() {
	return queue->arr[queue->rear-1];
}

void Queue_opn::print() {
	if (isEmpty())
		return;
	for (int i = queue->front; i < queue->rear; i++) {
		cout << queue->arr[i] << " ";
	}
	cout << "\n";
}

int main() {
	Queue_opn q(20);
	cout << q.queue->capacity << "\n";
	for (int i = 0; i < 5; i++) {
		q.enqueue(i);
	}
	q.print();
	int j = q.dequeue();
	cout << "rem." << j << "\n";
	q.print();
	int f = q.front1();
	cout << f << "\n";
	int r = q.rear1();
	cout << r << "\n";

}