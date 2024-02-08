#include<iostream>
using namespace std;
int getmax(int arr[],int n){
	int max = arr[0];
	for(int i=0;i<=n;i++){
		if(arr[i]>max){
			max = arr[i];
		}
	}
	return max;
}
void countsort(int arr[],int n, int pos){
	int output[n];
	int count[10]={0};
	//counting the occurance
	for(int i=0;i<n;i++){
		int digit =(arr[i]/pos)%10;
		count[digit]++;
	}
	// comulative freq in rev order
	for(int i=8;i>=0;i--){
		count[i]+=count[i+1];
	}
	// output array
	for(int i=n-1;i>=0;i--){
		int digit = (arr[i]/pos)%10;
		output[count[digit]-1]=arr[i];
		count[digit]--;
	}
	//copying to the orginal array
	for(int i=0;i<n;i++){
		arr[i]=output[i];
	}
}

void radixsort(int arr[],int n){
	int max = getmax(arr,n);
	for(int pos=1;(max/pos)>0;pos*=10){
		countsort(arr,n,pos);
	}
}
int main(){
	int arr[]={170,45,75,90,802,24,2,66};
	int n=sizeof(arr)/sizeof(arr[0]);
	radixsort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
