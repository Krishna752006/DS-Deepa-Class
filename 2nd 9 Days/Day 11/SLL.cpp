#include <iostream>
using namespace std;
class Node 
{
public:
    string name;
    Node *ptr;

    Node(string name) : name(name), ptr(nullptr) {}
    ~Node() 
    {
        cout << "\nDestructor Called for: " << name << "\n";
    }
};
class SLL 
{
    private:
        Node *head;
    public:
        SLL() 
    {
     head = nullptr; 
    }
    void add(string name) 
    {
        Node *n = new Node(name);
        if (head == nullptr) 
        {
            head = n;
            return;
        }

        Node *temp = head;
        while (temp->ptr != nullptr) 
        {
            temp = temp->ptr;
        }
        temp->ptr = n;
    }
    void addatBegin(string name)
    {
      Node *n = new Node(name);
      n->ptr = head;
      head = n;
    }  
    void addAfter(string a,string b)
    {
      Node *temp = head;
      while(temp)
      {
        if (temp->name == a)
        {
         Node *n = new Node(b);
         n->ptr = temp->ptr;
         temp->ptr = n;
        }
         temp = temp->ptr;
      }
    }  
    void addBefore(string a, string b) 
    {   
    if (!head) return; 
    if (head->name == a) 
    {
        Node *newNode = new Node(b);
        newNode->ptr = head;
        head = newNode;
        return;
    }
    for (Node *temp = head; temp->ptr; temp = temp->ptr) 
    {
        if (temp->ptr->name == a) 
        {
            Node *newNode = new Node(b);
            newNode->ptr = temp->ptr;
            temp->ptr = newNode;
            return;
        }
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
            cout << temp->name << "\n";
            temp = temp->ptr;
        }
    }
    void remove(string name) 
    {
    if (!head) return;
    if (head->name == name) 
    {
        Node *temp = head;
        head = head->ptr;
        delete temp;
        return;
    }
    for (Node *temp = head; temp->ptr; temp = temp->ptr)
        {
            if (temp->ptr->name == name) 
            {
                Node *toDelete = temp->ptr;
                temp->ptr = temp->ptr->ptr;
                delete toDelete;
                return;
            }
        }
    }
};

int main() 
{
    SLL *s = new SLL(); 
    s->add("GODESS");
    s->addatBegin("Qojja");
    s->add("Empress");
    s->add("Lady");
    s->add("Pooky");
    s->addAfter("Lady","Poova");
    s->addBefore("Lady","hi");
    s->remove("Qojja");
    cout << "List Elements:\n";
    s->display();

    return 0;
}