#include <iostream>
#include <cstring>
using namespace std;

class node {
public:
    char name[20];
    char art[20];
    node* next;
    node* prev;

    node(char n[], char a[]) {
        strcpy(this->name, n);
        strcpy(this->art, a);
        prev = NULL;
        next = NULL;
    }
};

class linkedlist {
public:
    node* head;
    node* tail;

    linkedlist() {
        head = NULL;
        tail = NULL;
    }

    void atHead(char n[], char a[]) {
        node* newnode = new node(n, a);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
            return;
        }
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        return;
    }

    ~linkedlist() {
        // Implement code to delete nodes and free memory if necessary
    }
};

int main() {
    linkedlist l;
    
    // Insert nodes at the beginning using atHead function
    l.atHead("Node1", "Art1");
    l.atHead("Node2", "Art2");
    l.atHead("Node3", "Art3");

    // Print the linked list
    node* temp = l.head;
    while (temp != NULL) {
        cout << "Name: " << temp->name << ", Art: " << temp->art << endl;
        temp = temp->next;
    }

    return 0;
}

