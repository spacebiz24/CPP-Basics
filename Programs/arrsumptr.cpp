#include <iostream>

using namespace std;

int main()
{
    int sum = 0, num, arr[100];
    cout << "Enter size of array:" << endl;
    cin >> num;
    cout << "Enter Array:" << endl;
    for (int i = 0; i < num; i++)
        cin >> arr[i];
    int *ptr;
    ptr = &arr[0];
    for (int i = 0; i < num; i++)
    {
        sum += *ptr;
        ptr++;
    }
    cout << "Sum is " << sum << endl;
    return 0;
}