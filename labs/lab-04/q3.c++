#include <bits/stdc++.h>
using namespace std;

void backtrackPermute(vector<int> &arr, size_t index, vector<vector<int>> &result)
{
    if (index == arr.size())
    {
        result.push_back(arr);
        return;
    }
    for (size_t i = index; i < arr.size(); i++)
    {
        swap(arr[index], arr[i]);
        backtrackPermute(arr, index + 1, result);
        swap(arr[index], arr[i]);
    }
}

vector<vector<int>> permute(vector<int> arr)
{
    vector<vector<int>> result;
    backtrackPermute(arr, 0, result);
    return result;
}

int main()
{
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
    cout << "Given Array: ";
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    vector<vector<int>> res(permute(arr));
    cout << "\nTotal permutation of the given array:\n";
    for (auto subarr : res)
    {
        for (auto element : subarr)
            cout << element << " ";
        cout << endl;
    }
    return 0;
}