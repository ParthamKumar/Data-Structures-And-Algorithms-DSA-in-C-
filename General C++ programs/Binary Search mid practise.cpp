//osmn
#include<iostream>
using namespace std;

//// Binary search  fun
//void search(int arr[],int n, int target){
//	int lo = 0;
//	int hi = n-1;
//	
//	// calculate the mid point
//	while(lo<hi){
//		int mid = (lo+hi)/2;
//		
//		if(arr[mid]==target){
//			cout<<"Targets position is "<<mid;
//			return ;
//		}else if(arr[mid]<target){
//			// Discard the left of the mid
//			lo = mid +1;
//		}else{
//			// Discard the right of the mid
//			hi=mid-1;
//		}
//	}
////	cout<<"Not in the list ";
//}
// recursive fun
void binarySearch(int arr[],int target, int lo, int hi){
	if(lo>hi){
		return ;
	}
	int mid = (lo+hi)/2;
	if(arr[mid]==target){
		cout<<"Tarhets position is "<<mid;
		return ;
	}
	if(target>arr[mid]){
		binarySearch(arr,target,mid+1,hi);
	}else{
		binarySearch(arr,target,lo,mid);
	}
}
int main(){
	int arr[] = {1,3,12,14,23,34,55,65,79,75,78};
	int n = sizeof(arr)/sizeof(arr[0]);
	
//	cout<<"N is "<<n;
//	search(arr,n,79);
binarySearch(arr,79,0,n-1);
	
}
