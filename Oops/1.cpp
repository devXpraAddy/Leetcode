#include <bits/stdc++.h>

using namespace std;

class Student
{
private:
    double salary;

public:
    string name;
    int roll;
    int age;
    long long phone;

    Student()
    {
        roll = 2106177;
        age = 21;
        phone = 8690871399;
    }

    double getter()
    {
        cout << "Salary: " << salary << endl;
    }
    double setter()
    {
    }

    void display()
    {
        cout << "roll:  " << roll << "age:  " << age << "phone:  " << phone << endl;
    }
};

int main()
{
    Student s1;
    s1.display();
    s1.getter();
    return 0;
}
