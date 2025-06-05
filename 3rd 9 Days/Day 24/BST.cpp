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
  ~Node(){}
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
      Node *n = new Node(a);
      if(root == nullptr)
      {
          root = n;
          return;
      }
      Node *temp = root;
      while(true)
      {
          if(a < temp->data) 
          {
              if(temp->left == nullptr)
              {
                  temp->left = n;
                  return;
              }
              else temp = temp->left;
          }
          else
          {
              if(temp->right == nullptr)
              {
                  temp->right = n;
                  return;
              }
              else temp = temp->right;
          }
      }
  }
  bool search(int key)
  {
      if(root == nullptr)
      {
          return false;
      }
      Node *temp = root;
      while(temp != nullptr)
      {
          if(key < temp->data) 
          {
              temp = temp->left;
          }
          else if(key > temp->data)
          {
              temp = temp->right;
          }
          else if(key == temp->data)
          {
              return true;
          }
      }
      return false;
  }
  void inordert(Node *node)
  {
      if (node == nullptr) return;
      inordert(node->left);
      cout << node->data << " ";
      inordert(node->right);
  }
  void inorder()
  {
      inordert(root);
  }
  void findmin(Node *n)
  {
      if(n->left != nullptr)
      {
        findmin(n->left);
      }
      else 
      cout << "\nMinimum: " << n->data; 
  }
  void findmax(Node *n)
  {
      if(n->right != nullptr)
      {
        findmax(n->right);
      }
      else 
      cout << "\nMaximum: " << n->data; 
  }
};
int main()
{
    bst *b = new bst();
    b->insert(20);
    b->insert(13);
    b->insert(1);
    b->insert(0);
    b->insert(2);
    b->inorder();
    cout << "\n" << b->search(2);
    b->findmin(b->root);
    b->findmax(b->root);
    return 0;
}