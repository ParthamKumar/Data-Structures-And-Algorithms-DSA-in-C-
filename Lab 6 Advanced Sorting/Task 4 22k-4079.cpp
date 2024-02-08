#include<iostream>
using namespace std;
void binarysearch(int arr[],int n,int target){
	int lo =0;
	int hi= n-1;
	
	while(lo<=hi){
		// calculating the mid point
		int mid =(lo+hi)/2;
		if(arr[mid]==target){
			cout<<"Position is "<<mid;
			return ;
		}else if(arr[mid]<target){
			// discarding the left of mid
			lo = mid+1;
		}else if(arr[mid]>target){
			// discarding the right of mid
			hi = mid-1;
		}
	}
	cout<<"Not in the list";
}

int main(){
	int arr[]={1,3,12,14,23,34,55,65,79,75,78};
	int n = sizeof(arr)/sizeof(arr[0]);
	binarysearch(arr,n,79);
}

