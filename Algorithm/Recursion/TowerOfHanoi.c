#include <stdio.h>

void hanoi(int n, char x, char y, char z)
{
	if(n == 1)
	{
		printf("%d pannel from %c to %c\n", n, x, z);
	}
	else
	{
		hanoi(n-1, x, z, y);
		printf("%d pannel from %c to %c\n", n, x, z);
		hanoi(n-1, y, x, z);
	}

}

int main()
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;
	
	printf("please enter the number of pannel: ");
	scanf("%d", &n);
	
	hanoi(n, ch1, ch2, ch3);

	return 0;
}
