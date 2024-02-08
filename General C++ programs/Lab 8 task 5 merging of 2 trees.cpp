//osmn
#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int data){
			this->data = data;
			this->left= NULL;
			this->right=NULL;
		}
};

class Tree{
	public:
	Node* root;
	
	Tree(){
		root = NULL;
	}
	Node* insert(Node* root, int data){
		if(root==NULL){
			return new Node(data);
		}
		if(data<root->data){
			root->left = insert(root->left,data);
		} else if(data > root->data){
			root->right = insert(root->right,data);
		}else{
			root->right = insert(root->right, data);
		}
		return root;
	}
	void inOrder(Node* root){
		if(root==NULL){
			return ;
		}
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
	// join
	void join(Node* t,Node* &t2){
		if(t==NULL){
			return ;
		}
		join(t->left,t2);
		t2 =insert(t2,t->data);
		join(t->right,t2);
		
	}
// Merge
	void merge(Tree* t1, Tree* t2){
		
		join(t1->root,t2->root);
	}
	
};
int main(){
	Tree tree1;
	tree1.root = tree1.insert(tree1.root,5);
	tree1.insert(tree1.root,3);
	tree1.insert(tree1.root,2);
	tree1.insert(tree1.root,6);
	tree1.insert(tree1.root,4);
//	tree1.insert(tree1.root,4);
	
	
	Tree tree2;
	tree2.root = tree2.insert(tree2.root,2);
	tree2.insert(tree2.root,1);
	tree2.insert(tree2.root,3);
	tree2.insert(tree2.root,7);
	tree2.insert(tree2.root,6);
	

	tree1.merge(&tree1, &tree2);
//	tree1.inOrder(tree1.root);

    tree2.inOrder(tree2.root);
}
