#include <iostream>
using namespace std;
class Pen
{
    public:
        int quantity;
        float price;
        string name;
    
    Pen(int a, float b, string c) : quantity(a), price(b), name(c) 
    {
    cout << "Constructor called\n";
    }
    ~Pen() 
    {
    cout << "Destructor called for " << name << "\n";
    }
    void display() 
    {
    cout << name << ": " << price << endl;
    }
};

int main()
{
    Pen* s[3];  
    s[0] = new Pen(12, 33.33, "Camlin");
    s[1] = new Pen(15, 40.50, "Gold");
    s[2] = new Pen(10, 20.75, "Silver");

    for (int i = 0; i < 3; i++) 
    {
    s[i]->display();
    }
    for (int i = 0; i < 3; i++) 
    {
    delete s[i];
    }
    return 0;
}