#include<iostream>
using namespace std;
int main(){
	int arr[4];
	int i ,j ,k ;
//	int n = length(a);
	int n = 4;
	int temp;
	cout<<"Enter the Array of four numbers"<<"\n";
		for(i=0;i<n;i++){
		cin>>arr[i];
	}
	
	
	for(j=0;j<n;j++){
		for(i=0;i<n-1;i++){
			if(arr[i]>arr[i+1]){
				temp = arr[i];
				arr[i]= arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
	cout<<"Sorted Array is "<<"\n";
	for(i=0;i<n;i++){
//		printf("%d ",arr[i]);
		cout<<arr[i]<<"\t";
	}
	
	
}
