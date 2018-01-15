#include "ft_printf.h"

static int	ft_put_wchar2(wchar_t C)
{
	if (C <= 65535)
	{
		ft_putchar((C >> 12) + 0b11100000);
		ft_putchar(((C >> 6) & 0b111111) + 0b10000000);
		ft_putchar((C & 0b111111) + 0b10000000);
		return (3);
	}
	else if (C <= 1114111)
	{
		ft_putchar((C >> 18) + 0b11110000);
		ft_putchar(((C >> 12) & 0b111111) + 0b10000000);
		ft_putchar(((C >> 6) & 0b111111) + 0b10000000);
		ft_putchar((C & 0b111111) + 0b10000000);
		return (4);
	}
	else
		return (0);
}

static void		ft_putik(t_printf **format, wchar_t C)
{
	char	*str;
	int		r;

	if((*format)->flag[0] == '-')
	{
		r = ft_put_wchar(C);
		(*format)->num = (*format)->num + r;
		ft_putstr(str = ft_genchar(' ', (*format)->width - r));
		(*format)->num = (*format)->num + ft_strlen(str);
	}
	else
	{
		r = ft_wchar_len(C);
		if((*format)->flag[4] == '0')
			ft_putstr(str = ft_genchar('0', (*format)->width - r));
		else
			ft_putstr(str = ft_genchar(' ', (*format)->width - r));
		(*format)->num = (*format)->num + ft_put_wchar(C);
		(*format)->num = (*format)->num + ft_strlen(str);
	}
	free(str);
}

int			ft_put_wchar(wchar_t C)
{
	if (C <= 127)
	{
		ft_putchar(C);
		return (1);
	}
	else if (C <= 2047)
	{

		ft_putchar((C >> 6) + 0b11000000);
		ft_putchar((C & 0b111111) + 0b10000000);
		return (2);
	}
	else
		return (ft_put_wchar2(C));
}

void			ft_pput_wchar(t_printf **format, va_list argum)
{
	wchar_t	C;

	C = va_arg(argum, wchar_t);
	if ((*format)->width < 0)
		(*format)->width = 0;
	(*format)->num = (*format)->num + ft_strlen((*format)->buf);
	write(1, (*format)->buf, ft_strlen((*format)->buf));
	free((*format)->buf);
	(*format)->buf = ft_strdup("");
	ft_putik(format, C);
}
