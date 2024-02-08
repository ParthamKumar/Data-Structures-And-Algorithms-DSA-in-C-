#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		node* prev;
		
		node()
		{
			next=NULL;
		}
		node(int a)
		{
			data=a;
			next=NULL;
			prev=NULL;
		}
};

class linkedlist{
	public:
		node* head;
	
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
        		head->next=head;
			}
			else
			{
				node *temp=head;
				do
	            {
	                temp=temp->next;
	            }while(temp->next!=head);
	            temp->next=newnode;
	            newnode->prev=temp;
	            newnode->next=head;
	            head->prev=newnode;
			}
		}
		void swap(int a,int b)
		{
			node *temp=head;
			int count=0;
			while(count!=a-1)
			{
				count++;
				temp=temp->next;
			}
			node *n1=temp;
			temp=head;
			count=0;
			while(count!=b-1)
			{
				count++;
				temp=temp->next;
			}
			node *n2=temp;

			temp=n1->next;
		    n1->next=n2->next;
		    n2->next=temp;
		
		    temp=n1->prev;
		    n1->prev=n2->prev;
		    n2->prev=temp;
		
		    n1->next->prev=n1;
		    n2->next->prev=n2;
		    n1->prev->next=n1;
		    n2->prev->next=n2;
		}
		
		void display()
		{
			node *temp=head;
			do
	    	{
	    		cout<<temp->data<<" ";
	           	temp=temp->next;
			}while(temp!=head);
		}
};


main()
{
	linkedlist list;
	cout<<"Appending to list:\n";
	list.append(1);
	list.append(7);
	list.append(4);
	list.append(2);
	list.append(6);
	list.append(4);
	list.append(5);
	list.append(3);
	list.append(9);
	list.append(8);
	list.display();
	
	int a,b;
	cout<<"\nEnter the Positions of list: ",cin>>a>>b;
	list.swap(a,b);
	list.display();
}

