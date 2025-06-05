#include <iostream>
using namespace std;
class Node
{
  public:
  int data;
  Node* left;
  Node* right;
  Node(int a)
  {
      data = a;
      left = right = nullptr;
  }
  ~Node(){}
};
class BST
{
  public:
  Node* root;
  BST()
  {
      root = nullptr;
  }
  void insert(int a)
  {
      Node* n = new Node(a);
      if(root == nullptr)
      {
          root = n;
          return;
      }
      Node* temp = root;
      while(temp != nullptr)
      {
          if(a < temp->data)
          {
              if(temp->left == nullptr)
              {
                  temp->left = n;
                  return;
              }
              else
              temp = temp->left;
          }
          else
          {
              if(temp->right == nullptr)
              {
                  temp->right = n;
                  return;
              }
              else
              temp = temp->right;
          }
      }
  }
  void inorder()
  {
      inorder(root);
  }
  void inorder(Node* n)
  {
      if(n != nullptr)
      {
          inorder(n->left);
          cout << n->data << " ";
          inorder(n->right);
      }
  }
  void findmin()
  {
      findmin(root);
  }
  void findmin(Node* n)
  {
      if(n->left != nullptr)
      findmin(n->left);
      else
      cout << "\nMinimum: " << n->data;
  }
  void findmax()
  {
      findmax(root);
  }
  void findmax(Node* n)
  {
      if(n->right != nullptr)
      findmax(n->right);
      else
      cout << "\nMaximum: " << n->data;
  }
  int successor(int a)
  {
      return successor(root,a);
  }
  int successor(Node* n, int a)
  {
      if(n == nullptr) return -1;
      if(n->data<=a)
      return successor(n->right,a);
      else{
          int l = successor(n->left,a);
          return (l != -1) ? l : n->data;
      }
  }
  int predecessor(int a)
  {
      return predecessor(root,a);
  }
  int predecessor(Node* n, int a)
  {
      if(n == nullptr) return -1;
      if(n->data>=a)
      return predecessor(n->left,a);
      else{
          int l = predecessor(n->right,a);
          return (l != -1) ? l : n->data;
      }
  }
};
int main()
{
    BST* b = new BST();
    b->insert(69);
    b->insert(169);
    b->insert(9);
    b->insert(6);
    b->inorder();
}