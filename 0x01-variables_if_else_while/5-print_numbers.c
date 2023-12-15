#include <stdio.h>

/**
*main - Program that prints single digit numbers of base 10
*Return: 0 (success)
*/

int main(void)
{
	int d;
	
	for (d = 0; d < 10; d++)
		printf("%d", d);
	putchar('\n');
	return (0);
}
