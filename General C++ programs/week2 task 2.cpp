#include<iostream>
using namespace std;

int main(){
	int a[][3] ={{3,2,5},
				{6,4,1},
				{9,8,7}};
	
	//sorting algo for 2d array
	
	//column
	for(int k=0;k<3;k++)
	{
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(a[i][j]>a[i+1][j])
				{
					swap(a[i][j],a[i+1][j]);
				}
			}
		}
	}
	//rows
	for(int k=0;k<3;k++)
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<2;j++)
			{
				if(a[i][j]>a[i][j+1])
				{
					swap(a[i][j],a[i][j+1]);
				}
			}
		}
	}
	
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
