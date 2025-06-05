/*wite a cpp program to print all the leaf nodes


*/
#include<iostream>
#include <queue>
using namespace std;
class Node
{
    public:
    int data; 
    Node *right;
    Node *left;
    Node(int data):data(data){right = nullptr;left=nullptr;}
};


void printAllLeafNodes(Node * root)
{
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        Node *n = q.front().first;
        int level = q.front().second;
        q.pop();
        if(n->left == nullptr && n->right == nullptr)
        {
            cout << "Node " << n->data << " Level " << level <<"\n";
        }
        if(n->left) q.push({n->left,level+1});
        if(n->right) q.push({n->right,level+1});
    }
    
}
int main(int argc, char const *argv[])
{
    Node * root = new Node(20);
    root->left = new Node(80);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(78);
    root->right->left = new Node(31);
    printAllLeafNodes(root);

    return 0;
}