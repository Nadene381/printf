#include "main.h"

/**
 * printBuf - prints buffer
 * @buf: buffer pointer
 * @nbuf: number of bytes to print
 * Return: number of bytes printed.
 */
int printBuf(char *buf, unsigned int nbuf)
{
	return (write(1, buf, nbuf));
}
