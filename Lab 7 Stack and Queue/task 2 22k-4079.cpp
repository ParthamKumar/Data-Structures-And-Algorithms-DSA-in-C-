#include<iostream>
using namespace std;
const int MAX_SIZE = 10;
class Stack{
    int top;
    int front;
    int arr[MAX_SIZE];
public:
    Stack(){
        top = -1;
        front =0;
    }
    void enqueue(int x) {
        if (top >= MAX_SIZE - 1) {
            cout<<"queue is Full\n";
        }else{
            arr[++top]= x;
            cout<<x<< " Enqueue into queue\n";
        }
    }
    void dequeue(){
        if (front>top){
            cout<<"Queue is empty\n";
        }else{
           cout<<arr[front++]<<" Dequeued\n";
        	arr[front-1] =0;
           
        }
    }
};
int main(){
    Stack s1;
    s1.enqueue(10);
    s1.enqueue(8);
    s1.enqueue(6);
    s1.enqueue(1);
    s1.enqueue(4);
    s1.enqueue(7);
    s1.enqueue(13);
//	s1.print();
	s1.dequeue();
	s1.dequeue();
	s1.dequeue();
	
//	s1.print();
    return 0;
}
