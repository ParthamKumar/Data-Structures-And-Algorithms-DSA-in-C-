#include<iostream>
using namespace std;
	const int rows=3,col=4;
	void print(int sol[rows][col]){
		for(int i=0;i<rows;i++)
		{
       		 for (int j=0;j<col;j++)
      		      cout<<sol[i][j]<<" ";	  
		cout<<endl;
		}
	}
	bool valid(int x,int y,int maze[rows][col]){
		if(x>=0&&x<rows&&y>=0&&y<col&&maze[x][y]==1)
		return true;
		else
		return false;
	}
bool findpath(int path[rows][col], int x, int y, int sol[rows][col]){
			if(x==0&&y==3)
			{
			sol[x][y]=1;
			return true;
			}
		if(valid(x,y,path)){
			sol[x][y]=1;
			if(findpath(path,x,y+1,sol))
				return true;
			if(findpath(path,x+1,y,sol))
				return true;
			 sol[x][y] = 0;
			 return false;
		}
		return false;
	}
int main(){
	int path[3][4]={
					{1,0,0,1},
   				    {0,1,1,1},
        			{0,1,1,0}};
				
	int s[3][4]={0};
	    if(findpath(path,0,0,s)){
       		cout << "Output path:" << endl;
       		print(s);
 	   	}
		else
      		cout<<"Output Not found"<<endl;
}
