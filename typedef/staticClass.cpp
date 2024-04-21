#include <iostream>
using namespace std;

class Num {
	int m_value;
	//Static variable that belongs to the class
	static int m_s;
public:
	Num(int value = 0) : m_value(value) {
		m_s++; //Increment the static variable for every instantiation
	}

	void prn() const {
		cout << "m_value is: " << m_value << endl;
		cout << "in one of " << m_s << " objects" << endl;
	}
	
	//A static function is a function that belongs to the class, not object
	//It is not dependent upon any object instantiated of Num
	static void NoOfObjects() {

		//A static function cannot access a non-static variable. That is, it doesn't know which of the many object's variable it is referring to
		//A static function CAN however access a static variable as there is a one to one relationship

		//cout << m_value << endl; //Can not be accessed
		cout << "Total number of " << m_s << " nums exist" << endl;
 	}

	virtual ~Num() {
		m_s--;
	}

};

int Num::m_s = 0; //Initializing


int main() {

	//Question: How does a static exist in 2 objects? 
	//It doesn't. It becomes class scoped and shared between ALL instances
	//Accessible by both objects as a shared property

	//Complication: Impossible to set it's value in a constructor, which object decides it's value?
	//Line 20 solves this. When an instance of Num is created, that initalized value is shared
	Num N(10);
	Num M(50);

	//This shows us that m_s is class scoped and shared
	N.prn(); //m_value is 10 in one of 2 objects
	M.prn(); //m_value is 50 in one of 2 objects


	Num* p = new Num[100];
	N.prn(); //m_value is 10 in one of 102 objects
	delete[] p;

	N.prn(); //m_value is 10 in one of 2 objects

	Num::NoOfObjects(); //Doesn't need an object to invoke!

	return 0;
}