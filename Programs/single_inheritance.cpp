#include <iostream>

using namespace std;

class A
{
    int a;

public:
    int b;
    void get_a_b(int x, int y)
    {
        a = x;
        b = y;
    }
    int show_a(void) {
        return a;
    }
};

class mul : private A
{
    int multiply;
    public:
    void get(int x, int y)
    {
        get_a_b(x, y);
    }
    int multi(void)
    {
        multiply = show_a() * b;
        return multiply;
    }
};

int main()
{
    mul ob;
    ob.get(10, 40);
    cout << ob.multi() << endl;
    return 0;
}