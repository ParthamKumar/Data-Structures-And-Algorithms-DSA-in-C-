
#include<iostream>
using namespace std;
int partition(char arr[],int low,int high,char pivot){
	int i =low;
	char temp1,temp2;
	
	for(int j=low;j<high;j++){
		if(arr[j]<pivot){
			temp1 = arr[i];
			arr[i]=arr[j];
			arr[j]=temp1;
			i++;
		}
		else if(arr[j]==pivot){
			temp1 = arr[j];
			arr[j]=arr[high];
			arr[high]=temp1;
			j--;
		}
	}
	temp2 =arr[i];
	arr[i]=arr[high];
	arr[high]=temp2;
	
	return i;
}
void match(char nuts[], char bolts[], int low, int high){
	if(low<high){
		int pivot = partition(nuts,low,high,bolts[high]);
		
		partition(bolts,low,high,nuts[pivot]);
		
		match(nuts,bolts,low,pivot-1);
		match(nuts,bolts,pivot+1,high);
	}
}
void print(char arr[]){
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	char nuts[]={'@', '%', '$', '#', '^'};
	char bolts[] ={'%', '@', '#', '$', '^'};
	
	match(nuts,bolts,0,4);
	print(nuts);
	print(bolts);
	return 0;
}
