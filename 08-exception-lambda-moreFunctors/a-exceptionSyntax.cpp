#include <iostream>
using namespace std;
int main(void) {
    int i;
    double d = 10;
    char str[] = "A Cstring!";
    for (i = 0; i < 3; i++) {
    //Business logic goes in our try block
        try {
            if (i == 0) {
        //For our undesired outcomes we throw an exception TYPE for a catch to handle
                throw d;
            }
            if (i == 1) {
                throw str;
            }
            throw i;
            cout << "This will never happen!!!!!";
        }
        //This catch handles when a double exception is thrown
        catch (double de) {
            cout << "A double exception is here: " << de << endl;
        }
        //This catch handles when a string exception is thrown
        catch (const char* cstre) {
            cout << "A cString exception is here: " << cstre << endl;
        }
        //This catch handles all other exceptions
        catch (...) {
            cout << "Something thing was thrown, I don't know what!" << endl;
        }
    }

    return 0;
}