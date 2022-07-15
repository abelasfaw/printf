#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
/**
 * num_len- get length of a number
 * @num: number to be processed
 * Return: length
 */
int num_len(int num)
{
	int len;

	len = 0;
	if (num < 0)
	{
		num = num * (-1);
	}
	if (num < 10)
	{
		return (1);
	}
	else
	{
		while (num > 0)
		{
			num = (num / 10);
			len += 1;
		}
	}
	return (len);
}
/**
 * convert_decimal- converts decimal input to str
 * @num: number to convert
 * @len: length of number
 * Return: converted string
 */
char *convert_decimal(int num, int len)
{
	char *ptr;
	int temp, index;

	index = 0;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
	{
		return (NULL);
	}
	if (num < 0)
	{
		num = num * -1;
	}
	if (len == 1)
	{
		*(ptr + index) = num + '0';
		index += 1;
	}
	else
	{
		while (num > 9)
		{
			temp = num % 10;
			*(ptr + index) = temp + '0';
			index += 1;
			num = num / 10;
		}
		*(ptr + index) = num + '0';
		index += 1;
	}
	*(ptr + index) = '\0';
	return (ptr);
}
/**
 * print_reverse- prints string in reverse order
 * @str: string to print
 * @len: length of string
 * @char_count_ptr: pointer to character counting variable
 * Return: void
 */
void print_reverse(char *str, int len, int *char_count_ptr)
{
	char ch;
	int index;

	index = len - 1;

	while (index >= 0)
	{
		ch = *(str + index);
		_putchar(ch);
		*(char_count_ptr) += 1;
		index -= 1;
	}
	free(str);
}

/**
 * print_decimal - prints decimal input
 * @num: number to print
 * @char_count_ptr: pointer to character counting variable
 * Return: void
 */
void print_decimal(int num, int *char_count_ptr)
{
	int len;
	char *str;

	if (num < 0)
	{
		_putchar('-');
		*(char_count_ptr) += 1;
	}
	if (num == INT_MIN)
	{
		print_str2("2147483648");
		*(char_count_ptr) += 10;
	}
	else
	{
		len = num_len(num);
		str = convert_decimal(num, len);
		print_reverse(str, len, char_count_ptr);
		free(str);
	}

}
