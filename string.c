#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_str2 - prints str
 * @str: string to be printed
 * Return: void
 */
void print_str2(char *str)
{
	int index;
	char ch;

	index = 0;
	ch = *(str + index);
	while (ch != '\0')
	{
		_putchar(ch);
		index += 1;
		ch = *(str + index);
	}
}
/**
 * print_str - prints string
 * @str: string to be printed
 * @count_ptr: pointer to char count
 * Return: void
 */
void print_str(char *str, int *count_ptr)
{
	char ch;
	int index = 0;

	if (str == ((char *)0))
	{
		print_str2("(null)");
		*(count_ptr) += 6;
	}
	else
	{
		ch = *(str + index);
		while (ch != '\0')
		{
			_putchar(ch);
			*(count_ptr) += 1;
			index += 1;
			ch = *(str + index);
		}
	}
}
