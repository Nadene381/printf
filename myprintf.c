#include <stdio.h>
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
while (*format != '\0')
{
if (*format == '%')
{
format++;
if (*format == 's')
{
char *val = va_arg(arg_list, char*);
printf("%s", val);
}
else if (*format == 'c')
{
char val = va_arg(arg_list, int);
printf("%c", val);
}
else if (*format == '%')
{
printf("%c", 37);
}
format++;
}
else
{
printf("%c", *format);
format++;
}
}
va_end(arg_list);
return (1);
}
