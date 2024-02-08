#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
	node(int val){
		data = val;
		next = NULL;
	}
};
class LinkedList{
	public:
	
		node* head;
		
		LinkedList(){
			head=NULL;
		}
	// Adding the node at the end of the list
	void inserAtEnd(int val){
		node* newnode = new node(val);
		if(head==NULL){
			head=newnode;
			return;
		}
		node* temp = head;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newnode;
	}
	// Adding the node at the starting position
	void insertAtHead(int val){
		node* newnode = new node(val);
		newnode->next=head;
		head=newnode;
	}
	// Inserting the node at the given value
	void insertAtPos(int pos, int val){
		if (pos==0){
			insertAtHead(val);
    		return;
		}
		
		node* newnode = new node(val);
		node* temp= head;
		int currpos = 0;
		
		while(currpos!=pos-1){
			temp= temp->next;
			currpos++;
		}
		newnode->next = temp->next;
		temp->next=newnode;
		
	}
	//Displaying the list
	void display(){
		node* temp = head;
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL";
	}
};
int main(){
	LinkedList newlist;
	cout<<"Inseting at the end of the list"<<endl;
	newlist.inserAtEnd(3);
	newlist.inserAtEnd(4);
	newlist.inserAtEnd(5);
	newlist.inserAtEnd(10);
	newlist.display();
	cout <<endl<<"Inserting at the Start of the list"<<endl;
	newlist.insertAtHead(55);
	newlist.insertAtHead(60);
	newlist.display();
	cout<<endl<<"Inserting the node at the given position"<<endl;
	newlist.insertAtPos(2,100);
	newlist.insertAtPos(3,800);
	newlist.display();
}
