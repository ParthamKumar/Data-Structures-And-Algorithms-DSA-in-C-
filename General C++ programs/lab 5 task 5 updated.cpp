#include<iostream>
using namespace std;
void print(int maze[][4],int sol[][4]){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(sol[i][j]==1){
				cout<<". ";
			}else{
				cout<<maze[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}
bool isValid(int x,int y){
	return x>=0 && x<4 && y>=0 && y<4;
}
bool solvemaze(int maze[4][4], int sol[4][4],int x,int y){
	//Terminating condition
	if(x==3 && y==3){
		sol[x][y]=1;
		return true;
	}
	int steps= maze[x][y];
	
	// Moving to the right
	for(int i=1;i<=steps;i++){
		if(isValid(x,y+i)&&solvemaze(maze,sol,x,y+i)){
			sol[x][y]=1;
			return true;
		}
	}
	// Moving to the down
	for(int i=1;i<=steps;i++){
		if(isValid(x+i,y)&&solvemaze(maze,sol,x+i,y)){
			sol[x][y]=1;
			return true;
		}
	}
	return false;
}
int main(){
	int maze[4][4]={{2,1,0,0},
					{3,0,0,1},
					{0,1,0,1},
					{0,0,0,1}};
					
	int sol[4][4]={0};
	cout<<"Original"<<endl;
	print(maze,sol);
	
	if(solvemaze(maze,sol,0,0)){
		cout<<"Path found"<<endl;
		print(maze,sol);
	}else{
		cout<<"No path";
	}
}
