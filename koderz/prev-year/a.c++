#include <bits/stdc++.h>
using namespace std;

int main() {
    // unsigned long long input;
    // string line;
    // getline(cin, line);
    // stringstream ss(line);
    // unsigned long long sum = 0, min = SIZE_MAX, max = 0;
    // while (ss >> input) {
    //     sum+=input;
    //     if (input < min) min = input;
    //     if (input > max) max = input;
    // }

    // cout << sum - max << " " <<sum - min << endl;
    // return 0;
    unsigned long long x;
    unsigned long long sum = 0, min = -1, max = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> x;
        sum += x;
        if (x < min) min = x;
        if (x > max) max = x;
    }
    cout << sum - max << " " << sum - min << endl;
    return 0;
}

