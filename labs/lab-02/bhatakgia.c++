#include <iostream>
using namespace std;

int main() {
    int n, k, count = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int nz = 0, temp = i;
        while (temp) {
            (temp%10) ? nz++ : NULL;
            temp/=10;
        }
        if (nz == k) count++;
    }
    cout << count << endl;
    return 0;
}