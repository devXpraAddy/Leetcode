#include <bits/stdc++.h>

using namespace std;

class student
{
private:
    int marks;

public:
    string name;
    int age;
    double *cgpaPtr;

    // student()
    // {
    //     cout << "I am default constructor";
    //     name = "Aditya";
    //     age = 22;
    //     roll = 2106177;
    // }
    student(string name, int age, double cgpa)
    {
        this->name = name;
        *cgpaPtr = new double;

        cgpaPtr = cgpa;
    }
};

int main()
{
    student s1("Aditya", 22, 8.01);
    student s2(s1); // default copy constructor
    cout << "Name:  " << s1.name << "  Age:  " << s1.age << "  Roll:  " << cout << s2.name << endl;
}
