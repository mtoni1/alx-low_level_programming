#include <stdio.h>

/**
*main - Program that prints all possible combinatios of single-digit numbers 
*Return: 0 (success)
*/

int main(void)
{
	int m;

	for (m = 0; m < 10; m++)
	{
		putchar(m + '0');
		if (a< 9)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
