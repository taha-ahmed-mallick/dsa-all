#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {3, 4, 6, 1, 2, 5};
    for (int i = 0; i < arr.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < arr.size(); j++)
            if (arr[j] < arr[min]) min = j;
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    for (int i = 0; i < arr.size() ;i++) cout << arr[i] << "  ";
    return 0;
}