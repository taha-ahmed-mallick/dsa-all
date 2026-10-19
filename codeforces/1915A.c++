#include <iostream>
using namespace std;

int main() {
    size_t t;
    cin >> t;
    while (t) {
        size_t a, b, c;
        cin >> a >> b >> c;
        cout << (a ^ b ^ c) << endl;
        t--;
    }
    return 0;
}