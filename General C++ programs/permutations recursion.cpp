#include<iostream>
#include<algorithm>
using namespace std;

void permutation(char arr[],int start,int end){
	if(start==end){
		for(int i=0;i<=end;++i){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}else{
		for(int i=start;i<=end;++i){
			swap(arr[start],arr[i]);
			permutation(arr,start+1,end);
			swap(arr[start],arr[i]);
		}
	}
}
int main(){
	char arr[]={'a','b','c'};
	int n = sizeof(arr)/sizeof(arr[0]);
	permutation(arr,0,n-1);
	
}
	

