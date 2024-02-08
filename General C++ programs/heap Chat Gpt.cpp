#include <iostream>

class MinHeap {
private:
    static const int MAX_SIZE = 100;
    int heap[MAX_SIZE];
    int size;

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[parentIndex] > heap[index]) {
                std::swap(heap[parentIndex], heap[index]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < size && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }

        if (rightChild < size && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap() : size(0) {}

    void insert(int value) {
        if (size == MAX_SIZE) {
            std::cerr << "Heap is full." << std::endl;
            return;
        }

        heap[size] = value;
        size++;
        heapifyUp(size - 1);
    }

    int extractMin() {
        if (size == 0) {
            std::cerr << "Heap is empty." << std::endl;
            return -1;  // Assuming -1 as an indicator of an error or an empty heap
        }

        int minValue = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);

        return minValue;
    }

    void printHeap() {
        for (int i = 0; i < size; ++i) {
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MinHeap minHeap;

    minHeap.insert(3);
    minHeap.insert(1);
    minHeap.insert(4);
    minHeap.insert(1);
    minHeap.insert(5);

    minHeap.printHeap();

    std::cout << "Min value: " << minHeap.extractMin() << std::endl;

    minHeap.printHeap();

    return 0;
}

