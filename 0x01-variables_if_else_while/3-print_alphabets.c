#include <stdio.h>

/**
*main - Program that prints the alphabet in lowercase and then in uppercase
*Return: 0 (success)
*/

int main(void)
{
	char c;
	char m;

	c = 'a';
	m = 'A';
	while
		(c <= 'z') {
			putchar(c);
			c++;
		}
	while
		(m <= 'z') {
			putchar(c);
			m++;
		}
	putchar('\n');
	return (0);
}
