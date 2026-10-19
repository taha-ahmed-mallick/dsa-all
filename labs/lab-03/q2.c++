#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next, *prev;
    ListNode(int val) : val(val), next(nullptr), prev(nullptr) {}
};

class Deque
{
private:
    ListNode *front, *rear;

public:
    Deque() : front(nullptr), rear(nullptr) {}

    bool empty() { return front == nullptr && rear == nullptr; }

    void enqueueFront(int val)
    {
        ListNode *newNode = new ListNode(val);
        if (empty())
        {
            front = rear = newNode;
            return;
        }
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }

    void enqueueRear(int val)
    {
        ListNode *newNode = new ListNode(val);
        if (empty())
        {
            front = rear = newNode;
            return;
        }
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }

    int dequeueFront()
    {
        if (empty())
            return -1;
        ListNode *temp = front;
        int val = temp->val;
        if (front == rear)
            front = rear = nullptr;
        else
        {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
        return val;
    }

    int dequeueRear()
    {
        if (empty())
            return -1;
        ListNode *temp = rear;
        int val = temp->val;
        if (front == rear)
            front = rear = nullptr;
        else
        {
            rear = rear->prev;
            rear->next = nullptr;
        }
        delete temp;
        return val;
    }

    void display()
    {
        if (empty())
        {
            cout << "The Deque is empty.\n";
            return;
        }
        ListNode *temp = front;
        cout << "FRONT -> ";
        while (temp != nullptr)
        {
            cout << temp->val << " <-> ";
            temp = temp->next;
        }
        cout << "<- REAR\n";
    }

    ~Deque() {
        while (!empty())
            dequeueFront();
    }
};

int main()
{
    Deque dq;
    dq.enqueueFront(10);
    dq.enqueueRear(20);
    dq.enqueueFront(5);
    dq.enqueueFront(15);
    dq.display();

    dq.dequeueFront();
    dq.display();
    dq.dequeueRear();
    dq.display();
    return 0;
}