#include <iostream>
using namespace std;


int main() {
    size_t k, n, w;
    cin >> k >> n >> w;
    int result = (k*w*(w+1)/2) - n;
    if (result < 0) result = 0;
    cout << result << endl;
    return 0;
}