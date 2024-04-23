#include <iostream>
using namespace std;
double tax = 0.7;
int value() {
	return 10;
}
//Be aware that this function returns a reference
double& taxValue() {
	return tax;
}

//lvalue - an lvalue is something we can actually put at left side of an assignment operator
//rvalue - an rvalue can always stay on right side of an assignment operator but not left side

int main() {
	int i;
	int* p;
	i = 6;
	//rvalues cannot be put at left
	//6 = i 
	p = &i;
	//&i = 1234 
	i = value();
	//value() = i;


	cout << taxValue() << endl;
	//Tax value can become an lvalue due to it returning a reference of a double called tax
	taxValue() = 0.13;
	cout << tax << endl;
	cout << taxValue() << endl;
}