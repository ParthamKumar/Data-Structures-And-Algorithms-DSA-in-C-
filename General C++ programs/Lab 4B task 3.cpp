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
	// Appending function
	void append(int data)
	{
	node* newnode = new node(data);
   	if(head==NULL)
    	{
    		head=newnode;
    		head->next=NULL;
    		head->prev=NULL;
		}
		else
		{
			node *temp=head;
			while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
            tail=newnode;
		}
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
		return;}
	// Display function
	void display(){
		node* temp = head;
		while(temp!=NULL){
			cout<<temp->data<<"<->";
			temp = temp->next;
		}
		cout<<"NULL"<<endl;
	}
	// Concating fun
		void concatenate(doublyLinkedList l,doublyLinkedList m)
		{
			node *temp=l.head;
			while(temp!=NULL)
			{
				int d=temp->data;
				this->append(d);
				temp=temp->next;
			}
			temp=m.head;
			while(temp!=NULL)
			{
				int d=temp->data;
				this->append(d);
				temp=temp->next;
			}
		}	
	
};
int main(){
	doublyLinkedList L;
	L.insertAtHead(1);
	L.insertAtHead(2);
	L.insertAtHead(3);
	L.insertAtHead(4);
	L.display();
	doublyLinkedList M;
	M.insertAtHead(5);
	M.insertAtHead(6);
	M.insertAtHead(7);
	M.insertAtHead(8);
	M.display();
	doublyLinkedList newlist;
	newlist.concatenate(L,M);
	newlist.display();
}
