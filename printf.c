#include "main.h"

void output_buffer(char buffer[], int *buff_count)
{
    write(1, buffer, *buff_count);
    *buff_count = 0;
}



int _printf(const char *format, ...)
{
    char buffer[buffer_size];
    char *str;
    int buff_count=0,j;
    va_list args;
    
    va_start(args, format);
    

    if (format == NULL)
		return (-1);
      while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    if (buff_count >= buffer_size)
                        output_buffer(buffer, &buff_count);
                    buffer[buff_count++] = (char)va_arg(args, int);
                    break;
                case 's':
                    for (str = va_arg(args, char *); *str; str++) {
                        if (buff_count >= buffer_size)
                            output_buffer(buffer, &buff_count);
                        buffer[buff_count++] = *str;
                    }
                    break;
                case '%':
                    if (buff_count >= buffer_size)
                        output_buffer(buffer, &buff_count);
                    buffer[buff_count++] = '%';
                    break;
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    char str_num[12]; 
                    int i = 0;
                    if (num == 0) {
                        str_num[i++] = '0';
                    } else {
                        if (num < 0) {
                        buffer[buff_count++] = '-';
                            num = -num;
                        }
                        for (; num > 0; num /= 10) {
                            str_num[i++] = '0' + num % 10;
                        }
                    }
                    
                    for (j = 0; j < i / 2; j++) {
                        char temp = str_num[j];
                        str_num[j] = str_num[i - j - 1];
                        str_num[i - j - 1] = temp;
                    }
                    str_num[i] = '\0'; 
                    for (str = str_num; *str; str++) {
                        if (buff_count >= buffer_size)
                            output_buffer(buffer, &buff_count);
                        buffer[buff_count++] = *str;
                    }
                    break;
                }

            }
        } else {
            if (buff_count >= buffer_size)
                output_buffer(buffer, &buff_count);
            buffer[buff_count++] = *format;
        }
        format++;
    }

    

    output_buffer(buffer, &buff_count);

    va_end(args);

    return buff_count;
}