#include <iostream>

using namespace std;

class B;

class A
{
    int a;

public:
    void setValue(int x)
    {
        a = x;
    }
    friend void max(A, B);
};

class B
{
    int b;

public:
    void setValue(int x)
    {
        b = x;
    }
    friend void max(A, B);
};

void max(A c, B d)
{
    if (c.a >= d.b)
        cout << c.a << " is largest" << endl;
    else
        cout << d.b << " is largest" << endl;
}

int main()
{
    A p;
    B q;
    p.setValue(4);
    q.setValue(6);
    max(p, q);
    return 0;
}