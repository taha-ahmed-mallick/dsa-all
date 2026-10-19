#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &arr)
{
    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        size_t min = i;
        for (size_t j = i + 1; j < arr.size(); j++)
            if (arr[j] < arr[min])
                min = j;
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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