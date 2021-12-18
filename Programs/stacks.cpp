#include <iostream>

using namespace std;

int STACK_SIZE;
int element;

class Stack
{
    int top, arr[100], ele;

public:
    Stack()
    {
        top = -1;
    }
    void getElement();
    void push();
    void pop();
    void display();
};

void Stack::push(void)
{
    if (top == STACK_SIZE - 1)
        cout << "Stack is full!" << endl;
    else
    {
        getElement();
        arr[++top] = ele;
    }
}

void Stack::pop(void)
{
    if (top == -1)
        cout << "Stack is empty!" << endl;
    else
        top--;
}

void Stack::getElement(void)
{
    cout << "Enter Element" << endl;
    cin >> element;
    ele = element;
}

void Stack::display(void)
{
    if (top == -1)
        cout << "Stack is empty!" << endl;
    else
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
            if (i == top)
                cout << endl;
        }
    }
}

int main()
{
    Stack st1;
    cout << "Enter Stack Size:" << endl;
    cin >> STACK_SIZE;
    int choice;
    while (1)
    {
        cout << endl;
        cout << "*************Stack Stuff*************" << endl;
        cout << "1. Push element" << endl;
        cout << "2. Pop element" << endl;
        cout << "3. Display elements" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            st1.push();
            break;
        case 2:
            st1.pop();
            break;
        case 3:
            st1.display();
            break;
        case 4:
            cout << "Exited with exit code '0'" << endl;
            exit(0);
            break;
        default:
            cout << "Exited with exit code '-1'" << endl;
            break;
        }
    }
    return 0;
}
