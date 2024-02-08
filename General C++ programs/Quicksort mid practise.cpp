//osmn
#include<iostream>
using namespace std;
//Partition function that will return the index
int partition(int arr[],int f,int l){
	int pivot = arr[l];
	int i =f-1; // for inseting the elements < pivot
	int j = f;
	
	for(j=f;j<l;j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	
	// now i is pointing to the last element <pivot
	// correct position of the pivot will be i+1
	swap(arr[i+1],arr[l]);
	return i+1;
}
// Quick sort recursive function
void qiicksort(int arr[],int f, int l){
	if(f>=l){
		return ;
	}
	int piv = partition(arr,f,l);
	qiicksort(arr,f,piv-1);
	qiicksort(arr,piv+1,l);
}
int main (){
	int arr[] ={20,12,35,16,18,30};
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
		}
		cout<<endl;
	qiicksort(arr,0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
		}
}

