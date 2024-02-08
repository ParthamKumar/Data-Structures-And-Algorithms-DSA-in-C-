#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i);
void max_heapify(int arr[],int n,int i);

int arr[]={35,33,42,10,14,19,27,44,26,31};
int n=sizeof(arr)/sizeof(arr[0]);

int main(){
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);

    int root=arr[0];
    arr[0]=arr[n-1];
    n--;

    heapify(arr,n,0);
    for(int i=n/2-1;i>=0;i--)
        max_heapify(arr,n,i);

    while(n>0){
        int root=arr[0];
        cout<<root<<" ";
        arr[0]=arr[n-1];
        n--;
        max_heapify(arr,n,0);
    }

    return 0;
}

void heapify(int arr[],int n,int i){
    int smallest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n&&arr[l]<arr[smallest])
        smallest=l;

    if(r<n&&arr[r]<arr[smallest])
        smallest=r;

    if(smallest!=i){
        swap(arr[i],arr[smallest]);
        heapify(arr,n,smallest);
    }
}

void max_heapify(int arr[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n&&arr[l]>arr[largest])
        largest=l;
    if(r<n&&arr[r]>arr[largest])
        largest=r;
    if (largest!=i){
        swap(arr[i],arr[largest]);
        max_heapify(arr,n,largest);
    }
}
