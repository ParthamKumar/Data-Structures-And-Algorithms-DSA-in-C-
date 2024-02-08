
#include<iostream>
using namespace std;
int solve(int arr[],int n){
	
	for(int i=0;i<n;i++){
		int l = i+1;
		int r = n-1;
		while(l<r){
			int sum = arr[i]+arr[l]+arr[r];
			if(sum ==0){
				return 1;
			}else if (sum>0){
				r--;
			}else{
				l++;
			}
		}
		return 0;
	}
}
	
int main(){
    int arr[] = {0, -1, 2, -3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int result = solve(arr,size);
    cout<<result;
    return 0;
}
