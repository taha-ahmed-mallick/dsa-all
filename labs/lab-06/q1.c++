#include <iostream>
using namespace std;

void bubbleSort(int *arr, size_t n)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        cout << "PASS " << i + 1 << endl;
        bool swapped = false;
        for (size_t j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j + 1])
            {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        if (!swapped)
            return;
    }
}

void print(int *arr, size_t n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {5, 1, 4, 8};
    size_t N = sizeof(arr) / sizeof(arr[0]);
    cout << "Given array: ";
    print(arr, N);
    bubbleSort(arr, N);
    cout << "Sorted array: ";
    print(arr, N);
    return 0;
}