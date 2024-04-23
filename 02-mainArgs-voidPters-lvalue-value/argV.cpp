#include <iostream>
using namespace std;

//arg c = argument count
//arg v = an array of pointers that point to null terminated cstrings i.e each argument word
//that is, arg[0] will be the full path to the relocatable after compilation
int main(int argc, char* argv[]) {

    //It can also use the syntax pointer to pointer, remember arrays are pointers!
/*int main(int argc, char** argv) {*/

    for (int i = 0; i < argc; i++) {
        cout << argv[i] << endl;
    }
    return 0;
}