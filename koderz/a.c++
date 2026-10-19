#include <bits/stdc++.h>
using namespace std;

int main()
{
    size_t n, sum = 0, i = 1;
    cin >> n;
    for (; sum <= n; i++)
        sum += i * (i + 1) / 2;
    cout << i - 2 << endl;
    return 0;
}


/*
    #include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 0;
    int temporary = n;
    int temp = 0;
    for(int i = 1; i <= temporary; i++){
        
        temp += i;
        if( temp > n){
            break;
        }
        n = n - temp;
        count++;
    }

    cout << count  << endl;
    
    //4115 output 22

    return 0;
}

*/