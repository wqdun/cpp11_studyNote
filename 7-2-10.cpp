#include <cstddef>
#include <new>

extern void *p;

class NoStackAlloc {
public:
    ~NoStackAlloc() = delete;
};

int main() {
    // NoStackAlloc nsa;
    new (p) NoStackAlloc();
    return 1;
}

