#include <bits/stdc++.h>
using namespace std;

struct Range {
    int min, max;
    Range(int val) : min(val), max(val) {}
};

vector<Range> maxMinFinder(vector<int> &nums, int k)
{
    vector<Range> result;
    for (int i = 0; i <= nums.size() - k; i++)
    {
        Range curr(nums[i]);
        for (int j = i + 1; j < k + i; j++) {
            if (nums[j] > curr.max)
                curr.max = nums[j];
            if (nums[j] < curr.min)
                curr.min = nums[j];
        }
        result.push_back(curr);
    }
    return result;
}

int main()
{
    size_t n, k;
    cout << "Enter length of array (n): ";
    cin >> n;
    vector<int> arr(n, 0);
    cout << "ENTER ELEMENTS:\n";
    for (int i = 0; i < n; i++)
            cin >> arr[i];
    cout << "Enter size of window (k): ";
    cin >> k;
    vector<Range> result(maxMinFinder(arr, k));
    cout << "MIN\tMAX\n";
    for (int i = 0; i < result.size(); i++)
        cout << result[i].min << "\t" << result[i].max << endl;
    cout << endl;
    return 0;
}