#include <iostream>

using namespace std;

class Student
{
protected:
    int rollno;

public:
    void getNumber(int a)
    {
        rollno = a;
    }
    void displayNumber()
    {
        cout << "RollNo: " << rollno << endl;
    }
};

class Test : public Student
{
protected:
    float m1, m2;

public:
    void getAcademia(float a, float b)
    {
        m1 = a;
        m2 = b;
    }
    void displayAcademia()
    {
        cout << "Academics: " << m1 << m2 << endl;
    }
};

class Sports
{
protected:
    float score;

public:
    void getSports(float x)
    {
        score = x;
    }
    void displaySports()
    {
        cout << "Sports: " << score << endl;
    }
};

class Result : public Test, public Sports
{
    float totalScore;

public:
    void displayTotal()
    {
        totalScore = m1 + m2 + score;
        displayNumber();
        displayAcademia();
        displaySports();
        cout << "Total: " << totalScore << endl;
    }
};

int main()
{
    Result result;
    result.getNumber(24);
    result.getAcademia(95, 95);
    result.getSports(84);
    result.displayTotal();
    return 0;
}