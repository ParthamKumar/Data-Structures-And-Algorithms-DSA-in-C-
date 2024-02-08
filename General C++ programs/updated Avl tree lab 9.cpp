#include<iostream>
using namespace std;
class Node {
public:
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->height = 1;
        this->left = NULL;
        this->right = NULL;
    }
};

class AVLTree{
private:
    Node* root;
    int getHeight(Node* n) {
        if (n == NULL) {
            return 0;
        }
        return n->height;
    }
    Node* rightRotation(Node* y) {
        Node* x = y->left;
        Node* t2 = x->right;
        x->right = y;
        y->left = t2;
        y->height = max(getHeight(y->right), getHeight(y->left))+1;
        x->height = max(getHeight(x->right), getHeight(x->left))+1;
        return x;
    }
    Node* leftRotation(Node* x) {
        Node* y = x->right;
        Node* t2 = y->left;
        y->left = x;
        x->right = t2;
        y->height = max(getHeight(y->right), getHeight(y->left))+1;
        x->height = max(getHeight(x->right), getHeight(x->left))+1;
        return y;
    }
    Node* insert(Node* node, int key) {
        if(node==NULL){
            return new Node(key);
        }
        if(key<node->data) {
            node->left= insert(node->left, key);
        }
        else if(key>node->data) {
            node->right = insert(node->right, key);
        }
        else{
            return node;
        }
        node->height = 1+max(getHeight(node->left), getHeight(node->right));
        int bf = getBalanceFactor(node);
        // Cases for rotation
        if(bf>1&&key<node->left->data) {
            return rightRotation(node);
        }
        if(bf<-1&&key>node->right->data) {
            return leftRotation(node);
        }
        if (bf>1&&key>node->left->data) {
            node->left = leftRotation(node->left);
            return rightRotation(node);
        }
        if(bf<-1&&key<node->right->data) {
            node->right = rightRotation(node->right);
            return leftRotation(node);
        }
        return node;
    }
    int getBalanceFactor(Node* node) {
        if (node==NULL) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    void inOrder(Node* node) {
        if (node==NULL) {
            return;
        }
        inOrder(node->left);
        cout<<node->data << "-> ";
        inOrder(node->right);
    }
public:
    AVLTree(){
        root = NULL;
    }

    void insert(int key) {
        root=insert(root, key);
    }
    void inOrderTraversal() {
        inOrder(root);
    }
};

int main() {
    AVLTree avl;
    avl.insert(1);
    avl.insert(2);
    avl.insert(3);
    avl.insert(4);
    avl.insert(5);
    avl.insert(5);
    avl.insert(6);
    avl.insert(7);

    avl.inOrderTraversal();
    return 0;
}

