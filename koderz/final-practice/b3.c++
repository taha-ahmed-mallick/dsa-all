#include <bits/stdc++.h>
using namespace std;

int main()
{
    size_t n, x, shuttle = 0;
    cin >> n >> x;
    vector<size_t> weights(n);
    for (int i = 0; i < n; i++)
        cin >> weights[i];
    sort(weights.begin(), weights.end());
    for (int i = 0, j = weights.size() - 1; i <= j;)
    {
        if (weights[i] + weights[j] > x)
            j--;
        else
        {
            i++;
            j--;
        }
        shuttle++;
    }
    cout << shuttle << endl;
    return 0;
}