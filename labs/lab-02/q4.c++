#include <iostream>
#include <stack>
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

    ListNode *middleNode()
    {
        ListNode *slow = head, *fast = head->next, *prev = nullptr;
        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast == nullptr)
        {
            prev->next = nullptr;
            return slow->next;
        }
        else
        {
            prev = slow->next;
            slow->next = nullptr;
            return prev;
        }
    }

    bool palindrome()
    {
        if (head == nullptr) return true;
        stack<int> check;
        ListNode *right = middleNode();
        while (head != nullptr)
        {
            check.push(head->val);
            head = head->next;
        }
        while (right != nullptr)
        {
            if (check.empty() || check.top() == right->val)
                check.pop();
            else
                return false;
            right = right->next;
        }
        return true;
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
};

int main()
{
    List *list = new List();
    list->insert(1);
    list->insert(2);
    list->insert(2);
    list->insert(1);
    cout << "LIST:\n";
    list->print();
    cout << "IS PALINDROME: " << (list->palindrome() ? "yes" : "no");
    cout << endl;
    return 0;
}