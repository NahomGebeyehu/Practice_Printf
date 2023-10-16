#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define buffer_size 1024

int _printf(const char *format, ...);
void output_buffer(char buffer[], int *buff_count);
void buffer_int(int n, char buffer[], int *buff_count);

#endif /* MY_PRINTF_H */
