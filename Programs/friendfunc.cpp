#include <iostream>

using namespace std;

class Sample
{
    int a, b;

public:
    void setValue(int x, int y)
    {
        a = x;
        b = y;
    }
    friend float mean(Sample S)
    {
        return float(S.a + S.b) / 2.0;
    }
};

int main()
{
    Sample X;
    int a, b;
    cout << "Enter two numbers:" << endl;
    cin >> a >> b;
    X.setValue(a, b);
    cout << "Mean is: " << mean(X) << endl;
    return 0;
}