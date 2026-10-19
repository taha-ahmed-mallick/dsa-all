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

class List
{
    ListNode *head;

public:
    List() : head(nullptr) {}
    List(ListNode *node) : head(node) {}
    void insert(int val)
    {
        ListNode *newNode = new ListNode(val);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        ListNode *curr = head;
        while (curr->next != nullptr)
            curr = curr->next;
        curr->next = newNode;
    }

    void print()
    {
        cout << "HEAD -> ";
        ListNode *curr = head;
        while (curr != nullptr)
        {
            cout << curr->val << " -> ";
            curr = curr->next;
        }
        cout << "NILL\n";
    }

    void removeDuplicate()
    {
        // considers a sorted list.
        if (head == nullptr || head->next == nullptr)
            return;
        ListNode *curr = head->next, *prev = head;
        int currVal = head->val;
        while (curr != nullptr)
        {
            if (curr->val == currVal)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else
            {
                currVal = curr->val;
                prev = curr;
                curr = curr->next;
            }
        }
    }

    ~List()
    {
        while (head != nullptr)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    List *list = new List();
    list->insert(1);
    list->insert(1);
    list->insert(2);
    list->insert(3);
    list->insert(3);
    list->print();
    list->removeDuplicate();
    list->print();
    return 0;
}