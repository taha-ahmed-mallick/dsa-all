#include <iostream>
#include <vector>
using namespace std;

class BrowserHistory {
    vector<string> pages;
    int curr, end;
public:
    BrowserHistory(string homepage) : pages(1, homepage), curr(0), end(0) {
    }
    
    void visit(string url) {
        if (curr == end) {
            if (end == pages.size() - 1) {pages.push_back(url); end++;}
            else pages[++end] = url;
            curr++;
        } else {
            pages[++curr] = url;
            end = curr;
        }
    }
    
    string back(int steps) {
        curr = max (0, curr - steps);
        return pages[curr];
    }
    
    string forward(int steps) {
        curr = min(end, curr + steps);
        return pages[curr];
    }
};

int main() {
    BrowserHistory browser("leetcode.com");

    browser.visit("google.com");
    browser.visit("facebook.com");
    browser.visit("youtube.com");
    string url = browser.back(1);
    cout << "Current URL after going back 1 step: " << url << endl; // Expected Output: facebook.com
    cout << endl;

    url = browser.back(2);
    cout << "Current URL after going back 2 steps: " << url << endl; // Expected Output: leetcode.com
    cout << endl;
    url = browser.forward(1);
    cout << "Current URL after going forward 1 step: " << url << endl; // Expected Output: google.com
    return 0;
}