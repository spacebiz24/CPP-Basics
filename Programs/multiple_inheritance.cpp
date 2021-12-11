#include <iostream>

using namespace std;

class B;
class A
{
    int a;

public:
    void get_a(int x)
    {
        a = x;
    }
    int show_a(void)
    {
        return a;
    }
    void display()
    {
        cout << a << " exists in class A" << endl;
    }
};
class B
{
    int b;

public:
    void get_b(int x)
    {
        b = x;
    }
    int show_b(void)
    {
        return b;
    }
    void display()
    {
        cout << b << " exists in class B" << endl;
    }
};

class Mul : public A, public B
{
    int multiply;
    public:
    int multi(void)
    {
        multiply = show_a() * show_b();
        return multiply;
    }
    void display()
    {
        cout << "Multiplication happening in class Mul" << endl;
    }
};

int main()
{
    Mul multiplication;
    multiplication.get_a(10);
    multiplication.get_b(40);
    cout << multiplication.multi() << endl;
    multiplication.A::display();
    multiplication.B::display();
    multiplication.display();
    return 0;
}