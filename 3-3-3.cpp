#include <iostream>

using namespace std;

class HasPtrMem {
public:
    HasPtrMem(): d(new int(20)) {
        cout << "Constructor: " << ++n_cstr << endl;
    }
    HasPtrMem(const HasPtrMem &h): d(new int(*(h.d))) {
        cout << "Copy Constructor: " << ++n_cptr << endl;
    }
    ~HasPtrMem() {
        cout << "Destructor: " << ++n_dstr << endl;
        delete d;
    }

    int *d;
    static int n_cstr;
    static int n_dstr;
    static int n_cptr;

};

int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_cptr = 0;

HasPtrMem GetTemp() {
    return HasPtrMem();
}

int main() {
    HasPtrMem a = GetTemp();
}

