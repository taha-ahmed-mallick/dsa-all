#include <cstdio>

int main()
{
    int n, d;
    scanf(" %d", &n);
    scanf(" %d", &d);
    d = d % n;
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);
    int temp[n];
    for (int i = 0; i + d < n; i++)
    {
        // if (i + d >= n)
        //     break;
        temp[i] = arr[i + d];
    }
    for (int i = n - d, j = 0; i < n; i++, j++)
    {
        temp[i] = arr[j];
    }
    for (int i = 0; i < n; i++)
        printf("%d ", temp[i]);
    return 0;
}