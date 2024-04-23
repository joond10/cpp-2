#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
struct Coord {
	double x, y;
};
struct CoordId {
	double x, y;
	long long val;
	char id;
};

//Alignment
//The size of test could be: sizeof(char) + padding + sizeof(double) + sizeof(int) + padding.
struct test {
	char c;
	double d;
	int i;
};
//could be sizeof(double) + sizeof(int) + sizeof(char) + padding.
struct test2 {
	double d;
	int i;
	char c;
};

//So, if a char variable takes 1 byte and is followed by an int variable, 
//the compiler may insert 3 bytes of padding after the char variable to align the int variable to the next 4 byte boundary.
//This ensures that accessing the int variable is efficient and doesn't incur any performance penalties due to misalignment.
struct test3 {
	char c;
	int i;
	double d;
};

void foo(char* str) {
	//Prints the size of the pointer, not the size of the array
	cout << "size in foo: " << sizeof(str) << endl;
}

//sizeof is an operator that returns the size in bytes of its operand. It's commonly used to determine the size of variables, data types, or structures.
int main() {
	char s[1000];
	foo(s);
	cout << "in main: " << sizeof(s) << endl; //1000 * sizeof(char)

	//The actual size might be larger than the sum of its members. 
	//Padding is added by the compiler to ensure proper alignment of the members in memory, which can improve access speed.
	cout << "size of Coord " << sizeof(Coord) << endl;
	cout << "size of Coord " << sizeof(CoordId) << endl;
	cout << "size of test " << sizeof(test) << endl;
	cout << "size of test2 " << sizeof(test2) << endl;
	cout << "size of test3 " << sizeof(test3) << endl;
	return 0;

	//Size of int: 4 bytes
    //Alignment requirement of int: 4 bytes
	//In this example, sizeof(int) returns the size of an integer, which is 4 bytes on many systems, 
	//and alignof(int) returns the alignment requirement of an integer, which is also 4 bytes on many systems. 






}