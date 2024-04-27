#include <iostream>
#include "CStr.h"
#include "Tracer.h"
using namespace std;
using namespace sdds;
class Name {
private:
    char* m_value{};
public:
    //Single argument constructor
    Name(const char* value = nullptr) {
        if (value) {
            CStr::allocNcpy(m_value, value);
        }
        tracer << "Create " << m_value << nl;
    }
    //Copy constructor
    Name(const Name& N) {
        tracer << "Copy " << N.m_value << nl << "  using: ";
        //operator=(N);
        *this = N;
    }
    //Move constructor
    Name(Name&& N) {
        //Both are the same
        //operator=(move(N));
        *this = move(N);
    }
    //Copy assignment operator
    Name& operator=(const Name& N) {
        if (this != &N) {
            tracer << "Assign " << m_value << " to " << N.m_value << nl;
            delete[] m_value;
            CStr::allocNcpy(m_value, N.m_value);
        }
        return *this;
    }
    //Move assignment operator
    //As you can see it's almost identical except we remove const and denote the r-value or
    //to-be-moved object as double ampersand 
    Name& operator=(Name&& N) {
        if (this != &N) {
            tracer << " Move assign " << N.m_value << " into " << m_value << " by assignment" << nl;
            delete[] m_value;
            //Makes our destination/current object point to our source/to-be-moved object
            m_value = N.m_value;
            //Makes our source/to-be-moved object a dummy object
            N.m_value = nullptr;
        }
        return *this;
    }



    ~Name() {
        tracer << "Remove " << m_value << " from memory" << nl;
        delete[] m_value;
    }
    ostream& print(ostream& os = cout)const {
        return os << (m_value ? m_value : "(Nullstr)");
    }
    istream& read(istream& is = cin) {
        delete[] m_value;
        m_value = CStr::read(is);
        return is;
    }
};

ostream& operator<< (ostream& os, const Name& N) {
    return N.print(os);
}
istream& operator>> (istream& is, Name& N) {
    return N.read(is);
}
Name getName() {
    Name N;
    cout << "Enter a name: ";
    cin >> N;
    return N;
}

int main() {
    tracer.trace(false);
    Name A = "Fred"; //Single argument constructor invoked
    Name B = A;  //Copy asssignment constructor invoked
    Name C;     //Single argument constructor invoked with default null value
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    cout << "C: " << C << endl;
    tracer << " C = move(A);" << nl;
    //We specify a move operation with the move function
    C = move(A);  //Move assignment operator invoked, C already instantiated
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    cout << "C: " << C << endl;
    tracer << "Name D = getName();" << nl;
    //GetName creates a temporary object and returns by value, D is instantiated and assumes that temporary object and the temporary object dies
    Name D = getName(); //No copy assignment invoked
    cout << "D: " << D << endl;
    tracer << "D = getName();" << nl;
    D = getName(); //Copy assignment invoked because D is an existing object
    cout << "D: " << D << endl;
    tracer << "Name E = move(B);" << nl;
    Name E = move(B); //Move constructor invoked, E is instantiated and B is moved into E 
    cout << "E: " << E << endl;
    cout << "B: " << B << endl;
    return 0;
}