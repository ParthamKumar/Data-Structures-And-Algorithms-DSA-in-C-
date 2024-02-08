#include<iostream>
using namespace std;
class Stack {
	int capacity;
	char* arr;
	int top;
	public:
		Stack(int c){
			this->capacity =c;
			this->arr = new char[c];
			this->top =-1;
		}
		
	bool isEmpty(){
		return this->top==-1;
	}
	bool isFull(){
		return this->top == this->capacity-1;
	}
	void push(char data ){
		if(isFull()){
			cout<<"OverFlow";
			return;
		}
		this->top++;
		this->arr[this->top] = data;
	}
	void pop(){
		if(isEmpty()){
			cout<<"UnderFlow";
			return ;
		}
		this->top--;
	}
	char gettop(){
		if(isEmpty()){
			cout<<"UnderFlow";
			return ' ';
		}
		return this->arr[this->top];
	}
	int getsize(){
		return this->top+1;
	}
	void print(){
		if(isEmpty()){
			cout<<"UnderFlow";
			return ;
		}
		for(int i=0;i<(getsize());i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	void ispalindrome(Stack s){
		Stack temp(s.capacity);
		temp=s;
		Stack s2(s.capacity);
		bool check;
		int size = s.getsize();
		for(int i=0;i<size;i++){
			s2.push(s.gettop());
			s.pop();
		}
		for(int i=0;i<size;i++)
		{
			if(s2.gettop()==temp.gettop())
			{
				s2.pop();
				temp.pop();
				check=true;
			}
			else
			{
				check=false;
				break;
			}
		}
		
		if(check)
		{
			cout<<"This is palindrome\n";
		}else{
			cout<<"This is Not palindrome";
		}
	}
};
int main(){
	Stack s1(9);
	s1.push('B');
	s1.push('O');
	s1.push('R');
	s1.push('R');
	s1.push('O');
	s1.push('W');
	s1.push('R');
	s1.push('0');
	s1.push('B');
	

	s1.print();
	s1.ispalindrome(s1);
}
