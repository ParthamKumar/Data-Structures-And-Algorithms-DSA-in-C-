#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *next;
		
		node()
		{
			next=NULL;
		}
		node(int a)
		{
			data=a;
			next=NULL;
		}
};

class linkedlist
{
	public:
		node *head;
		
		linkedlist()
		{
			head=NULL;
		}
		
		void append(int data)
		{
			node* newnode = new node(data);
        	
        	if(head==NULL)
        	{
        		head=newnode;
			}
			else
			{
				node *temp=head;
	            while(temp->next != NULL)
	            {
	                temp=temp->next;
	            }
	            temp->next=newnode;
			}
		}
		
			void prepend(int data)
		{
			node* newnode = new node(data);
				node *temp;
				temp=newnode;
				temp->next=head;
				head=temp;
		}
		
		void function()
		{
			linkedlist newlist;
			node *temp=head;
			while(temp!=NULL)
			{
				int d=temp->data;
				newlist.append(d);
				temp=temp->next->next;
			}
//			linkedlist newlist2;
			temp=head;
			int even;
			while(temp!=NULL){
				even++;
				temp= temp->next->next;
			}
			temp = head;
			node* trye = head;
			while(temp!=NULL){
				//cout<<"In while"<<endl;
				for(int i=even;i>=1;i--){
				//	cout<<"In for";
				//	cout<<temp->data<<"  **";
					trye = trye->next;
				}
				cout<<trye->data<< "->";
				temp = temp->next->next;
			}
		//	newlist.display();
		}
		void display()
		{
			node *temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<"->";
				temp=temp->next;
			}			cout<<" NULL";
		}
};
main()
{
	linkedlist list;
	list.append(10);list.append(4);list.append(9);list.append(1);list.append(3);list.append(5);list.append(9);list.append(4);
	list.display();
	cout<<endl;
	list.function();
	
}

