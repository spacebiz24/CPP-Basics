#include <iostream>

using namespace std;

int main()
{
    int num, parityNumber, count = 0, rem, n;
    cout << "Even parity or odd parity (Even - 0, Odd - 1)" << endl;
    cin >> parityNumber;
    cout << "Enter data to check parity:" << endl;
    cin >> num;
    n = num;
    while (n != 0)
    {
        rem = num % 10;
        if (rem == 1)
            count++;
        n /= 10;
    }
    if (parityNumber == 0 && count % 2 == 0)
        cout << "Data not corrupted" << endl;
    else if (parityNumber == 0 && count % 2 != 0)
        cout << "Data corrupted" << endl;
    else if (parityNumber == 1 && count % 2 != 0)
        cout << "Data not corrupted" << endl;
    else if (parityNumber == 1 && count % 2 == 0)
        cout << "Data corrupted" << endl;
    return 0;
}