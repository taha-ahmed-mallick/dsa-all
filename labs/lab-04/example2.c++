#include <bits/stdc++.h>
using namespace std;

void backtrackSubset(const vector<int>& set, int index, vector<int>& prevSet, vector<vector<int>>& totalSubsets)
{
    if (index == set.size())
    {
        totalSubsets.push_back(prevSet);
        return;
    }
    backtrackSubset(set, index + 1, prevSet, totalSubsets);
    prevSet.push_back(set[index]);
    backtrackSubset(set, index + 1, prevSet, totalSubsets);
    prevSet.pop_back(); // now it is backtracking thought i don't get the difference, actually i do using this we can place & in the prevSet parameter
}

vector<vector<int>> powerSet(vector<int> set)
{
    vector<vector<int>> res;
    vector<int> current;
    backtrackSubset(set, 0, current, res);
    return res;
}

int main()
{
    vector<int> set;
    int input;
    while (true)
    {
        cin >> input;
        if (input)
            set.push_back(input);
        else
            break;
    }
    cout << "Given set: ";
    for (int i = 0; i < set.size(); i++)
    {
        cout << set[i] << " ";
    }
    vector<vector<int>> res(powerSet(set));
    cout << "\nSubsets in a Power Set:\n";
    for (auto subset : res)
    {
        if (!subset.size())
        {
            cout << "NULLSET" << endl;
            continue;
        }
        for (auto element : subset)
            cout << element << " ";
        cout << endl;
    }
    return 0;
}