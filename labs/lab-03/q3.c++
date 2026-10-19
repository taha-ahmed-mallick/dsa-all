#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next, *prev;
    ListNode(int val) : val(val), next(nullptr), prev(nullptr) {}
};

class DLL
{
private:
    ListNode *head, *tail;

public:
    DLL() : head(nullptr), tail(nullptr) {}
    DLL(ListNode *head) : head(head)
    {
        ListNode *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        tail = temp;
    }

    bool empty() { return head == nullptr && tail == nullptr; }

    void push(int val)
    {
        ListNode *newNode = new ListNode(val);
        if (empty())
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void print()
    {
        if (empty())
        {
            cout << "Empty List.\n";
            return;
        }
        cout << "HEAD -> ";
        ListNode *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << " <-> ";
            temp = temp->next;
        }
        cout << "NILL\n";
    }

    friend ListNode *concatenate(DLL *list1, DLL *list2);

    ~DLL()
    {
        while (head != nullptr)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};

ListNode *concatenate(DLL *list1, DLL *list2)
{
    /* one drawback it modifies the original lists provided which you may not particularly want */
    list1->tail->next = list2->head;
    list2->head->prev = list1->tail;
    return list1->head;
}

int main()
{
    DLL *L = new DLL(), *M = new DLL();
    for (int i = 2; i < 11; i += 2)
        L->push(i);
    for (int i = 1; i < 10; i += 2)
        M->push(i);
    L->print();
    M->print();

    DLL *N = new DLL(concatenate(L, M));
    N->print();
    L->print();
    M->print();
    return 0;
}