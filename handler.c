#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * amp_handler- handles cases where '%' is detected
 * @format: string to be printed
 * @index: pointer to current position of character read
 * @args: pointer to va_list type argument
 * @char_count: pointer to char count
 * Return: void
 */
void amp_handler(const char *format, int *index, va_list args, int *char_count)
{
	char ch;

	*(index) += 1;
	ch = *(format + *(index));
	if (ch == '\0')
	{
		*(char_count) = -1;
		*(index) -= 1;
	}
	else if (ch == 'c')
	{
		char cr = va_arg(args, int);

		_putchar(cr);
		*(char_count) += 1;
	}
	else if (ch == 's')
	{
		char *str = va_arg(args, char *);

		print_str(str, char_count);
	}
	else if (ch == 'd' || ch == 'i')
	{
		int num = va_arg(args, int);

		print_decimal(num, char_count);
	}
	else if (ch == '%')
	{
		_putchar('%');
		*(char_count) += 1;
	}
	else
	{
		_putchar('%');
		_putchar(ch);
		*(char_count) += 2;
	}
}
/**
 *backslash_handler- hanlde cases where '\' is detected
 *@format: string to be printed
 *@index: pointer to current position of character read
 *@char_count: ptr to char count
 */
void backslash_handler(const char *format, int *index, int *char_count)
{
	char ch;

	*(index) += 1;
	ch = *(format + *(index));
	if (ch == 92)
	{
		_putchar(92);
	}
	else if (ch == 'n')
	{
		_putchar('\n');
	}
	else if (ch == 't')
	{
		_putchar('\t');
	}
	else if (ch == 'r')
	{
		_putchar('\r');
	}
	else if (ch == 'v')
	{
		_putchar('\v');
	}
	else if (ch == 'b')
	{
		_putchar('\b');
	}
	else
	{
		_putchar(ch);
	}
	*(char_count) += 1;
}
/**
 * _printf - controls overall flow of print fucntion
 * @format: string to be printed with format specifier
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int index, char_count;
	char ch;
	va_list args, args_copy;

	index = char_count = 0;
	if (format == NULL)
	{
		return (-1);
	}
	ch = *(format + index);
	va_start(args, format);
	va_copy(args_copy, args);
	while (ch != '\0')
	{
		if (ch == '%')
		{
			amp_handler(format, &index, args_copy, &char_count);
		}
		else
		{
			_putchar(ch);
			char_count += 1;
		}
		index += 1;
		ch = *(format + index);
	}
	va_end(args);
	return (char_count);
}
