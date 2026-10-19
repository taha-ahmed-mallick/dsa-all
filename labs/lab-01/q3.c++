#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    vector<int> list;
    MedianFinder() {

    }
    
    void addNum(int num) {
        list.push_back(num);
    }
    
    double findMedian() {
        sort(list.begin(), list.end());
        int n = list.size();
        double med = double(list[(n-1)/2]+list[n/2])/2;
        return med;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    MedianFinder *medfinder = new MedianFinder();
    medfinder->addNum(2);
    medfinder->addNum(1);
    cout << medfinder->findMedian() << endl;
    medfinder->addNum(3);
    cout << medfinder->findMedian() << endl;
    return 0;
}