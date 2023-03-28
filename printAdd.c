#include "main.h"
#include <stdio.h>
/**
 * printAdd - prints the address of an input variable
 * @arguments: input address.
 * @buf: buffer pointer.
 * @ibuf: index for buffer pointer
 *
 * Return: number of chars printed.
 */
int printAdd(va_list arguments, char *buf, unsigned int ibuf)
{
	void *add;
	long int int_input;
	int i, count, first_digit, isnegative;
	char *hexadecimal, *binary;
	char nill[] = "(nil)";

	add = (va_arg(arguments, void *));
	if (add == NULL)
	{
		for (i = 0; nill[i]; i++)
			ibuf = handleBuffer(buf, nill[i], ibuf);
		return (5);
	}
	int_input = (intptr_t)add;
	isnegative = 0;
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}
	binary = malloc(sizeof(char) * (64 + 1));
	binary = binaryArray(binary, int_input, isnegative, 64);
	hexadecimal = malloc(sizeof(char) * (16 + 1));
	hexadecimal = hexArray(binary, hexadecimal, 0, 16);
	ibuf = handleBuffer(buf, '0', ibuf);
	ibuf = handleBuffer(buf, 'x', ibuf);
	for (first_digit = i = count = 0; hexadecimal[i]; i++)
	{
		if (hexadecimal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = handleBuffer(buf, hexadecimal[i], ibuf);
			count++;
		}
	}
	free(binary);
	free(hexadecimal);
	return (count + 2);
}
