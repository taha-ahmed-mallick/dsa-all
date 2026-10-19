#include <iostream>
#include <string>
using namespace std;

int main() {
    size_t m, n;
    cin >> m >> n;
    bool alt = true;
    string even_row(n, '#');
    string odd_row(n, '.');
    odd_row[n-1] = '#';
    string odd_row_alt(n, '.');
    odd_row_alt[0] = '#';
    for (size_t i = 0; i < m; i++) {
        if (i%2 == 0) {
            cout << even_row;
        } else {
            if(alt){
                cout << odd_row;
                alt = false;
            }
            else{
                cout << odd_row_alt;
                alt = true;
            }
        }
        cout << endl;
    }
    return 0;
}