#include <iostream>
using namespace std;

void func(int test) {
    if (test < 1) return;
    else {
        cout << test << " ";
        func(--test); // my own modification
        cout << test << " ";
    }
}

int main() {
    // 3 2 1 0 1 2
    int test = 3;
    func(test);
    cout << endl;
    return 0;
}