/*

Write a C++ program for the singly linked list, where each node contains an value and a pointer to the next node in the list. 
implement a function to calculate the  average of the list.
input:"apple" -> "banana" -> "cherry" -> "date"

Output: average of the linked list: 2

*/
#include <iostream>
using namespace std;
class Node
{
    public:
    string name; Node *ptr;int num;
  Node(string name,int num):num(num),name(name),ptr(nullptr){}
  ~Node()
  {
      cout<<"Destructor Called for " << name << endl;
  }
};
class SLL
{
  public:
  float a = 0,s = 0;
  Node *head;
  SLL()
  {
      head = nullptr;
  }
  void add(string name,int num)
  {
      Node *n = new Node(name,num);
      if(head == nullptr)
      {
          head = n;
          a++;
          s = num;
          return;
      }
      Node *temp = head;
      while(temp->ptr != nullptr)
      {
          temp = temp->ptr;
      }
      temp->ptr = n;
      a++;
      s+=num;
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
  void avg()
  {
      cout << "average of the linked list: " << (s/a);
  }
};
int main()
{
    SLL *s = new SLL();
    s->add("apple",1);
    s->add("banana",2);
    s->add("cherry",3);
    s->add("date",2);
    s->display();
    s->avg();
    return 0;
}