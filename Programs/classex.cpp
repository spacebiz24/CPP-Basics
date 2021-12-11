#include <iostream>

using namespace std;

class Example
{
    string message = "Hello, World!";
    public:
    string printMessage(void)
    {
        return message;
    }
};

int main()
{
    Example ex;
    cout << ex.printMessage() << endl;
    return 0;
}