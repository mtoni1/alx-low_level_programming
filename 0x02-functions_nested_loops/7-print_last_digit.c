#include "main.h"

/**
*print the last digigt of a number
*@c: the number to be treated
*Return: value of the last digit of a number
*/

int print_last_digit(int n)
{
	int last;
	last = n%10;
	if (last<0)
	{
	last = last*-1;
	}
	_putchar(last + '0');
	return(last);
}
