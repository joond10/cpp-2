#include <iostream>
using namespace std;

//Pretty much deep copy minus the dynamic memory
void copyMem(char* des, const char* src, size_t size) {
    for (size_t i = 0; i < size; i++) {
        des[i] = src[i];
    }
}
int main() {

    //Deep copy one double to another
    double a = 1234.56789;
    double b;
    
    //sizeof gets the number of bytes to copy over
    copyMem((char*)&b, (const char*)&a, sizeof(double));
    cout << b << endl;
    return 0;
}