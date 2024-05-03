#include <iostream>
#include <string>
using namespace std;

//Function definitions that receieve an int and a string to modify the correct error message
bool isAdult(int num, string& err) {
    bool res = true;
    if (!(num >= 18 && num <= 65)) {
        err = "No children or Seniors";
        res = false;
    }
    return res;
}
bool validNoOfStudents(int num, string& err) {
    bool res = true;
    if (!(num >= 10 && num <= 35)) {
        err = "Invlid number of students";
        res = false;
    }
    return res;
}

//Forward declaration
int getInt(bool (*isValid)(int, string&));

//Essentially we treat function pointers like any other variables and pass it around to other functions

int main() {
    cout << "08-Oct06 OOP345 NBB" << endl;
    cout << "Enter your age: ";
    //We pass the name of the function to the function. 
    //Pass the logic of isAdult address to getInt
    int age = getInt(isAdult);
    cout << "age: " << age << endl;
    cout << "Enter the number of studets: ";
    //Pass the logic of validNoOfStudents address to getInt
    int stno = getInt(validNoOfStudents);
    cout << stno << " students in class." << endl;
    return 0;
}


//Get int needs to change the logic of it's evaluation when its running depending on what it is operating on
//We can put a pointer to a function as an argument!
//Get int now recieves a pointer to any function that receieves an integer and string and returns a boolean

//Don't be confused here! isValid receieves an integer and a string. NOT getInt
int getInt(bool (*isValid)(int, string&)) {
    int num{};
    bool done = false;
    string errMes{}; //Make an empty string
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
            else if (isValid(num, errMes)) { //Pass the empty string which the respective function will use to change via reference
                done = true;
            }
            else {
                cout << errMes << "...\n> ";
            }
        }
        cin.ignore(10000, '\n');
    } while (!done);
    return num;
}