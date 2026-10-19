#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& colors) {
    // given that the array only has elements as 0, 1, 2
    int low = 0, mid = 0, high = colors.size() - 1;
    while (mid <= high)
    {
        if (colors[mid] == 0)
            swap(colors[low++], colors[mid++]);
        else if (colors[mid] == 1)
            mid++;
        else
            swap(colors[mid], colors[high--]);
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
    cout << "Enter elements (0-2) (enter -1 to stop):\n";
    vector<int> arr;
    int input;
    while (true)
    {
        cin >> input;
        if (input > 2 || input < 0)
            break;
        else
            arr.push_back(input);
    }
    cout << "Entered array: ";
    print(arr);
    sortColors(arr);
    cout << "After Sorting: ";
    print(arr);
    return 0;
}