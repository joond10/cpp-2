#include <iostream>
using namespace std;
void add(int a, int b) {
	cout << a << "+" << b << "=" << (a + b) << endl;
}

int main() {

	//Understanding that pointer to function essentially packages data that sits in memory and they have an address

	//Put the protptype inside brackets with a asterisk preceding

	//Funcptr becomes an address for that function and if you set it to the name of a function
	//You can call the logic of that function using that pointer

	//Use case: When you want the logic to be passed as data 
	//and when you want different logics passed to your program or functions
	void (*funcPtr)(int, int) = add;
	//(*funcPtr)(10, 2); // C
	funcPtr(10, 2); // C++
	return 0;
}