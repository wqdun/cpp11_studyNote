#include <type_traits>
#include <iostream>

using namespace std;

class ConvType {
public:
    ConvType(int i) {}
    // ConvType(char c) = delete;
};

void Func(const ConvType &ct) {}

int main() {
    Func(3);
    Func('c');
    ConvType ci(3);
    ConvType cc('c');

}

