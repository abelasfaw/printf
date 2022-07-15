#ifndef PRINTF_HEADERS_H
#define PRINTF_HEADERS_H
#include <stdarg.h>
int checkamp(char format);
int _printf(const char *format, ...);
int _putchar(char c);
void print_decimal(int num, int *char_count_ptr);
int num_len(int num);
char *convert_decimal(int num, int len);
void print_reverse(char *str, int len, int *char_count_ptr);
void print_hex(int num);
void print_str(char *str, int *count_ptr);
void update_char_count(int *count_ptr, int num);
void print_str2(char *str);
void print_binary(int num, int *char_count);
#endif
