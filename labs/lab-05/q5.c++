#include <iostream>
using namespace std;

class DataStream
{
    int val, k, streak;

public:
    DataStream(int val, int k) : val(val), k(k), streak(0) {}

    bool consec(int num)
    {
        if (num == val)
            streak++;
        else
            streak = 0;
        return streak >= k;
    }
};

string format(bool val)
{
    return val ? "True" : "False";
}

int main()
{
    DataStream *dataStream = new DataStream(4, 3);
    cout << format(dataStream->consec(4)) << endl;
    cout << format(dataStream->consec(4)) << endl;
    cout << format(dataStream->consec(4)) << endl;
    cout << format(dataStream->consec(3)) << endl;
    return 0;
}