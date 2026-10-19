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

    friend ListNode *merge(List *list1, List *list2);

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

ListNode *merge(List *list1, List *list2)
{
    // considers both list1 and list2 are sorted and takes O(m+n) space
    ListNode *curr1 = list1->head, *curr2 = list2->head;
    ListNode *dummy = new ListNode(); // dummy head to eliminate edge cases
    ListNode *curr = dummy;
    while (curr1 != nullptr || curr2 != nullptr)
    {
        ListNode *temp = nullptr;

        if (curr2 == nullptr || (curr1 != nullptr && curr1->val < curr2->val))
        {
            temp = new ListNode(curr1->val);
            curr1 = curr1->next;
        }
        else
        {
            temp = new ListNode(curr2->val);
            curr2 = curr2->next;
        }
        curr->next = temp;
        curr = temp;
    }
    ListNode *head = dummy->next;
    delete dummy;
    return head;
}

int main()
{
    List *list1 = new List(), *list2 = new List();
    list1->insert(1);
    list1->insert(2);
    list1->insert(4);
    cout << "List 1: ";
    list1->print();
    list2->insert(1);
    list2->insert(3);
    list2->insert(4);
    cout << "List 2: ";
    list2->print();
    cout << "MERGED:\n";
    List *merged = new List(merge(list1, list2));
    merged->print();
    return 0;
}