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
			root = NULL;
		}
		// Insertion of the node to the tree
		Node* insert(Node* node, int val){
			if(node == NULL){
				return new Node(val);
			}
			if(val < node->data){
				node->left = insert(node->left,val);
			}else if(val > node->data){
				node->right = insert(node->right,val);
			}
			return node;
		}
// In order traversal
	void inOrderTraversal(Node* node){
		if (node == NULL) {
            return;
        }
        inOrderTraversal(node->left);
        cout<< node->data<< " ";
        inOrderTraversal(node->right);
	}
};
int main(){
	Tree tree;
	tree.root =tree.insert(tree.root,1);
	tree.insert(tree.root,2);
	tree.insert(tree.root,3);
	tree.insert(tree.root,4);
	tree.insert(tree.root,5);

	tree.inOrderTraversal(tree.root);
}

