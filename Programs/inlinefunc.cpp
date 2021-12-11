#include <iostream>

using namespace std;

inline int largest(int x, int y);

int main()
{
    int num1, num2;
    cout << "Enter two numbers: " << endl;
    cin >> num1 >> num2;
    cout << "Largest of two numbers: " << endl;
    cout << largest(num1, num2) << endl;
    return 0;
}

int largest(int x, int y)
{
    return ((x > y) ? x : y);
}