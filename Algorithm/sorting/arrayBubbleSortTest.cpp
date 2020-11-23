#include <iostream>
#include "arrayBubbleSort.h"

int main()
{
		arrayBubbleSort bbSort;
		int* arr = new int [5];
		arr[0] = 9;
		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 0;
		arr[4] = -3;

		bbSort.BubbleSort(arr, 5, 1);
		for(int i=0; i<5; i++)
		{
				std::cout << arr[i] << std::endl;
		}
		bbSort.BubbleSort(arr, 5, 2);
		for(int i=0; i<5; i++)
		{
				std::cout << arr[i] << std::endl;
		}


		return 0;
}
