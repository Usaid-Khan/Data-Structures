#include <iostream>
using namespace std;

int isPresent(int *arr, int val, int n)
{
	int low=0, high=n-1, mid;
	
	while(low<=high)
	{
		mid=(low+high)/2;
		if(arr[mid]==val)
		{
			return mid;
		}
		else if(arr[mid]<val)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	cout<<"Value is not found\n";
	return -1;
}

int main()
{
	int arr[9];
	arr[0]=1;
    arr[1]=5;
    arr[2]=7;
    arr[3]=9;
    arr[4]=10;
    arr[5]=13;
    arr[6]=17;
    arr[7]=19;
    arr[8]=27;

	int check=isPresent(arr, 7, 9);
	
	if(check!=-1)
	{
		cout<<"Value found at index: "<<check<<"\n";
	}
}