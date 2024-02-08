#include<iostream>
#include<algorithm>
using namespace std;
// partition function
int partition(int arr[],int first, int last){
	int mid =(first+last)/2;
	swap(arr[mid],arr[last]);
	
	int pivot=arr[last];
	int i = first-1;
	int j = first;
	
	for(j=first;j<last;j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[last]);
	return i+1;
}
//Quick sort function
void quicksort(int arr[],int first, int last){
	if(first>=last){
		return;
	}
	// partition function
	int pi = partition(arr,first,last);
	quicksort(arr,first,pi-1);
	quicksort(arr,pi+1,last);
}
int main(){
	int arr[]={5,6,2,-2,6,10,12,15};
	int n = sizeof(arr)/sizeof(arr[0]);
//	cout<<n;
	
	quicksort(arr,0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}

