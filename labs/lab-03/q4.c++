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

    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *sort(ListNode *left, ListNode *right)
    {
        ListNode dummy(0);
        ListNode *curr = &dummy;
        while (left != nullptr || right != nullptr)
        {
            if (left == nullptr || (right != nullptr && right->val > left->val))
            {
                curr->next = right;
                right = right->next;
            }
            else
            {
                curr->next = left;
                left = left->next;
            }
            curr = curr->next;
        }

        return dummy.next;
    }

    ListNode *divide(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *middle = middleNode(head);
        ListNode *rightHead = middle->next;
        middle->next = nullptr;
        ListNode *left = divide(head);
        ListNode *right = divide(rightHead);
        return sort(left, right);
    }

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

    // sort and its child functions are directly copied from q3 of lab-02 and they just work without any modification except for the change in < to > since order is descending
    void sort() { head = divide(head); }

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
    cout << "-----------\n";
    N->sort();
    N->print();
    return 0;
}