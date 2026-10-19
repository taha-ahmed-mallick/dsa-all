#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
            head = newNode;
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void remove(int key)
    {
        Node *temp = head;
        Node *prev = nullptr;

        if (temp != nullptr && temp->data == key)
        {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
            return;

        prev->next = temp->next;
        delete temp;
    }

    bool search(int key)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void display()
    {
        cout << "HEAD -> ";
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList* list = new LinkedList();
    list->push(10);
    list->push(20);
    list->push(30);
    list->push(40);
    list->display();
    int key = 20;
    cout << ((list->search(key)) ? "" : "not ");
    cout << "found\n";
    list->remove(key);
    cout << "After deleting " << key << endl;
    list->display();
    return 0;
}