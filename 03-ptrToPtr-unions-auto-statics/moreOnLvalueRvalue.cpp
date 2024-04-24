#include <iostream>
using namespace std;

class Name {
private:
    //Holds a dynamic value, is null by default
    char* m_value{};
public:
    Name(const char* value = nullptr) {
        if (value) {
            int size = 0;
            //strlen
            while (value[size++]);// size = strlen + 1
            m_value = new char[size--];  // allocate size then size-=1
            // strcopy backwards, first null termination copied, if not at the first, go back once and opy the value, repeat
            //strcpy
            for (m_value[size] = value[size]; size; m_value[size] = value[--size]);
        }
    }
    Name(const Name& N) {
        if (N.m_value) {
            int size = 0;
            //strlen
            while (N.m_value[size++]);// size = strlen + 1
            m_value = new char[size--];  // allocate size then size-=1
            // strcopy backwards, first null termination copied, if not at the first, go back once and opy the value, repeat
            //strcpy
            for (m_value[size] = N.m_value[size]; size; m_value[size] = N.m_value[--size]);
        }
    }

    ostream& print(ostream& os)const {
        if (m_value) os << m_value;
        return os;
    }

    ~Name() {
        cout << "destructor" << endl;
        delete[] m_value;
    }
};

ostream& operator<< (ostream& os, const Name& N) {
    os << "lvalue: ";
    return N.print(os);
}

//Shows if the object passed is an r value - note Name&&
ostream& operator<< (ostream& os, Name&& N) {
    os << "rvalue: ";
    return N.print(os);
}

void prnName(Name N) {
    cout << N << endl;
}

int main() {
    Name A = "Jack"; //Parametized constructor
    Name  B = A; //Copy constructor

    //Nameless objects are never copied, in this case John. John is created, C assumes identity of John, and John is destroyed. 
    //C++ knows that John is a temporary object so the compiler does not bother to do a copy operation
    //Constructor of C copy constructor is supposed to be called but sees John is an rvalue and denies the copy operation.

    //Benefits: Saves time of memory
    Name C = Name("John"); // Equivalent to Name C = "John" 
    cout << "After Name Creations!" << endl;

    cout << A << endl;
    cout << B << endl;
    A = B;
    B = A;
    //Iman is a nameless object, it doesn't have any reference attached to it therefore it's an rvalue
    cout << Name("Iman") << endl;
    prnName(Name("Wilson")); // prnName(Name N = Name("Wilson"));


    return 0;

    /*
    A reference is an alias for an existing object. That is, 
    it is an alternative name for the entity defined elsewhere. 
    Each object defined in source code can have a reference associated with it. C++17 admits two reference declarations:

    an *lvalue reference* - denoted by &
    an *rvalue reference* - denoted by &&
        
    The declaration of an lvalue reference identifies an accessible region of memory. 
    The declaration of an rvalue reference identifies:
        an object near the end of its lifetime
        a temporary object or subobject
        a value not associated with an object
    */

}