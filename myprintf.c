#include <stdarg.h>
#include "main.h"
/**
*_printf - A function that prints a char, string and %
*@format: A character string.
* Return: 1
*/
int _printf(const char *format, ...)
{
va_list arg_list;
va_start(arg_list, format);
char character;
char *string;
char *percentage;
char *n;
n = format;
while (*n != '\0')
{
if (*n == '%')
{
n++;
if (*n == 's')
{
string = va_arg(arg_list, char*);
printf("%s", string);
}
else if (*n == 'c')
{
character = va_arg(arg_list, int);
printf("%c", character);
}
else if (*n == '%')
{
printf("%c", 37);
}
n++;
}
else
{
printf("%c", *n);
n++;
}
}
va_end(arg_list);
}

