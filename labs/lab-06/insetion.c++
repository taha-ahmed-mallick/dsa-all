#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &arr)
{
    for (size_t i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;
        for (; j >=0 && arr[j] > key; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
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