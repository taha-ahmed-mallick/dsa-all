#include <iostream>
#include <stack>
using namespace std;

string stringProcessing(const string &s)
{
    string result;
    for (char c : s)
        if (c == '#')
        {
            if (!result.empty())
                result.pop_back();
        }
        else
            result.push_back(c);
    return result;
}

bool equalStrings(const string &s, const string &t)
{
    return stringProcessing(s) == stringProcessing(t);
}

int main()
{
    string s, t;
    cout << "Enter the strings:\n";
    getline(cin, s);
    getline(cin, t);
    cout << "The strings are " << (equalStrings(s, t) ? "Equal" : "Unequal") << endl;
    return 0;
}