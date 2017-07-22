#include <iostream>
using namespace std;

struct A {
    A(int a) {
        cout << "a" << endl;
    }
};

struct B {
    B(int b) {
        cout << "b" << endl;
    }
};

struct C : A, B {
    using A::A;
    using B::B;
    C(int c) {
        cout << "c" << endl;
    }
};

int main() {
    C c(3);

}


