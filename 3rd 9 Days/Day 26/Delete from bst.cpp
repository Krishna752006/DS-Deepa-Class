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

    Node* minValueNode(Node* n) {
        Node* current = n;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    void deleten(int a) {
        root = deleten(root, a);
    }

    Node* deleten(Node* node, int key) {
        if (node == nullptr)
            return root;
        
        if (key < node->data) {
            node->left = deleten(node->left, key);
        }
        else if (key > node->data) {
            node->right = deleten(node->right, key);
        }
        else {
            // Node found
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            } else if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            } else {
                TreeNode* successor = findMin(node->right);
                node->val = node->val;
                node->right = deleteBST(node->right, successor->val);
            }
        }
        return root;
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
    
    cout << "Before Deletion: ";
    b->display();
    cout << endl;
    
    b->deleten(41);
    
    cout << "After Deletion: ";
    b->display();
    cout << endl;
    
    return 0;
}