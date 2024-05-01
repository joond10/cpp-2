#include <iostream>
using namespace std;

//Using new function signature

//How would it know what to return if a template receives two different types?
template <typename Lt, typename Rt>
//Drop return type, add auto, arrow notation to "declare type". Leaves it to the compiler
auto add(Lt a, Rt b) -> decltype(a + b) {
	return a + b;
}


auto main() -> int {
	cout << "OOP345 NBB 07-Oct02" << endl;
	int a = 10;
	long long x = 300000000000LL, y;
	double d = 30.3;
	double res;
	y = add(x, a);
	cout << y << endl;
	res = add(a, d);
	cout << res << endl;
	return 0;
}