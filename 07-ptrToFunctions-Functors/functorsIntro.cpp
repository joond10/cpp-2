#include <iostream>
using namespace std;


//Any class that overloads the function call operator is a functor
//It can overload the function call operator as many times as desired
class Add {
    size_t m_noOfCalls{};
public:
    //Function invokation operator
    //This operator overloading is what enables the functor to be callable just like a function.
    int operator()(int num1, int num2) {
        //Allows it to be a stateful function!
        m_noOfCalls++;
        return num1 + num2;
    }
    operator size_t()const {
        //Allows for tracing!
        return m_noOfCalls;
    }
};

/*
Think of a functor as a function wrapped inside a class. 
It's a way to treat a function like an object, which means you can pass it around and store it just like any other variable. 
In this case, the Add class acts as a functor. It overloads the operator() so that instances of the class can be called like functions.
*/

int main() {
    Add add;
    int a = 10, b = 20, c;
    cout << "08-Oct06 OOP345 NBB" << endl;
    c = add(a, b);
    cout << c << endl;
    a = add(c, b);
    cout << a << endl;
    cout << size_t(add) << " times called!" << endl;
    return 0;
}
/*
Why functors over global functions? 

Encapsulation: 
    With a functor, you can encapsulate data along with the function logic. 
    In the Add example, we're keeping track of the number of calls (m_noOfCalls). 
    This encapsulation helps organize related data and behavior together.
Statefulness: 
    Functors can maintain state between function calls. 
    In contrast, global functions cannot store state unless you use global variables, 
    which can lead to issues with data integrity and make your code harder to reason about.
Flexibility: 
    Functors can be passed around just like any other object, enabling more flexible and expressive code.
    For instance, you can store functors in containers, pass them as arguments to other functions, or even return them from functions.
Polymorphism: 
    Functors can be used in polymorphic contexts. 
    You can create different functor classes that implement the same interface, allowing you to switch between behaviors dynamically.

*/