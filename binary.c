#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

void print_binary(unsigned int num)
{
	char binary[32];
	int i = 0, j;

	for (j = 31; j >= 0; j--)
	{
		binary[i++] = (num & (1 << j)) ? '1' : '0';
	}

	i = 0;
	while (binary[i] == '0')
	{
		i++;
	}

	write(1, binary + i, 32 - i);
}
