#include <iostream>
#include <queue>
#include <vector>
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
class Tree
{
  public:
  Node* root;
  Tree()
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
      queue<Node* > q;
      q.push(root);
      while(!q.empty())
      {
          Node* temp = q.front();
          q.pop();
          if(!temp->left)
          {
              temp->left = n;
              return;
          }
          else
          q.push(temp->left);
          if(!temp->right)
          {
              temp->right = n;
              return;
          }
          else
          q.push(temp->right);
      }
  }
  void bst_traversal()
  {
      if(root == nullptr)
      return;
      queue<pair<Node*,int>> q;
      q.push({root,0});
      while(!q.empty())
      {
          Node* n = q.front().first;
          int l = q.front().second;
          q.pop();
          cout << n->data << " Level: " << l << "\n";
          if(n->left) q.push({n->left,l+1});
          if(n->right) q.push({n->right,l+1});
      }
      cout << "\n";
  }
  void printleaf()
  {
      if(root == nullptr)
      return;
      queue<pair<Node*,int>> q;
      q.push({root,0});
      while(!q.empty())
      {
          Node* n = q.front().first;
          int l = q.front().second;
          q.pop();
          if(n->left == nullptr && n->right == nullptr)
          cout << "Leaf Node: " << n->data << " Level: " << l << "\n";
          if(n->left) q.push({n->left,l+1});
          if(n->right) q.push({n->right,l+1});
      }
      cout << "\n";
  }
  void printmaxwidth()
  {
      if(root == nullptr)
      return;
      queue<pair<Node*,int>> q;
      vector<int> v;
      q.push({root,0});
      while(!q.empty())
      {
          Node* n = q.front().first;
          int l = q.front().second;
          q.pop();
          if(l>=v.size())
          v.resize(l+1,0);
          v[l]++;
          if(n->left) q.push({n->left,l+1});
          if(n->right) q.push({n->right,l+1});
      }
      int m = -20;
      for(int i = 0;i<v.size();i++)
      {
          m = max(m,v[i]);
      }
      cout << "Max Width = " << m << "\n";
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
          cout << n->data << "\n";
          inorder(n->right);
      }
  }
  void preorder()
  {
      preorder(root);
  }
  void preorder(Node* n)
  {
      if(n != nullptr)
      {
          cout << n->data << "\n";
          preorder(n->left);
          preorder(n->right);
      }
  }
  void postorder()
  {
      postorder(root);
  }
  void postorder(Node* n)
  {
      if(n != nullptr)
      {
          postorder(n->left);
          postorder(n->right);
          cout << n->data << "\n";
      }
  }
  /*
  void delete(int a)
  {
      To Be Done Later --> This Manual Delete
  }
  */
};
int main()
{
    Tree* t = new Tree();
    t->insert(5);
    t->insert(6);
    t->insert(7);
    t->insert(8);
    t->insert(9);
    t->insert(10);
    t->insert(11);
    t->insert(12);
    t->bst_traversal();
    t->inorder();
    t->postorder();
    t->preorder();
}