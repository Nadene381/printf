#include "main.h"

/**
 * handlebuffer - A Function that concatenates the buffer characters
 * @buf: buffer pointer
 * @c: charcter to concatenate
 * @i: index of buffer pointer
 * Return: 1.
 */
unsigned int handlebuffer(char *buf, char c, unsigned int i)
{
if (i == 1024)
{
printBuf(buf, i);
i = 0;
}
buf[i] = c;
i++;
return (i);
}
