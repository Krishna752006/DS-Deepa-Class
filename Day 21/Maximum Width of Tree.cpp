#include <iostream>
#include <queue>
using namespace std;
class Node
{
    public:
    Node *left;
    Node *right;
    int data;
    Node(int a)
    {
        data = a;
        left = right = nullptr;
    }
    ~Node(){}
};
class Tree
{
  public:
  Node *root;
  Tree()
  {
      root = nullptr;
  }
  void width()
  {
      queue<Node*> q;
      q.push(root);
      int width = 0;
      while(!q.empty())
      {
          int levelsize = q.size();
          width = max(width,levelsize);
          for(int i = 0;i < levelsize;i++)
          {
              Node *n = q.front();
              q.pop();
              if(n->left) q.push(n->left);
              if(n->right) q.push(n->right);
          }
      }
      cout << "Width = " << width;
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
    t->root->right->left = new Node(41);
    t->root->right->right = new Node(44);
    t->width();
    return 0;
}