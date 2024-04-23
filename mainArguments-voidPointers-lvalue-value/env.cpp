#include <iostream>
using namespace std;

//Another argument env is environment variables that is null terminated 
//env is until its null terminated
int main(int argc, char* argv[], char* env[]) {
    for (int i = 0; env[i]; i++) {
        cout << (i + 1) << " " << env[i] << endl;
    }
    return 0;
}