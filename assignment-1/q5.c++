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

class CDLL
{
private:
    ListNode *head, *tail;
    size_t len;

public:
    CDLL() : head(nullptr), tail(nullptr), len(0) {}

    void push_front(int val)
    {
        ListNode *newNode = new ListNode(val);
        len++;
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
            return;
        }
        newNode->prev = tail;
        newNode->next = head;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }

    void push_back(int val)
    {
        ListNode *newNode = new ListNode(val);
        len++;
        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
            return;
        }
        newNode->prev = tail;
        newNode->next = head;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }

    bool insert(int val, size_t pos)
    {
        if (pos == 0)
        {
            push_front(val);
            return true;
        }
        if (pos == len)
        {
            push_back(val);
            return true;
        }
        if (pos > len)
            return false;
        ListNode *newNode = new ListNode(val);
        ListNode *curr = head;
        len++;
        for (size_t i = 1; i < pos; i++)
            curr = curr->next;
        curr->next->prev = newNode;
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next = newNode;
        return true;
    }

    void insert(int val, ListNode *prev)
    {
        if (prev == tail)
        {
            push_back(val);
            return;
        }
        ListNode *newNode = new ListNode(val);
        len++;
        prev->next->prev = newNode;
        newNode->next = prev->next;
        newNode->prev = prev;
        prev->next = newNode;
    }

    void print()
    {
        if (head == nullptr)
        {
            cout << "EMPTY LIST\n";
            return;
        }
        cout << "HEAD <-> ";
        ListNode *curr = head;
        do
        {
            cout << curr->val << " <-> ";
            curr = curr->next;
        } while (curr != head);
        cout << " TAIL\n";
    }
};

ListNode *insert(ListNode *head, int val, size_t pos)
{
    ListNode *newNode = new ListNode(val);
    if (head == nullptr)
    {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }
    if (pos == 0)
    {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
        return;
    }

    ListNode *curr = head;
    for (size_t i = 0; i < pos - 1; i++)
        curr = curr->next;
    newNode->next = curr->next;
    newNode->prev = curr;
    curr->next->prev = newNode;
    curr->next = newNode;
}

int main()
{
    CDLL list;
    list.print();
    list.push_back(10);
    list.print();
    list.push_back(20);
    list.print();
    list.push_back(30);
    list.print();
    list.push_back(40);
    list.print();
    list.push_back(50);
    list.print();
    list.push_front(5);
    list.print();
    list.insert(15, 2);
    list.print();
    return 0;
}