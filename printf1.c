#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <string.h>
#include <stdio.h>

/**
 * print_integer - function to handle the %d and %i for integers
 * @num: variable to hold input
 * return: number of characters
 */

int print_integer(int num)
{
	char buffer[1024];
	int num_chars = 0;
	int is_negative = 0;
	int i, j;
	char temp;
	unsigned int num2;

	if (num < 0)
	{
		is_negative = 1;
		num2 = -num;
	}
	else
	{
		num2 = num;
	}
	do {
		buffer[num_chars++] = num2 % 10 + '0';
		num2 /= 10;
	} while (num2 > 0);

	if (is_negative)
	{
		buffer[num_chars++] = '-';
	}
	for (i = 0, j = num_chars - 1; i < j; i++, j--)
	{
		temp = buffer[i];
		
		buffer[i] = buffer[j];
		buffer[j] = temp;
	}
	buffer[num_chars] = '\0';

	write(1, buffer, num_chars);
	return (num_chars);
}
