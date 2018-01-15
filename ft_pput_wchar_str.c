#include "ft_printf.h"

static void		ft_putik(t_printf **format, wchar_t *S)
{
	char	*str;
	int		r;

	if((*format)->precision < ft_wandc_len(S))
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

void ft_pput_wchar_str(t_printf **format, va_list argum)
{
	wchar_t	*S;

	S = va_arg(argum, wchar_t*);
	if ((*format)->width < 0)
		(*format)->width = 0;
	(*format)->num = (*format)->num + ft_strlen((*format)->buf);
	write(1, (*format)->buf, ft_strlen((*format)->buf));
	free((*format)->buf);
	(*format)->buf = ft_strdup("");
	ft_putik(format, S);
}
