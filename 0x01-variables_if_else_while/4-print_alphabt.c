#include <stdio.h>

/**
*main - Program that prints the alphabet in lowercase except 'q' and 'e'
*Return: 0 (success)
*/

int main(void)
{
	char c;
	c = 'a';
	while
		(c <= 'z') {
			if ((c != 'q' && c != 'e') && c <= 'z')
				putchar(c);
			c++;
		}
	putchar('\n');
	return (0);
}
