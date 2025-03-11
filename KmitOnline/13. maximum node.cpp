/*

Write a c++ program to Find the maximum node in the single linked list
input: 10 20 30 40 
output:40

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
int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
class SLL
{
  public:
  int a = -34567;
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
        a = max(a,num);
        return;
      }
      Node *temp = head;
      while(temp->ptr != nullptr)
      {
          temp = temp->ptr;
      }
      temp->ptr = n;
      a = max(a,num);
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
};
int main()
{
    SLL *s = new SLL();
    s->add(10);
    s->add(20);
    s->add(30);
    s->add(40);
    s->display();
    cout<< "Maximum Element in the Linked List: " << s->a;
    return 0;
}