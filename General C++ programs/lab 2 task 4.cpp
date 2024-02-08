#include<iostream>
using namespace std;
// We will use the insertion sort as it first compare the all array then it shift the pasition
int main(){
	// Assuming the in hours hours
//	cout<<"Hello";
	
	//int time[10] = {3,5,8,1,7,6,9,2,13,4};
	int num;
	cout<<"Enter the size of array: ",cin>>num;
	int time[num];
	cout<<"Enter the array: "<<endl;
	for(int i=0;i<num;i++)
	{
		cin>>time[i];
	}
	int i,j;
	
	for(i=0;i<num;i++){
		int key = time[i];
		j=i-1;
		while(j>=0&&key<time[j]){
			time[j+1]= time[j];
			j=j-1;
		}
		time[j+1]=key;
	}
	cout<<"Sorted Array is "<<endl;
	for(i=0;i<num;i++){
		cout<<time[i]<<endl;
	}
}
