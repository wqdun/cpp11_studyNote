#include <iostream>

using std::cout;
using std::endl;

int func(const int &ra) {
    cout << &ra << endl;
    return 0;
}

int main() {
    func(2);
    const int &a = 3;
    cout << &a << endl;
    func(3);
    return 0;
}