/*Time complexity of this algorithm is O(n^2) and selection sort is in-place algorithm*/
/*Selection Sort is not stable algorithm*/

#include <iostream>
using namespace std;

int findIndex(int arr[], int start, int N)
{
    int posmin=start, index;
    
    for(index=start; index<N; index++)
    {
        if(arr[index]<arr[posmin])
        {
            posmin=index;
        }
    }
    return posmin;
}

void selectionSort(int arr[], int N)
{
    int count, posmin, tmp;
    
    for(count=0; count<N; count++)
    {
        posmin=findIndex(arr, count, N);
        tmp=arr[posmin];
        arr[posmin]=arr[count];
        arr[count]=tmp;
    }
}

int main()
{
    int arr[5]={20, 8, 5, 10, 7};
    
    cout<<"Befor sorting:\t";
    for(int i=0; i<5; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n\n";
    
    selectionSort(arr, 5);
    cout<<"After sorting:\t";
    for(int i=0; i<5; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}
