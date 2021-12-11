#include <iostream>

using namespace std;

class Numbers
{
    int a, b;

public:
    void getValues(int x, int y)
    {
        a = x;
        b = y;
    }
    int showA()
    {
        return a;
    }
    int showB()
    {
        return b;
    }
};

class Multiply : public Numbers
{
    int result;

public:
    int Multiplication(void)
    {
        result = showA() * showB();
        return result;
    }
};

class Add : public Numbers
{
    int result;

public:
    int Addition()
    {
        result = showA() + showB();
        return result;
    }
};

int main()
{
    Multiply M;
    Add A;
    int a, b;
    cout << "Enter two numbers: " << endl;
    cin >> a >> b;
    M.getValues(a, b);
    A.getValues(a, b);
    cout << endl;
    cout << "Numbers are: " << M.showA() << ", " << M.showB() << endl;
    cout << "Multiplication Result: " << M.Multiplication() << endl;
    cout << "Addition Result: " << A.Addition() << endl;
    return 0;
}