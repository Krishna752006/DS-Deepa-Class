#include <iostream>
using namespace std;
class Node 
{
public:
    int num;
    Node *next;
    Node *prev;

    Node(int num) : num(num), next(nullptr),prev(nullptr) {}
    ~Node() 
    {
        cout << "\nDestructor Called for: " << num << "\n";
    }
};
class DLL 
{
    public:
    Node *head;
        DLL() 
    {
     head = nullptr; 
    }
    void add(Node *n) 
    {
        if (head == nullptr) 
        {
            head = n;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr) 
        {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }
    void addAfter(Node *n,int data)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if(temp->num == data)
            {
                n->prev = temp;
                n->next = temp->next;
                temp->next = n;
                temp = n->next;
                temp->prev = n;
                return;
            }
            temp = temp->next;
        }
    }
    void remove(int data)
    {
        Node *temp = head;
        while(temp != nullptr)
        {
            if(temp->num == data)
            {
                if(temp == head)
                {
                    head = head->next;
                }
                else
                {
                    temp->prev->next = temp->next;
                    if(temp->next != nullptr)
                    {
                        temp->next->prev = temp->prev;    
                    }
                }
                    delete temp;
                    return;
            }
            temp = temp->next;
        }
    }
    void display() 
    {
        if (head == nullptr) 
        {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        while (temp != nullptr) 
        {
            cout << temp->num;
            if (temp->next != nullptr) cout << "<-->";
            temp = temp->next;
        }
        cout << "\n";
    }
};
int main() 
{
    DLL *d = new DLL();
    Node *n = new Node(23);
    d->add(n);
    Node *n1 = new Node(69);
    d->add(n1);
    Node *n2 = new Node(106);
    d->add(n2);
    Node *n3 = new Node(253);
    d->addAfter(n3,69);
    d->remove(69);
    d->display();
    return 0;
}