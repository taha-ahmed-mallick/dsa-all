#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class CircularQueue
{
    ListNode *rear;

public:
    CircularQueue() : rear(nullptr) {}

    bool isEmpty() { return rear == nullptr; }

    void enqueue(int val)
    {
        ListNode *newNode = new ListNode(val);
        cout << "ENQUEUED..." << newNode->val << endl;
        if (isEmpty())
        {
            newNode->next = newNode;
            rear = newNode;
            return;
        }
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow...\n";
            return;
        }
        ListNode *front = rear->next;
        cout << "DEQUEUED..." << front->val << endl;
        if (rear == front)
            rear = nullptr;
        else
            rear->next = front->next;

        delete front;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return -1;
        }
        return rear->next->val;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is empty...\n";
            return;
        }
        cout << "FRONT -> ";
        ListNode *curr = rear->next;
        do
        {
            cout << curr->val << " -> ";
            curr = curr->next;
        } while (curr != rear->next);
        cout << "REAR\n";
    }

    ~CircularQueue()
    {
        while (!isEmpty())
            dequeue();
    }
};

int main()
{
    CircularQueue *queue = new CircularQueue();
    queue->print();
    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);
    queue->enqueue(4);
    queue->enqueue(5);
    queue->print();
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    queue->print();
    cout << "The element at the front is: " << queue->peek() << endl;
    return 0;
}