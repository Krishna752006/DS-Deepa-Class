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
    public:
    Node *head;
        SLL() 
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
        while (temp->ptr != nullptr) 
        {
            temp = temp->ptr;
        }
        temp->ptr = n;
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
            cout << temp->name;
            if (temp->ptr != nullptr) cout << "-->";
            temp = temp->ptr;
        }
        cout << "\n";
    }
    void reverse()
    {
        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;
        while(curr->ptr != nullptr)
        {
            next = curr->ptr;
            curr->ptr = prev;
            prev = curr;
            curr = next;
        }
        curr->ptr = prev;
        head = curr;
    }
    void find(Node *head2)
    {
        Node *temp1 = head;
        while(temp1 != nullptr)
        {
            Node *temp2 = head2;
            while(temp2 != nullptr)
            {
                if(temp1 == temp2)
                {
                    cout << "\nThey intersect at " << temp1->name;
                    return;
                }
                temp2 = temp2->ptr;
            }
            temp1 = temp1->ptr;
        }
        cout << "No Intersection found.";
    }
    int length()
    {
        int a=0;
        Node *temp = head;
        if (temp == nullptr) return 0;
        while(temp != nullptr)
        {
            ++a;
            temp = temp->ptr;
        }
        return a;
    }
};
void find2(Node *head1,Node *head2)
{
        Node *temp1 = head1;
        Node *temp2 = head2;
        while(temp1 != nullptr)
        {
            if(temp1 == temp2)
            {
                cout << "\nThey intersect at " << temp1->name;
                return;
            }
            temp1 = temp1->ptr;
            temp2 = temp2->ptr;
        }
        cout << "No Intersection found.";
}
void find3(int a,int b, Node *head1, Node *head2)
{
        int d = a>b?a-b:b-a;
        if(a>b)
        {
            Node *temp = head1;
            int i =0;
            while(i<d && head1 != nullptr)
            {
                temp = temp->ptr;
                i++;
            }
            find2(temp,head2);
        }
        else if(a<b)
        {
            Node *temp = head2;
            int i = 0;
            while(i<d && head2 != nullptr)
            {
                temp = temp->ptr;
                i++;
            }
            find2(head1,temp);
        }
}
int main() 
{
    SLL *s = new SLL(); 
    Node *m1 = new Node("Godess");
    Node *m2 = new Node("God");
    Node *m3 = new Node("Lady");
    Node *m4 = new Node("Aasrith");
    s->add(m1);
    s->add(m2);
    s->add(m3);
    s->add(m4);
    s->display();
    SLL *s2 = new SLL();
    Node *n1 = new Node("Goodness");
    Node *n2 = new Node("Goth");
    s2->add(n1);
    s2->add(m3);
    s2->display();
    find3(s->length(),s2->length(),s->head,s2->head);
    return 0;
}