#include<iostream>
using namespace std;
void fun(int a[],int b[],int c[]){
	int sizea = sizeof(a)/sizeof(a[0]);
	int sizeb = sizeof(b)/sizeof(b[0]);
//	c[]=c[sizea+sizeb];
	for(int i=0;i<10;i++){
		if(i<5){
		c[i]=a[i];
		}else{
		c[i]=b[i-5];
		}
	}
//	int n = sizeof(c)/sizeof(c[0]);
//	cout<<" value of n is"<<n<<endl;
	int n = 10;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(c[j]>c[j+1]){
				swap(c[j],c[j+1]);
			}
		}
	}
	for(int i=0;i<10;i++){
		cout<<c[i]<<" ";
	}	
}
int main(){
	int a[5]={1,2,3,4,5};
	int b[5]={10,9,8,7,6};
	int c[10];
	fun(a,b,c);
	
}
