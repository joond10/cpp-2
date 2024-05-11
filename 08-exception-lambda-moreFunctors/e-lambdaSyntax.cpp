/*
[capture_clause](parameter_list) -> return_type {
    // body of lambda
};

1. capture_clause: Specifies which outside variables are available
   for the lambda. Because this is essentially an anonymous function created within a scope.
   The compiler needs to know how to deal with variables outside of it's scope.
   Here is where you mention which variables it's using outside of its scope.

   //////////////////////////////////////////////////////////////////////////
   []: No variables are captured: 

    int x = 5;
    auto lambda = []() {
        return 42; // This lambda does not capture any variables from the enclosing scope
    };
    std::cout << lambda() << std::endl; // Outputs 42
    //////////////////////////////////////////////////////////////////////
    [=]: Captures all used variables by value. - Use the actual variables, stays static

    auto lambda = [=]() {
        return x; // x is captured by value
    };

    std::cout << lambda() << std::endl; // Outputs 5
    /////////////////////////////////////////////////////////////////////
   [&]: Captures all used variables by reference. - Make a reference of the variables, can be modified

   int x = 5;
    auto lambda = [&]() {
        return x; // x is captured by reference
    };

    x = 10; // Modifying x after lambda creation
    std::cout << lambda() << std::endl; // Outputs 10
   /////////////////////////////////////////////////////////////////////
   [x, &y]: Captures x by value and y by reference. - Mix and match

       int x = 5;
    int y = 10;
    auto lambda = [x, &y]() {
        return x + y; // x is captured by value, y is captured by reference
    };

    y = 20; // Modifying y after lambda creation
    std::cout << lambda() << std::endl; // Outputs 25 (x = 5 + y = 20)
    ////////////////////////////////////////////////////////////////////

2. parameter_list: The parameters just like in a regular function.

3. return_type: Optional. If omitted, it's inferred from the
   return statements in the lambda.

4. body: The code to be executed when the lambda is invoked.
*/

//A lambda expression is a brief way to create an anonymous function
//This means a temporary nameless function
//Pass an anonymous function:
//similar to JavaScript's arrow syntax or storing an anonymous function to a variable

//Use case: Any place that you can accept CALLABLE objects (functors) 
//makes it handy to use lambda expressions instead of function pointer or functors
#include <iostream>
using namespace std;
int main() {

/*
add is a variable. Specifically, it's a variable that holds a lambda function. 
You're creating a lambda function and assigning it to the variable add. 
This lambda function can then be called using the variable name add, just like you would call any other function.
Lambda functions in C++ are essentially syntactic sugar for defining function objects (functors), and they can be assigned to variables just like any other type of object.
*/

//A lambda function to add two numbers, don't be confused, there's no function identifier 
    auto add = [](int a, int b) -> int {
        return a + b;
        };

    std::cout << add(3, 4) << std::endl;  // Outputs 7
      //capture   parameter list      return      body/logic  invokation with argumetns
    cout << [](double a, double b) -> double { return a * b; }(10, 20) << endl;

    return 0;
}