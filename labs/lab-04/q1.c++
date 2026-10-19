#include <iostream>
#include <stack>
using namespace std;

bool palindrome(const string& s) {
    stack<char> check;
    for (char c : s)
        check.push(c);
    for (char c : s) {
        if (c != check.top()) return false;
        check.pop();
    }
    return true;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    cout << "Is it a palindrome? " << (palindrome(s) ? "Yes" : "No") << endl;
    return 0;
}