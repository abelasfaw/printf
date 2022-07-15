#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * convert_to_binary - converts decimal to binary
 * @num: number to be converted
 * Return: binary form of number
 */
unsigned long int convert_to_binary(int num)
{
	unsigned long int bin = 0;
	int rem, i;

	i = 1;
	while (num != 0)
	{
		rem = num % 2;
		num /= 2;
		bin += rem * i;
		i *= 10;
	}
	return (bin);
}
/**
 * bin_len- calculate length of binary number
 * @num: number input
 * Return: length of number
 */
int bin_len(unsigned long int num)
{
	int len;

	len = 0;
	if (num < 10)
	{
		return (1);
	}
	else
	{
		while (num > 0)
		{
			num = num / 10;
			len += 1;
		}
	}
	return (len);
}
/**
 * _str_len- calculate length of string
 * @str: string to be processed
 * Return: length
 */
int _str_len(char *str)
{
	char ch;
	int len, index;

	len = index = 0;
	ch = *(str + index);
	while (ch != '\0')
	{
		len += 1;
		index += 1;
		ch = *(str + index);
	}
	return (len);
}
/**
 * convert_to_str- convert decimal to binary string
 * @num: number to be converted
 * Return: binary string format
 */
char *convert_to_str(int num)
{
	char *ptr;
	int index, rem;

	index = 0;
	ptr = malloc(sizeof(char) * 32);
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (num != 0)
	{
		rem = num % 2;
		num /= 2;
		printf("rem: %d", num);
		*(ptr + index) = rem + '0';
		index += 1;
	}
	*(ptr + index) = '\0';
	return (ptr);
}
/**
 * print_binary- prints number in binary format
 * @num: number to be printed
 * @char_count: pointer to char count variable
 * Return: number of chars printed
 */
void print_binary(int num, int *char_count)
{
	char *str;
	int len;

	if (num == 0)
	{
		_putchar(num + '0');
		*(char_count) += 1;
	}
	else
	{
		if (num < 0)
		{
			num = num * -1;
			_putchar('-');
			*(char_count) += 1;
		}
		str = convert_to_str(num);
		len = _str_len(str);
		print_reverse(str, len, char_count);
	}
}
