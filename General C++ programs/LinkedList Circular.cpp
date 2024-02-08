#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
	node(int val){
		this->data = val;
		next = NULL;
	}
};
class LinledList{
	public:
	node* head;
	LinledList(){
		head= NULL;
	}
	// Inserting at the head
	void insertAtHead(int val){
		node* newnode = new node(val);
		if(head==NULL){
			head = newnode;
			newnode->next =head; //Circular LL
			return;
		}
		node* tail = head;
		while(tail->next!=head){
			tail = tail->next;
		}
		// now tail is pointing the last node of the list
		tail->next = newnode;
		newnode->next=head;
		head = newnode;
	}
	// Inserting at the end of the list
	void insertAtEnd(int val){
		node* newnode = new node(val);
		if(head==NULL){
			head = newnode;
			newnode->next= head;
			return;
		}		
		node* tail = head;
		while(tail->next!=head){
			tail = tail->next;
		}
		// Here we have will be pointing to the lastnode
		tail->next=newnode;
		newnode->next=head;
	}
	//Deleting the node at the start
	void deleteAtHead(){
		if(head==NULL){
			return;
		}
		node* temp = head;
		node* tail= head;
		while(tail->next!=head){
			tail = tail->next;
		}
		head = head->next;
		tail->next=head;
		delete(temp);
	}
	//Delete At the End
	void deleteAtEnd(){
		if(head==NULL){
			return;
		}
		node* tail = head;
		while(tail->next->next!=head){
			tail= tail->next;
		}
		// Here we are pointing to the sec last node
		node* temp = tail->next;
		tail->next = head;
		delete(temp);
	}
	// Display fun
	void display(){
		node* temp = head;
		do{
			cout<<temp->data<<"->";
			temp = temp->next;
		}while(temp!=head);
		cout<<"Null"<<endl;
	}
};
int main(){
	LinledList newlist;
	newlist.insertAtHead(3);
	newlist.insertAtHead(5);
	newlist.insertAtHead(56);
	newlist.insertAtHead(59);
	newlist.insertAtHead(78);
	newlist.display();
	newlist.insertAtEnd(300);
	newlist.insertAtEnd(500);
	newlist.display();
	newlist.deleteAtHead();
	newlist.display();
	newlist.deleteAtEnd();
	newlist.display();
}
