#include <iostream>

using namespace std;

int main() {
    int a;
    // int &&b = a;
    int &c = a;
    // int &d = 1;
    const int &e = 1;
    int &&f = 1;
}