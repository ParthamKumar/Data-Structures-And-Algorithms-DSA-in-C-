#include<iostream>
using namespace std;
class node{
	public:
		int data;
		int key;
		node* next;
		node* prev;
	node(int k, int val){
		this->data = val;
		this->key = k;
		next =NULL;
		prev=NULL;
	}
};
class LinkedList{
	public:
		node* head;
		node* tail;
	LinkedList(){
		head =NULL;
		tail-=NULL;
	}
	// Inserting at the head
	void insertAtHead(int k,int val){
		node* newnode = new node(k,val);
		if(head==NULL){
			head=newnode;
			tail=newnode;
			return;
		}
		newnode->next = head;
		head->prev = newnode;
		head= newnode;
		return;
	}
	//inserting node at the tail
	void insertAtEnd(int k,int val){
		node* newnode =new node(k,val);
		if(head==NULL){
			head=newnode;
			tail=newnode;
			return;
		}
		tail->next = newnode;
		newnode->prev=tail;
		tail=newnode;
		return;
	}
	//inserting the node after the position
	void insertAtPos(int pos,int k,int val){
		node* temp=head;
		int count=1;
		while(count<(pos-1)){
			temp=temp->next;
			count++;
		}
		node* newnode = new node(k,val);
		newnode->next=temp->next;
		temp->next = newnode;
		newnode->prev = temp;
		temp->next->prev=newnode;
	}
	//Delete the node via key
	void deleteViaKey(int k){
		node* temp=head;
		while(temp->key!=k){
			temp= temp->next;
		}
		// now we are at the pos of deleting
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
	// Display fun
	void display(){
		node* temp=head;
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"Null";
	}
};
int main(){
	LinkedList newlist;
	newlist.insertAtHead(1,3);
	newlist.insertAtHead(2,66);
	newlist.display();
	cout<<endl<<"Inserting(76 ,36 78) at the end of the list"<<endl;
	newlist.insertAtEnd(3,76);
	newlist.insertAtEnd(4,36);
	newlist.insertAtEnd(5,78);
	newlist.display();
	cout<<endl;
	cout<<"Inserting the value(100) at the 3rd position"<<endl;
	newlist.insertAtPos(3,6,100);
	newlist.display();
	cout<<endl<<"Deleting the value at key 4 which is 36 "<<endl;
	newlist.deleteViaKey(4);
	newlist.display();
}

