#include<iostream>
using namespace std;
int m=11;
void fun2(int,int,int,int);

void fun1(int n,int a,int b,int c)
{
	if(n==m)
	{
		cout<<a<<" "<<b<<" ";
	}
	if(n==0)
	{
		return;
	}
	fun2(n,a,b,c);
}
void fun2(int n,int a,int b,int c)
{
	c=a+b;
	cout<<c<<" ";
	a=b;
	b=c;
	fun1(n-1,a,b,c);
}
main()
{
	fun1(m,0,1,0);
}
