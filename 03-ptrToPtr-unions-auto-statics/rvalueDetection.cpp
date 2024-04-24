#include <iostream>
using namespace std;

void display(int& a) {
	cout << "lvalue: " << a << endl;
}
void display(int&& a) {
	cout << "rvalue: " << a << endl;
}
/*
The double ampersand (&&) in C++ is used to denote an rvalue reference, 
and it doesn't imply a reference of a reference or anything more complex. 
It's simply a syntactical construct used to declare a parameter as being able to bind to rvalue arguments.*/

/*
So, to summarize, when you see && in a function parameter declaration, 
you should interpret it as indicating that the function can accept rvalue arguments. 
It's a key feature in modern C++ for implementing move semantics and improving performance in certain scenarios.
*/
int main() {
	int i = 10;
	display(i);
	display(123);
	return 0;
}