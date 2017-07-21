#include <cstddef>

class NoHeapAlloc {
public:
    // void *operator new(std::size_t) = delete;
};

int main() {
    NoHeapAlloc nha;
    NoHeapAlloc *pnha = new NoHeapAlloc();
    return 1;
}

