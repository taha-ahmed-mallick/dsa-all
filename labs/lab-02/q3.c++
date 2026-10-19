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
            if (left == nullptr || (right != nullptr && right->val < left->val))
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

    void mergeSort() { head = divide(head); }

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
};

int main()
{
    List *list = new List();
    list->insert(4);
    list->insert(2);
    list->insert(1);
    list->insert(3);
    cout << "UNSORTED:\n";
    list->print();
    list->mergeSort();
    cout << "SORTED:\n";
    list->print();
    return 0;
}