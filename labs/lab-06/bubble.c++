#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &arr)
{
    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        for (size_t j = 0; j < arr.size() - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    }
}

void print(const vector<int> &arr)
{
    for (auto element : arr)
        cout << element << " ";
    cout << endl;
}

int main()
{
    cout << "Enter elements (enter 0 to stop):\n";
    vector<int> arr;
    int input;
    while (true)
    {
        cin >> input;
        if (input)
            arr.push_back(input);
        else
            break;
    }
    cout << "Entered array: ";
    print(arr);
    sort(arr);
    cout << "Sorted array: ";
    print(arr);
    return 0;
}