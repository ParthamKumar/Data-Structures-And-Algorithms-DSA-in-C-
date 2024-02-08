#include<iostream>
using namespace std;

class Node{
	public:
		int value;
		Node* left;
		Node* right;
		
		Node(int v){
			this->value = v;
			this->left=NULL;
			this->right=NULL;
		}
		
};
class PriorityQueue{
	private:
		Node* root;
		
	void insert(Node* &root,int value){
		if(root==NULL){
			root = new Node(value);
			return;	
		}
		if(root->left==NULL){
			root->left=new Node(value);
		}else if(root->right==NULL){
			root->right = new Node(value);
		}else{
			insert(root->left,value);
		}
	}
	void heapify(Node* node) {
    if (node == NULL) {
        return;
    }

    Node* smallest = node;
    Node* left = node->left;
    Node* right = node->right;

    if (left != NULL && left->value < smallest->value) {
        smallest = left;
    }

    if (right != NULL && right->value < smallest->value) {
        smallest = right;
    }

    if (smallest != node) {
        swap(node->value, smallest->value);
        heapify(smallest);
    }
}

	
	public:
		PriorityQueue(){
			root=NULL;
		}
		void push(int value){
			insert(root,value);
			heapify(root);
		}
		void pop(){
			if(root==NULL){
				cout<<"Queue Emptyt"<<endl;
				return;
			}
			Node* rightLeaf = root;
			while(rightLeaf->right!=NULL){
				rightLeaf = rightLeaf->right;
			}
			swap(root->value,rightLeaf->value);
			delete(rightLeaf);
		}
		int const top(){
			if(root==NULL){
				return -1;
			}
			return root->value;
		}
		bool const empty(){
			return root==NULL;
		}
};
int main(){
	PriorityQueue q;
	q.push(0);
	q.push(5);
	q.push(8);
	q.push(6);
	q.push(5);
	q.push(4);
	q.push(3);
	q.push(1);
	q.push(2);
	
	while(q.empty()){
		cout<<q.top()<<" ";
		q.pop();
	}
}
