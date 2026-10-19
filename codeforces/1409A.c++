#include <bits/stdc++.h>
using namespace std;

int main()
{
    size_t t;
    cin >> t;
    while (t)
    {
        int a, b;
        cin >> a >> b;
        size_t steps = 0;
        if (a == b)
            cout << 0 << endl;
        else
            if (abs(b - a) < 10)
                cout << 1 << endl;
            else
            { // a = 0->10->10=20+1; b = 20
                steps = abs(b - a) / 10;
                if ((b - a) % 10)
                    steps++;
                cout << steps << endl;
            }
        t--;
    }
    return 0;
}