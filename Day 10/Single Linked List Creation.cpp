#include <iostream>
using namespace std;
class Node
{
    public:
    string name;
    Node *ptr;
    
    Node(string a):name(a),ptr(nullptr) {}
    ~Node()
    {
        cout << "\nDestructor called";
    }
};
int main()
{
    Node *n1 = new Node("KMIT");
    Node *n2 = new Node("KC");
    Node *n3 = new Node("God");
    n1->ptr = n2;
    n2->ptr = n3;
    
    Node *temp = n1;
    while(temp !=nullptr)
    {
        cout << temp->name << " -> ";
        temp = temp->ptr;
    }
    cout << "NULL";
    delete n1;
    delete n2;
    delete n3;
}