#include "Bag.h"
#include "Queue.h"
#include <iostream>
#include "vld.h"

int main(int argc, char* argv[]) {
	using namespace std;
	int foo[5] = { 1, 3, 5, 6, 8 };
	Bag<int> bag;
	Queue<int> queue;
	for (int i = 0; i < 5; i++) {
		bag.add(foo[i]);
		queue.enqueue(foo[i]);
	}
	
	// Bag
	cout << "Bag" << endl;
	Bag<int> b_copy;
	b_copy = bag;
	for (int s : b_copy)
		cout << s << " ";
	cout << endl;
	cout << b_copy.size() << endl;

	// Queue
	cout << "Queue" << endl;
	Queue<int> q_copy;
	q_copy = queue;
	
	int N = queue.size();
	for (int i = 0; i < N; i++)
		cout << queue.dequeue() << " ";
	cout << endl;
	cout << queue.size() << endl;

	for (int s : q_copy)
		cout << s << " ";
	cout << endl;
	cout << q_copy.size() << endl;

	return 0;
}