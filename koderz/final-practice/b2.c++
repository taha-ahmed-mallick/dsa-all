#include <bits/stdc++.h>
using namespace std;

int main()
{
    size_t n, q, input;
    cin >> n >> q;
    size_t *arr = new size_t[n+1];
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> input;
        arr[i] = arr[i - 1] + input;
    }
    while (q)
    {
        size_t a, b;
        cin >> a >> b;
        cout << arr[b]-arr[a-1] << endl;
        q--;
    }
    return 0;
}