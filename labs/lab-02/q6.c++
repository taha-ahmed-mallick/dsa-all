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

class Stack
{
private:
    ListNode *head;

public:
    Stack() : head(nullptr) {}
    Stack(ListNode *node) : head(node) {}

    int peak() { return head->val; }
    bool isEmpty() { return head == nullptr ? true : false; }

    void push(int val)
    {
        ListNode *newNode = new ListNode(val);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    void pop()
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "EMPTY STACK.\n";
            return;
        }
        cout << "TOP -> ";
        ListNode *curr = head;
        while (curr != nullptr)
        {
            cout << curr->val << ", ";
            curr = curr->next;
        }
        cout << "END\n";
    }

    ~Stack()
    {
        while (!isEmpty())
            pop();
    }
};

int main()
{
    Stack *stack = new Stack();
    stack->print();
    for (int i = 10; i < 51; i += 10)
        stack->push(i);
    stack->print();
    for (int i = 0; i < 5; i++)
    {
        cout << stack->peak() << endl;
        stack->pop();
        stack->print();
    }
    return 0;
}