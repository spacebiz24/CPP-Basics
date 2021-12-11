#include <iostream>

using namespace std;

class Example
{
public:
    Example()
    {
        cout << "Constructor Called" << endl;
    }
    void someFunction()
    {
        cout << "Just some fuction stuff" << endl;
    }
    ~Example()
    {
        cout << "Destructor Called" << endl;
    }
};

int main()
{
    Example ex1;
    Example ex2;
    return 0;
}