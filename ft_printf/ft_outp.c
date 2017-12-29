
#include "ft_printf.h"

int ft_outp(t_printf *format, va_list argum, int num)
{
	if(format->flag[0] == '%')
	{
		ft_putchar('%');
		num ++;
		return(num);
	}
	if(format->type[0] == 's')
		num = ft_pputstr(&format, argum, num);
	 if(format->type[0] == 'c')
	 	num = ft_pputchar(&format, argum, num);
	 /*if(format->type[0] == 'd')
	 	num = ft_pputnbr()*/
	return (num);
}