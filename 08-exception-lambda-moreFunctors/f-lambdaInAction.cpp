#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v = { 3, 1, 4, 1, 5, 9, 2, 6 };
    //Pass a lambda expression as an argument, or a function pointer, or functor
    sort(v.begin(), v.end(), [](int a, int b) {return a > b; });
    for (int n : v) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}