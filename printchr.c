#include "main.h"
#include <stdio.h>
/**
 * print_chr - writes the character c to stdout
 * @arguments: variable passed in function
 * @buf: buffer pointer
 * @i: variable passed in function
 * Return: On success 1.
 */
int print_chr(va_list arguments, char *buf, unsigned int i)
{
char c;
c = va_arg(arguments, int);
handl_buf(buf, c, i);
return (1);
}
