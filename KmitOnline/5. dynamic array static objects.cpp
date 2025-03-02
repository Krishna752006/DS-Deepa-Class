/*
Write a C++ program to implement a Car,
Consider Car Details as Brand, Price and Manufacturing Year.  
Dynamically create an array of N static car objects  and display their details.
*/
#include <iostream>
#include <cmath>
using namespace std;
class Car
{
  public:
    string brand;
    int price;
    int myear;
    
    Car() {}
    Car(string a,int b,int c):brand(a),price(b),myear(c) {}

    void display()
    {
        cout << "\n" << brand << " has manufactured in the year " << myear << " and is sold at a price of $" << price << ".";
    }
    
    ~Car()
    {
        cout << "\nDestructor Called.";
    }
};
int main()
{
    Car* c = new Car[3] {
    {"Farrai",9999,2000},
    {"Lamborgini",9998,2001},
    {"BMW",999,999}};
    c[2].display();
    delete[] c;
    return 0;
}