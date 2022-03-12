#include <iostream>

using namespace std;

class CircularQueue
{
    int size, ele, front, rear, arr[100];

public:
    CircularQueue()
    {
        front = rear = -1;
    }
    bool isEmpty();
    bool isFull();
    void enQueue();
    void deQueue();
    void displayQueue();
    void getData();
    void getSize();
};

void CircularQueue::getSize()
{
    cout << "\nEnter size of queue: ";
    cin >> size;
}

void CircularQueue::getData()
{
    cout << "\nEnter data: ";
    cin >> ele;
}

bool CircularQueue::isEmpty()
{
    if (front == -1)
        return true;
    return false;
}

bool CircularQueue::isFull()
{
    if (front == 0 && rear == size - 1)
        return true;
    if (front == rear + 1)
        return true;
    return false;
}

void CircularQueue::enQueue()
{
    if (isFull())
        cout << "\nQueue is full!" << endl;
    else
    {
        getData();
        if (front == -1)
            front = 0;
        rear = (rear + 1) % size;
        arr[rear] = ele;
    }
}

void CircularQueue::deQueue()
{
    if (isEmpty())
        cout << "\nQueue is empty!" << endl;
    else
    {
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
    }
}

void CircularQueue::displayQueue()
{
    if (isEmpty())
        cout << "Queue is empty" << endl;
    else
    {
        int i;
        cout << "Queue contents:\n";
        for (i = front; i != rear; i = (i + 1) % size)
            cout << arr[i] << " ";
        cout << arr[i] << endl;
    }
}

int main()
{
    CircularQueue Q;
    int choice;
    Q.getSize();
    while (true)
    {
        cout << "\nOperations List:\n";
        cout << "1. EnQueue\n";
        cout << "2. DeQueue\n";
        cout << "3. DisplayQueue\n";
        cout << "4. Exit\n";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Q.enQueue();
            break;
        case 2:
            Q.deQueue();
            break;
        case 3:
            Q.displayQueue();
            break;
        default:
            exit(0);
        }
    }
    return 0;
}