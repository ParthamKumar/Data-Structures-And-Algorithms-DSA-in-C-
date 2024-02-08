#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		
		Node(int v){
			this->data=v;
			this->next=NULL;
		}
};
class Graph{
	private:
		int V;
		Node** adjList;
	
	public:
		Graph(int vertices){
			this->V = vertices;
			
			adjList = new Node*[V];
			for(int i=0;i<V;++i){
				adjList[i]=NULL;
			}
		}
		
		void addEdge(int u,int v){
			Node* newNode = new Node(v);
    	    newNode->next = adjList[u];
     	    adjList[u] = newNode;
     	    
     	    newNode = new Node(u);
      		newNode->next = adjList[v];
      		adjList[v] = newNode;
		
		}
		void printAdjList(){
			for(int i=0;i<V;++i){
				cout<<i<<" ";
				Node* current = adjList[i];
				while(current!=NULL){
					cout<<current->data<<" ";
					current=current->next;
				}
				cout<<endl;
			}
		}
};
int main(){
	int V = 5;
	int E =7;
	
	int edges[][2]={{0,1}, {0,4}, {4,1}, {4,3}, {1,3}, {1,2}, {3,2}};
	
	Graph graph(V);
	
	for(int i=0;i<V;++i){
		graph.addEdge(edges[i][0],edges[i][1]);
	}
	cout<<endl;
	graph.printAdjList();
}
