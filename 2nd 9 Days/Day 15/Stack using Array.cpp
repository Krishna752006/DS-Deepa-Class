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
      cout << n << " is pushed into Stack.\n";
  }
  void pop()
  {
      if(top == -1)
      {
          cout << "Stack Underflow Error";
          return;
      }
      cout << Arr[top--] << " popped out of Stack.\n";
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
  void peek()
  {
      if(top == -1)
      {
          cout << "Stack is Empty.";
          return;
      }
      cout << Arr[top] << " is on top of Stack.\n";
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
    s.display();
    s.peek();
    s.pop();
    s.display();
}