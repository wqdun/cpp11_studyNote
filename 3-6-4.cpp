#include <type_traits>
#include <iostream>

using namespace std;

union U {};
union U1 {
    U1() {}
};

enum E {};

typedef double *DA;
typedef void (*PF)(int, double);

int main() {
    cout << is_pod<U>::value << endl;
    cout << is_pod<U1>::value << endl; // 0
    cout << is_pod<E>::value << endl;
    cout << is_pod<DA>::value << endl;
    cout << is_pod<PF>::value << endl;

}
