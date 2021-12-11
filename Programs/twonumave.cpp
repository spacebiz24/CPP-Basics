#include <iostream>

using namespace std;

int main()
{
	int num1, num2;
	cout << "Enter two numbers:" << endl;
	cin >> num1 >> num2;
	float average = (num1 + num2) / 2.0;
	cout << "Average: " << average << endl;
	return 0;
}