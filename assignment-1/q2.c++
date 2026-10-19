#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path)
{
    deque<string> directories;
    for (size_t i = 1; i < path.size(); i++)
    {
        string currDir = "";
        while (i < path.size() && path[i] != '/')
        {
            currDir += path[i];
            i++;
        }
        if (currDir == "" || currDir == ".")
            continue;
        if (currDir == "..")
        {
            if (!directories.empty())
                directories.pop_back();
        }
        else
            directories.push_back(currDir);
    }
    string result = "";
    for (const string &folder : directories)
        result += "/" + folder;
    return result.empty() ? "/" : result;
}

int main()
{
    string input;
    cout << "Enter an absolute Unix-style path:\n";
    getline(cin, input);
    string simplified = simplifyPath(input);
    cout << "The simplified path is:\n" << simplified << endl;
    return 0;
}