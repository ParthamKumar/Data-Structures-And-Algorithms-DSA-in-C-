#include<iostream>
using namespace std;
int solve(int arr[],int n,int sum){
	int i =0 ;
	int j=n-1;
	int k =0;
	int count =0;
	
	while(i<j){
		k=arr[i]+arr[j];
		if(k==sum){
			count++;
			i++;
			j--;
		}else if(k>sum){
			j--;
		}else {
			i++;
		}
	}
	cout<<"Total pairs are "<<count<<endl;
}
int main() {
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    solve(arr,size,8);
  //  cout<<size;
    return 0;
}

