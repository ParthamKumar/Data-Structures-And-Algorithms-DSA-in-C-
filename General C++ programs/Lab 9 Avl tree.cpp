#include<iostream>
using namespace std;

struct Node{
	int data;
	int height;
	Node* left;
	Node* right;
};

int getHeight(struct Node* n){
	if(n==NULL){
		return 0;
	}
	return n->height;
}
struct Node* createNode(int data){
	struct Node* node = new Node();
	node->data = data;
	node->height=1;
	node->left=NULL;
	node->right=NULL;
	return node;
};
// Balance Factor function
int getBalanceFactor(struct Node* node){
	if(node==NULL){
		return 0;
	}
	return getHeight(node->left)-getHeight(node->right);
}
// Max fun
int max(int a, int b){
	return a>b?a:b;
}
// Right Rotation
struct Node* rightRotation(struct Node* y){
	struct Node* x = y->left;
	struct Node* t2 = x->right;
	
	x->right=y;
	y->left=t2;
	
	y->height=max(getHeight(y->right),getHeight(y->left))+1;
	x->height=max(getHeight(x->right),getHeight(x->left))+1;
	
	return x;
}
struct Node* leftRotation(struct Node* x){
    struct Node* y = x->right;
    struct Node* t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

// Insertion of the node
struct Node* insert(struct Node* node, int key){
    if(node==NULL){
        return (createNode(key));
    }
    if(key<node->data){
        node->left = insert(node->left,key);
    }
    else if (key > node->data){
        node->right = insert(node->right,key);
    } else {
        return node; // Duplicate keys are not allowed
    }

    // Update height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    // Cases for rotation
    if (bf > 1 && key < node->left->data) {
        return rightRotation(node);
    }
    if (bf < -1 && key > node->right->data) {
        return leftRotation(node);
    }
    if (bf > 1 && key > node->left->data) {
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }
    if (bf < -1 && key < node->right->data) {
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }

    return node;
}

 void inOrder(Node* root){
	if(root==NULL){
		cout<<"in ";
		return ;
	}
	inOrder(root->left);
	cout<<root->data<<"-> ";
	inOrder(root->right);
}
int main(){
	struct Node* root = NULL;
	root = insert(root,1);
	root = insert(root,2);
	root = insert(root,3);
	root = insert(root,4);
	root = insert(root,5);
	
	inOrder(root);
	return 0;
}
