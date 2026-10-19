#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "ROW: ";
    cin >> m;
    cout << "COL: ";
    cin >> n;
    int arr[m][n];
    cout << "Enter elements\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    cout << "\n\nThe entered elements\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << "\nCOL-majored 1D representation\n";
    int arr2[m + n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr2[i*m +j] = arr[j][i];
    for (int i = 0; i < (m + n + 1); i++)
        cout << arr2[i] << " ";
    return 0;
}