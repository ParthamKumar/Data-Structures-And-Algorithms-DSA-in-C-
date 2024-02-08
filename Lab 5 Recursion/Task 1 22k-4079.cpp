#include<iostream>
using namespace std;
void function(int a, int b, int n){
	if(n==1){
		return;
	}else{
		int c = a+b;
		cout<<c<<" ";
		function(b,c,n-1);
	}
}
int main(){
	int a=0;
	int b=1;
	int n=14;
	cout<<a<<" "<<b<<" ";
	function(a,b,n-2);
}

