#include "arrayBubbleSort.h"

void arrayBubbleSort::BubbleSort(int* arr, int len, int order)
{
	for(int i=0; i<len-1; i++)
	{
			for(int j=0; j<len-i-1; j++)
			{
					if(order == 1)
					{
						if(arr[j] > arr[j+1])
						{
								int temp = arr[j];
								arr[j] = arr[j+1];
								arr[j+1] = temp;
						}
					}
					else if(order == 2)
					{
						if(arr[j] < arr[j+1])
						{
								int temp = arr[j];
								arr[j] = arr[j+1];
								arr[j+1] = temp;
						}
					}
			}
	}

}
