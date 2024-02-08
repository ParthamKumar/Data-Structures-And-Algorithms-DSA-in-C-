#include<iostream>
using namespace std;
	const int n=4;
	void Print(int sol[n][n]){
		for(int i=0;i<n;i++) {
       		for(int j=0;j<n;j++){
      			cout<<sol[i][j]<<" ";
      		}
      		cout<<endl;
  		}
	}
	
bool isSafe(int x,int y,int maze[n][n]){
		if(x>=0&&x<n&&y>=0&&y<n&&maze[x][y]==1)
			return true;
		else
		return false;
	}

bool solveMaze(int maze[n][n],int x,int y,int sol[n][n]){
		if(x==n-1&&y==n-1){
			sol[x][y]=1;
			return true;
		}
		if(isSafe(x,y,maze)){
			sol[x][y]=1;
			if(solveMaze(maze,x,y+1,sol))
				return true;
			if(solveMaze(maze,x+1,y,sol))
				return true;
			
			sol[x][y] = 0;
      		return false;
		}
		return false;
	}

main(){
	int maze[n][n]={{1,0,0,0},
   				    {1,1,0,1},
        			{0,1,0,0},
        			{1,1,1,1}};
	int sol[n][n]={0};
	
	    if (solveMaze(maze,0,0,sol))
		{
       		cout<<"Final Path:"<<endl;
       		Print(sol);
 	   	}
		else
      		cout<<"No Path Found"<<endl;
}

