#include <iostream>
#include <queue>
using namespace std;

int findTheWinnerMath(int n, int k) {
    queue<int> friends;
    for (int i = 1; i <= n; i++)
        friends.push(i);
    while (friends.size() > 1)
    {
        for (int steps = 1; steps < k; steps++) {
            int curr = friends.front();
            friends.pop();
            friends.push(curr);
        }
        friends.pop();
    }
    return friends.front();
}

int main() {
    int n = 5, k = 2;
    cout << "Winner Friend: " << findTheWinnerMath(n, k) << endl;
    return 0;
}