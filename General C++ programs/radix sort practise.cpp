#include<iostream>
using namespace std;
int getmax(int arr[],int n){
	int max = arr[0];
	for(int i=0;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}
void countsort(int arr[],int n,int pos){
	int output[n];
	int count[10] ={0};
	
	//Counting the occurance
	for(int i=0;i<n;i++){
		int digit = (arr[i]/pos)%10;
		count[digit]=count[digit]+1;
	}
	//Commulative freq
	for(int i=1;i<10;i++){
		count[i]=count[i]+count[i-1];
	}
	//insrting values to output arr
	for(int i=n-1;i>=0;i--){
		output[count[(arr[i]/pos)%10]-1]=arr[i];
		count[(arr[i]/pos)%10]--;
	}
	
	//coping the values to the original arr
	for(int i=0;i<n;i++){
		arr[i]=output[i];
	}
}
int radixsort(int arr[],int n){
	int max = getmax(arr,n);
	for(int pos=1;(max/pos)>0;pos*=10){
		countsort(arr,n,pos);
	}
}

int main(){
	int arr[]={170,45,75,90,802,24,2,66};
	int n = sizeof(arr)/sizeof(arr[0]);
	radixsort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
