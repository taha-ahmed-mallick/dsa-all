#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
};

class CircularQueue
{
private:
    ListNode *rear;

public:
    CircularQueue() : rear(nullptr) {}

    void enqueue(int val)
    {
        ListNode *newNode = new ListNode(val);
        if (rear == nullptr)
        {
            rear = newNode;
            newNode->next = rear;
            return;
        }
        else
        {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue()
    {
        if (empty())
            return -1;
        if (rear == rear->next)
        {
            int val = rear->val;
            delete rear;
            rear = nullptr;
            return val;
        }
        ListNode *temp = rear->next;
        rear->next = rear->next->next;
        int val = temp->val;
        delete temp;
        return val;
    }

    bool empty() { return rear == nullptr; }

    void display()
    {
        if (empty())
        {
            cout << "The queue is empty.\n";
            return;
        }
        cout << "FRONT -> ";
        ListNode *temp = rear->next;
        do
        {
            cout << temp->val << " -> ";
            temp = temp->next;
        } while (temp != rear->next);
        cout << "REAR\n";
    }

    ~CircularQueue()
    {
        while (!empty())
            dequeue();
    }
};

int main()
{
    CircularQueue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    queue.display();

    queue.dequeue();
    queue.display();
    queue.dequeue();
    queue.enqueue(60);
    queue.display();
    return 0;
}