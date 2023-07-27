#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_integer - function to handle the %d and %i for integers
 * @num: variable to hold input
 * return: an integer
 */

void print_integer(int num)
{
	char buffer[1024];
	int num_chars = 0;
	int is_negative = 0;
	int i, j;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	do {
		buffer[num_chars++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);

	if (is_negative)
	{
		buffer[num_chars++] = '-';
	}
	for (i = 0, j = num_chars - 1; i < j; i++, j--)
	{
		char temp = buffer[i];

		buffer[i] = buffer[j];
		buffer[j] = temp;
	}

	write(1, buffer, num_chars);
}
