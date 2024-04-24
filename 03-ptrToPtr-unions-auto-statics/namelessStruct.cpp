#include <iostream>
using namespace std;
class Student {
    struct {
        string first;
        string last;
    } m_name; //m_name is the identifier of the struct within this class
public:
    void foo() {
        auto n = m_name;


    }

};


int main() {


    return 0;
}