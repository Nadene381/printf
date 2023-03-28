/**
* print_rot - A function that writes the str in ROT13
* @arguments: input string
* @buf: buffer pointer
* @ibuf: index for buffer pointer
* Return: 1.
*/

int print_rot(va_list arguments, char *buf, unsigned int ibuf)
{
char alf[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
char *str;
unsigned int i, n, k;
char nill[] = "(avyy)";

str = va_arg(arguments, char *);
if (str == NULL)
{
for (i = 0; nill[i]; i++)
ibuf = handleBuffer(buf, nill[i], ibuf);
return (6);
}
for (i = 0; str[i]; i++)
{
for (k = n = 0; alf[n]; n++)
{
if (str[i] == alf[n])
{
k = 1;
ibuf = handleBuffer(buf, rot[n], ibuf);
break;
}
}
if (k == 0)
ibuf = handleBuffer(buf, str[i], ibuf);
}
return (i);
}
/**
* print_rev - A function that writes the str in reverse
* @arguments: input string
* @buf: buffer pointer
* @ibuf: index for buffer pointer
* Return: number of chars printed.
*/
int print_rev(va_list arguments, char *buf, unsigned int ibuf)
{
char *str;
unsigned int i;
int n = 0;
char nill[] = "(llun)";

str = va_arg(arguments, char *);
if (str == NULL)
{
for (i = 0; nill[i]; i++)
ibuf = handleBuffer(buf, nill[i], ibuf);
return (6);
}
for (i = 0; str[i]; i++)
;
n = i - 1;
for (; n >= 0; n--)
{
ibuf = handleBuffer(buf, str[n], ibuf);
}
return (i);
}

