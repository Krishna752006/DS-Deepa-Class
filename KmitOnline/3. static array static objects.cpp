/*
Write a C++ program to implement an Employee,
Consider employee details as Name, Employee ID and Salary. 
create a static array of N static employee objects.

*/
#include <iostream>
#include <cmath>
using namespace std;
class Employee
{
  public:
    string name;
    int eid;
    int salary;
    
    Employee() {}
    Employee(string a,int b,int c):name(a),eid(b),salary(c) {}

    void display()
    {
        cout << "\n" << name << " has an employee id of " << eid << " and a salary of $" << salary << ".";
    }
    
    ~Employee()
    {
        cout << "\nDestructor Called.";
    }
};
int main()
{
    int n;
    cout << "Enter value of N: ";
    cin >> n;
    Employee e[n];
    for(int i = 0;i<n;i++)
    {
        cout << "Employee " << i+1 << ": \n";
        cout << "Enter the name: ";
        cin >> e[i].name;
        cout << "Enter the eid: ";
        cin >> e[i].eid;
        cout << "Enter the salary: ";
        cin >> e[i].salary;
        cout << "\n";
    }
    for(int i =0;i<n;i++)
    {
        e[i].display();
    }
    return 0;
}