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
    //Palindrome 
void isPalindrome() {
    node* temp = head;
    int c = 0;
    do {
        c++;
        temp = temp->next;
    } while (temp != NULL);
//    cout << c;

    temp = head;
    node* check = head;
    if (c % 2 == 1) {
        int t = (c / 2) + 1;
//        cout << endl << "t= " << t;
//        cout << endl << " c is " << c;
        int counter=0;
        int k = 0;
        do {
            check = head;
            for (int i = 0; i < c - 1 - k; i++) {
                check = check->next;
            }
            if (temp->data == check->data) {
//                cout << endl << "Passed";
                counter++;
            }
//            cout << endl << "check data is " << check->data << endl;
//            cout << endl << "temp data is " << temp->data << endl;
            temp = temp->next;
            k++;
           // cout << endl << "t is " << t << "k is " << k;
        } while (t != k);
    if(counter==t){
    	cout<<"Palindrome";
	}else{
		cout<<"Not Palindrome";
	}
    }else{
        int t = (c / 2) + 1;
//        cout << endl << "t= " << t;
//        cout << endl << " c is " << c;
        int counter=0;
        int k = 0;
        do {
            check = head;
            for (int i = 0; i < c - 1 - k; i++) {
                check = check->next;
            }
            if (temp->data == check->data) {
//                cout << endl << "Passed";
                counter++;
            }
//            cout << endl << "check data is " << check->data << endl;
//            cout << endl << "temp data is " << temp->data << endl;
            temp = temp->next;
            k++;
           // cout << endl << "t is " << t << "k is " << k;
        } while (t != k);
    if(counter==t){
    	cout<<"Palindrome";
	}else{
		cout<<"Not Palindrome";
	}
	}
}

};
int main(){
	LinkedList newlist;
	newlist.insertAtTail(1);
	newlist.insertAtTail(0);
	newlist.insertAtTail(2);
	newlist.insertAtTail(0);
	newlist.insertAtTail(1);
	newlist.display();
	newlist.isPalindrome();
}
