#include <iostream>
using namespace std;

//A union is exactly like a structure but
//a union does not create member variables in sequence but are overlapped
//They all start at the beginning of the union and share the same memory

//That is, they all start at the same place in memory

//Use case: whenever you need to look at a piece of memory with different types of filters
union Vars {
    double a;
    int b;
    char c[7];
};

int main() {
    Vars V;
    cout << sizeof(Vars) << endl;
    cout << alignof(Vars) << endl;
    cout << unsigned(&V.a) << endl;
    cout << unsigned(&V.c) << endl;
    V.a = 123456.789;
    cout << V.a << endl;
    V.b = 123456;
    cout << V.b << endl;
    for (int i = 0; i < 7; i++) {
        V.c[i] = 'A' + i;
    }
    for (int i = 0; i < 7; i++) {
        cout << V.c[i];
    }
    //a and b have been overwritten by c
    cout << endl;
    cout << V.a << endl;
    cout << V.b << endl;


    return 0;
}