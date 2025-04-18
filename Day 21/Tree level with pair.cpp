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
      queue <pair<Node *,int>> q;
      q.push({root,0});
      while(!q.empty())
        {
          Node *n = q.front().first;
          int level = q.front().second;
          q.pop();
          if(level == 2)
          cout << n->data << " ";
          if(n->left) q.push({n->left,level+1});
          if(n->right) q.push({n->right,level+1});
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