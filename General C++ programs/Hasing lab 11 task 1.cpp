#include <iostream>

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// Hash table size
const int TABLE_SIZE = 10;

// Hash table class
class HashTable {
private:
    Node* table[TABLE_SIZE];

    // Hash function
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    // Constructor
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = NULL	;
        }
    }

    // Insert element into the table
    void insertElement(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node;
        newNode->data = key;
        newNode->next = NULL;

        // If the slot is empty, insert the node
        if (table[index] == NULL) {
            table[index] = newNode;
        } else {
            // If the slot is not empty, insert at the beginning of the linked list
            newNode->next = table[index];
            table[index] = newNode;
        }

        std::cout << "Element " << key << " inserted at index " << index << std::endl;
    }

    // Search element from the key
    void searchElement(int key) {
        int index = hashFunction(key);
        Node* current = table[index];

        while (current != NULL) {
            if (current->data == key) {
                std::cout << "Element " << key << " found at index " << index << std::endl;
                return;
            }
            current = current->next;
        }

        std::cout << "Element " << key << " not found" << std::endl;
    }

    // Delete element at a key
    void deleteElement(int key) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* prev = NULL;

        while (current != NULL) {
            if (current->data == key) {
                if (prev == NULL) {
                    // If the element to be deleted is the first node in the linked list
                    table[index] = current->next;
                } else {
                    // If the element to be deleted is in the middle or end of the linked list
                    prev->next = current->next;
                }

                delete current;
                std::cout << "Element " << key << " deleted from index " << index << std::endl;
                return;
            }

            prev = current;
            current = current->next;
        }

        std::cout << "Element " << key << " not found for deletion" << std::endl;
    }
};

int main() {
    HashTable hashTable;

    // Insert elements into the hash table
    hashTable.insertElement(20);
    hashTable.insertElement(34);
    hashTable.insertElement(45);
    hashTable.insertElement(70);
    hashTable.insertElement(56);

    // Search elements in the hash table
    hashTable.searchElement(45);
    hashTable.searchElement(80);

    // Delete elements from the hash table
    hashTable.deleteElement(34);
    hashTable.deleteElement(80);

    return 0;
}

