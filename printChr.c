#include "main.h"
#include <stdio.h>
/**
 * printChr - writes the character c to stdout
 * @arguments: input char
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: On success 1.
 */
int printChr(va_list arguments, char *buf, unsigned int ibuf)
{
	char c;

	c = va_arg(arguments, int);
	handlBuf(buf, c, ibuf);

	return (1);
}
