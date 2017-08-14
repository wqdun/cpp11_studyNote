#include <iostream>

using namespace std;

template <typename T>
class Ptr {
public:
    Ptr(T *p) : _p(p) {}
    operator bool() const {
        if(0 != _p) {
            return true;
        }
        else {
            return false;
        }
    }

private:
    T *_p;
};

int main() {
    int a;
    Ptr<int> p(&a);
    if(p)
        cout << "Valid Pointer." << endl;
    else
        cout << "Invalid Pointer." << endl;

    Ptr<double> pd(0);
    cout << p + pd << endl;
}


