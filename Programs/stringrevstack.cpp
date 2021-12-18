#include <iostream>

using namespace std;

int STACK_SIZE;
string element;

class Stack
{
    int top;
    char arr[100];
    string ele;
    string rev;

public:
    Stack()
    {
        top = -1;
        push();
        pop();
        display();
    }
    void getElement();
    void push();
    void pop();
    void display();
};

void Stack::push(void)
{
    getElement();
    for (int i = 0; i <= STACK_SIZE; i++)
        arr[++top] = ele[i];
}

void Stack::pop(void)
{
    for (int i = 0; i <= STACK_SIZE; i++)
        rev[i] = arr[--top];
}

void Stack::getElement(void)
{
    cout << "Enter String to Reverse: ";
    cin >> ele;
    STACK_SIZE = ele.size();
}

void Stack::display(void)
{
    string reverse;
    cout << "Original String is " << ele << endl;
    cout << "Reversed String is ";
    for (int i = 0; i <= STACK_SIZE; i++)
        cout << rev[i];
}

int main()
{
    Stack st1;
    return 0;
}
