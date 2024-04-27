#include <iostream>
#include <cstring>
using namespace std;

struct Container {
	int value;
	bool hasMore(const Container&);
};


//Same thing, no difference
//template <class T>
template <typename T>
T largest(T a, T b) {
	return a > b ? a : b;
}


//Specialized templates used for explicit type invokations
//As you can see const char* is not a fundamental type, and it has a different implementation
//Similar to an overload, we use a specialized template
template <>
const char* largest<const char*>(const char* a, const char* b) {
	return strcmp(a, b) > 0 ? a : b;
}

//It is important to note that, overloaded functions take higher priority than templates
//So in some cases, it may be better to use overloads rather than redundant generic code
//"In principle, good design prefers overloading to the equivalent specialization, and only specializes when it is required."
template <>
Container largest<Container>(Container C1, Container C2) {
	return C1.hasMore(C2) ? C1 : C2;
}

int main() {
	int a, b = 10;
	double c = 11.0;
	char s1[] = "abc";
	char s2[] = "cdefg";
	cout << largest(s1, s2) << endl;
	//We can resolve our template calls manually with whatever data type desired just as we would when instantiating a template class 
	a = largest<int>(b, c); 

	return 0;
}