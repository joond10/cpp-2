#include <iostream>
using namespace std;

//Identical function return and arguments
auto isAdult(int num) -> bool {
    return num >= 18 && num <= 65;
}
auto validNoOfStudents(int num) -> bool {
    return num >= 10 && num <= 35;
}

/*
- The name of the functions hold the address of logic in memory
- This address holds the execution of the logic
- Function types represent behavior. 
- Function types implement cohesive blocks of logic. 
- They reside in memory alongside other types and may have global, class or function scope.
*/

/*
- A C++ compiler needs sufficient information about a function to infer its return type. 
- Sometimes this information is in the identifier and sometimes in the parameter list itself. 

- A return-type inference takes the form:
    auto identifier(parameter-type-list) -> return-type;

- The auto keyword identifies the declaration as one with a return type inference. 
- The return-type follows the closing parenthesis and depends on the identifier or the parameter list. 
- This is particularly useful with enumerations that have been defined within a class templated functions
*/

auto getInt() -> int;
auto main() -> int {
    cout << "08-Oct06 OOP345 NBB" << endl;
    cout << "Enter your age: ";
    int age = getInt();
    cout << "age: " << age << endl;
    return 0;
}
auto getInt() -> int {
    int num{};
    bool done = false;
    do {
        cin >> num;
        if (cin.fail()) {
            cin.clear();
            cout << "Invlid integer, try again...\n> ";
        }
        else {
            if (cin.peek() != '\n') {
                cout << "Only an integer number please...\n> ";
            }
            else if (isAdult(num)) {
                done = true;
            }
            else {
                cout << "No children or Seniors permitted...\n> ";
            }
        }
        cin.ignore(10000, '\n');
    } while (!done);
    return num;
}