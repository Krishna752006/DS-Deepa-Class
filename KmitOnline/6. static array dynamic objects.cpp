/*
Write a C++ program to implement a Car, 
Consider Car Details as Brand, Price and Manufacturing Year.  
create a static array of N dynamic car objects  and display their details.

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
    Car* c[3];
    c[0] = new Car("Farrai",9999,2000);
    c[1] = new Car("Lamborgini",9998,2001);
    c[2] = new Car("BMW",999,999);
    c[2]->display();
    delete c[2];
    delete c[0];
    delete c[1];
    return 0;
}