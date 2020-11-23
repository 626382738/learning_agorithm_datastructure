#include <cstdio>
#include <cstdlib>							// for exit
#include <malloc.h>							// for malloc

struct Arr
{
	int *pBase; // store the address of the first element of the array
	int len;	// capability
	int cnt;	// current number of element
};

void init_arr(struct Arr * pArr, int length); 								// +
bool append_arr(struct Arr * pArr, int val); // append a element		  	// +
bool insert_arr(struct Arr * pArr, int pos, int val);// insert befor pos, pos start form 1		// +
bool delete_arr(struct Arr * pArr, int pos, int* pVal); 					// +
bool is_empty(struct Arr * pArr);			  								// +
bool is_full(struct Arr * pArr);			  								// +
void sort_arr(struct Arr * pArr);			  								// +
void show_arr(struct Arr * pArr);			  								// +
void reverse_arr(struct Arr* pArr);							  				// +

int main()
{
	struct Arr arr;
	int val;

	init_arr(&arr, 6);		
	show_arr(&arr);
	append_arr(&arr, 1);
	append_arr(&arr, 2);
	append_arr(&arr, 3);
	append_arr(&arr, 4);
	show_arr(&arr);
	reverse_arr(&arr);
	show_arr(&arr);
	sort_arr(&arr);
	show_arr(&arr);
	
//	if(delete_arr(&arr, 1, &val))
//	{
//			printf("success delete %d\n", val);
//	}
//	else
//	{
//			printf("fail delete/n");
//	}
	
//	append_arr(&arr, 3);
//	append_arr(&arr, 2);
//	append_arr(&arr, 4);
//	append_arr(&arr, 5);
//	insert_arr(&arr, 1, 99);



	return 0;
}


void init_arr(struct Arr *pArr, int length)
{
	pArr->pBase = (int*) malloc (sizeof(int) * length);
	if( NULL == pArr->pBase)
	{
		printf("malloc fail/n");
		exit(-1);
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
}

bool is_empty(struct Arr * pArr)
{
	if(pArr->cnt == 0)
	{
			return true;
	}
	else
	{
			return false;
	}
}

void show_arr(struct Arr * pArr)
{
	if (is_empty(pArr))
	{
			printf("array is empty\n");
	}
	else
	{
		for (int i=0; i<pArr->cnt; i++)
		{
				printf("%d ", pArr->pBase[i]);
		}
		printf("\n");
	}

}

bool is_full(struct Arr * pArr)
{
	if(pArr->cnt == pArr->len)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool append_arr(struct Arr * pArr, int val)
{
	if(is_full(pArr))
	{
		return false;
	}
	else
	{
		pArr->pBase[pArr->cnt] = val;
		pArr->cnt++;							// update the current number of values
		return true;
	}
}

bool insert_arr(struct Arr * pArr, int pos, int val)
{
	if(is_full(pArr))
	{
			return false;
	}
	if(pos<1 || pos>pArr->cnt+1)
	{
			return false;
	}
	else
	{
			for(int i=pArr->cnt-1; i>=pos-1; --i)
			{
				pArr->pBase[i+1] = pArr->pBase[i];
			}
			pArr->pBase[pos-1] = val;
			pArr->cnt++;
			return true;
	}
}

bool delete_arr(struct Arr * pArr, int pos, int* pVal)
{
	if(is_empty(pArr))
	{
			return false;
	}
	if (pos<1 || pos>pArr->cnt)
	{
			return false;
	}
	
	*pVal = pArr->pBase[pos-1];

	for (int i=pos; i<pArr->cnt; ++i)
	{
			pArr->pBase[i-1] = pArr->pBase[i];
	}
	pArr->cnt--;
	return true;

}

void reverse_arr(struct Arr* pArr)
{
	int i=0;
	int j= pArr->cnt-1;
	int t;
	while(i<j)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		++i;
		--j;
	}
	return;
}

void sort_arr(struct Arr * pArr)
{
	int t;
	for(int i=0; i<pArr->cnt; ++i)
	{
		for(int j=i+1; j<pArr->cnt; ++j)
		{
			t = pArr->pBase[i];
			pArr->pBase[i] = pArr->pBase[j];
			pArr->pBase[j] = t;

		}
	}
}
