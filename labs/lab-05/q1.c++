#include <iostream>
using namespace std;

class MyCircularDequeue
{
    int *data;
    size_t cap, front, rear, size;

public:
    MyCircularDequeue(int k) : cap(k), size(0), front(0), rear(0)
    {
        data = new int[k];
    }
    ~MyCircularDequeue()
    {
        delete[] data;
    }
    bool insertFront(int val)
    {
        if (isFull())
            return false;
        front = (front - 1 + cap) % cap;
        data[front] = val;
        size++;
        return true;
    }
    bool insertLast(int val)
    {
        if (isFull())
            return false;
        data[rear] = val;
        rear = (rear + 1) % cap;
        size++;
        return true;
    }
    bool deleteFront()
    {
        if (isEmpty())
            return false;
        front = (front + 1) % cap;
        size--;
        return true;
    }
    bool deleteLast()
    {
        if (isEmpty())
            return false;
        rear = (rear - 1 + cap) % cap;
        size--;
        return true;
    }
    int getFront() const
    {
        if (!isEmpty())
            return data[front];
        return -1;
    }
    int getRear() const
    {
        if (!isEmpty())
                return data[(rear - 1 + cap) % cap];
        return -1;
    }
    bool isEmpty() const { return size == 0; }
    bool isFull() const { return size == cap; }
};

string format(bool val)
{
    return val ? "True" : "False";
}

int main()
{
    MyCircularDequeue *deque = new MyCircularDequeue(3);
    cout << format(deque->insertLast(1)) << endl;
    cout << format(deque->insertLast(2)) << endl;
    cout << format(deque->insertFront(3)) << endl;
    cout << format(deque->insertFront(4)) << endl;
    cout << deque->getRear() << endl;
    cout << format(deque->isFull()) << endl;
    cout << format(deque->deleteLast()) << endl;
    cout << format(deque->insertFront(4)) << endl;
    cout << deque->getFront() << endl;
    return 0;
}