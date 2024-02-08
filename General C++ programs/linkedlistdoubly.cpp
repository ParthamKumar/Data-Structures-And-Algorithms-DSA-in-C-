#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* prev;
		node* next;
		
	node(int val){
		this->data = val;
		prev = NULL;
		next= NULL;
	}
};
class doublyLinkedList{
	public:
		node* head;
		node* tail;
		
	doublyLinkedList(){
		head= NULL;
		tail = NULL;
	}
	//Inserting at the head
	void insertAtHead(int val){
		node* newnode = new node(val);
		if(head==NULL){
			head= newnode;
			tail = newnode;
			return;
		}
		newnode->next =head;
		head->prev = newnode;
		head = newnode;
		return;
	}
	//Inserting at the Tail
	void insertAtTail(int val){
		node* newnode = new node(val);
		if(tail==NULL){
			head = newnode;
			tail = newnode;
			return;
		}
		tail->next = newnode;
		newnode->prev = tail;
		tail = newnode;
		return;
	}
	//Inserting at the given position
	void insertAtPos(int pos, int val){
		node* temp = head;
		int count =1;
		while(count<(pos-1)){
			temp= temp->next;
			count ++;
		}
		node* newnode = new node(val);
		newnode->next=temp->next;
		temp->next= newnode;
		newnode->prev=temp;
		newnode->prev->next = newnode;
	}
	//Deleting at the start
	void deleteAtStart(){
		
		if(head==NULL){
			return;
		}
		node* temp = head;
		head = head->next;
		if(head==NULL){
			tail =NULL;
		}else{
			head->prev=NULL;
		}
		delete(temp);
		return;
	}
	//Deleting at the end
	void deleteAtEnd(){
		if(head==NULL){
			return;
		}
		node* temp = tail;
		tail = tail->prev;
		if(tail==NULL){
			head=NULL;
		}else{
			tail->next=NULL;
		}
		delete(temp);
		return;
	}
	//Deleting At the pos
	void deleteAtPos(int pos){
		node* temp = head;
		int count=1;
		while(count<pos){
			temp = temp->next;
			count++;
		}
		// now we are at the pos of node that is going to be deleted
		temp->prev->next=temp->next;
		temp->next->prev= temp->prev;
		delete(temp);
	}
	//Display
	void display(){
		node* temp = head;
		while(temp!=NULL){
			cout<<temp->data<<"<->";
			temp = temp->next;
		}
		cout<<"NULL"<<endl;
	}
};

main()
{
	cout<<"It's PK Chawla"<<endl;
	doublyLinkedList newlist;
	newlist.insertAtHead(5);
	newlist.insertAtHead(10);
	newlist.insertAtHead(15);
	newlist.display();
	newlist.insertAtTail(55);
	newlist.insertAtTail(60);
	newlist.display();
	newlist.insertAtPos(3,700);
	newlist.display();
	cout<<"Deleting at the start"<<endl;
	newlist.deleteAtStart();
	newlist.display();
	newlist.deleteAtEnd();
	newlist.display();
	cout<<"Deleting at the pos"<<endl;
	newlist.deleteAtPos(2);
	newlist.display();
	
	
}
