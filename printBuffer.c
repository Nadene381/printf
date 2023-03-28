#include "main.h"

/**
 * printBuf - A Function that prints the buffer
 * @buf: buffer pointer
 * @numbuf: number of bytes to print
 * Return: number of bytes printed.
 */
int printBuf(char *buf, unsigned int numbuf)
{
return (write(1, buf, numbuf));
}
