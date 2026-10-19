#include <bits/stdc++.h>
using namespace std;

map<int, int> findNextGreaterFrequency(vector<int> nums)
{
    map<int, int> freq;
    for (int x : nums)
        freq[x]++;

    set<int> frequencies;
    for (auto p : freq)
        frequencies.insert(p.second);

    map<int, int> result;
    for (auto p : freq)
    {

        int element = p.first;
        int currentFrequency = p.second;

        auto it = frequencies.upper_bound(currentFrequency);
        if (it == frequencies.end())
            result[element] = -1;
        else
            result[element] = *it;
    }
    return result;
}

int main()
{

    vector<int> nums = {2, 1, 1, 3, 2, 1};

    map<int, int> result = findNextGreaterFrequency(nums);
    for (auto it : result)
    {
        cout << it.first << " -> " << it.second << endl;
    }

    return 0;
}