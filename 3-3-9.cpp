#include <iostream>

using namespace std;

void RunCode(int &&m) {
    cout << "Rvalue ref." << endl;
}

void RunCode(int &m) {
    cout << "Lvalue ref." << endl;
}

void RunCode(const int &&m) {
    cout << "const Rvalue ref." << endl;
}

void RunCode(const int &m) {
    cout << "const Lvalue ref." << endl;
}

template <typename T>
void PerfectForward(T &&t) {
    RunCode(forward<T>(t));
}

int main() {
    int a;
    int b;
    const int c = 1;
    const int d = 0;
    PerfectForward(a);          // Lvalue ref
    PerfectForward(move(b));    // Rvalue ref
    PerfectForward(c);          // const Lvalue ref
    PerfectForward(move(d));    // const Rvalue ref
}



