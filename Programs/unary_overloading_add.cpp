#include <iostream>

using namespace std;

class Test
{
    int count;

public:
    Test() : count(4) {}
    void display(void)
    {
        cout << "Count: " << count << endl;
    }
    Test operator++()
    {
        Test temp;
        ++count;
        temp.count = count;
        return temp;
    }
};

int main()
{
    Test temp1, temp2;
    temp1.display();
    temp2.display();
    temp2 = ++temp1;
    cout <<"New Values:" << endl;
    temp1.display();
    temp2.display();
    return 0;
}