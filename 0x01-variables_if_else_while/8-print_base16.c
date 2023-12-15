#include <stdio.h>

/**
*main - Program that prints all numbers of base 16 and alphabet in lowercase
*Return: 0 (success)
*/

int main(void)
{
	char c;
	int m;

	c = 'a';
	m = 0;
	while
		(m < 10) {
			putchar(m + '0');
			m++;
		}
	while
		(c <= 'f') {
			putchar(c);
			m++;
		}
	putchar('\n');
	return (0);
}
