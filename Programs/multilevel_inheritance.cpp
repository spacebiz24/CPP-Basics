#include <iostream>

using namespace std;

class B;
class mul;

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
};

class B : public A
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
};

class mul : public B
{
    int multiply;
    public:
    void multi()
    {
        multiply = show_a() * show_b();
    }
    int get_mul(void)
    {
        return multiply;
    }
};

int main()
{
    mul ob;
    ob.A::get_a(10);
    ob.B::get_b(40);
    ob.multi();
    cout << ob.show_a() << " exists in class A" << endl;
    cout << ob.show_b() << " exists in class B" << endl;
    cout << ob.get_mul() << " is the result" << endl;
    return 0;
}