//osmn
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(NULL), rear(NULL) {}

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Dequeue operation
    int dequeue() {
        if (front == NULL) {
           
            return -1;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }

        int dequeuedValue = temp->data;
        delete temp; // Free the memory of the dequeued node

        return dequeuedValue;
    }
    bool isEmpty() const {
        return front == NULL;
    }
};

int main() {
    Queue q;

    int node;
    int i=0;// The point from where we are satarting
    int visited[7]={0,0,0,0,0,0,0};
    
    int arr[7][7]={
	{0,1,1,1,0,0,0},
	{1,0,1,0,0,0,0},
	{1,1,0,1,1,0,0},
	{1,0,1,0,1,0,0},
	{0,0,1,1,0,1,1},
	{0,0,0,0,1,0,0},
	{0,0,0,0,1,0,0},
	};
	
	cout<<i<<" ";
	visited[i]=1;
	q.enqueue(i);
	
	while(!q.isEmpty()){
		int node =q.dequeue();
		for(int j=0;j<7;j++){
			if(arr[node][j]==1&&visited[j]==0){
//				cout<<endl;
				cout<<j<<" ";
				visited[j]=1;
				q.enqueue(j);
			}
		}
	}
    

    return 0;
}

