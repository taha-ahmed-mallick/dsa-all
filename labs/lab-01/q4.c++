#include <iostream>
using namespace std;

int binSearch(int arr[], int n, int t) {
    int l = 0, r = n-1;
    while(l <= r) {
        int m = l + (r-l)/2;
        if (arr[m] == t)
            return m;
        else if (t < arr[m])
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

int main() {
    int n, t;
    cout << "LEN: ";
    cin >> n;
    int arr[n];
    cout << "ENTER ELEMENTS: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "ENTER TARGET: ";
    cin >> t;
    int index = binSearch(arr, n, t);
    (index == -1) ? (cout << "TARGET N/A\n") : (cout << "TARGET AT: " << index << endl);
    return 0;
}