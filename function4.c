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
/**
* print_prg - A function that writes the character c to stdout
* @a: input char
* @buf: buffer pointer
* @i: index for buffer pointer
* Return: On success 1.
*/
int print_prg(va_list a __attribute__((unused)), char *buf, unsigned int i)
{
handleBuffer(buf, '%', i);
return (1);
}
/**
* prinpint - A function that print integer with plus symbol
* @arguments: input string
* @buf: buffer pointer
* @ibuf: index for buffer pointer
* Return: 1
*/
int prinpint(va_list arguments, char *buf, unsigned int ibuf)
{
int input;
unsigned int n, m, i, div;

input = va_arg(arguments, int);
if (input < 0)
{
n = input * -1;
ibuf = handleBuffer(buf, '-', ibuf);
}
else
{
n = input;
ibuf = handleBuffer(buf, '+', ibuf);
}
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
return (i + 1);
}

