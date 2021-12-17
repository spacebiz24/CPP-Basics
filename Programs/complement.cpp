#include <iostream>

using namespace std;

class Complement
{
    string bin;

public:
    Complement(string s)
    {
        cout << "Entered binary sequence " << s << endl;
        bin = s;
        checkEntry();
        ComplementGenerator();
        displayComplement();
    }
    void checkEntry(void);
    void ComplementGenerator(void);
    void displayComplement(void);
};

void Complement::checkEntry(void)
{
    for (int i = 0; i < bin.length(); i++)
    {
        if (bin.at(i) != '0' && bin.at(i) != '1')
        {
            cout << "Binary number is invalid" << endl;
            exit(-1);
        }
    }
}

void Complement::ComplementGenerator(void)
{
    for (int i = 0; i < bin.length(); i++)
    {
        if (bin.at(i) == '0')
            bin.at(i) = '1';
        else
            bin.at(i) = '0';
    }
}
void Complement::displayComplement(void)
{
    cout << "One's Complement is " << bin << endl;
}

int main()
{
    string binSequence;
    cout << "Enter a binary sequence" << endl;
    cin >> binSequence;
    Complement comp(binSequence);
    return 0;
}