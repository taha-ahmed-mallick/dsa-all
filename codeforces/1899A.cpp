#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t != 0){
        int n;
        cin >> n;
        cout << ((n%3) ? "First" : "Second" ) << endl;
        t--;
    }

    return 0;
}