#include <iostream>

using namespace std;

class Complex
{
    float x, y;

public:
    Complex() {}
    Complex(float real, float imag)
    {
        x = real;
        y = imag;
    }
    Complex operator+(Complex Prev)
    {
        Complex Curr;
        Curr.x = x + Prev.x;
        Curr.y = y + Prev.y;
        return (Curr);
    }
    void display()
    {
        cout << x << " + " << y << "i" << endl;
    }
};

int main()
{
    Complex C1, C2, C3;
    C1 = Complex(2, 2);
    C2 = Complex(2, 2);
    C3 = C1 + C2;
    cout << "C1: ";
    C1.display();
    cout << "C2: ";
    C2.display();
    cout << "C3: ";
    C3.display();
    return 0;
}