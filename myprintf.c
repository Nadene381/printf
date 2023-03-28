#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - formatted output conversion and print data.
 * @format: Character string.
 * Return: 1.
 */
int _printf(const char *format, ...)
{
unsigned int n = 0, lenght = 0, buf = 0;
va_list arguments;
int (*function)(va_list, char *, unsigned int);
char *buffer;
va_start(arguments, format), buffer = malloc(sizeof(char) * 1024);
if (!format || !buffer || (format[n] == '%' && !format[n + 1]))
return (-1);
if (!format[n])
return (0);
for (n = 0; format && format[n]; n++)
{
if (format[n] == '%')
{
if (format[n + 1] == '\0')
{
print_buf(buffer, ibuf), free(buffer), va_end(arguments);
return (-1);
}
else
{
function = getFunct(format, n + 1);
if (function == NULL)
{
if (format[n + 1] == ' ' && !format[n + 2])
return (-1);
handleBuffer(buffer, format[n], buf), lenght++, n--;
}
else
{
len += function(arguments, buffer, buf);
n += printFunc(format, n + 1);
}
}
n++;
}
else
handleBuffer(buffer, format[n], buf), lenght++;
for (buf = lenght; buf > 1024; buf -= 1024)
;
}
print_buf(buffer, buf), free(buffer), va_end(arguments);
return (lenght);
}
