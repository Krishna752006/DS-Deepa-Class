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
            cout << "Empty Queue";
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
            cout << "Empty Queue";
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
int main()
{
    Queue q;
    q.enqueue(6);
    q.enqueue(69);
    q.dequeue();
    q.enqueue(77);
    q.display();
    cout << "Size = " << q.size;
}