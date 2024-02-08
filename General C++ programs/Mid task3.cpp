#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
	node(int val){
		this->data = val;
		next =NULL;
	}
};
class linkedlist{
	public:
		node* head;
	linkedlist(){
		head =NULL;
	}
	//prepend
	void prepend(int val){
		node* newnode = new node(val);
		if(head==NULL){
			head=newnode;
		}else{
			newnode->next=head;
			head= newnode;
		}
	}
	// Append
	void append(int val){
		node* newnode = new node(val);
		
		if(head==NULL){
			head=newnode;
			return;
		}
		node* temp = head;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next=newnode;
	}
	// Display
	void display(){
		node* temp= head;
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp = temp->next;
		}
		cout<<"Null"<<endl;
	}
	void slice(linkedlist list,int from,int to){
		cout<<"In slice";
		 linkedlist newlist;
		 int pos=0;
		 node *temp = list.head;
		node* temp2 = list.head;
		linkedlist newlist2;
		while(temp!=NULL){
			
		if(pos>=from-1&&pos+1<=to){
			
			newlist2.append(temp->data);
		}
		else{
			newlist.append(temp->data);
		}
			temp=temp->next;
			pos++;
		}
		cout<<"\nDisplaying the new list"<<endl;
		newlist.display();
		cout<<"\n New list 2"<<endl;
		newlist2.display();
	}
};
int main(){
	linkedlist l;
	l.append(1);
	l.append(2);
	l.append(3);
	l.append(4);
	l.append(5);
	l.append(6);
	l.append(7);
	l.display();
	l.slice(l,3,5);
	
}
