#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
		node* prev;
	node(int val){
		this->data = val;
		next = NULL;
		prev=NULL;
	}
};
class cirLinkedList{
	public:
		node* head;
		node* tail;
	cirLinkedList(){
		head = NULL;
		tail = NULL;
	}
	// Adding the node at the end
	void insertAtEnd(int val){
		node* newnode = new node(val);
		if(head==NULL){
			newnode->next= newnode;
			newnode->prev = newnode;
			head = newnode;
		}else{
			newnode->next = head;
			newnode->prev = head->prev;
			newnode->prev->next = newnode;
			head->prev=newnode;
		}
	}
	// Inserting the node at the head
	void insertAtHead(int val){
		node* newnode = new node(val);
		if(head ==NULL){
			newnode->next = newnode;
			newnode->prev = newnode;
		}else{
			newnode->next = head;
			newnode->prev = head->prev;
			head->prev->next = newnode;
			head->prev= newnode;
		}
		head = newnode;
	}
	// Inserting the node at the Given pos
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
	//Deleting the node at the end
	void deleteAtEnd(){
		if(head->next==head){
			delete head;
			return;
		}else{
			node* temp = head->prev;
            temp->prev->next = head;
            head->prev = temp->prev;
            delete temp;
		}
	}
	// display function
	void display(){
		if(head==NULL){
			cout<<"List is Empty"<<endl;
			return;
		}
		node* temp = head;
		do{
			cout<<temp->data<<"->";
			temp=temp->next;
		}while(temp!=head);
		cout<<"Null"<<endl;
	}
	
};

int main(){
	cirLinkedList list1;
	list1.insertAtHead(1);
	list1.insertAtHead(2);
	list1.insertAtHead(3);
	list1.insertAtHead(4);
	list1.display();
	cout<<endl<<"\nInserting the newnode at the end of the list"<<endl;
	list1.insertAtEnd(5);
	list1.insertAtEnd(6);
	list1.insertAtEnd(7);
	list1.insertAtEnd(8);
	list1.display();
	cout<<endl<<"\nInserting the node at the pos 5 val = 99"<<endl;
	list1.insertAtPos(5,99);
	list1.display();
	cout<<endl<<"\nDeleting the node at the end"<<endl;
	list1.deleteAtEnd();
	list1.display();
}
