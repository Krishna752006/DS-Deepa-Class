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
      queue<pair<Node*,int>> q;
      q.push({root,0});
      int width = 0,curlevel = 0,count = 0;
      while(!q.empty())
      {
          Node *n = q.front().first;
          int level = q.front().second;
          q.pop();
          if( level != curlevel)
          {
              if(count > width) width = count;
              count = 0;
              curlevel = level;
          }
          count++;
          if(n->left) q.push({n->left,level+1});
          if(n->right) q.push({n->right,level+1});
      }
      if(count > width) width = count;
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
    t->root->right->right->left = new Node(414);
    t->width();
    return 0;
}