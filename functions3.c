/**
* prinhunt - A Function that prints a short unsigned integer
* @arguments: number to print
* @buf: buffer pointer
* @ibuf: index for buffer pointer
* Return: number of chars printed.
*/
int prinhunt(va_list arguments, char *buf, unsigned int ibuf)
{
unsigned short int n, m, i, div;

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

