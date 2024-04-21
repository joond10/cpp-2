#include <iostream>
using namespace std;

int main() {

	//Age becomes a type that is equivalent to a size_t
	//Basically defining a type called age with equivalency to a standard C++ type
	typedef size_t age;
	age a; 
	cin >> a;
	return 0;
}