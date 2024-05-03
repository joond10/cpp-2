#include <iostream>
using namespace std;
void sum(int a, int b) {
	cout << (a + b) << endl;
}
void prod(int a, int b) {
	cout << (a * b) << endl;
}
auto main() -> int {
	cout << "08-Oct06 OOP345 NBB" << endl;
	int x = 10;
	int y = 5;

/*
- To create a pointer that can hold the same address as a function,
we type the same signature with a new pointer name

- Don't put variable names, because you don't know which function you're calling
- We preceded the identfier with an asterisk to discern a function pointer from a function prototype
- It must be within parantheses to say "I want it to be a pointer to a function that returns void"
- This is one variable that can hold the address of function that returns two ints and returns a void now!
*/

	void (*funcptr)(int, int) = nullptr;

	//Assign this pointer the sum function
	funcptr = sum;

	//Both pointing to the same location in memory!
	cout << unsigned(sum) << endl;
	cout << unsigned(funcptr) << endl;
	//(*funcptr)(10, 20); // C language version
	funcptr(10, 30); // Call the sum fucntion C++ version

	//Assign this pointer the prod function
	funcptr = prod;

	//Both pointing to the same location in memory!
	cout << unsigned(prod) << endl;
	cout << unsigned(funcptr) << endl;

	funcptr(10, 30); // call the prod function

	return 0;
}