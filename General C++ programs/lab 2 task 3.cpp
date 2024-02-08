#include<iostream>
#include<string>
using namespace std;

struct Member{
	string post;
	int num;
};

int main(){
	Member member[] ={{"EMP",6},{"CFO",3},{"MGR",5},{"EMP",6},{"VP",4},{"CTO",2},{"MGR",5},{"CEO",1}};
	
	int i , j;
	int n= 8;
	
	for(i=1;i<n;i++){
		
		Member sm = member[i];
		
		int j=i-1;
		
		while(j>= 0 &&member[j].num>sm.num){
			member[j+1] = member[j];
			j=j-1;
		}
		
		member[j+1]=sm;
	}
	
	cout<<"Sorted Array is"<<endl;
	for(i=0;i<n;i++){
		cout<<member[i].post<<endl;
	}
}
