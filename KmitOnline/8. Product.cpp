/*
Write a C++ program for class Product with attributes as name, price,quantity.

Overload the following operators:
1. + to add two products of the same type (Eg:product1 = product1 + product2).
2. - to decrease the quantity of a product (Eg:product1 = product1 - 2).
3. * to apply a discount (Eg:product1 = product1 * 0.10;).
4. == to check if two products are the same (Eg:product1==product2).
5. << to print product details.
6. >> to take input for a product.

*/

#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string name;
    double price;
    int quantity;

    Product(){}
    Product(string n, double p, int q) : name(n), price(p), quantity(q) {}

    Product operator+(const Product &p) {
        if (name == p.name) { 
            return Product(name, price, quantity + p.quantity);
        }
        cout << "\nCannot add different products!";
        return *this;
    }

    Product operator-(int q) {
        if (quantity >= q) {
            return Product(name, price, quantity - q);
        }
        cout << "\nInsufficient quantity!";
        return *this;
    }

    Product operator*(double discount) {
        return Product(name, price * (1 - discount), quantity);
    }

    bool operator==(const Product &p) {
        return (name == p.name && price == p.price);
    }

    friend ostream &operator<<(ostream &out, const Product &p) {
        out << "Product: " << p.name << ", Price: $" << p.price << ", Quantity: " << p.quantity;
        return out;
    }

    friend istream &operator>>(istream &in, Product &p) {
        cout << "Enter Product Name: ";
        in >> p.name;
        cout << "Enter Product Price: ";
        in >> p.price;
        cout << "Enter Product Quantity: ";
        in >> p.quantity;
        return in;
    }
};


int main() {
    Product product1, product2;
    
    cout << "Enter details for the first product:\n";
    cin >> product1;
    cout << "\nEnter details for the second product:\n";
    cin >> product2;

    cout << "\nProduct 1 Details: " << product1 << endl;
    cout << "Product 2 Details: " << product2 << endl;

    cout << "\nAre the two products the same? " << ((product1 == product2) ? "Yes" : "No") << endl;

       if (product1 == product2) {
        product1 = product1 + product2;
        cout << "\nAfter combining both products: " << product1 << endl;
    }

    product1 = product1 - 2;
    cout << "\nAfter reducing Product 1 quantity by 2: " << product1 << endl;

    product1 = product1 * 0.10;
    cout << "\nAfter applying 10% discount on Product 1: " << product1 << endl;

    return 0;
}