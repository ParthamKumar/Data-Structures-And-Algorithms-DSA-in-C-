#include<iostream>
using namespace std;

void interpolationsearch(int arr[], int n, int key)
{
    int low = 0, high = n-1;
    bool flag = true;
    while(low <= high && key >= arr[low] && key <= arr[high])
    {
        int q = (key - arr[low])/(arr[high] - arr[low]);
        int pos = low + (high - low) * q;
        cout<<"Low value is "<<low<<" High value is "<<high<<" position calculated is "<<pos<<endl;
        if(arr[pos] == key)
        {
            cout<<"Element found at position "<<pos<<endl;
            flag = false;
        }
        if(arr[pos] < key)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }
    if(flag == true)
    {
     cout<<"Element not found"<<endl;
    }
}

int main()
{
	int n=5,i,x;
	int arr[n]={1,2,3,4,5};;
    cout<<"Enter the element to be searched\n";
    cin>>x;
    interpolationsearch(arr, n, x);
//    return 0;
}
