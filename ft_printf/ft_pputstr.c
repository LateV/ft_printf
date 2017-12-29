
#include "ft_printf.h"

int	ft_flagmins(t_printf **format, char *str,int num)
{
	int i;

	i = 0;
	while((i < (*format)->precision) && str[i] != '\0')
	{
		ft_putchar(str[i]);
		num++;
		i++;
	}
	while(i < (*format)->width)
	{
		ft_putchar(' ');
		i++;
		num++;
	}
	return (num);
}

int	ft_noflagmins(t_printf **format, char *str, int num)
{
	int i;
	int j;
	int k;


	j = ((*format)->width) - ((*format)->precision);
	i = 0;
	k = 0;
	while(i < j)
	{
		ft_putchar(' ');
		num++;
		i++;
	}
	while(i < (*format)->width)
	{
		ft_putchar(str[k]);
		num++;
		k++;
		i++;
	}
	return (num);
}

int ft_ptops(t_printf **format, char *str, int num)
{
	if((*format)->flag[0] == '-' && str)
		num = ft_flagmins(format, str, num);
	else
		num = ft_noflagmins(format, str, num);
	return(num);
}

int ft_pputstr(t_printf **format, va_list argum, int num)
{
	int 	a;
	char	*str;

	a = 0;
	str = va_arg(argum,char*);
	if((*format)->precision < 0)
		(*format)->precision = (int)ft_strlen(str);
	if((*format)->width < 0 && (*format)->precision < 0)
		(*format)->width = ft_strlen(str);
	if((*format)->width < 0 && (*format)->precision >= 0)
		(*format)->width = (*format)->precision;
	if((*format)->width >= 0 && (*format)->precision < 0 && (int)ft_strlen(str) > (*format)->width)
		(*format)->width = (int)ft_strlen(str);
	num = ft_ptops(format, str, num);
	return(num);
}