#include <iostream>
using namespace std;


//void prnArray(int arr[]) { // cant do it here, since arr is not a primitive array, just a pointer, should be used locally
//   for(auto& e : arr) {
//
//   }
//}


int main() {

    //C++'s version of forEach or for in loop

    int a[]{ 10, 20, 30, 40, 50, 60 };
    for (int& el : a) {
        //el stores each element in array "a"
        cout << unsigned(&el) << ": " << el << endl;
    }

    //Comes in handy for collections where we have array of things where we don't have types
    cout << "----------------------------------------" << endl;
    //auto automatically grabs the type within a collection
    for (auto& e : a) {
        cout << unsigned(&e) << ": " << e << endl;
    }
    return 0;
}