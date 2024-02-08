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
	//Adding the node at the start
	void insertAtHead(int val){
		node* newnode = new node(val);
		newnode->next=head;
		head= newnode;
	}
	//Display
	void display(){
		node* temp = head;
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp= temp->next;
		}
		cout<<"NULL";
	}
	//Deleting From end;
	void del(){
		node* second_last= head;
		while(second_last->next->next!=NULL){
			second_last= second_last->next;
		}
		node* temp = second_last->next;
		second_last->next=NULL;
		temp=NULL;
	}
	void delAtPos(int pos){
		int currpos =0;
		node* prev = head;
		while(currpos!=pos-2){
			prev=prev->next;
			currpos++;
		}
		node* temp = prev->next;
		prev->next= prev->next->next;
		temp=NULL;
	}
};
int main(){
	LinkedList newlist;
	newlist.insertAtHead(7);
	newlist.insertAtHead(897);
	newlist.insertAtHead(667);
	newlist.insertAtHead(10);
	newlist.insertAtHead(15);
	newlist.insertAtHead(18);
	newlist.insertAtHead(1300);
	newlist.insertAtHead(177);
	newlist.display();
	cout<<endl<<"Deleting from the end"<<endl; 
	newlist.del();
	newlist.display();
	cout<<endl<<"Deleting from the position"<<endl;
	newlist.delAtPos(2);
	newlist.display();
}
