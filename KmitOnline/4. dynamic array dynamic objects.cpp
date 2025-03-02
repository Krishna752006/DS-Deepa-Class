/*
Write a C++ program to implement an Employee, 
Consider employee details as Name, Employee ID and Salary.
create a dynamic array of N dynamic employee objects.


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
    Employee** e = new Employee*[3];
    e[0] = new Employee("KC",1,9999);
    e[1] = new Employee("Loki",2,6969);
    e[2] = new Employee("God",0,80085);
    e[0]->display();
    e[1]->display();
    e[2]->display();
    delete e[0];
    delete e[1];
    delete e[2];
    delete[] e;
    return 0;
}