#include <iostream>
using namespace std;

//Void pointers are pure address that are basically unspecified of data type at compile time for now but is for sure an address.
//Benefits: To be able to access a piece of memory without knowing what is at the target so we can manipulate it however we want

void copyMem(void* des, const void* src, size_t size) {
    for (size_t i = 0; i < size; i++) {
        ((char*)des)[i] = ((const char*)src)[i];
    }
}

int main() {
    double a = 1234.56789;
    double b;
    //No need to cast here
    copyMem(&b, &a, sizeof(double));
    cout << b << endl;
    return 0;
}