#include <iostream>
#include "CStr.h"
using namespace std;
namespace sdds {
    void CStr::cpy(char* des, const char* src) {
        while (*des++ = *src++); // strcpy (fix for gcc on linux
    }
    int CStr::len(const char* str) {
        const char* end = str;
        while (*end++);
        return static_cast<int>(end - str) - 1;
    }
    void CStr::allocNcpy(char*& des, const char* src) {
        des = new char[len(src) + 1];
        cpy(des, src);
    }
    char* CStr::read(istream& is) { // reading any size of Cstr dynamically and return it
        char* data = new char[ReadBufferSize];
        char* str = data;
        int noOfBuffers = 1;
        bool done;
        do {
            done = true;
            cin.getline(str, ReadBufferSize, '\n'); // if cin fails, it means entry was greater than 50 chars
            if (cin.fail()) {
                noOfBuffers++;  // keep track of number of buffers to add
                char* temp = new char[(ReadBufferSize - 1) * noOfBuffers + 1]; // allocate bigger memory
                cpy(temp, data); // copy the already read test into temp
                delete[] data;  // delete the old (too short) memory
                data = temp;    // point to newly large allocated memory 
                str = data + (ReadBufferSize - 1) * (noOfBuffers - 1); // set the read pointer to continue reading the rest of text
                cin.clear();   // clear cin to read again
                done = false;  //we are not done yet
            }
        } while (!done);   // go back and continue reading if not done
        allocNcpy(str, data);
        delete[] data;
        return str;
    }

}