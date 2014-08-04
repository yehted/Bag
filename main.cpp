#include "Bag.h"
#include <iostream>
#include "vld.h"

int main(int argc, char* argv[]) {
	using namespace std;
	int foo[5] = { 1, 3, 5, 6, 8 };
	Bag<int> bag;
	for (int i = 0; i < 5; i++) {
		bag.add(foo[i]);
	}
	Bag<int> copy = bag;

	for (int s : copy)
		cout << s << " ";
	cout << endl;
	cout << copy.size() << endl;

	return 0;
}