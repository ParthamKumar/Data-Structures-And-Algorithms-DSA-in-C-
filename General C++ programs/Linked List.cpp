#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    node* head;

    LinkedList() {
        head = NULL;
    }

    // Inserting the value at the start of the Linked list
    void insertAtHead(int val) {
        node* newnode = new node(val);
        newnode->next = head;
        head = newnode;
    }
    // Inserting the value at the end of List
    void insertAtTail(int val){
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

    // Displaying the linked List
    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    //Insert at the position
    void insertAtpos(int pos, int data){
    	if(pos == 0){
    		insertAtHead(data);
    		return;
		}
		node* newnode = new node(data);
		node* temp = head;
		int currpos =0;
		//if i change the pos to pos-2 it will place the value at given position
		while(currpos!= pos-1){
			temp = temp->next;
			currpos++;
		}
		// now the temp is pointing to the node at positon n-1
		newnode->next=temp->next;
		temp->next = newnode;
	}
	
	//Updating the value at the given position
	void updateAtPos(int pos,int val){
		node* temp = head;
		int currpos=0;
		while(currpos!=pos-1){
			temp=temp->next;
			currpos++;
		}
		//Temp will be pointing to the pos val
		temp->data = val;
	}
	// Deleting at the Head
	void deleteAtHead(){
		node* temp = head;
		head= head->next;
		temp==NULL;
	}
	//Deleting at the Tail
	void deleteAtEnd(){
		cout<<"I am in";
		node* second_last=head;
		while(second_last->next->next!=NULL){
			second_last= second_last->next;
		}
		node *temp = second_last->next;
		second_last->next=NULL;
		temp =NULL;
		cout<<"I am OUT"<<endl;
	}
	//Deleting at the given position
	void deleteAtPos(int pos){
		if(pos==0){
			deleteAtHead();
			return;
		}
		int currpos=0;
		node* prev=head;
		while(currpos!=pos-2){
			prev=prev->next;
			currpos++;
		}
		//Now prev is pointing to the node at pos
		node* temp = prev->next;
		prev->next=prev->next->next;
		temp==NULL;
	}
};

int main() {
//    LinkedList mylist;
	 LinkedList myList;
    myList.insertAtHead(5);
    myList.insertAtHead(6);
    myList.insertAtHead(9);
    myList.display();
//    mylist.insertAtTail(1);
//    mylist.insertAtTail(2);
//    mylist.insertAtTail(3);
//    mylist.insertAtTail(8);
//    mylist.display();
//    mylist.insertAtpos(2,55);
//    mylist.display();
//    mylist.updateAtPos(2,60);
//    mylist.display();
//    mylist.deleteAtHead();
//    mylist.display();
//    mylist.deleteAtEnd();
//	mylist.display();
//   	mylist.deleteAtPos(2);
//   	mylist.display();
}

