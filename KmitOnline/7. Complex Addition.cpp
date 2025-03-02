/*
Write a CPP program to perform addition of two complex numbers using operator overloading.

Sample Input:
3+4i
4+7i

Sample Output:
7+11i

*/
#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;
    Complex() {}
    Complex(int r, int i) : real(r), imag(i) {}

    Complex operator+(const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }

    friend ostream &operator<<(ostream &out, const Complex &c) {
        out << c.real << "+" << c.imag << "i";
        return out;
    }

    friend istream &operator>>(istream &in, Complex &c) {
        char sign, i;
        in >> c.real >> sign >> c.imag >> i; 
        return in;
    }
};

int main() {
    Complex c1, c2, sum;
    cin >> c1;
    cin >> c2;
    sum = c1 + c2;

    cout << sum << endl;

    return 0;
}