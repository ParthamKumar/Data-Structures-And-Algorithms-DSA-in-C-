#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int data){
			this->data = data;
			this->left = NULL;
			this->right=NULL;
		}
};
class Tree{
	public:
		Node* root;
		
		Tree(){
			root=NULL;
		}
		// Insertion of the node
		Node* insert(Node* root, int value){
			if(root==NULL){
				return new Node(value);
			}
			if(value<root->data){
				root->left = insert(root->left,value);
			}else if(value > root->data){
				root->right = insert(root->right,value);
			}
			return root;
		}
		// In order Traversal
		void inOrder(Node* root){
			if(root == NULL){
				return ;
			}
			inOrder(root->left);
			cout<<root->data<<" ";
			inOrder(root->right);
		}
		
};
int main(){
	int n;
	int sel;
	int data;
	
	Tree tree;
	tree.root =tree.insert(tree.root,7);
	tree.insert(tree.root,5);
	tree.inOrder(tree.root);
	
	cout<<"\nHow many numbers you want to enter"<<endl;
	cin>>n;
	for(int i=0; i<n;i++){
		cout<<"What do you want ceil (1) or Floor(0)"<<endl;
		cin>>sel;
		cout<<"Enter the value"<<endl;
		cin>>data;
		if(sel== 0){
			data = data+1;
			tree.insert(tree.root,data);
			cout<<"Done"<<endl;
		}else if(sel == 1){
			data = data-1;
			tree.insert(tree.root,data);
			cout<<"Done"<<endl;
		}
	}
	tree.inOrder(tree.root);
}

