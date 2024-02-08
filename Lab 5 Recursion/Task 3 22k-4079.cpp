#include<iostream>
using namespace std;
void Print(int arr[],int n)
{
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}
void NormalSorting(int i,int j,int n,int arr[]){
	if(i!=n){
		if(arr[i]<arr[j])
	{
		swap(arr[i],arr[j]);
	}
		if(j==n)
		NormalSorting(i+1,0,n,arr);
		else
		NormalSorting(i,j+1,n,arr);
	}
	else{
		Print(arr,n);
		return;	
	}	
}

void TailSorting(int i,int j,int n,int arr1[]){
if(i==n){
		Print(arr1,n);
		return;
	}
	
	if(arr1[i]<arr1[j]){
		swap(arr1[i],arr1[j]);
	}
		if(j==n)
		NormalSorting(i+1,0,n,arr1);
		else
		NormalSorting(i,j+1,n,arr1);
}

main()
{
	int arr[5]={11,13,5,6,7};
	NormalSorting(0,0,sizeof(arr)/4,arr);
	
	cout<<endl;
	
	int arr1[5]={11,13,5,9,7};
	TailSorting(0,0,sizeof(arr1)/4,arr1);
}

