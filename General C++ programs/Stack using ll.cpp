//osmn
#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	
	Node(int d){
		this->data=d;
		this->next=NULL;
	}
};
class Stack{
	Node* head;
	int capacity;
	int currsize;
	
	public:
	Stack(int c){
		this->capacity=c;
		this->currsize =0;
		head=NULL;
	}
	bool isEmpty(){
		return this->head==NULL;
	}
	bool isFull(){
		return this->currsize==this->capacity;
	}
	//Push ()
	void push(int d){
		if(isFull()){
			cout<<"Stack Overflow \n";
			return ;
		}
		Node* newnode = new Node(d);
		newnode->next =head;
		head=newnode;
		this->currsize++;
	}
	//Size ()
	int size(){
		return this->currsize;
	}
	int pop(){
		if(isEmpty()){
			cout<<" Stack Underflow /n";
			return 0;
		}
		//////////////////////////////////////////////////////////
		Node* newhead = head->next;
		head->next=NULL;
		/////////////////////////////////////////////////////////	
		Node* toberemoved = head;
		int result = toberemoved->data;
		delete(toberemoved);
		
		head = newhead;
		return result;
	}
	// peek
	int gettop(){
		if(isEmpty()){
			cout<<" Stack Underflow /n";
			return 0;
		}
		return this->head->data;
	}
};
int main(){
	Stack s1(5);
	s1.push(5);
	s1.push(15);
	s1.push(10);
	s1.pop();
	
	int g = s1.gettop();
	cout<<g;
}
