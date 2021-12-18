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
        checkPalindrome();
    }
    void getElement();
    void push();
    void pop();
    void display();
    void checkPalindrome();
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
    cout << "Enter String to check Palindromicity: ";
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
    cout << endl;
}

void Stack::checkPalindrome()
{
    int flag = 0;
    for (int i = 0; i < STACK_SIZE; i++)
    {
        if (rev[i] != ele[i])
            flag++;
    }
    if (flag != 0)
        cout << "String is not a palindrome!" << endl;
    else
        cout << "String is a palindrome!" << endl;
}

int main()
{
    Stack st1;
    return 0;
}
