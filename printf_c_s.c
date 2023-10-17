#include "main.h"
void output_buffer(char buffer[], int *buff_count)
{
	write(1, buffer, *buff_count);
}
void handle_c_s_mod(char buffer[], int *buff_count, va_list args, char format)
{
    char *str;
	if (*buff_count >= buffer_size)
		output_buffer(buffer, buff_count);
	if (format == 'c')
		buffer[(*buff_count)++] = (char)va_arg(args, int);
	else if (format == 's')
		for (str = va_arg(args, char *); *str; str++)
			buffer[(*buff_count)++] = *str;
	else if (format == '%')
		buffer[(*buff_count)++] = '%';
}
