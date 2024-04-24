#include <iostream>
using namespace std;

void prnAddress(int* ptr) {
	cout << unsigned(ptr) << endl;

}

//This is literally how we normally use pointers, pass the address
//Dereference num and increment it. So the same works as well if we pass an existing pointer
//That is, we pass the address of existing pointer and add another asterisk to parameter and dereference inside body
void gotoNextNumber(long* num) {
	(*num)++;
}

void yetGotoNextOneLevelHigher(int*** ptr) {
	(**ptr)++;
}

//Just like how we have to use target of with a normal pointer
//We add an asterisk to the parameter
void gotoNextElement(int** ptr) { // pointer ptr (points to->) int* 
	//(*ptr)++;

	//Example of going higher and higher, so remember, whenever we pass the address, 
	//the parameter should add another asterisk as well as another asterisk for dereference
	yetGotoNextOneLevelHigher(&ptr);
	prnAddress(*ptr);
}


//But to simplify in C++, use int* reference and no need to dereference ref
void gotoNextElement(int*& ref) { //integer-pointer, reference ref
	ref++;
	prnAddress(ref);
}



int main() {
	//long n = 30;
	//gotoNextNumber(&n);
	//cout << n << endl;

	//Why do we need this? 
		//You will find yourself needing to pass the address of a pointer sometime

	int ar[5]{ 10,20,30,40,50 };
	int* p = ar;
	prnAddress(p);

	cout << "*p: " << *p << endl;
	p++;
	prnAddress(p);

	cout << "*p: " << *p << endl;
	gotoNextElement(&p);
	prnAddress(p);

	cout << "*p: " << *p << endl;
	gotoNextElement(p);
	prnAddress(p);

	cout << "*p: " << *p << endl;
	return 0;
}