#include <stdio.h>

long f(long n)
{
	if(n==1)
	{
		return 1;
	}
	else
	{
		return n*f(n-1);
	}
}

int main()
{
	int val,mult=1;
	printf("Enter the number: ");
	scanf("%d", &val);

	// loop 
	for (int i=1; i<=val; i++)
	{
		mult *= i;
	}
	printf("%d's factorial is %d\n", val, mult);
	// recursion
	long n = val;
	long ret;
	ret = f(n);
	printf("%ld\n",ret);



	return 0;
}
