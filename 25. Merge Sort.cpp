/*Time Complexity of this algorithm is n(log n) and merge sort is not in-place algorithm*/
/*Merge Sort is stable algorithm*/

#include <iostream>
using namespace std;

void mergeArrays(int leftArr[], int leftArrSize, int rightArr[], int rightArrSize, int tempArr[])
{
	int i=0, j=0, k=0;
	
	while(i<leftArrSize && j<rightArrSize)
	{
		if(leftArr[i]<rightArr[j])
		{
			tempArr[k]=leftArr[i];
			i++;
			k++;
		}
		else
		{
			tempArr[k]=rightArr[j];
			j++;
			k++;
		}
	}
	while(i<leftArrSize)
	{
		tempArr[k]=leftArr[i];
		i++;
		k++;
	}
	while(j<rightArrSize)
	{
		tempArr[k]=rightArr[j];
		j++;
		k++;
	}
}

void mergeSortRec(int array[], int size, int tmp[])
{
	int i;
	int mid=size/2;
	
	if(size>1)
	{
		mergeSortRec(array, mid, tmp);
		mergeSortRec(array+mid, size-mid, tmp);
		
		mergeArrays(array, mid, array+mid, size-mid, tmp);
		for(i=0; i<size; i++)
		{
			array[i]=tmp[i];
		}
	}
}

void mergeSort(int array[], int size)
{
	int* tmpArrayPtr = new int[size];
	
	if(tmpArrayPtr!=NULL)
	{
		mergeSortRec(array, size, tmpArrayPtr);
	}
	else
	{
		cout<<"Not enough memory to sort list.\n";
		return;
	}
	
	delete[] tmpArrayPtr;
}

int main()
{
	int arr[8]={12, 4, 10, 8, 5, 2, 11, 7};
	
	cout<<"Before Sorting:\t";
	for(int i=0; i<8; i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<"\n\n";
	
	mergeSort(arr, 8);
	cout<<"After Sorting:\t";
	for(int i=0; i<8; i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<"\n";
}