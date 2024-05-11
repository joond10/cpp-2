#include <iostream>
#include <fstream>
using namespace std;

//Functors are classes that have the function invokation overloaded in them
//These types of classes can be used as functions,
//when you instantiate them, use the name of the object and the invokation to use it as a function
//Essentially, it is an object masked as a function

//Use case: To pass around logic without pointer to functions
//we can create the logic we want inside an object and pass the object wherever we want
//also allows the function to be stateful
class Add {
public:
    int operator()(int a, int b) {
        return a + b;
    }
};

class Line {
    char m_fill{ '*' };
    ostream& m_ostr{ std::cout };
public:
    Line() {
    }
    Line(char fill, ostream& ostr = std::cout) : m_fill{ fill }, m_ostr{ ostr } {
    }
    void operator()(unsigned len) {
        for (unsigned i = 0; i < len; m_ostr << m_fill, i++);
        m_ostr << endl;
    }
};

int main() {
    ofstream f("line.txt");
    Line divider('-'), fileDivider('=', f);
    Add addFunctor, heehaw;
    int x = addFunctor(2, 3);
    divider(50);
    cout << x << endl;
    x = heehaw(5, 6);
    fileDivider(70);
    cout << x << endl;
}