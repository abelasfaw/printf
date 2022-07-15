#include "main.h"
/**
 * update_char_count- updates number of char printed by num
 * @count_ptr: pointer to character counting variable
 * @num: number of chars printed
 * Return: void
 */
void update_char_count(int *count_ptr, int num)
{
	*(count_ptr) += num;
}
