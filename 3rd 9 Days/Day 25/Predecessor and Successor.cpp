#include <iostream>
using namespace std;
class Node
{
  public:
  int data;
  Node *left;
  Node *right;
  Node(int a)
  {
      data = a;
      left = right = nullptr;
  }
  ~Node(){ }
};
class bst
{
  public:
  Node *root;
  bst()
  {
      root = nullptr;
  }
  void insert(int a)
  {
      if(root == nullptr)
      {
          root = new Node(a);
          return;
      }
      else
      {
          insert(root,a);
      }
  }
  void insert(Node *n,int a)
  {
      if(a < n->data) 
      {
          if(n->left != nullptr)
          insert(n->left,a);
          else
          n->left = new Node(a);
      }
      else if(a > n->data)
      {
          if(n->right != nullptr)
          insert(n->right,a);
          else
          n->right = new Node(a);
      }
  }
  void display(Node *n)
  {
      if(n == nullptr) return;
      display(n->left);
      cout << n->data << " ";
      display(n->right);
  }
  void display()
  {
      display(root);
  }
  void successor(int a)
  {
      cout << "\nSuccessor of " << a << " is " << successor(root,a);
  }
  int successor(Node *n,int a)
  {
      if(n == nullptr) return -1;
      if(n->data <= a)
      return successor(n->right,a);
      else if(n->data > a)
      {
          int l = successor(n->left,a);
          return (l != -1) ? l: n->data;
      }
  }
  void predecessor(int a)
  {
      cout << "\nPredessor of " << a << " is " << predecessor(root,a);
  }
  int predecessor(Node *n,int a)
  {
      if(n == nullptr) return -1;
      if(n->data >= a)
      return predecessor(n->left,a);
      else
      {
          int l = predecessor(n->right,a);
          return (l != -1) ? l: n->data;
      }
  }
};
int main()
{
    bst *b = new bst();
    b->insert(39);
    b->insert(41);
    b->insert(23);
    b->insert(34);
    b->insert(69);
    b->insert(49);
    b->display();
    b->successor(49);
    b->predecessor(69);
}