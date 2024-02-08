#include<iostream>
using namespace std;
class node{
	public:	
		int data;
		node* next;
		
		node(int val){
		data = val;
		next = NULL;
		}
};
class LinkedList{
	public:
	node* head;
	LinkedList(){
		head=NULL;
	}
	// Inserting the value at the start of the Linked list
    void insertAtHead(int val) {
        node* newnode = new node(val);
        newnode->next = head;
        head = newnode;
    }
    // Displaying the linked List
    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
	LinkedList newlist;
	newlist.insertAtHead(4);
	newlist.insertAtHead(9);
	newlist.insertAtHead(5);
	newlist.insertAtHead(3);
	newlist.insertAtHead(1);
	newlist.insertAtHead(9);
	newlist.insertAtHead(4);
	newlist.insertAtHead(10);
	newlist.display();
}
