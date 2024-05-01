#include <iostream>
using namespace std;

//New function signatures, drop the return type, replace with auto, append return type to end 
auto add(int a, int b) -> int {
	return a + b;
}


auto main() -> int {
	cout << "OOP345 NBB 07-Oct02" << endl;

	return 0;
}