#include<iostream>
#include<array>

using namespace std;

struct S {
    float d;
    long long l:8; // 16 bits for long long
    int i:8;        // 8 bits for int
    short s:3;      // 3 bits for short
    bool b:1;       // 1 bit for bool

    bool operator<(const S &s) {return this->i < s.i;}
};

int main() {
    cout << "Size of struct S: " << sizeof(S) << " bytes" << endl;
    return 0;
}
