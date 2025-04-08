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
class Queue
{
    public:
    Node *first;
    Node *last;
    int size = 0;
    Queue()
    {
        first = nullptr;
        last = nullptr;
    }
    void enqueue(int i)
    {
        Node *n = new Node(i);
        size++;
        if(isEmpty())
        {
            first = n;
            last = n;
            return;
        }
        last->next = n;
        last = n;
    }
    void display()
    {
        if(isEmpty())
        {
            cout << "Empty";
            return;
        }
        Node *temp = first;
        cout << "Elements are: \n";
        while(temp != nullptr)
        {
            cout << temp->data << "\n";
            temp = temp->next;
        }
    }
    void dequeue()
    {
        if(isEmpty())
        {
            cout << " ";
            return;
        }
        Node *temp = first;
        first = temp->next;
        delete temp;
        size--;
    }
    bool isEmpty()
    {
        return first==nullptr;
    }
};
class Stack
{
  public:
  Queue *q = new Queue();
  void push(int i)
  {
      q->enqueue(i);
  }
  void peek()
  {
      if(q->isEmpty())
      {
          cout << "Stack is Empty\n";
          return;
      }
      cout << "Latest Element: " << q->last->data << "\n";
  }
  void pop()
  {
      Node *temp = q->first;
      if(q->size != 1)
      {
          while(temp->next != q->last)
          {
              temp = temp->next;
          }
          delete q->last;
          q->last = temp;
          q->last->next = nullptr;
          q->size--;
      }
      else
      {
            delete q->first;
            q->first = q->last = nullptr;
            q->size--;
            return;
        }
  }
  void display()
  {
      q->display();
  }
};
int main()
{
    Stack *s = new Stack();
    s->push(5);
    s->push(69);
    s->push(106);
    s->peek();
    s->pop();
    s->push(607);
    s->push(46);
    s->peek();
    s->pop();
    s->display();
}