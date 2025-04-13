/*Time complexity of this algorithm is O(n^2) and insertion sort is in-place and stable algorithm*/
/

#include <iostream>
using namespace std;

void insertionSort(int arr[], int N)
{
    int count, val, pos;
    
    for(count=1; count<N; count++)
    {
        val=arr[count];
        for(pos=count-1; pos>=0; pos--)
        {
            if(arr[pos]>val)
            {
                arr[pos+1]=arr[pos];
            }
            else
            {
                break;
            }
        }
        arr[pos+1]=val;
    }
}

int main()
{
    int arr[4]={19, 12, 5, 7};
    
    cout<<"Before Sorting:\t";
    for(int i=0; i<4; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n\n";
    
    insertionSort(arr, 4);
    cout<<"After Sorting:\t";
    for(int i=0; i<4; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}
