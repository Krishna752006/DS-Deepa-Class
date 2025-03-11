/*

Write a c++ program for singly linked list, where each node contains an value and a pointer to the next node in the list. 
implement weather the node exist or not in the list.

input1:
 A list with the elements 1 -> 2 -> 3 -> 4  
 search value 3.

 Output: Node with value 3 exists in the list.
 
 Input2: 
 A list with the elements 10 -> 20 -> 30 -> 40  
 search value 25.

 Output: Node with value 25 does not exist in the list.



*/
#include <iostream>
using namespace std;
class Node
{
    public:
    int num; Node *ptr;
  Node(int num):num(num),ptr(nullptr){}
  ~Node()
  {
      cout<<"Destructor Called for " << num << endl;
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
  void add(int num)
  {
      Node *n = new Node(num);
      if(head == nullptr)
      {
          head = n;
          return;
      }
      Node *temp = head;
      while(temp->ptr != nullptr)
      {
          temp = temp->ptr;
      }
      temp->ptr = n;
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
        cout << temp->num;
        if (temp->ptr != nullptr) cout << " -> ";
        temp = temp->ptr;
      }
        cout << endl;
  }
  bool value(int a)
  {
      if(head == nullptr) return false;
      Node *temp = head;
      while(temp != nullptr)
      {
          if(temp->num == a)
          {
              return true;
          }
          temp = temp->ptr;
      }
      return false;
  }
};
int main()
{
    SLL *s = new SLL();
    s->add(1);
    s->add(2);
    s->add(3);
    s->add(4);
    s->display();
    int n;
    cout<< "search value ";
    cin >> n;
    if(s->value(n) == false)
    {
        cout << "Node with value " << n << " does not exist in the list.";
    }
    else
    {
        cout << "Node with value " << n << " exists in the list.";
    }
    return 0;
}