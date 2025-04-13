/*Time Complexity of this algorithm is O(n^2) and bubble sort is in-place algorithm*/
/*Bubble Sort is stable algorithm*/

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int N)
{
    int swapped=1, i, bound=N-1, temp;
    
    while(swapped>0)
    {
        swapped=0;
        for(i=0; i<bound; i++)
        {
            if(arr[i]>arr[i+1])
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                swapped=i;
            }
        }
        bound=swapped;
    }
}

int main()
{
    int arr[4]={19, 5, 12, 7};
    
    cout<<"Before Sorting:\t";
    for(int i=0; i<4; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n\n";
    
    bubbleSort(arr, 4);
    cout<<"After Sorting:\t";
    for(int i=0; i<4; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}
