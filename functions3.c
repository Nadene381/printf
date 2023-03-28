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
i{
ibuf = handleBuffer(buf, ((n / div) % 10) + '0', ibuf);
}
return (i);
}
/**
* prinhupx - A function that prints a short decimal in hexadecimal
* @arguments: The character to print
* @buf: buffer pointer
* @ibuf: index for buffer pointer
* Return: number of chars printed
*/
int prinhupx(va_list arguments, char *buf, unsigned int ibuf)
{
short int input, i, neg, count, digit1;
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
binary = malloc(sizeof(char) * (16 + 1));
binary = binaryArray(binary, input, neg, 16);
hexadecimal = malloc(sizeof(char) * (4 + 1));
hexadecimal = hexArray(binary, hexadecimal, 1, 4);
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


