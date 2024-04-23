#include <iostream>
using namespace std;

void num() {
	//Static variables lifetime is the lifetime of the program but its visibility is in the function
	static int i = 0;
	i++;
	cout << i << " ";
}


int main() {

	//Question: what is unsigned?
		//No overflow from datatype value, only positive

	//Question: what is static?
		//A static variable in a function keeps its value. "I will not die within this function"
	
	for (int i = 0; i < 5; i++) {
		num();
	}

	return 0;
}