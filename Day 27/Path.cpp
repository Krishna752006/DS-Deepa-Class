#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int a) {
        data = a;
        left = right = nullptr;
    }
};

class bst {
public:
    Node* root;
    
    bst() {
        root = nullptr;
    }

    void insert(int a) {
        if (root == nullptr) {
            root = new Node(a);
        } else {
            insert(root, a);
        }
    }

    void insert(Node* n, int a) {
        if (a < n->data) {
            if (n->left != nullptr)
                insert(n->left, a);
            else
                n->left = new Node(a);
        }
        else if (a > n->data) {
            if (n->right != nullptr)
                insert(n->right, a);
            else
                n->right = new Node(a);
        }
    }

    void display(Node* n) {
        if (n == nullptr) return;
        display(n->left);
        cout << n->data << " ";
        display(n->right);
    }

    void display() {
        display(root);
    }

    Node* find(int a) {
        return find(root, a);
    }

    Node* find(Node* n, int a) {
        if (n == nullptr) return nullptr;
        if (a > n->data)
            return find(n->right, a);
        else if (a < n->data)
            return find(n->left, a);
        else
            return n;
    }
    
    int height() {
        return height(root);
    }
    
    int height(Node* node) {
        if (node == nullptr)
            return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + max(leftHeight, rightHeight);
    }

    
    void path(int a)
    {
        Node *temp = root;
        while(temp!=nullptr)
        {
        if(temp->data == a)
        {
            cout << a << "\n";;
            return;
        }
        else if(a < temp->data)
        {
            cout << temp->data << "-->";
            temp = temp->left;
        }
        else
        {
            cout << temp->data << "-->";
            temp = temp->right;
        }
        }
    }
};

int main() {
    bst* b = new bst();
    
    b->insert(39);
    b->insert(41);
    b->insert(23);
    b->insert(34);
    b->insert(69);
    b->insert(49);
    
    b->path(41);
    b->path(69);
    cout <<"Height: " << b->height();
    return 0;
}