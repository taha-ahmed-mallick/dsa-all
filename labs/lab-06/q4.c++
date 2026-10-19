#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> pancakeSort(vector<int> &arr)
{
    vector<int> result;
    int n = arr.size();
    for (int size = n; size > 1; --size)
    {
        int maxIdx = 0;
        for (int i = 1; i < size; i++)
            if (arr[i] > arr[maxIdx])
                maxIdx = i;

        if (maxIdx == size - 1)
            continue;
        
        if (maxIdx != 0) {
            reverse(arr.begin(), arr.begin() + maxIdx + 1);
            result.push_back(maxIdx + 1);
        }

        reverse(arr.begin(), arr.begin() + size);
        result.push_back(size);
    }
    return result;
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
    vector<int> flipsIdx = pancakeSort(arr);
    cout << "Sorted array: ";
    print(arr);
    cout << "Flips (k): ";
    print(flipsIdx);
    return 0;
}