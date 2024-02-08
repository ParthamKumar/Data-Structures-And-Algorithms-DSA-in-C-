#include<iostream>
using namespace std;
	const int n = 5;
	void printSol(int sol[n][n]){
		for (int i = 0; i < n; i++) {
       		 for (int j = 0; j < n; j++) {
      		      cout << sol[i][j] << " ";
      			  }
      		  cout << endl;
  			  }
	}
	// Safe  function
	bool isSafe(int x, int y,int maze[n][n]){
		if(x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1){
			return true;
		}
		return false;
	}
	// Recursion fun
	bool solveMaze(int maze[n][n], int x, int y, int sol[n][n]){
		// Terminating condition
		if(x==n-1&&y==n-1){
			sol[x][y]=1;
			return true;
		}
		if(isSafe(x,y,maze)){
			sol[x][y]=1;
			//Move Right
			if(solveMaze(maze,x,y+1,sol)){
				return true;
			}
			//Move down
			if(solveMaze(maze,x+1,y,sol)){
				return true;
			}
			// If neither right nor down leads to a solution, backtrack
      		  sol[x][y] = 0;
      		  return false;
		}
		return false;
	}
int main(){
	int maze[n][n]={
					{1, 0, 0, 0, 0},
   				    {1, 1, 0, 1, 0},
        			{0, 1, 1, 1, 0},
        			{0, 0, 0, 1, 0},
        			{0, 0, 0, 1, 1}
					};
				
	int sol[n][n]={0};
	
	    if (solveMaze(maze, 0, 0, sol)) {
       		 cout << "Solution path:" << endl;
       		 printSol(sol);
 	   } else {
      		  cout << "No solution exists!" << endl;
   			 }

    return 0;
	
}
