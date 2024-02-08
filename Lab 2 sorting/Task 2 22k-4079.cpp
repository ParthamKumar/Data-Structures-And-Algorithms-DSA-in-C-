#include<iostream>
struct Date{
	int date;
	int month;
	int year;
};
using namespace std;
int main(){
//	e1.year = 23;
//	e2.year = 22;
//	e3.year = 20;
//	e3.year = 24;
//	e3.year = 21;

//	Date d[5] = {{23, 07, 2021},{23, 07, 2022},{23, 07, 2025},{23, 07, 2023},{23, 07, 2020} };

	Date d[5];
	int i, j, smallest,temp;
	int n = 5;
//	cout<<"Enter the date" << "\n";
	for(i=0;i<n;i++){
//		cout << d[i].date <<"/" <<d[i].month <<"/"<<d[i].year<<"\n";
cout<<"Enter the date "<<i+1 <<"\n";
	cin>>d[i].date ;
	cin>>d[i].month;
	cin >> d[i].year;
	}
	
	for(j=0;j<n-1;j++){
		smallest = j;
		for(i=j+1;i<n;i++){
			if(d[i].year<d[smallest].year){
			smallest = i;
			}
			
			}
		swap(d[j],d[smallest]);
	}
	for(i=0;i<n;i++){
		cout << d[i].date <<"/" <<d[i].month <<"/"<<d[i].year<<"\n";
	}
}

