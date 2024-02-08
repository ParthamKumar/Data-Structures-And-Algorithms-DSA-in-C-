#include<iostream>
using namespace std;
int main(){
//	int arr[]={5,4,3,2,1};
	
//	// insertion sort
//	for(int i=1;i<4;i++){
//		int key=arr[i];
//		int j= i-1;
//		while(key<arr[j]<< j>0){
//			arr[j+1]=arr[j];
//			j=j-1;
//		}
//		arr[j+1]=key;
//	}

// SELECTION SORT
    int arr2[]={5,4,3,2,1};
    int n=5;
	int i,j,min;
	for(i=0;i<n-1;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(arr2[j]<arr2[min]){
				min = j;
			}
		}
		if(min!=1){
			swap(arr2[min],arr2[i]);
		}
	}
	//printing
	for(int i=0;i<5;i++){
		cout<<arr2[i]<<" ";
	}
	
}
