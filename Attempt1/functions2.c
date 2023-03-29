#include "main.h"
#include <stdarg.h>
/**
* print_usr - A Function prints a string and values of
* non-printed chars
* @arguments: input string
* @buf: buffer pointer
* @ibuf: index for buffer pointer
* Return: 1
*/
int print_usr(va_list arguments, char *buf, unsigned int ibuf)
{
unsigned char *str;
char *hexadecimal, *binary;
unsigned int i, sum, op;

str = va_arg(arguments, unsigned char *);
binary = malloc(sizeof(char) * (32 + 1));
hexadecimal = malloc(sizeof(char) * (8 + 1));
for (sum = i = 0; str[i]; i++)
{
if (str[i] < 32 || str[i] >= 127)
{
ibuf = handleBuffer(buf, '\\', ibuf);
ibuf = handleBuffer(buf, 'x', ibuf);
op = str[i];
binary = binaryArray(binary, op, 0, 32);
hexadecimal = hexArray(binary, hexadecimal, 1, 8);
ibuf = handleBuffer(buf, hexadecimal[6], ibuf);
ibuf = handleBuffer(buf, hexadecimal[7], ibuf);
sum += 3;
}
else
ibuf = handleBuffer(buf, str[i], ibuf);
}
free(binary);
free(hexadecimal);
return (i + sum);
}
/**
* print_upx - A Function that prints a decimal in hexadecimal
* @arguments: The character to print
* @buf: buffer pointer
* @ibuf: index for buffer pointer
* Return: number of chars printed
*/
int print_upx(va_list arguments, char *buf, unsigned int ibuf)
{
int input, i, neg, count, digit1;
char *hexadecimal, *binary;

input = va_arg(arguments, int);
neg = 0;
if (input == 0)
{
ibuf = handleBuffer(buf, '0', ibuf);
return (1);
}
if (input < 0)
{
input = (input * -1) - 1;
neg = 1;
}
binary = malloc(sizeof(char) * (32 + 1));
binary = binaryArray(binary, input, neg, 32);
hexadecimal = malloc(sizeof(char) * (8 + 1));
hexadecimal = hexArray(binary, hexadecimal, 1, 8);
for (digit1 = i = count = 0; hexadecimal[i]; i++)
{
if (hexadecimal[i] != '0' && digit1 == 0)
digit1 = 1;
if (digit1)
{
ibuf = handleBuffer(buf, hexadecimal[i], ibuf);
count++;
}
}
free(binary);
free(hexadecimal);
return (count);
}
/**
* print_unt - A Function that prints an unsigned int
* @arguments: number to print
* @buf: buffer pointer
* @ibuf: index for buffer pointer
* Return: number of chars printed.
*/
int print_unt(va_list arguments, char *buf, unsigned int ibuf)
{
unsigned int n, m, i, div;

n = va_arg(arguments, unsigned int);
m = n;
div = 1;
while (m > 9)
{
div *= 10;
m /= 10;
}
for (i = 0; div > 0; div /= 10, i++)
{
ibuf = handleBuffer(buf, ((n / div) % 10) + '0', ibuf);
}
return (i);
}
/**
* print_str - A Function that writes the string to stdout
* @arguments: input string
* @buf: buffer pointer
* @ibuf: index for buffer pointer
* Return: 1.
*/
int print_str(va_list arguments, char *buf, unsigned int ibuf)
{
char *str;
unsigned int i;
char nill[] = "(null)";

str = va_arg(arguments, char *);
if (str == NULL)
{
for (i = 0; nill[i]; i++)
ibuf = handleBuffer(buf, nill[i], ibuf);
return (6);
}
for (i = 0; str[i]; i++)
ibuf = handleBuffer(buf, str[i], ibuf);
return (i);
}
/**
* prinsint - A Function that prints int begining with space
* @arguments: input string
* @buf: buffer pointer
* @ibuf: index for buffer pointer
* Return: 1
*/
int prinsint(va_list arguments, char *buf, unsigned int ibuf)
{
int input;
unsigned int int_in, m, i, div;

input = va_arg(arguments, int);
if (input < 0)
{
int_in = input * -1;
ibuf = handleBuffer(buf, '-', ibuf);
}
else
{
int_in = input;
ibuf = handleBuffer(buf, ' ', ibuf);
}
m = int_in;
div = 1;
while (m > 9)
{
div *= 10;
m /= 10;
}
for (i = 0; div > 0; div /= 10, i++)
{
ibuf = handleBuffer(buf, ((int_in / div) % 10) + '0', ibuf);
}
return (i + 1);
}
