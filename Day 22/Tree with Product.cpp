#include <iostream>
#include <queue>
using namespace std;
class Product
{
    public:
    Product *left;
    Product *right;
    int price,quantity;
    string name;
    Product(int a,int b,string c)
    {
        price = a;
        quantity = b;
        name = c;
        left = right = nullptr;
    }
    ~Product(){}
};
class Tree
{
  public:
  Product *root;
  Tree()
  {
      root = nullptr;
  }
  void traversal()
  {
      queue<pair<Product*,int>> q;
      q.push({root,0});
      while(!q.empty())
      {
          Product *n = q.front().first;
          int level = q.front().second;
          q.pop();
          cout << "Name: " << n->name << " Price: " << n->price << " Quantity: " << n->quantity << "\n";
          if(n->left) q.push({n->left,level+1});
          if(n->right) q.push({n->right,level+1});
      }
  }
};
int main()
{
    Tree *t = new Tree();
    t->root = new Product(10,20,"Coke");
    t->root->left = new Product(20,80,"Mazaa");
    t->root->right = new Product(10,3,"Rum");
    t->root->left->left = new Product(100,4,"Oreo Biscute");
    t->traversal();
    return 0;
}