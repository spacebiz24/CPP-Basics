#include <iostream>

using namespace std;

class Class2;
class Class1
{
    int Val1;

public:
    void getValue(int x)
    {
        Val1 = x;
    }
    void display()
    {
        cout << "Val1: " << Val1 << endl;
    }
    friend void exchangeValue(Class1 &, Class2 &);
};

class Class2
{
    int Val2;

public:
    void getValue(int x)
    {
        Val2 = x;
    }
    void display()
    {
        cout << "Val2: " << Val2 << endl;
    }
    friend void exchangeValue(Class1 &, Class2 &);
};

void exchangeValue(Class1 &X, Class2 &Y)
{
    int temp = X.Val1;
    X.Val1 = Y.Val2;
    Y.Val2 = temp;
}

int main()
{
    Class1 C1;
    Class2 C2;
    C1.getValue(40);
    C2.getValue(20);
    cout << "Before Swapping: " << endl;
    C1.display();
    C2.display();
    cout << endl;
    cout << "After Swapping: " << endl;
    exchangeValue(C1, C2);
    C1.display();
    C2.display();
    return 0;
}