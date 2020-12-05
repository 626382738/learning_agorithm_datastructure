#include <stdio.h>

long summation(long n)
{
	if(n == 1)
	{
		return n;
	}
	else
	{
		return n+summation(n-1);
	}
}
int main()
{
	long ret = summation(100);
	printf("%ld\n",ret);

	return 0;
}
