#include <type_traits>
#include <iostream>

using namespace std;

class TwoCstor {
public:
    TwoCstor() = default;
    TwoCstor(int i): data(i) {}

private:
    int data;
};

class NoCopyCstor {
public:
    NoCopyCstor() = default;
// private:
    // NoCopyCstor(const NoCopyCstor &) = delete;
};

int main() {
    cout << is_pod<TwoCstor>::value << endl;

    NoCopyCstor a;
    NoCopyCstor b(a);
}
