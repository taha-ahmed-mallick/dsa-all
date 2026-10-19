#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t t;
    cin >>t;
    while (t)
    {
        size_t x, y;
        cin >> x >>y;
        // cout << (y-1)/x << endl;
        // // cout << y % x<<endl;
        int count = 0;
        while(x < y){
            x += x;
            count++;
        }
        cout << count << endl;
        t--;
    }
    return 0;
}