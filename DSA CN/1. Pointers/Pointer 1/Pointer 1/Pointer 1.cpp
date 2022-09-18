#include <iostream>

using namespace std;

int main() {
	int i = 10;
	int* p = &i;

	cout << p << endl;
	cout << *p << endl;

	int* j = 0;     
	cout << j << endl;

	cout << *j << endl;

	return 0;
}