#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
int smallest = i;
int left_child = 2 * i + 1;
int right_child = 2 * i + 2;

if (left_child < n && arr[left_child] < arr[smallest])
smallest = left_child;
if (right_child < n && arr[right_child] < arr[smallest])
smallest = right_child;

if (smallest != i) {
swap(arr[i], arr[smallest]);
heapify(arr, n, smallest);
}
}

void buildMinHeap(int arr[], int n)
{
int startIdx = (n / 2) - 1;

for (int i = startIdx; i >= 0; i--)
heapify(arr, n, i);
}

void buildMaxHeap(int arr[], int n)
{
int startIdx = (n / 2) - 1;

for (int i = startIdx; i >= 0; i--)
{
int largest = i;
int left_child = 2*i + 1;
int right_child = 2*i + 2;

if (left_child < n && arr[left_child] > arr[largest])
largest = left_child;
if (right_child < n && arr[right_child] > arr[largest])
largest = right_child;

if (largest != i)
swap(arr[i], arr[largest]);
}
}

void printHeap(int arr[], int n)
{
for (int i = 0; i < n; ++i)
cout << arr[i] << " ";
cout << "\n";
}

int main()
{
int arr[] = {7,1,6,2,5,9,10,2};
int n = sizeof(arr) / sizeof(arr[0]);

buildMinHeap(arr, n);
cout << "Min Heap: " << endl;
printHeap(arr, n);


buildMaxHeap(arr, n);
cout << "Max Heap: " << endl;
printHeap(arr, n);
return 0;
}
