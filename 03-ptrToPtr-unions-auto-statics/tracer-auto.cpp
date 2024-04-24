#include <iostream>
using namespace std;

//Overall, this code defines a tracing mechanism that allows you to monitor 
//the execution flow and values of variables in your program by selectively enabling or disabling tracing output.
class {
    bool m_trace{};
public:
    auto& trace(bool value = true) {
        m_trace = value;
        return *this;
    }
    auto& operator<<(const char* message) {
        if (m_trace) cout << (message ? message : "(NULLstr)");
        return *this;
    }
    auto& operator<<(int val) {
        if (m_trace) cout << val;
        return *this;
    }
    auto& operator<<(double val) {
        if (m_trace) cout << val;
        return *this;
    }
    auto& operator<<(char ch) {
        if (m_trace) cout << ch;
        return *this;
    }
} tracer;
//tracer is an instance of the anonymous class that was defined inline. 
//So, while the class itself doesn't have a name, an instance of it is created and named tracer.

//auto keyword is used for automatic type inference. When you declare a variable using auto, 
//the compiler deduces the data type of that variable based on the initializer (the value used to initialize the variable).
int main() {
    tracer.trace(false);
    int a, b = 10, c = 30;

    tracer << "adding b and c in a\n";
    a = b + c;
    tracer << "the value is " << a << "\n";


    return 0;
}