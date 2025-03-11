/*

WRITE A C++ Program for the singly linked list, where each node contains an value and a pointer to the next node in the list. 
implement a function to calculate the length of the list.
input:"apple" -> "banana" -> "cherry" -> "date"

Output: Length of the linked list: 4

*/
#include <iostream>
using namespace std;
class Node
{
    public:
    string name; Node *ptr;
  Node(string name):name(name),ptr(nullptr){}
  ~Node()
  {
      cout<<"Destructor Called for " << name << endl;
  }
};
class SLL
{
  public:
  int a = 0;
  Node *head;
  SLL()
  {
      head = nullptr;
  }
  void add(string name)
  {
      Node *n = new Node(name);
      if(head == nullptr)
      {
          head = n;
          a++;
          return;
      }
      Node *temp = head;
      while(temp->ptr != nullptr)
      {
          temp = temp->ptr;
      }
      temp->ptr = n;
      a++;
  }
  void display()
  {
      if(head == nullptr)
      {
          cout << "List is Empty.";
          return;
      }
      Node *temp = head;
      while (temp != nullptr) 
      {
        cout << temp->name;
        if (temp->ptr != nullptr) cout << " -> ";
        temp = temp->ptr;
      }
        cout << endl;
  }
};
int main()
{
    SLL *s = new SLL();
    s->add("apple");
    s->add("banana");
    s->add("cherry");
    s->add("date");
    s->display();
    cout<< "Length of the Linked List: " << s->a;
    return 0;
}