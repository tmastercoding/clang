#include <iostream>
using namespace std;

// create parent class
class Person
{
public:
    // method, showing description
    void showDesc()
    {
        cout << "I AM NOT KING KONG UWWWWAAAWAWA!" << endl;
    }
};

// child class of Person
class Student : public Person
{
};

// child class of Student, grandchild of Person
class Hacker : public Student
{
};

int main()
{
    // create hacker object
    Hacker badHacker;
    // hacker still has method from Person
    badHacker.showDesc();

    return 0;
}