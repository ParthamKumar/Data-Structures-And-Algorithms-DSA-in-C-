#include<iostream>
using namespace std;
main()
{
	int arr[10];
	//int arr[10] = {5,1,3,6,2,9,7,4,8,10};
	for(int i=0;i<10;i++)
	{
		cout<<"Enter the value: ",cin>>arr[i];
	}
	int temp;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(arr[i]<arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	for(int i=0;i<10;i++)
	{
		cout<<arr[i]<<" ";
	}
}
