#include <iostream>
using namespace std;
//Why do we static cast? 

/*
Constrained casts improve type safety. Type safety is an important feature of any strongly typed language.
Bypassing the type system introduces ambiguity to the language itself and is best avoided.
Casting a value from one type to another type circumvents the type system's type checking facilities.
It is good programming practice to implement casts only where absolutely unavoidable and localize them as much as possible.
*/

//Static casting is used to tell to the compiler what the intention of this cast is
//Cast is a dangerous thing, manually changing the type isn't good
//therefore if the types aren't related, a compiler error will be generated improving type safety


void copyMem(void* des, const void* src, size_t size) {
    char* cdes = static_cast<char*>(des); 
    const char* csrc = static_cast<const char*>(src);
    for (size_t i = 0; i < size; i++) {
        cdes[i] = csrc[i];
    }
}

int main() {
    double a = 1234.56789;
    double b;
    copyMem(&b, &a, sizeof(double));
    cout << b << endl;
    return 0;
}