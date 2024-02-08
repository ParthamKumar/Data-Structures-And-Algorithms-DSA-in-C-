#include<iostream>
using namespace std;
void binarysearch(int arr[],int n,int target){
	int lo =0;
	int hi= n-1;
	
	while(lo<=hi){
		// calculating position
       int mid=lo+((hi-lo)/(arr[hi]-arr[lo]))*(target-arr[lo]);
			
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
	int arr[]={1,3,7,10,14,15,16,18,20,21,22,23,25,33,35,42,45,47,50,52};
	int n = sizeof(arr)/sizeof(arr[0]);
	binarysearch(arr,n,33);
}
