#include <iostream>
using namespace std;
class Node
{
  public:
  int data;
  Node *next;
  Node(int a)
  {
      data = a;
      next = nullptr;
  }
  ~Node(){ }
};
class Stack
{
    public:
    Node *top;
    Stack()
    {
        top = nullptr;
    }
    void push(int i)
    {
        Node *n = new Node(i);
        if(isEmpty())
        {
            top = n;
            return;
        }
        n->next = top;
        top = n;
    }
    void display()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty";
            return;
        }
        Node *temp = top;
        cout << "Elements: ";
        while(temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
    void peek()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty";
            return;
        }
        cout << "Top Element: " << top->data << "\n";
    }
    void pop()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty";
            return;
        }
        Node *temp = top;
        top = temp->next;
        delete temp;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
};
int main()
{
    Stack s;
    s.push(6);
    s.push(69);
    s.push(3);
    s.push(65);
    s.pop();
    s.push(77);
    s.push(256);
    s.peek();
    s.display();
}