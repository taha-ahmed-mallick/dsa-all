#include <iostream>
using namespace std;

bool binSearch(int **arr, int m, int n, int t) {
    int l = 0, r = m*n-1;
    while (l <= r) {
        int mid = l + (r-l)/2;
        int row = mid /n;
        int col = mid %n;
        if (t == arr[row][col])
            return true;
        else if (t < arr[row][col])
            r = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}

int main()
{
    int m, n;
    cout << "ROW: ";
    cin >> m;
    cout << "COL: ";
    cin >> n;
    int** arr = new int*[m];
    cout << "Enter elements\n";
    for (int i = 0; i < m; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    cout << "\n\nThe entered elements\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    int t;
    cout << endl << "Target: ";
    cin >> t;
    binSearch(arr, m, n, t) ? (cout << "found the element.") : (cout << "couldn\'t find the Specified element.");
    cout << endl;
    return 0;
}