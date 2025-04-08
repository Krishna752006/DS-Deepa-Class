#include <iostream>
#define MAX 10
using namespace std;
class Stack
{
    public:
  int top;
  int Arr[MAX];
  Stack()
  {
      top = -1;
  }
  void push(int n)
  {
      if(top == MAX-1)
      {
          cout << "Stack Overflow Error";
          return;
      }
      Arr[++top] = n;
  }
  int pop()
  {
      if(top == -1)
      {
          cout << "Stack Underflow Error" << endl;
      }
      return Arr[top--];
  }
  void display()
  {
      if(top == -1)
      {
          cout << "Stack is Empty.";
          return;
      }
      cout << "Elements: \n";
      for(int i = 0;i<=top;i++)
      {
          cout << Arr[i] << "\n";
      }
  }
  int peek()
  {
      if(top == -1)
      {
          cout << "Stack is Empty." << endl;
      }
      return Arr[top];
  }
  bool isEmpty()
  {
      return top == -1;
  }
  void sort()
  {
      if(top == -1)
      {
          cout << "Stack is Empty.";
          return;
      }
      Stack s1;
      while(!isEmpty())
      {
          s1.push(pop());
      }
      int e;
      while(!s1.isEmpty())
      {
          e = s1.pop();
          if(isEmpty() || e>peek())
          {
              push(e);
          }
          else
          {
              while(!isEmpty() && e<peek())
              {
                  s1.push(pop());
              }
              push(e);
          }
      }
  }
};
int main()
{
    Stack s;
    s.push(11);
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(90);
    s.sort();
    s.display();
}