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
	// Adding the node at the end of the list
    void insertAtEnd(int val){
    	node* newnode = new node(val);
    	  if (head == NULL) {
            head = newnode;
            return;
        }
        
    	node* temp = head;
    	while(temp->next!=NULL){
    		temp = temp->next;
		}
		temp->next = newnode;
	}
	// Display fun
    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    //Updating the list
    void update(int pv, int nv){
    	node* temp = head;
    	while(temp->data!=pv){
    		temp= temp->next;
		}
		temp->data=nv;
    	
	}
    
};
int main(){
	LinkedList newlist;
	newlist.insertAtEnd(4);
	newlist.insertAtEnd(1);
	newlist.insertAtEnd(5);
	newlist.insertAtEnd(7);
	newlist.insertAtEnd(2);
	newlist.display();
	cout<<endl<<"Updated value is "<<endl;
	newlist.update(5,6);
	newlist.display();
}
