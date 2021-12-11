#include <iostream>

using namespace std;

void callbyref(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
    cout << "X an Y are " << endl;
    cout << x << " " << y << endl
         << endl;
}

int main()
{
    int a, b;
    cout << "Enter two numbers: " << endl;
    cin >> a >> b;
    cout << endl;
    cout << "Before Swap: " << endl;
    cout << a << " " << b << endl
         << endl;
    cout << "After Swap: " << endl;
    callbyref(a, b);
    cout << "A and B are " << endl;
    cout << a << " " << b << endl;
    return 0;
}