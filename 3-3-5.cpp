#include <iostream>

using namespace std;

struct Copyable {
    Copyable() {}
    Copyable(const Copyable &o) {
        cout << "Copied." << endl;
    }
    Copyable(Copyable &&o) {
        //
    }
};

Copyable ReturnRvalue() {
    return Copyable();
}

void AcceptVal(Copyable) {}

void AcceptRef(const Copyable &) {}

void AcceptRvalueRef(Copyable &&s) {
    Copyable newS = std::move(s);
}

int main() {
    cout << "Pass by value." << endl;
    AcceptVal(ReturnRvalue());

    cout << "Pass by reference." << endl;
    AcceptRef(ReturnRvalue());
}