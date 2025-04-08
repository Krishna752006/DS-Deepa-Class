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
            cout << " ";
            return;
        }
        Node *temp = top;
        while(temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void peek()
    {
        if(isEmpty())
        {
            cout << "Empty";
            return;
        }
        cout << "Top Element: " << top->data << "\n";
    }
    int pop() 
    {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
    ~Stack(){}
};
class Queue
{
    public:
    Stack *s1 = new Stack();
    Stack *s2 = new Stack();
    int size = 0;
    void enqueue(int i)
    {
        s1->push(i);
        size++;
    }
    void display()
    {
        cout << "\nElements: ";
        Stack *a = s2;
        while(!a->isEmpty())
        {
            cout << a->pop() << " ";
        }
        Stack *b = new Stack();
        Stack *c = s1;
        while(!c->isEmpty())
        {
            b->push(c->pop());
        }
        while(!b->isEmpty())
        {
            cout << b->pop() << " ";
        }
        cout << "\n";
        delete a,b,c;
    }
    void dequeue()
    {
        if(s2->isEmpty())
        {
            while(!s1->isEmpty())
            {
                s2->push(s1->pop());
            }
        }
        if(!s2->isEmpty())
        {
            s2->pop();
            size--;
            return;
        }
    }
    bool isEmpty()
    {
        return size == 0;
    }
};
int main()
{
    Queue *q = new Queue();
    q->enqueue(13);
    q->enqueue(76);
    q->dequeue();
    q->enqueue(69);
    q->enqueue(1);
    q->dequeue();
    q->enqueue(74);
    q->enqueue(77);
    cout << "Size = " << q->size;
    q->display();
}