#include <iostream>

using namespace std;

class DCExpect {
public:
    DCExpect(double d)
        try : DCExpect(1, d) {
            cout << "Run the body." << endl;
        }
        catch(...) {
            cout << "Got exception." << endl;
        }

private:
    DCExpect(int i, double d) {
        cout << "Gonna throw!" << endl;
        // throw 0.1;
    }

    int type;
    double data;
};

int main() {
    DCExpect a(1.2);
}



