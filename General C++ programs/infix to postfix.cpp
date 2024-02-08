
#include<iostream>
using namespace std;
class Node{
	public:
	char data;
	Node* next;
	
	Node(char d){
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
	bool isFull() {
    return this->currsize == this->capacity;
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
int priority(char ch){
    if(ch== '+' || ch =='-')
        return 1;
    if(ch == '*' || ch =='/')
        return 2;
    if(ch == '^')
        return 3;
    return 0;
}
string infix_to_postfix(string infix){
	int i=0;
	string postfix = "";
	
	Stack s(25);
	//Loop to travel the entire equation
	while(infix[i]!='\n'){
		//operands
		if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z')          
        {
            postfix += infix[i];
            i++;
        }else if(infix[i]=='('){
        	s.push(infix[i]);
        	i++;
		}////////////////////////////////////////////////////
		else if(infix[i]==')'){
            while(s.gettop()!='('){
                postfix += s.gettop();
                s.pop();
            }
            s.pop();
            i++;
        }///////////////////////////////////////////////////////
        else            
        {
            while (!s.isEmpty() && priority(infix[i]) <= priority(s.gettop())){
                postfix += s.gettop();
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
        
	}
	while(!s.isEmpty()){
        postfix += s.gettop();
        s.pop();
    }
    cout << "Final solution : " << postfix; //it will print postfix conversion  
    return postfix;
}
int main(){
	
	string infix = "((a+(b*c))-d)"; 
    string result;
    result =infix_to_postfix(infix);

}
