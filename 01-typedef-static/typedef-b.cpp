#include <iostream> //Preprocessor directive - Literally just copy and paste before compiling
using namespace std;
int main() {

	//This type name is really long, we can define this ourselves
	const unsigned long long int* numptr;

	//Now it's called culli_type
	typedef const unsigned long long int* culli_type;
	culli_type a;

	//Question: What are the types of "a" and "b"? 
	int* a, b;
	//The pointer does not supercede the comma
	// a is int*
	// b is int 

	//Define an int ptr ourselves (workaround)
	typedef int* intptr;
	intptr p, q;
	// p is int*
	// q is int*

	return 0;
}