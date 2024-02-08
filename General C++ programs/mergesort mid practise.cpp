//osmn
#include<iostream>
using namespace std;

//merge fun
void merge(int arr[], int l, int mid, int r){
	
	// creating the two temp arrays that will hold the left and right arrays
	
	int an = mid -l +1; // size of right array
	int bn = r-mid;     // size of left array
	
	int a[an];
	int b [bn];
	
	//filling the elemnts for left array
	for(int i =0 ;i<an; i++){
		a[i] = arr[l+i];
	}	
	
	//filling the elemnts for right array
	for(int i =0 ;i<bn; i++){
		b[i] = arr[mid+1+i];
	}
	
	int i=0;
	int j=0;
	int k=; //0
	
	// now comparing the elemnts and making the sorted array
	
	while (i < an && j < bn) {
    if (a[i] < b[j]) {
        arr[k++] = a[i++];
    } else {
        arr[k++] = b[j++];
    }
}
	
	// if already sorted
	
	while(i<an){
		arr[k++]=a[i++];
	}
	while(j<bn){
		arr[k++]=b[j++];
	}
//	cout<<"passed ";
}
//Merge sort recursive function
void mergesort(int arr[],int l , int r){
	// base case
	if(l>=r){
	//	cout<<"passed ";
		return ;
	}
	
	//Dividing the array to mid
	int mid = (l+r)/2;
	mergesort(arr,l,mid); //Dividing the whole left part of the array
	mergesort(arr,mid+1,r);// Dividing the whole right of the array
	merge(arr,l,mid,r); // fun that will sort and make the sorted array
}

int main(){
	int arr[] ={10,28,24,6,34,18,38,44};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	mergesort(arr,0,n-1);
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

