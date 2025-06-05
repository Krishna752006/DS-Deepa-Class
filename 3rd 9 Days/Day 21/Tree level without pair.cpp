#include<iostream>
#include<queue>
using namespace std;
class Node
{
    public:
    int data; 
    Node *right;
    Node *left;
    Node(int data):data(data){right = nullptr;left=nullptr;}
};
class Tree
{
  public:
  Node *root;
  Tree()
  {
      root = nullptr;
  }
  void traverse()
  {
      queue <Node *> q;
      q.push(root);
      q.push(nullptr);
      int level = 0;
      while(!q.empty())
      {
          Node *n = q.front();
          q.pop();
          if(n == nullptr)
          {
              level++;
              if(!q.empty())
              {
                  q.push(nullptr);
              }
          }
              else
              {
                  if(level == 2)
                  cout << n->data << " ";
                  if(n->left) q.push(n->left);
                  if(n->right) q.push(n->right);
              }
          }
  }
};
int main()
{
    Tree *t = new Tree();
    t->root = new Node(20);
    t->root->left = new Node(80);
    t->root->right = new Node(3);
    t->root->left->left = new Node(4);
    t->root->left->right = new Node(78);
    t->root->right->left = new Node(31);
    t->traverse();

    return 0;
}