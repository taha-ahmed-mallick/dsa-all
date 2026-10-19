#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    cin >> input;
    char last = input[0];
    size_t max = 0, streak = 1;
    for (int i = 1; i < input.size(); i++) {
        if (input[i] == last)
            streak++;
        else {
            if (max < streak) max = streak;
            last = input[i];
            streak = 1;
        }
    }
    if (streak > max) max = streak;
    cout << max << endl;
    return 0;
}