#include <iostream>
using namespace std;

int main()
{
    size_t t;
    cin >> t;
    while (t)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        t--;
    }
    return 0;
}