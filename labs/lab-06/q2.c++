#include <iostream>
using namespace std;

void sort(int *arr, int n)
{
    for (size_t i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        for (; j >=0 && arr[j] > key; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}

size_t maxToys(int *arr, size_t N, int K) {
    sort(arr, N);
    size_t count = 0;
    for (size_t i = 0; i < N; i++)
        if (arr[i] <= K) {
            K-= arr[i];
            count++;
        } else break;
    return count;
}

int main() {
    size_t N, K;
    cout << "Enter N (len): ";
    cin >> N;
    cout << "Enter K (amt): ";
    cin >> K;
    int *arr = new int[N];
    cout << "Enter Toys amt: ";
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << "Number of toys you can buy: " << maxToys(arr, N, K) << endl;
    delete[] arr;
    return 0;
}