#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* next;
	
	node(int val){
		data=val;
		next=NULL;
	}
};
class LinkedList{
	public:
	node* head;
	LinkedList(){
		head=NULL;
	}
	//Inserting the value at the head
	void insertAtHead(int val){
		node* newnode = new node(val);
		newnode->next=head;
		head=newnode;
	}
	//Inserting the value at the end
	void insertAtEnd(int val){
		node* newnode= new node(val);
		if(head==NULL){
			head = newnode;
			return;
		}
		node* temp = head;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next= newnode;
	}
	//Display
	void display(){
		node* temp = head;
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL";
	}
	//Operation
	void operation(){
		LinkedList update;
		int evcnt=0;
		int odcnt=0;
		node* temp = head;
		do{
		//	cout<<endl<<temp->data<<"->";
			if(temp->data%2 ==0){
				update.insertAtEnd(temp->data);
			//	cout<<endl<<"inserted"<<temp->data<<endl;
			}
			temp=temp->next;
		
		}while(temp!=NULL);
		//cout<<endl<<"This is second do-while"<<endl;
		temp=head;
		do{
		//	cout<<endl<<temp->data<<"->";
			if(temp->data%2 ==1){
				update.insertAtEnd(temp->data);
		//		cout<<endl<<"inserted"<<temp->data<<endl;
			}
			temp=temp->next;
		
		}while(temp!=NULL);		
		cout<<endl<<"NEW LIST IS"<<endl;
		update.display();
	
	}
};

int main(){
	 LinkedList newlist;
	 newlist.insertAtHead(6);
	 newlist.insertAtHead(7);
	 newlist.insertAtHead(1);
	 newlist.insertAtHead(4);
	 newlist.insertAtHead(5);
	 newlist.insertAtHead(10);
	 newlist.insertAtHead(12);
	 newlist.insertAtHead(8);
	 newlist.insertAtHead(15);
	 newlist.insertAtHead(17);
	 newlist.display();
	// newlist.insertAtEnd(300);
	newlist.operation();
	cout<<endl;
	LinkedList evenList;
	evenList.insertAtEnd(8);
	evenList.insertAtEnd(12);
	evenList.insertAtEnd(10);
	evenList.display();
	evenList.operation();
	LinkedList oddList;
	oddList.insertAtEnd(1);
	oddList.insertAtEnd(3);
	oddList.insertAtEnd(5);
	oddList.insertAtEnd(7);
	oddList.display();
	oddList.operation();
	
}

