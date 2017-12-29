
#include "ft_printf.h"
int ft_flagminc(t_printf **format, char *c,int num)
{
	int i;

	i = 0;
	write(1, &c, 1);
	i++;
	num++;
	while (i < (*format)->width)
	{
		ft_putchar(' ');
		i++;
		num++;
	}
	return (num);
}

int	ft_noflagminc(t_printf **format, char *c, int num)
{
	int i;

	i = 0;
	while (i < (*format)->width - 1)
	{
		ft_putchar(' ');
		i++;
		num++;
	}
	write(1, &c, 1);
	num++;
	return(num);
}

int ft_ptopc(t_printf **format, char *c, int num)
{
	if((*format)->flag[0] == '-' && c)
		num = ft_flagminc(format, c, num);
	else
		num = ft_noflagminc(format, c, num);
	return(num);
}

int	ft_pputchar(t_printf **format, va_list argum, int num)
{
	char	*c;

	c = va_arg(argum, char*);
	if((*format)->width < 0)
		(*format)->width = 1;
	num = ft_ptopc(format, c, num);
	return(num);
}
