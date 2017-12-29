

#include "ft_printf.h"

int ft_printf(char *str, ...)
{
	int num;
	va_list argum;
	t_printf *format;
	int i;

	num = 0;
	i = 0;
	format = NULL;
	va_start(argum, str);
	while(str[i] != '\0')
	{
		while (str[i] != '%' && str[i] != '\0')
		{
			ft_putchar(str[i]);
			num++;
			i++;
		}
		if(str[i] == '%')
		{
			i = ft_specif(&format, str, i + 1);
			// printf("flag = %s\n", format->flag);
			// printf("width = %d\n", format->width);
			// printf("precision = %d\n", format->precision);
			// printf("length = %s\n", format->length);
			// printf("type = %s\n", format->type);
			num = ft_outp(format, argum, num);
		}
	}
	va_end(argum);
	return (num);
}
