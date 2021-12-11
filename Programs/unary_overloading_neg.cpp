#include <iostream>

using namespace std;

class Negative
{
    int x, y, z;
    public:
    void getData(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }
    void display(void)
    {
        cout << "X" << " " << "Y" << " " << "Z" << endl;
        cout << x << " " << y << " " << z << endl;
    }
    void operator-(void)
    {
        x = -x;
        y = -y;
        z = -z;
    }
};

int main()
{
    Negative neg;
    neg.getData(10, -20, 40);
    neg.display();
    -neg;
    cout << "New neg object:" << endl;
    neg.display();
    return 0;
}