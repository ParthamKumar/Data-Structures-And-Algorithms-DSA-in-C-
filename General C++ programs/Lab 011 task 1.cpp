
#include<iostream>
using namespace std;

const int tableSize = 10;

struct Node{
	int data;
	Node* next;
};

class HashTable{
	private:
		Node* table[tableSize];
		
		int hashFun(int key){
			return key%tableSize;
		}
	
	public:
		HashTable(){
			for(int i=0;i<tableSize;i++){
				table[i]=NULL;
			}
		}
		void insert(int key){
			int index = hashFun(key);
			Node* newNode = new Node;
			newNode->data= key;
			newNode->next= NULL;
			
			if(table[index]==NULL){
				table[index]=newNode;
			}else{
				newNode->next = table[index];
				table[index]=newNode;
			}
			
			cout<<"Data " <<key<<" inserted at "<<index<<endl;
		}
		
		void search(int key){
			int index = hashFun(key);
			Node* current = table[index];
			while(current!=NULL){
				if(current->data == key){
					cout<<"Data "<<key<<" Found at "<<index<<endl;
					return;
				}
				current=current->next;
			}
			cout<<"Element Not Present!"<<endl;
		}
		
		void deletee(int key){
			int index = hashFun(key);
			Node* current = table[index];
			Node* temp = NULL;
			
			while(current!=NULL){
				if(current->data = key){
					if(temp == NULL){
						table[index]=current->next;
					} else{
						temp->next = current->next;
					}
					delete current;
					cout<<"Data " <<key <<" Deleted from index "<<index<<endl;
					return;
				}
				temp = current;
				current = current->next;
			}
			cout<<"Data not present "<<endl;
		}
};
int main(){
	HashTable hashtable;
	hashtable.insert(20);
	hashtable.insert(34);
	hashtable.insert(45);
	hashtable.insert(70);
	hashtable.insert(56);
	
	hashtable.search(70);
	hashtable.search(56);
	
	hashtable.deletee(70);
}
