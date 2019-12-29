#include <iostream>

// this a problem with NULL constant 

using namespace std;

void func(char* str) { cout << "char* version" << endl; }
void func(int i) { cout << "integer version" << endl; }

int main() {
	func(NULL);
	func(nullptr);
	return 0;
}