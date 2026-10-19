#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t n, a, b;
    cin >> n >> a >> b;
    size_t sum = n*(n+1)/2;
    for (size_t i = 1; i <= n; i++) {
        size_t temp = i, digit_sum = 0;
        while (temp) {
            digit_sum+=temp %10;
            temp/=10;
        }
        if (digit_sum < a || digit_sum > b)
        sum -= i;
    }
    cout << sum << endl;
    return 0;
}