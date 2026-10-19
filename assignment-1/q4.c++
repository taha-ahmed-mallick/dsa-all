#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next), prev(nullptr) {}
    ListNode(int x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev) {}
};

class DLL
{
private:
    ListNode *head, *tail;

public:
    DLL() : head(nullptr), tail(nullptr) {};

    void push_front(int val)
    {
        ListNode *newNode = new ListNode(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void push_back(int val)
    {
        ListNode *newNode = new ListNode(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void print()
    {
        cout << "HEAD <-> ";
        ListNode *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << " <-> ";
            temp = temp->next;
        }
        cout << "TAIL\n";
    }

    void reverse() {
        ListNode *curr = head, *temp = nullptr;
        while (curr != nullptr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        temp = head;
        head = tail;
        tail = temp;
    }
};

int main()
{
    DLL *list = new DLL();
    list->push_back(10);
    list->push_back(20);
    list->push_back(30);
    list->push_back(40);
    list->push_back(50);
    list->print();
    list->reverse();
    list->print();
    return 0;
}