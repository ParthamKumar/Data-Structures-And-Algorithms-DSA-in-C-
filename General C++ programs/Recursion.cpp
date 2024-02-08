#include<iostream>
using namespace std;
// Printing the numbers from 1 to 10 using recursion
void print(int n){
	if(n<1){
		return;
	}else{
		cout<<n<<" ";
		print(n-1);
	}
}
//  Printing in ascending order
void prints(int n){
	if(n==6){
		return;
	}
	else{
		cout<<n;
		prints(n+1);
	}
}
// Factorial function
int fact(int n){
	if(n<1){
		return 1;
	}
	else{
		return n * fact(n-1);
	}
}
// Fabonacci Series
void fabonacci(int a, int b, int n){
	if(n==1){
		return ;
	}else{
		int c= a+b;
		cout<<c<<" ";
		fabonacci(b,c,n-1);
	}
}
int main(){
	print(5);
	cout<<"An other Fun"<<endl;
	prints(1);
	cout<<endl<<"Printing the facorail of 5"<<endl;
	cout<<fact(5);
	cout<<"Printing the Fabonacci Series"<<endl;
	int a=0;
	int b=1;
	int n=10;
	cout<<a<<" "<<b<<" ";
	fabonacci(a,b,n-2);
}
