#include <iostream>
#include "clsMyStack.h"

using namespace std;

int main() {

	clsMyStack <int> MyStack;

	MyStack.push(10);
	MyStack.push(20);
	MyStack.push(30);
	MyStack.push(40);
	MyStack.push(50);


	cout << "\nStack:\n";
	MyStack.Print();

	cout << "\nStack Size : " << MyStack.Size();
	cout << "\nStack Top  : " << MyStack.Top();
	cout << "\nStack Bottom : " << MyStack.Bottom();

	MyStack.pop();

	cout << "\n\nStack After Pop item:\n";
	MyStack.Print();
}