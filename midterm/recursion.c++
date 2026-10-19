#include <iostream>
using namespace std;

void func(int n) {
    if (n > 0) {
        cout << n << "  ";
        func(n-1);
        cout << n << "  ";
    }
}

int mystery(int n) {
    if (n <= 1) return 1;
    else return mystery(n-1) + mystery(n-2);
}

int main() {
    int x = 4;
    func(x);
    cout << endl;
    cout << mystery(x);
    return 0;
}