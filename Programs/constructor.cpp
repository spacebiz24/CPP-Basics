#include <iostream>

using namespace std;

class Counter
{
    int count;

public:
    Counter()
    {
        count = 4;
    }
    Counter(int x, int y)
    {
        count = x + y;
    }
    Counter(Counter &countPrev)
    {
        count = countPrev.getCount();
        count++;
    }
    int getCount()
    {
        return count;
    }
};

int main()
{
    Counter Count1;
    cout << "Count1: " << Count1.getCount() << endl;
    Counter Count2(10, 30);
    cout << "Count2: " << Count2.getCount() << endl;
    Counter Count3(Count2);
    cout << "Count3: " << Count3.getCount() << endl;
    return 0;
}