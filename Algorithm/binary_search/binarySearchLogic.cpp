#include <iostream>

int bin_search(int*, int, int);

int main()
{
		int sorted_arr1[6] = {3,5,6,8,10,99};
		int sorted_arr2[6] = {1,7,11,21,33,99};
		int sorted_arr3[7] = {0,1,7,11,21,33,99};
		std::cout << "expected value -> 5" << std::endl
			 	  << "function value -> " << bin_search(sorted_arr1, 6, 99) << std::endl << std::endl;
		std::cout << "expected value -> 3" << std::endl
			 	  << "function value -> " << bin_search(sorted_arr2, 6, 21) << std::endl << std::endl;
		std::cout << "expected value -> 5" << std::endl
			 	  << "function value -> " << bin_search(sorted_arr3, 7, 33) << std::endl;

		return 0;
}

int bin_search(int *arr, int len, int target)
{
	int min = 0;						// first value index of the sorted array
	int max = len-1;					// last value index of the sorted array
	int mid = (len-1)/2;				// the middle value index of the sorted array
	while (arr[mid] != target)
	{	
			if (arr[mid] > target)		// when the value in the middle is grater than the target value
			{
					max = mid-1;		// update the max index to the middle index-1
			}
			else 						// when the value in the middle is smaller than the target value
			{
					min = mid+1;		// updaate the mix index to the middle index+1
			}
			mid = (max + min)/2;		// finally update middle index
	}
	return mid;							// when the loop is over the mid is the index of our target value;
}
