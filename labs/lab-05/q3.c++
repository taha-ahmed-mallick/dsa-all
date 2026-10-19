#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Call
{
    static size_t callID;
    string name;
    size_t arrivalTime, ID;

public:
    Call(string name, size_t arrivalTime) : name(name), arrivalTime(arrivalTime)
    {
        ID = callID;
        callID++;
    }
    string getName() const { return name; }
    size_t getTime() const { return arrivalTime; }
    size_t getID() const { return ID; }
};

size_t Call::callID = 0;

class CallCenter
{
    queue<Call> calls;
    size_t CSR, time;
    vector<bool> availibility;
    vector<size_t> timeLeft;

public:
    CallCenter(size_t CSR) : time(0), CSR(CSR), availibility(CSR, true), timeLeft(CSR, 0)
    {
        cout << "\t\t\e[1;33m----- Call Center with " << CSR << " CSRS -----\n\n\e[0m";
    }

    void addCall(Call &call)
    {
        calls.push(call);
        cout << "\e[1;32m[Arrival] Call ID: " << call.getID() << " (" << call.getName() << ") joined at time: " << call.getTime() << "\e[0m" << endl;
    }

    void processCalls()
    {
        for (int i = 0; i < availibility.size(); i++)
            if (availibility[i] && !calls.empty())
            {
                Call dispatch = calls.front();
                calls.pop();
                availibility[i] = false;
                timeLeft[i] = rand() % 6 + 1; // assigns a random call duration
                cout << "\e[1;34m[Dispatched : CSR#" << i + 1 << "] Call ID: " << dispatch.getID() << ", (" << dispatch.getName() << ") for duration: " << timeLeft[i] << "\e[0m\n";
            }
    }

    void tick()
    {
        for (int i = 0; i < availibility.size(); i++)
            if (!availibility[i])
            {
                timeLeft[i]--;
                if (timeLeft[i] == 0)
                {
                    availibility[i] = true;
                    cout << "\e[1;35m[Completed] CSR#" << i + 1 << " has completed there call and now available.\n\e[0m";
                }
            }
        processCalls();
        time++;
    }

    bool hasPendingWork() const
    {
        if (!calls.empty())
            return true;
        for (bool busy : availibility)
            if (!busy)
                return true;
        return false;
    }

    size_t getTime() const { return time; }
};

int main()
{
    srand(time(0)); // random number gen seed

    CallCenter center(2);
    vector<Call> preplannedCalls = {
        Call("Taha", 0),
        Call("Danial", 2),
        Call("Yousuf", 2),
        Call("Ahmed", 5),
        Call("Yahya", 6)};

    size_t index = 0;

    while (index < preplannedCalls.size() || center.hasPendingWork())
    {
        cout << "\n\e[1m[Time: " << center.getTime() << "]\n\e[0m";
        while (index < preplannedCalls.size() && preplannedCalls[index].getTime() == center.getTime())
            center.addCall(preplannedCalls[index++]);
        center.tick();
    }
    return 0;
}